/**
 * \file
 *
 * \brief Busy-wait delay functions.
 */

#ifndef _DELAY_H_
#define _DELAY_H_

#include <stdint.h>

void delay_init();
void delay_cycles(uint32_t cycles);
void delay_us(uint32_t us);
void delay_ms(uint32_t ms);
void delay_s(uint32_t s);

#endif  /* #ifndef _DELAY_H_ */
