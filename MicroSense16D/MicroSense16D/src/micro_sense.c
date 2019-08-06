/*
 * micro_sense.c
 *
 * Created: 5/3/2019 7:04:59 AM
 *  Author: Robert Poor <rdpoor@gmail.com>
 */

#include <atmel_start.h>

#include <stdbool.h>
#include <stdio.h>
#include "atmel_start_pins.h"
#include "delay.h"
#include "micro_sense.h"
#include "profiling.h"
#include "pwm.h"

//=============================================================================
// definitions

// time to wait before asserting integrator reset
#define INTEGRATOR_HOLDOFF_US 1
// time to hold integrator reset asserted
#define INTEGRATOR_ASSERT_US 1

#define ADC_COUNT_TO_RATIO(count) ((float)(count)/(float)(1<<12))
#define SAMPLES_PER_FRAME 15

//=============================================================================
// forward declarations

static uint16_t get_conversion_result(void);

// called upon completion of ADC conversion
static void process_sample(void);

// called after 15 samples processed
static void process_frame(float average);

// momentarily drop A to reset integrator
static void reset_integrator(void);

static void emit_csv(float average);

static void led_on();

static void led_off();

//=============================================================================
// private storage

volatile static uint16_t s_sample_count;
volatile static float s_total;
volatile static float s_result;
volatile static bool s_has_result;

//=============================================================================
// "public" code

// called once at initialization
void micro_sense_init(void) {
    s_sample_count = 0;
    s_total = 0.0;
    s_result = 0.0;
    s_has_result = false;

    reset_integrator();
}

// called repeatedly in foreground
void micro_sense_step(void) {
    if (s_has_result) {
        printf("%e\r\n", s_result);
        s_has_result = false;
    }
    asm("nop");
}

// Called on completion of ADC conversion
void micro_sense_adc_complete_cb(void) {
  led_on();
  process_sample();
  led_off();
}

// Called whenever the SYNC input transitions low to high
void micro_sense_sync_cb(void) {
  reset_integrator();
}

//=============================================================================
// "private" code

static uint16_t get_conversion_result(void) {
	return (ADCA.CH0RES);
}

static void reset_integrator() {
  delay_us(INTEGRATOR_HOLDOFF_US);
  A_set_level(false);
  delay_us(INTEGRATOR_ASSERT_US);
  A_set_level(true);
}

// Arrive here at interrupt level upon completion of ADC conversion
static void process_sample(void) {
  float ratio = ADC_COUNT_TO_RATIO(get_conversion_result());

  // PWM tracks A/D
  pwm_set_ratio(ratio);

  // Call process_frame() after SAMPLES_PER_FRAME samples
  s_sample_count += 1;
  if (s_sample_count >= SAMPLES_PER_FRAME) {
    s_sample_count = 0;
    process_frame(s_total / SAMPLES_PER_FRAME);
    s_total = 0;
  }
}

// Arrive here at interrupt level after SAMPLES_PER_FRAME have been processed
static void process_frame(float average) {
  PROFILING_SET(PROCESSING_FRAME);
  emit_csv(average);
  PROFILING_CLR(PROCESSING_FRAME);
}

static void emit_csv(float average) {
  s_result = average;
  s_has_result = true;
}

static void led_on() {
  STATUS_LED_set_level(true);
}

static void led_off() {
  STATUS_LED_set_level(false);
}
