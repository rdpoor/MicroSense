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

// =============================================================================
// local (forward) declarations

static void reset_v_out();

// =============================================================================
// local storage

static int s_cca_irqs;
static int s_err_irqs;
static int s_vsync_irqs;
static int s_adc_irqs;
static uint16_t s_adc_raw;
static bool s_changed;
static uint16_t s_cca;

// =============================================================================
// public code

// called once at startup after chip and board initialization
void micro_sense_init(void) {
  MUX_A0_set_level(false);
  MUX_A1_set_level(true);
  s_changed = false;
}

// called repeatedly from the main loop
void micro_sense_step(void) {
  if (s_changed && (s_adc_irqs % 60 == 0)) {
    uint16_t pulse_width = s_cca;
    printf("\r\n%4d, %4d, %4d, %4d, %4d, %8d",
           s_cca_irqs,
           s_err_irqs,
           s_vsync_irqs,
           s_adc_irqs,
           s_adc_raw,
	         pulse_width);
    s_changed = false;
  }
}

/**
 * \brief [Interrupt] TCC1 completed pulse-width measurement.
 */
void micro_sense_on_tcc1_cca_irq(void) {
  s_cca_irqs += 1;
  // Reading the CCA registers clears the interrupt...
  s_cca = TCC1.CCA;
  // s_changed = true;
}

/**
* \brief [Interrupt] TCC1 registers were overwritten before reading.
 */
void micro_sense_on_tcc1_err_irq(void) {
  s_err_irqs += 1;
  // s_changed = true;
}

/**
 * \brief [Interrupt] ADC completed a reading.
 */
void micro_sense_on_adc_complete_irq(void) {
  USR_LED_toggle_level();
  s_adc_raw = ADCA.CH0RES;  // read ADC register, clears interrupt
  s_adc_irqs += 1;
  s_changed = true;
  reset_v_out();
}

/**
* \brief [Interrupt] V_SYNC went true.
 */
void micro_sense_on_vsync_irq(void) {
  s_vsync_irqs += 1;
  // s_changed = true;
}

// =============================================================================
// local (static) code

static void reset_v_out() {
	A_set_level(true);
	delay_us(200);
	A_set_level(false);
}