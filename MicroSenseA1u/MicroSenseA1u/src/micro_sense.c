/*
 * micro_sense.c
 *
 * Created: 5/3/2019 7:04:59 AM
 *  Author: Robert Poor <rdpoor@gmail.com>
 */

#include <stdbool.h>
#include <stdio.h>
#include "adc_basic.h"
#include "atmel_start_pins.h"
#include "micro_sense.h"
#include "pwm.h"

//=============================================================================
// definitions

#define ADC_COUNT_TO_RATIO(count) ((float)(count)/(float)(1<<12))
#define SAMPLES_PER_FRAME 250
#define RATIO_THRESHOLD_HI 0.8
#define RATIO_THRESHOLD_LO 0.2

typedef enum {
  SCALE_0 = 0,
  SCALE_1,
  SCALE_2,
  SCALE_3
} scale_t;

#define GAIN_0 1.0
#define GAIN_1 2.0
#define GAIN_2 4.0
#define GAIN_3 8.0

//=============================================================================
// forward declarations

// called upon completion of ADC conversion (once every mSec)
static void process_sample(void);

// called after 250 samples (once every 250 mSec)
static void process_frame(float average);

// set COMP_OUT and s_polarity
static void set_polarity(bool polarity);

// set MUXA[0:1] and s_gain
static void set_scale(scale_t scale);

static void emit_csv(float average);

//=============================================================================
// private storage

volatile static uint16_t s_sample_count;
volatile static float s_prev_ratio;
volatile static scale_t s_scale;
volatile static bool s_polarity;
volatile static float s_gain;
volatile static float s_total;
volatile static float s_result;
volatile static bool s_has_result;

//=============================================================================
// "public" code

// called once at initialization
void micro_sense_init(void) {
  s_sample_count = 0;
  s_prev_ratio = 0.0;
  set_polarity(true);
  set_scale(SCALE_0);
  s_total = 0.0;
  s_result = 0.0;
  s_has_result = false;

  ADC_0_register_callback(process_sample);
  ADC_0_enable();
}

// called repeatedly in foreground
void micro_sense_step(void) {
    if (s_has_result) {
        printf("%d (x 1000)\r\n", (int)(s_result * 1000));
        s_has_result = false;
    }
    asm("nop");
}

//=============================================================================
// "private" code

// Arrive here at interrupt level upon completion of ADC conversion (once every
// mSec)
static void process_sample(void) {
  CONVERTING_SAMPLE_set_level(false);
  uint16_t count = ADC_0_get_conversion_result();
  float ratio = ADC_COUNT_TO_RATIO(count);
  float d_ratio;

  // PWM tracks A/D
  pwm_set_ratio(ratio);

  if (s_polarity) {
    d_ratio = ratio - s_prev_ratio;
  } else {
    d_ratio = s_prev_ratio - ratio;
  }
  s_prev_ratio = ratio;
  s_total += d_ratio;

  // Call process_frame() after SAMPLES_PER_FRAME samples
  s_sample_count += 1;
  if (s_sample_count >= SAMPLES_PER_FRAME) {
    s_sample_count = 0;
    process_frame(s_total / SAMPLES_PER_FRAME);
    s_total = 0;
  }

  // flip polarity if needed
  if (ratio > RATIO_THRESHOLD_HI) {
    set_polarity(false);
  } else if (ratio < RATIO_THRESHOLD_LO) {
    set_polarity(true);
  }
}

// Arrive here at interrupt level after SAMPLES_PER_FRAME have been processed
static void process_frame(float average) {
  STATUS_LED_toggle_level();
  // PROCESSING_FRAME_set_level(true);
  emit_csv(average);
  // PROCESSING_FRAME_set_level(false);
}

// set COMP_OUT and s_polarity
static void set_polarity(bool polarity) {
  s_polarity = polarity;
  POLARITY_set_level(polarity);
}

// set MUXA[0:1] and s_gain
static void set_scale(scale_t scale) {
  scale = SCALE_0;   // for testing
  MUXA0_set_level(scale & 0x01);
  MUXA1_set_level(scale & 0x02);
  switch(scale) {
    case SCALE_0:
    s_gain = GAIN_0;
    break;
    case SCALE_1:
    s_gain = GAIN_1;
    break;
    case SCALE_2:
    s_gain = GAIN_2;
    break;
    case SCALE_3:
    s_gain = GAIN_3;
    break;
  }
}

static void emit_csv(float average) {
  s_result = average;
  s_has_result = true;
}
