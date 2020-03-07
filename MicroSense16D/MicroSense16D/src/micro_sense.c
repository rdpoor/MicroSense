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

FUNCTIONAL REQUIREMENTS:

When VOUT1 exceeds VREF, start ADC conversion.
  [Optional: Record T0]
Upon Conversion complete:
  Record sample (S0)
When SYNC_IN goes false, start ADC conversion.
  [Optional: Record T1]
Upon conversion complete:
  Record sample as S1
  If S1 not fully saturated, save (S1-S0)
  [Optional: save T1-T0]
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

At the start of a cycle, Vout0 (same as Vout1) starts to ramp up.  Or not.

At such time that Vout1 exceeds Vref, the comparator generates an Event on
channel 0 (set up in ATMEL START).

Event 0 initiates an ADC conversion.

[Optional: Event 0 resets TC0. Assign to t0.]

When the ADC completes conversion, it generates an interrupt.

In the interrupt, the ADC value is stored as v0 and `has_v0` is set true.

When SYNC_IN goes true, its GPIO generates an Event on channel 1 (set up in
Atmel START).

Event 1 initiates another ADC conversion.

[Optional: Event 1 captures TC0.  Assign to t1.]

When the ADC completes conversion, it generates an interrupt (again).

In the interrupt:
- the integrator is reset (described above)
- if the value is NOT saturated, it is stored as S1 and "has_s1" is set true
- if the value IS saturated, it is ignored
[NOTE: handling saturated values is not yet implemented.]
- if 15 samples have been processed, set has_dv true
The cycle repeats.

AT FOREGROUND LEVEL:

If `has_dv` is true: dv/dt = average_dv / k
[Optional: dv/dt = (S1-S0)/(TC1-TC0)]
Set `has_dv` to false.
For debugging, wiggle a GPIO pin to show that the foreground has processed the
  sample.

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
#define A_PIN_MASK (1<<5)  // PA5
#define B_PIN_MASK (1<<4)  // PA4
#define A_RESET_HOLD_CYCLES (18)
#define B_RESET_HOLD_CYCLES (36)

// Convert ADC count (0...2^12) to a ratio (0.0 ... 1.0)
#define ADC_COUNT_TO_RATIO(count) ((float)(count)/(float)(1<<12))
#define SAMPLES_PER_FRAME 15

// TODO: set DT to convert dvdt abstract units to meaningful units
#define DT (1.0)

//=============================================================================
// forward declarations

static void process_sample(float v0, float v1);
static uint16_t get_conversion_result(void);
static void reset_integrator(void);
static void led_on();
static void led_off();

//=============================================================================
// private storage

volatile static bool s_comp_did_trigger;  // Set true when comparator matches
volatile static bool s_sync_did_trigger;  // Set true when sync in goes true
volatile static float s_v0;               // integrator voltage captured at t0
volatile static uint16_t s_sample_count;  // # of samples processed
volatile static float s_total_dv;         // accumulated dv
volatile static float s_average_dv;       // averaged dv
volatile static bool s_has_dv;            // set after 15 samples (250 mSec)
volatile static bool s_has_initialized;   // set only after initial setup

//=============================================================================
// "public" code

// [foreground] called once at initialization
void micro_sense_init(void) {
  s_comp_did_trigger = false;
  s_sync_did_trigger = false;
  s_v0 = 0.0;
  s_sample_count = 0;
  s_total_dv = 0.0;
  s_average_dv = 0.0;
  s_has_dv = false;
  s_has_initialized = false;

  delay_ms(5);

  GAIN_A0_set_level(SDA_get_level());
  GAIN_A1_set_level(SCL_get_level());
  reset_integrator();

  s_has_initialized = true;
}

// [foreground] called repeatedly in foreground
void micro_sense_step(void) {
    if (s_has_dv) {
      // averaged dv is waiting for us...
      s_has_dv = false;
      float dvdt = s_average_dv / DT;
      printf("%e\r\n", dvdt);
    }
    // Until we implement autoscaling: each time through the loop, make MUX0 and
    // MUX1 track SDA and SCL
    GAIN_A0_set_level(SDA_get_level());
    GAIN_A1_set_level(SCL_get_level());

    asm("nop");
}

// [Interrupt] Called when comparator match goes true
void micro_sense_ac_match_cb(void) {
  if (!s_has_initialized) return;
  s_comp_did_trigger = true;
}

// [interrupt] Called on completion of ADC conversion
void micro_sense_adc_complete_cb(void) {
  if (!s_has_initialized) return;

  float ratio = ADC_COUNT_TO_RATIO(get_conversion_result());

  led_on();

//  if (ACA.STATUS & AC_AC0STATE_bp) {
//	  // Use comparator level rather than interrupt trigger to set s_comp_did_trigger
//	  s_comp_did_trigger = true;
//  }

  // Only two things trigger an ADC reading: when the comparator goes true or
  // when SYNC triggers.
  if (s_comp_did_trigger) {
	  if (!s_sync_did_trigger) {
		  // normal start: capture v0
          s_v0 = ratio;                // CASE 0
	  } else {
		  // normal end: capture v1 and process sample
          // Arrive here because the sync triggered.  Capture dv = v1 - v0
		  s_comp_did_trigger = false;  // CASE 1
          s_sync_did_trigger = false;  // prepare for next reading of v0
          process_sample(s_v0, ratio);
		  reset_integrator();
	  }
  } else {
	  // Arrive here if comparator did not trigger.
      reset_integrator();
	  if (s_sync_did_trigger) {
		  // flatline: gain is too low, ignore sample  CASE 3
          s_sync_did_trigger = false;  // prepare for next reading of v0
	  } else {
		  // wtf?
		  asm("nop");                  // CASE 2
	  }
  }
  led_off();
}

static void process_sample(float v0, float v1) {
  reset_integrator();               // reset integrator
  pwm_set_ratio(v1);                // pwm tracks A/D
  s_total_dv += (v1 - v0);          // accumulate dv (i.e. v1 - v0)
  s_sample_count += 1;

  if (s_sample_count >= SAMPLES_PER_FRAME) {
    // after 15 samples (250 mSec), emit averaged result
    s_average_dv = s_total_dv / SAMPLES_PER_FRAME;  // store result for fg
    s_has_dv = true;                                // notify fg
    s_total_dv = 0.0;                               // reset averaging filter
    s_sample_count = 0;
  }
}

// [Interrupt] Called on each low-to-high transition on SYNC_IN (60Hz)
void micro_sense_sync_cb(void) {
  if (!s_has_initialized) return;
  s_sync_did_trigger = true;
}


//=============================================================================
// local code

// Fetch the raw 12 bit sample from the A/D
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
  RESET_A_set_level(false);
  delay_cycles(B_RESET_HOLD_CYCLES - A_RESET_HOLD_CYCLES);
  RESET_B_set_level(false);
  asm("nop");
}

static void led_on() {
  STATUS_LED_set_level(true);
}

static void led_off() {
  STATUS_LED_set_level(false);
}
