/*
 * micro_sense.c
 *
 * Author: Robert Poor <rdpoor@gmail.com>
 */

/**

## Overview:

After initialization, almost all processing happens at interrupt level.

A 60Hz rectangular wave drives SYNC_IN.  On a positive going edge of SYNC_IN:

- SYNC_IN rising edge triggers an ADC read operation via the Event system.

Completion of the ADC read conversion generates an interrupt.  In the ISR:

- if this is the first of two readings, capture "v0" from the ADC.
- if this is the second of two readings:
-- capture "v1" from the ADC.
-- pulse the RESET_A GPIO line to reset the current integrator
-- add v0 to v0_total
-- add v1 to v1_total

After 15 conversions (250 mSec) still in the ISR:

- take the average of the accumulated ADC counts
- output sample frame as CSV
- perform autorange adjustments

## Autoranging

The system can set MUX0 and MUX1 to set the analog sensitivity to three levels
for LOW_, MED_, or HIGH_SENSITIVITY.  The update_autoranging() function adjusts
the sensitivity based on the most recent sample frame.

When the averaged ADC count exceeds ADC_THRESH_HI (and if the sensitivity is
not already set to the minimum), the sensitivity is decreased by one unit.
When the averaged ADC count drops below ADC_THRESH_LO (and if the sensitivity
is not yet maximum), then the sensitivity is increased by one unit.

## I/O PIN ASSIGNMENTS:

(NOTE: this list is outdated)

PA0: VOUT0 (input) feeds ADC+
PA1: VOUT1 (input) feeds Comparator+, generates interrupt to start conversion
PA2: VREF (input) feeds Comparator-
PA3: SYNC_IN (input) generates interrupt to end conversion
PA4: B (output) for resetting integrator.
PA5: A (output) for resetting integrator.
PA6: NC
PA7: NC

PB0: MUXA0 (out)
PB1: MUXA1 (out)
PB2: NC
PB3: NC

PC0: NC
PC1: NC
PC2: RXD
PC3: TXD
PC4: NC
PC5: NC
PC6: NC
PC7: NC

PD0: PWM (out)
PD1: NC
PD2: IRDA RXD
PD3: IRDA TXD
PD4: IRDA SDD
PD5: NC
PD6: NC
PD7: LED (output)

PE0: SDA
PE1: SCL
PE2: NC
PE3: NC

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

#undef USE_AUTORANGING

typedef enum {
  LOW_SENSITIVITY = 0,
  MID_SENSITIVITY = 1,
  HIGH_SENSITIVITY = 2
} sensitivity_t;

#define SAMPLES_PER_FRAME 15

#define ADC_COUNT_MIN ((int32_t)0)     // the minimum frame value
#define ADC_COUNT_MAX ((int32_t)17500) // the maximum frame value
#define ADC_COUNT_SPAN ((int32_t)(ADC_COUNT_MAX - ADC_COUNT_MIN))

// Set autoranging thresholds at 1/8th from each end of full scale
// #define COUNT_THRESHOLD_HI (int32_t)(ADC_COUNT_MAX - (ADC_COUNT_SPAN >> 3))
#define COUNT_THRESHOLD_HI 15000
// #define COUNT_THRESHOLD_LO (int32_t)(ADC_COUNT_MIN + (ADC_COUNT_SPAN >> 3))
#define COUNT_THRESHOLD_LO 2000

//=============================================================================
// forward declarations

static int16_t read_adc_count(void);
static void led_on();
static void led_off();
static void reset_integrator();
static void update_pwm(uint16_t adc_count);
static sensitivity_t update_autoranging(uint16_t count,
                                        sensitivity_t sensitivity);
static sensitivity_t get_desired_sensitivity(void);
static void set_sensitivity(sensitivity_t sensitivity);
static float lerp(float x, float x0, float x1, float y0, float y1);
static void start_adc_reading(void);

//=============================================================================
// private storage

static uint8_t s_sample_count; // counts from 0 to SAMPLES_PER_FRAME
static int32_t s_v0_total;
static int32_t s_v1_total;
static int32_t s_dv_total;
static sensitivity_t s_sensitivity; // LOW, MID, HIGH for autoranging

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
  delay_ms(5);

  set_sensitivity(MID_SENSITIVITY);
  pwm_set_ratio(0.5); // mid range
  reset_integrator();
}

// [foreground] called repeatedly in foreground
void micro_sense_step(void) {
  if (s_has_frame) {
    GAIN_A1_set_level(SDA_get_level());
    GAIN_A0_set_level(SCL_get_level());

    uint8_t switches = (SDA_get_level() ? 2 : 0) + (SCL_get_level() ? 1 : 0);
    printf("%d, %ld, %ld, %ld, %d\r\n",
           s_sensitivity_fg,
           s_v0_fg,
           s_v1_fg,
           s_dv_fg,
           get_desired_sensitivity());
    s_has_frame = false;
  }
}

// [interrupt] Called on completion of ADC conversion
void micro_sense_adc_complete_cb(void) {
  int16_t count = read_adc_count();

  if (s_is_reading_v0) {
    s_is_reading_v0 = false;
    s_v0 = count;
    return;
  }
  int16_t v1 = count;
  int16_t dv;

  dv = v1 - s_v0;

  s_is_reading_v0 = true;
  led_on();
  reset_integrator();
  delay_us(50);
  start_adc_reading(); // start a read for s_v_bottom

  s_v0_total += s_v0;
  s_v1_total += v1;
  s_dv_total += dv;
  s_sample_count += 1;

  if (s_sample_count >= SAMPLES_PER_FRAME) {
    update_pwm(s_dv_total);
    // report to foreground
    s_v0_fg = s_v0_total;
    s_v1_fg = s_v1_total;
    s_dv_fg = s_dv_total;
    s_sensitivity_fg = s_sensitivity;
    s_has_frame = true;

    s_sensitivity = update_autoranging(s_dv_total, s_sensitivity);
    // At this point, s_sensitivity represents what the system would choose if
    // autoranging is enabled.
    set_sensitivity(get_desired_sensitivity());
    s_v0_total = 0;
    s_v1_total = 0;
    s_dv_total = 0;
    s_sample_count = 0;
  }
  led_off();
}

//=============================================================================
// local code

// Fetch the raw 12 bit sample from the A/D
static int16_t read_adc_count(void) {
  int16_t count = ADCA.CH0RES;
  return count;
}

static void led_on() { STATUS_LED_set_level(true); }

static void led_off() { STATUS_LED_set_level(false); }

static void reset_integrator() {
  RESET_A_set_level(true);
  delay_us(200);
  RESET_A_set_level(false);
}

static void update_pwm(uint16_t adc_count) {
  float ratio = lerp(adc_count, ADC_COUNT_MIN, ADC_COUNT_MAX, 0.0, 1.0);
  pwm_set_ratio(ratio);
}

static sensitivity_t update_autoranging(uint16_t count,
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

static sensitivity_t get_desired_sensitivity(void) {
#ifdef USE_AUTORANGING
  return s_sensitivity;
#else
  // SDA(A1) SCL(A0) sensitivity
  // 0       0       LO  (0)
  // 0       1       MID (1)
  // 1       0       HI  (2)
  // 1       1       undef
  return (SDA_get_level() ? 2 : 0) + (SCL_get - level() ? 1 : 0);
#endif
}

/**
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
  }
rich }

static float lerp(float x, float x0, float x1, float y0, float y1) {
  return y0 + (x - x0) * (y1 - y0) / (x1 - x0);
}

static void start_adc_reading(void) {
  // Initiate an ADC reading
  ADCA.CTRLA = 1 << ADC_CH0START_bp // Start conversion
               | 0 << ADC_FLUSH_bp  // Flush Pipeline: disabled
               | 1 << ADC_ENABLE_bp // Enable ADC: enabled
      ;
}
