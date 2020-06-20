/**
 * MIT License
 *
 * Copyright (c) 2019 R. Dunbar Poor <rdpoor@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
Overview:

The goal of MicroSense is to measure dv/dt from an analog integrator (V_OUT),
reset every 16.7 mSec (60Hz).

At the beginning of time:

   has_sample = false;
    dt_is_valid = false;
    v1 = 0;
    v0 = SOME_CONSTANT;
    dt = 0;

Then:

on_vsync_interrupt:
    dvdt = (v1 - v0) / dt;         // do this every time to minimize ADC jitter
    if (dt_is_valid) {             // signal foreground
      sample_status = READY | VALID;
    } else {
      sample_status = READY;
  }
    dt_is_valid = false;           // prepare for next cycle
    // initiate ADC read

on_adc_complete:
    v1 = read_adc();
    update_pwm();
    reset_vout();

on_ pulse_width_captture_interrupt():
    dt = read_tcc1();
    dt_is_valid = true;

at foreground:

    while (1) {
      if (sample_status & READY) {
        if (sample_status & VALID) {
          process_sample();
        } else {
          note_invalid_sample();
        }
        // possible race condition here: assure that FG can always process
        // sample within 16 mSec
        sample_status = 0;   // possible race condition
      }
    }

At this point, we have dv (the captured ADC output - V_REF) and dt (captured
from TCC1).  We compute dv/dt and add that amount to a running total.  After
15 samples (approximately 250 mSec -- see below), we take the average and relay
that information to the foreground level code.

If the gain is too low:

The signals MUX_A0 and MUX_A1 control the gain of the analog circuitry.  If the
gain is set too low, V_OUT will not rise above V_REF before V_SYNC triggers an
ADC read.  The sequence of things will look like this:

 1. V_OUT starts to rise at a rate proportional to the electrode current.
 4. A 60Hz source triggers V_SYNC to to go true
 5. The rising edge of V_SYNC triggers an event on Event Channel 0.
 6. The event on Event Channel 0 initiates an ADC reading.
 7. Upon completion of the ADC reading, the ADC generates an interrupt.
 8. The ADC read value is captured as v1 and resets the integrator (V_OUT).

In this case, note that we will not get a TCC1 interrupt, so we cannot capture
TCC1's count.  However, we can detect a "gain too low" condition by looking at
the ADC count: it will be zero (or perhaps negative: TBD...).

If the gain is too high:

If the gain is set too high, V_OUT will saturate before V_SYNC.  We can
detect this by looing at the ADC count.

*/

// =============================================================================
// includes

#include "micro_sense.h"
#include <atmel_start.h>
#include "delay.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

// =============================================================================
// local types and definitions

// at 60 Hz V_SYNC, emit one frame every 250 mSec.
#define SAMPLES_PER_FRAME 15

// About the ADC:
//
// The ADC generates 12 bit unsigned values

#define ADC_MAX_COUNT (4096)
#define ADC_RATIO_TO_COUNT(ratio) (int)((ratio) * ADC_MAX_COUNT)
#define ADC_COUNT_TO_RATIO(count) ((float)(count) / ADC_MAX_COUNT)

// About the Pulse Width Modulator:
//
// The PWM is implemented using TCD0, a 16 bit timer driven by the 32MH system
// clock.  We want the PWM to update once every millisecond, so we set TCDO's
// period to 32,000.  This means that we can set the PWM to 32,000 different
// states (slightly fewer for reasons explained below).
//
// This also means the PWM can be set to one of 2000 different states (well, a
// few less for reaons explained below).  To convert a ratio to a compare value,
// we multiply by 2000.

#define PWM_MAX_COUNT (32000)
#define PWM_RATIO_TO_COUNT(ratio) (int)((ratio) * PWM_MAX_COUNT)
#define PWM_COUNT_TO_RATIO(count) ((float)(count) / PWM_MAX_COUNT)

typedef enum {
  SAMPLE_WAITING,  // no sample produced yet
  SAMPLE_VALID,    // valid dv and dt available
  SAMPLE_INVALID   // sample period ended without valid dv and dt
} sample_state_t;

// =============================================================================
// local (forward) declarations

static void emit_frame(int gain, float dvdt, int count);
static void reset_v_out();

static void pwm_init(void);
static void pwm_set_ratio(float ratio);
// static float pwm_get_ratio(void);
// static void pwm_overflow_cb(void);

// =============================================================================
// local storage

// interrupt only
static uint16_t s_dt_raw;
static bool s_has_dt;
static float s_v0_ratio;
static uint16_t s_v1_raw;
static float s_v1_ratio;
static float s_pwm_ratio;
static int s_err_irqs;

// shared
static volatile sample_state_t s_sample_state;
static volatile float s_dvdt;

// foreground only
static int s_sample_count;         // # of samples seen in this frame
static float s_sum_dvdt;   // sum of dvdt for this frame
static int s_sum_count;    // # of dvdt's sum

// =============================================================================
// public code

// called once at startup after chip and board initialization
void micro_sense_init(void) {
  pwm_init();
  MUX_A0_set_level(false);
  MUX_A1_set_level(true);
  s_sample_state = SAMPLE_WAITING;
  s_dvdt = 0.0;
  s_v0_ratio = 0.0;

  s_dt_raw = 0;
  s_has_dt = false;
  s_v0_ratio = 0.0;
  s_v1_ratio = 0.0;
  s_pwm_ratio = 0.5;
  s_err_irqs = 0;

  // shared
  s_sample_state = SAMPLE_WAITING;
  s_dvdt = 0.0;

  // foregrond only
  s_sample_count = 0;
  s_sum_dvdt = 0.0;
  s_sum_count = 0;
}

// \brief [Foreground] main loop
//
// If dvdt has been computed at interrupt level, accumulate it in s_sum_dvdt
// for averaging.
//
// If 15 samples have been generated, emit the averaged dvdt along with gain
// and # of samples averaged.
//
void micro_sense_step(void) {
  bool gain0 = FUTURE_SCL_get_level();
  bool gain1 = FUTURE_SDA_get_level();

  // setup MUX_A0 and MUX_A1 to follow SCL and SDA (respectively)
  MUX_A0_set_level(gain0);
  MUX_A1_set_level(gain1);

  if (s_sample_state != SAMPLE_WAITING) {
    if (s_sample_state == SAMPLE_VALID) {
      s_sum_dvdt += s_dvdt;
      s_sum_count += 1;
    }
    s_sample_state = SAMPLE_WAITING;

    s_sample_count += 1;
    TEST_PT_A_set_level(true);
    if (s_sample_count == SAMPLES_PER_FRAME) {
      emit_frame((gain1 << 1) + gain0,
                 s_sum_count > 0 ? s_sum_dvdt / s_sum_count : 0.0,
                 s_sum_count);
    s_sum_dvdt = 0.0;
    s_sum_count = 0;
    s_sample_count = 0;
    }
	TEST_PT_A_set_level(false);
  }  
}

/**
 * \brief [Interrupt] V_SYNC went true.
 *
 * Note that V_SYNC true also initiates an ADC reading via the Event system.
 */
void micro_sense_on_vsync_irq(void) {
  // always compute s_dvdt -- whether valid or not -- to reduce jitter.
  s_dvdt = (s_v1_ratio - s_v0_ratio) / (float)s_dt_raw;
  if (s_has_dt) {
    s_sample_state = SAMPLE_VALID;
  } else {
    s_sample_state = SAMPLE_INVALID;
  }
  s_has_dt = false;  // prepare for next cycle
}

/**
 * \brief [Interrupt] ADC completed a reading.
 */
void micro_sense_on_adc_complete_irq(void) {
  USR_LED_toggle_level();
  s_v1_raw = ADCA.CH0RES;                     // read ADC, clears interrupt
  printf("%d\r\n", s_v1_raw);
  s_v1_ratio = ADC_COUNT_TO_RATIO(s_v1_raw);  
  s_pwm_ratio = s_v1_ratio;
  reset_v_out();             // reset V_OUT
}

/**
 * \brief [Interrupt] TCC1 completed pulse-width measurement.
 */
void micro_sense_on_tcc1_cca_irq(void) {
  // Reading the CCA registers clears the interrupt...
  s_dt_raw = TCC1.CCA;   // capture comparator output pulse width
  s_has_dt = true;       // note that s_dt_raw was captured
}

/**
* \brief [Interrupt] TCC1 registers were overwritten before reading.
 */
void micro_sense_on_tcc1_err_irq(void) {
  s_err_irqs += 1;
}

/**
 * \brief [Interrupt] PWM wants reloading.
 */
void micro_sense_on_pwm_irq(void) {
  pwm_set_ratio(s_pwm_ratio);
}


// =============================================================================
// local (static) code

static void emit_frame(int gain, float dvdt, int count) {
	// printf("\r\n%d, %e, %d, %d, %u", gain, dvdt, count, s_v1_raw, s_dt_raw);
	// long int idvdt = dvdt * 2000000;
    // printf("\r\n%d, %ld, %d", gain, idvdt, count);
}

static void reset_v_out() {
  A_set_level(true);
  delay_us(200);
  A_set_level(false);
}


// =============================================================================
// ADC support



// =============================================================================

static uint16_t s_pwm_count;

static void pwm_init(void) {
	s_pwm_count = PWM_RATIO_TO_COUNT(0.5);
}

static void pwm_set_ratio(float ratio) {
  uint16_t tmp = PWM_RATIO_TO_COUNT(ratio);
	// TODO: figure out if there's a minimum or maximum value.  This may depend
	// on how quickly the interrupt service routine can update TCD0.CCA
	if (tmp > PWM_MAX_COUNT) {
		tmp = PWM_MAX_COUNT;
	} else if (tmp < 0) {
		tmp = 0;
	}
	// Race condition alert: TCD0 can interrupt when s_pwm_count is only
	// half-updated -- this will cause a glitch.  We choose to ignore this
	// because:
	// -- it's rare
	// -- it will (probably) self-correct on the next tic
	// -- the analog circuitry has a low-pass filter
	// -- we call this routine often, so we don't want the overhead of a mutex
	//
	// Note to self: the above would be true iff calls to pwm_set_ratio() were not
	// correlated with the PWM overflow interrupt.  But calls to pwm_set_ratio()
	// ARE correlated with the PWM overflow interrupt, so either we'll never hit
	// the race condition or we always will.  Caveat emptor.
	s_pwm_count = tmp;
}

// static float pwm_get_ratio() {
//   return PWM_COUNT_TO_RATIO(s_pwm_count);
// }
//
// // called from interrupt level when the PWM overflows.  Update ratio.
// static void pwm_overflow_cb() {
// 	TCD0.CCA = s_pwm_count;
// }
