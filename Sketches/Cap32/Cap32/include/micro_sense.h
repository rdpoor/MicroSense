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

#ifndef _MICRO_SENSE_H_
#define _MICRO_SENSE_H_

#ifdef __cplusplus
extern "C" {
#endif

// =============================================================================
// includes

#include <stdint.h>
#include <stdbool.h>

// =============================================================================
// types and definitions

// =============================================================================
// declarations

/**
 * \brief initialize the micro_sense module.
 */
void micro_sense_init(void);

/**
 * \brief  Perform one tick in the micro_sense module
 */
void micro_sense_step(void);

/**
 * \brief Called from interrupt level on TCC0 compare interrupt
 */
void micro_sense_on_tcc0_cca_irq(void);

/**
 * \brief Called from interrupt level on TCC0 error (overflow) interrupt
 */
void micro_sense_on_tcc0_err_irq(void);

/**
 * \brief Called from interrupt level on Port A interrupt
 */
void micro_sense_on_porta_irq(void);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef _MICRO_SENSE_H_ */
