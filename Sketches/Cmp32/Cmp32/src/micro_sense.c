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
#include <stdbool.h>
#include <stdio.h>

// =============================================================================
// local types and definitions

// =============================================================================
// local (forward) declarations

// =============================================================================
// local storage

static int s_cca_irqs;
static int s_err_irqs;
static int s_port_irqs;
static bool s_changed;
static uint16_t s_cca_lo;
static uint16_t s_cca_hi;

// =============================================================================
// public code

// called once at startup after chip and board initialization
void micro_sense_init(void) {
  s_changed = false;

  // I haven't found a way to get Atmel START to have AC_0 drive PA7 output and
  // specify that PA7 is configured to sense both edges, as required by the
  // pulse width counter.
  PORTA_pin_set_isc(7, PORT_ISC_BOTHEDGES_gc);
}

// called repeatedly from the main loop
void micro_sense_step(void) {
  USR_LED__set_level(USR_SWITCH__get_level());
  if (s_changed) {
    uint32_t pulse_width = ((uint32_t)s_cca_hi << 16) | s_cca_lo;
    printf("\r\n%4d, %4d, %4d %04x:%04x %8ld",
           s_cca_irqs, s_err_irqs, s_port_irqs, s_cca_hi, s_cca_lo, pulse_width);
    s_changed = false;
  }
}

/**
 * \brief Called from interrupt level on TCC0 compare interrupt
 */
void micro_sense_on_tcc0_cca_irq(void) {
  s_cca_irqs += 1;
  // I was noticing continual interrupts.  From the documentation:
  //
  // For input capture operation, the CCxIF will be set if the corresponding
  // compare buffer contains valid data (i.e., when CCxBV is set). The flag will
  // be cleared when the CCx register is read. Executing the interrupt vector in
  // this mode of operation will not clear the flag.
  //
  // So we read the CCA registers...
  s_cca_lo = TCC0.CCA;
  s_cca_hi = TCC1.CCA;
  s_changed = true;
}

/**
 * \brief Called from interrupt level on TCC0 error (overflow) interrupt
 */
void micro_sense_on_tcc0_err_irq(void) {
  s_err_irqs += 1;
  s_changed = true;
}

/**
 * \brief Called from interrupt level on Port A interrupt
 */
void micro_sense_on_porta_irq(void) {
  s_port_irqs += 1;
  s_changed = true;
}

// =============================================================================
// local (static) code
