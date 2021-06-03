/*
 * micro_sense.c
 *
 * Author: Robert Poor <rdpoor@gmail.com>
 */

#include "micro_sense.h"
#include "atmel_start_pins.h"
#include "delay.h"
#include "profiling.h"
#include "pwm.h"
#include <atmel_start.h>
#include <stdbool.h>
#include <stdio.h>

//=============================================================================
// definitions

typedef enum {
  LOW_SENSITIVITY = 0,
  MID_SENSITIVITY = 1,
  HIGH_SENSITIVITY = 2,
  UNKNOWN_SENSITIVITY = 3
} sensitivity_t;

#define SAMPLES_PER_FRAME 15

#define ADC_COUNT_MIN ((int32_t)0)     // the minimum frame value
#define ADC_COUNT_MAX ((int32_t)17500) // the maximum frame value
#define ADC_COUNT_SPAN ((int32_t)(ADC_COUNT_MAX - ADC_COUNT_MIN))

// Set autoranging thresholds at 1/8th from each end of full scale
// #define COUNT_THRESHOLD_HI (int32_t)(ADC_COUNT_MAX - (ADC_COUNT_SPAN >> 3))
#define COUNT_THRESHOLD_HI 20000
// #define COUNT_THRESHOLD_LO (int32_t)(ADC_COUNT_MIN + (ADC_COUNT_SPAN >> 3))
//#define COUNT_THRESHOLD_LO 2000
#define COUNT_THRESHOLD_LO 1800
//=============================================================================
// forward declarations

static sensitivity_t read_sensitivity_switches(); // read SDA:SCL
static void write_sensitivity_switches(sensitivity_t sensitivity);

static int16_t read_adc_count(void);
static void reset_integrator();
static void update_pwm(int16_t adc_count);
static sensitivity_t update_sensitivity(int16_t count,
                                        sensitivity_t sensitivity);
static void set_sensitivity(sensitivity_t sensitivity);
static float lerp(float x, float x0, float x1, float y0, float y1);
static void start_adc_reading(void);

//=============================================================================
// private storage

// True if autoranging in effect, false if SDA:SCL set the gain.
static bool s_is_autoranging;

static uint8_t s_sample_count; // counts from 0 to SAMPLES_PER_FRAME
static int32_t s_v0_total;
static int32_t s_v1_total;
static int32_t s_dv_total;
static sensitivity_t s_sensitivity;

static volatile bool s_has_frame;
static volatile int32_t s_v0_fg;
static volatile int32_t s_v1_fg;
static volatile int32_t s_dv_fg;
static volatile sensitivity_t s_sensitivity_fg;

static bool s_is_reading_v0; // true when reading v0
static int16_t s_v0;         // captured v0

//=============================================================================
// public code

// [foreground] called once at initialization
void micro_sense_init(void) {
  delay_ms(50);

  sensitivity_t initial_sensitivity = read_sensitivity_switches();
  if (initial_sensitivity == UNKNOWN_SENSITIVITY) {
    // If both SDA and SCL are open, pullups will make them both read as 1
    // which we use to set autoranging mode.  Set SDA and SCL as outputs.
    s_is_autoranging = true;
    set_sensitivity(MID_SENSITIVITY);
	SDA_set_dir(PORT_DIR_OUT);
	SCL_set_dir(PORT_DIR_OUT);
  } else {
    // If either SDA or SCL are pulled low, assume we want to set sensitivity
    // manually
    s_is_autoranging = false;
    set_sensitivity(initial_sensitivity);
  }

  pwm_set_ratio(0.5); // mid range
  reset_integrator();
}

// [foreground] called repeatedly in foreground
void micro_sense_step(void) {
  if (s_has_frame) {
    printf("%s, %d, %ld, %ld, %ld\r\n",
           s_is_autoranging ? "A" : "M",
           s_sensitivity,
           s_dv_fg,
		   s_v0_fg,
		   s_v1_fg);
    s_has_frame = false;
  }
}

// [interrupt] Called on completion of ADC conversion
void micro_sense_adc_complete_cb(void) {
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
  delay_us(200); //integrator recovery delay

  s_is_reading_v0 = true;
  start_adc_reading(); // initiate a read for s_v0

  s_v0_total += s_v0;
  s_v1_total += v1;
  s_dv_total += dv;
  s_sample_count += 1;

  if (s_sample_count >= SAMPLES_PER_FRAME) {
    // Here once every 250 mSec (after 15 frames): update PWM and transfer
    // computed variables to safe locations for the foreground.
    STATUS_LED_toggle_level();
    update_pwm(s_dv_total);
    s_v0_fg = s_v0_total;
    s_v1_fg = s_v1_total;
    s_dv_fg = s_dv_total;
    s_sensitivity_fg = s_sensitivity;
    s_has_frame = true;

    if (s_is_autoranging) {
      s_sensitivity = update_sensitivity(s_dv_total, s_sensitivity);
	  write_sensitivity_switches(s_sensitivity);
    } else {
      s_sensitivity = read_sensitivity_switches();
    }
    set_sensitivity(s_sensitivity);

    s_v0_total = 0;
    s_v1_total = 0;
    s_dv_total = 0;
    s_sample_count = 0;
  }
}

//=============================================================================
// local code

static sensitivity_t read_sensitivity_switches() {
  // SDA(A1) SCL(A0) sensitivity
  // 0       0       LO  (0)
  // 0       1       MID (1)
  // 1       0       HI  (2)
  // 1       1       undef
  return (SDA_get_level() ? 2 : 0) + (SCL_get_level() ? 1 : 0);
}

static void write_sensitivity_switches(sensitivity_t sensitivity) {
  switch (sensitivity) {
  case LOW_SENSITIVITY:
    SDA_set_level(false);
	SCL_set_level(false);
    break;
  case MID_SENSITIVITY:
    SDA_set_level(false);
    SCL_set_level(true);
    break;
  case HIGH_SENSITIVITY:
    SDA_set_level(true);
    SCL_set_level(false);
    break;
  default:
    break;
    // unknown: should not get here.  do nothing.
  }
}

// Fetch the raw 12 bit sample from the A/D
static int16_t read_adc_count(void) {
  int16_t count = ADCA.CH0RES;
  return count;
}

static void reset_integrator() {
  RESET_A_set_level(true);
  delay_us(200);
  RESET_A_set_level(false);
}

static void update_pwm(int16_t adc_count) {
  // ratio goes 0.0...1.0 as adc count goes ADC_COUNT_MIN...ADC_COUNT_MAX
  float ratio = lerp(adc_count, ADC_COUNT_MIN, ADC_COUNT_MAX, 0.0, 1.0);
  pwm_set_ratio(ratio);
}

static sensitivity_t update_sensitivity(int16_t count,
                                        sensitivity_t sensitivity) {
  if (count > COUNT_THRESHOLD_HI) {
    // reduce sensitivity if possible...
    if (sensitivity == HIGH_SENSITIVITY) {
      return MID_SENSITIVITY;
    } else {
      return LOW_SENSITIVITY;
    }
  } else if (count < COUNT_THRESHOLD_LO) {
    // increase sensitivity if possible...
    if (sensitivity == LOW_SENSITIVITY) {
      return MID_SENSITIVITY;
    } else {
      return HIGH_SENSITIVITY;
    }
  } else {
    // stay the course
    return sensitivity;
  }
}

/**
 * @brief Set GAIN_A1 and GAIN_A0 lines to control the sensitivity of the analog
 * system.
 */
static void set_sensitivity(sensitivity_t sensitivity) {
  switch (sensitivity) {
  case LOW_SENSITIVITY:
    GAIN_A1_set_level(false);
    GAIN_A0_set_level(false);
    break;
  case MID_SENSITIVITY:
    GAIN_A1_set_level(false);
    GAIN_A0_set_level(true);
    break;
  case HIGH_SENSITIVITY:
    GAIN_A1_set_level(true);
    GAIN_A0_set_level(false);
    break;
  default:
    break;
    // unknown: should not get here.  do nothing.
  }
}

static float lerp(float x, float x0, float x1, float y0, float y1) {
  float ret = y0 + (x - x0) * (y1 - y0) / (x1 - x0);
  return ret;
}

static void start_adc_reading(void) {
  // Initiate an ADC reading
  ADCA.CTRLA = 1 << ADC_CH0START_bp // Start conversion
               | 0 << ADC_FLUSH_bp  // Flush Pipeline: disabled
               | 1 << ADC_ENABLE_bp // Enable ADC: enabled
      ;
}
