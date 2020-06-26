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

// =============================================================================
// local storage

// =============================================================================
// public code

// called once at startup after chip and board initialization
void micro_sense_init(void) {
  pwm_init();
  MUX_A0_set_level(false);
  MUX_A1_set_level(true);
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
}

/**
 * \brief [Interrupt] V_SYNC went true.
 */
void micro_sense_on_vsync_irq(void) {
  // Initiate an ADC reading
	ADCA.CTRLA = 1 << ADC_CH0START_bp  // Start conversion
             | 0 << ADC_FLUSH_bp     // Flush Pipeline: disabled
             | 1 << ADC_ENABLE_bp    // Enable ADC: enabled
             ;
}

/**
 * \brief [Interrupt] ADC completed a reading.
 */
void micro_sense_on_adc_complete_irq(void) {
  uint16_t raw = ADCA.CH0RES; // read ADC
  USR_LED_toggle_level();
  printf("%d\r\n", raw);
  reset_v_out();              // reset V_OUT
}

/**
 * \brief [Interrupt] PWM wants reloading.
 */
void micro_sense_on_pwm_irq(void) {
  // pwm_set_ratio(s_pwm_ratio);
}


// =============================================================================
// local (static) code

static void emit_frame(int gain, float dvdt, int count) {
	// printf("\r\n%d, %e, %d, %d, %u", gain, dvdt, count, s_v1_raw, s_dt_raw);
	// long int idvdt = dvdt * 2000000;
    // printf("\r\n%d, %ld, %d", gain, idvdt, count);
}

static void reset_v_out() {
  V_RESET_set_level(true);
  delay_us(200);
  V_RESET_set_level(false);
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
