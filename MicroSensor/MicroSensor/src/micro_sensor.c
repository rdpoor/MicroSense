/*
 * \file micro_sensor.c
 *
 * Author: R. D. Poor <rdpoor@gmail.com>
 */

#include "micro_sensor.h"
#include "atmel_start_pins.h"
#include "delay.h"
#include "pwm.h"
#include <atmel_start.h>
#include <stdbool.h>
#include <stdio.h>

//=============================================================================
// definitions

// If true, run in single ended mode
// #define SINGLE_ENDED

// Define symbolic gain names.  By setting the name equal to the actual gain,
// we can print the value directly in the CSV string.
typedef enum {
  GAIN_AUTO = 0,
  GAIN_LOW = 1,
  GAIN_MEDIUM = 4,
  GAIN_HIGH = 16,
} gain_t;

#define SAMPLES_PER_FRAME 15

#ifdef SINGLE_ENDED
#define MAX_ADC_COUNT ((uint32_t)4096)
#else
#define MAX_ADC_COUNT ((uint32_t)2048)
#endif

#define FRAME_COUNT_MIN ((int32_t)0) // min frame value
#define FRAME_COUNT_MAX ((int32_t)(SAMPLES_PER_FRAME * (MAX_ADC_COUNT - 1)))
#define FRAME_COUNT_SPAN ((int32_t)(FRAME_COUNT_MAX - FRAME_COUNT_MIN))

/**
 * AUTORANGING:
 *
 * Available gains are 1, 4, 16 (subject to change).  Expected count is
 * 0 ... 2048.  If the read value is less than 2048/4 (=512), then we _could_
 * switch to higher gain, but to allow for hysteresis, we don't switch until
 * it's less than half of that (= 256).  Similarly, if the read value higher
 * than (2048-256) = 1792, then we lower the gain if possible.
 */
#define GAIN_UP_THRESH (MAX_ADC_COUNT / 8)
#define GAIN_DN_THRESH (MAX_ADC_COUNT - GAIN_UP_THRESH)

//=============================================================================
// forward declarations

/**
 * @brief Called after 15 samples have been accumulated.
 */
static void on_frame_complete(void);

/**
 * @brief Read SDA/SCL data lines to set the request LOW, MED, HIGH AUTO gain
 */
static gain_t read_gain_switches(void); // read SDA:SCL

/**
 * @brief Return true if the gain switches are set to AUTO
 */
static bool is_autoranging(void);

/**
 * @brief Compute new gain based on current gain and sample count.
 */
static gain_t autorange(int16_t count, gain_t gain);

/**
 * @brief Set the ADC gain (but only if it has changed).
 */
static void set_gain(gain_t gain);

/**
 * @brief Initiate an ADC reading.  Will interrupt when reading is complete.
 */
static void start_adc_reading(void);

/**
 * @brief Read the low-level ADC count.
 */
static int16_t read_adc_count(void);

/**
 * @brief Reset the integrator.
 */
static void reset_integrator(void);

/**
 * @brief Set the PWM duty cycle.
 */
static void update_pwm(int16_t frame_count);

/**
 * @brief map x value using linear intepolation.
 */
static float lerp(float x, float x0, float x1, float y0, float y1);

//=============================================================================
// private storage

static uint8_t s_sample_count; // counts from 0 to SAMPLES_PER_FRAME
static int32_t s_v0_total;
static int32_t s_v1_total;
static int32_t s_dv_total;

static gain_t s_gain;

static volatile bool s_has_frame;
static volatile int32_t s_v0_fg;
static volatile int32_t s_v1_fg;
static volatile int32_t s_dv_fg;
static volatile gain_t s_gain_fg;

static bool s_is_reading_v0; // true when reading v0
static int16_t s_v0;         // captured v0

//=============================================================================
// public code

// [foreground] called once at initialization
void micro_sensor_init(void) {
#ifdef SINGLE_ENDED
  ADCA.CH0.CTRL = ADC_CH_GAIN_1X_gc                  /* 1x gain */
                  | ADC_CH_INPUTMODE_SINGLEENDED_gc; /* Single-ended, no gain */
  ADCA.CTRLB = ADC_CURRLIMIT_NO_gc                   /* No limit */
               | 0 << ADC_CONMODE_bp                 /* Unsigned Mode */
               | 0 << ADC_FREERUN_bp /* Free Running Mode Enable: disabled */
               | ADC_RESOLUTION_12BIT_gc; /* 12-bit right-adjusted result */
#else
  ADCA.CH0.CTRL = ADC_CH_GAIN_1X_gc           /* 1x gain */
                  | ADC_CH_INPUTMODE_DIFF_gc; /* Differential input, no gain */
  ADCA.CTRLB = ADC_CURRLIMIT_NO_gc            /* No limit */
               | 1 << ADC_CONMODE_bp          /* Signed Mode: enabled */
               | 0 << ADC_FREERUN_bp /* Free Running Mode Enable: disabled */
               | ADC_RESOLUTION_12BIT_gc; /* 12-bit right-adjusted result */
#endif

  delay_ms(50);

  s_sample_count = 0;
  s_v0_total = 0;
  s_v1_total = 0;
  s_dv_total = 0;

  s_gain = GAIN_AUTO; // force initial write in set_gain()

  s_has_frame = false;
  s_is_reading_v0 = false;
  s_v0 = 0;

  gain_t target_gain = read_gain_switches();

  if (target_gain == GAIN_AUTO) {
    // If autoranging, assume medium gain to start with.
    set_gain(GAIN_MEDIUM);
  } else {
    set_gain(target_gain);
  }
  pwm_set_ratio(0.5); // mid range
  reset_integrator();
}

// [foreground] called repeatedly in foreground
void micro_sensor_step(void) {
  if (s_has_frame) {
    printf("%s, %d, %ld, %ld, %ld\r\n",
           is_autoranging() ? "A" : "M",
           s_gain_fg,
           s_dv_fg,
           s_v0_fg,
           s_v1_fg);
    s_has_frame = false;
  }
}

// [interrupt] Called on completion of ADC conversion
void micro_sensor_adc_complete_cb(void) {
  int16_t count = read_adc_count();

  if (s_is_reading_v0) {
    // Here, capture the first ADC reading after resetting the integrator
    s_v0 = count;
    s_is_reading_v0 = false;
    return;
  }

  // Here, capture the second ADC reading after VSync goes true
  int16_t v1 = count;
  int16_t dv;

  dv = v1 - s_v0;

  reset_integrator();

  s_is_reading_v0 = true;
  start_adc_reading(); // initiate a read for s_v0

  s_v0_total += s_v0;
  s_v1_total += v1;
  s_dv_total += dv;
  s_sample_count += 1;

  if (s_sample_count >= SAMPLES_PER_FRAME) {
    on_frame_complete();
    s_sample_count = 0;
  }
}

//=============================================================================
// local code

static void on_frame_complete(void) {
  // Here once every 250 mSec (after 15 frames): update PWM and transfer
  // computed variables to safe locations for the foreground.
  STATUS_LED_toggle_level();
  update_pwm(s_dv_total);
  s_v0_fg = s_v0_total;
  s_v1_fg = s_v1_total;
  s_dv_fg = s_dv_total;
  s_gain_fg = s_gain;
  s_has_frame = true;

  gain_t target_gain = read_gain_switches();
  if (target_gain == GAIN_AUTO) {
    target_gain = autorange(s_dv_total, s_gain);
  }
  set_gain(target_gain);

  s_v0_total = 0;
  s_v1_total = 0;
  s_dv_total = 0;
}

static gain_t read_gain_switches() {
  bool msb = SDA_get_level();
  bool lsb = SCL_get_level();

  // SDA SCL gain
  // 0   0   GAIN_LOW
  // 0   1   GAIN_MEDIUM
  // 1   0   GAIN_HIGH
  // 1   1   GAIN_AUTO
  if (msb) {
    if (lsb) {
      return GAIN_AUTO;
    } else {
      return GAIN_HIGH;
    }
  } else {
    if (lsb) {
      return GAIN_MEDIUM;
    } else {
      return GAIN_LOW;
    }
  }
}

static bool is_autoranging(void) { return read_gain_switches() == GAIN_AUTO; }

static gain_t autorange(int16_t count, gain_t gain) {
  if (count > GAIN_DN_THRESH * SAMPLES_PER_FRAME) {
    // count is too high -- reduce gain if possible.
    if (gain == GAIN_HIGH) {
      return GAIN_MEDIUM;
    } else {
      return GAIN_LOW;
    }
  } else if (count < GAIN_UP_THRESH * SAMPLES_PER_FRAME) {
    // count is too low -- increase gain if possible...
    if (gain == GAIN_LOW) {
      return GAIN_MEDIUM;
    } else {
      return GAIN_HIGH;
    }
  } else {
    // stay the course
    return gain;
  }
}

/**
 * @brief Set GAIN_A1 and GAIN_A0 lines to control the sensitivity of the analog
 * system.
 */
static void set_gain(gain_t gain) {
#ifdef SINGLE_ENDED
  (void)gain;
  ADCA.CH0.CTRL = ADC_CH_GAIN_1X_gc | ADC_CH_INPUTMODE_SINGLEENDED_gc;
#else
  if (gain != s_gain) {
    switch (gain) {
    case GAIN_LOW:
      // set gain = 1x
      ADCA.CH0.CTRL = ADC_CH_GAIN_1X_gc | ADC_CH_INPUTMODE_DIFF_gc;
      ADCA.CH0.MUXCTRL = ADC_CH_MUXPOS_PIN0_gc | ADC_CH_MUXNEG_PIN2_gc;
      break;
    case GAIN_MEDIUM:
      // set gain = 4x
      ADCA.CH0.CTRL = ADC_CH_GAIN_4X_gc | ADC_CH_INPUTMODE_DIFFWGAIN_gc;
      ADCA.CH0.MUXCTRL = ADC_CH_MUXPOS_PIN0_gc | ADC_CH_MUXNEG_PIN4_gc;
      break;
    case GAIN_HIGH:
      // set gain = 16x
      ADCA.CH0.CTRL = ADC_CH_GAIN_16X_gc | ADC_CH_INPUTMODE_DIFFWGAIN_gc;
      ADCA.CH0.MUXCTRL = ADC_CH_MUXPOS_PIN0_gc | ADC_CH_MUXNEG_PIN4_gc;
      break;
    default:
      break;
      // unknown: should not get here.  do nothing.
    }
    s_gain = gain;
  }
#endif
}

static void start_adc_reading(void) {
  // Initiate an ADC reading
  ADCA.CTRLA = 1 << ADC_CH0START_bp // Start conversion
               | 0 << ADC_FLUSH_bp  // Flush Pipeline: disabled
               | 1 << ADC_ENABLE_bp // Enable ADC: enabled
      ;
}

// Fetch the raw 12 bit sample from the A/D
static int16_t read_adc_count(void) {
  int16_t count = ADCA.CH0RES;
  return count;
}

static void reset_integrator() {
  RESET_A_set_level(true);
  delay_us(200); // hold time
  RESET_A_set_level(false);
  delay_us(200); // settling time
}

static void update_pwm(int16_t frame_count) {
  // ratio goes 0.0...1.0 as adc count goes FRAME_COUNT_MIN...FRAME_COUNT_MAX
  float ratio = lerp(frame_count, FRAME_COUNT_MIN, FRAME_COUNT_MAX, 0.0, 1.0);
  pwm_set_ratio(ratio);
}

static float lerp(float x, float x0, float x1, float y0, float y1) {
  float ret = y0 + (x - x0) * (y1 - y0) / (x1 - x0);
  return ret;
}
