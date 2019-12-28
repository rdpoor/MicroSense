/*
 * micro_sense.c
 *
 * Created: 5/3/2019 7:04:59 AM
 *  Author: Robert Poor <rdpoor@gmail.com>
 */

/**
I/O PIN ASSIGNMENTS:

PA0: VOUT0 (input) feeds ADC+
PA1: VOUT1 (input) feeds Comparator+, generates interrupt to start conversion
PA2: VREF (input) feeds Comparator-
PA3: SYNC_IN (input) generates interrupt to end conversion
PA4: NC
PA5: NC
PA6: B (output) for resetting integrator.
PA7: A (output) for resetting integrator.

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

FUNCTIONAL REQUIREMENTS:

When VOUT1 exceeds VREF, start ADC conversion.
Upon Conversion complete:
  Record sample (S0)
When SYNC_IN goes false, start ADC conversion.
Upon conversion complete:
  Record sample as S1
  If S1 not fully saturated, save (S1-S0)
  If S1 is fully saturated, decrease MUXA0:1
  If S1 < ??, increase MUXA0:1
Reset Integrator:
  - assert A, assert B
  - wait 1.25 uSec
  - de-assert A
  - wait 1.25 uSec
  - de-assert B
Loop

IMPLEMENTATION:

At the start of a cycle, Vout0 (same as Vout1) starts to ramp up.

When Vout1 exceeds Vref, the comparator generates an event on channel 0 (set up
in ATMEL START).

Event 0 initiates an ADC conversion.

[Optional: Event 0 resets TC0. Assign to t0.]

When the ADC completes conversion, it generates an interrupt.

In the interrupt, the ADC value is stored as S0 and `has_s0` is set true.

When SYNC_IN goes true, its GPIO generates an event on channel 1 (set up in
Atmel START).

Event 1 initiates another ADC conversion.

[Optional: Event 1 captures TC0.  Assign to t1.]

When the ADC completes conversion, it generates an interrupt.

In the interrupt:
- the integrator is reset (described above)
- if the value is NOT saturated, it is stored as S1 and "has_s1" is set true
- if the value IS saturated, it is ignored

The cycle repeats.

AT FOREGROUND LEVEL:

If `has_s1` is true: dv/dt = (S1-S0) / k
[Optinal: dv/dt = (S1-S0)/(TC1-TC0)]
Set `has_s1` to false.
Wiggle a GPIO pin to show that the foreground has processed the sample.

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

// A and B are responsible for resetting the integrator
#define A_PIN_MASK (1<<7)  // PA7
#define B_PIN_MASK (1<<6)  // PA6
#define A_RESET_HOLD_CYCLES (3)
#define B_RESET_HOLD_CYCLES (6)

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
    // each time through the loop, make MUX0 and MUX1 track SDA and SCL
    MUX_A0_set_level(SDA_get_level());
    MUX_A1_set_level(SCL_get_level());

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

/**
 * To reset integrator:
 * - assert A and B
 * - wait 1.5 uSec
 * - deassert A
 * - wait 1.5 uSec
 * - deassert B
 */
static void reset_integrator() {
  // Assert A and B simultaneously
  PORTA_set_port_level(A_PIN_MASK | B_PIN_MASK, true);
  delay_cycles(A_RESET_HOLD_CYCLES);
  A_set_level(false);
  delay_cycles(B_RESET_HOLD_CYCLES - A_RESET_HOLD_CYCLES);
  B_set_level(false);
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
