/**
 * \file delay.c
 *
 * \brief Busy-wait delay functions.
 */

#include "delay.h"
#include <stdint.h>

#define CYCLES_PER_US 4

static void _delay_cycles(uint32_t cycles);

void delay_init() {
  // no-op for now
}
void delay_cycles(uint32_t cycles) {
  _delay_cycles(cycles);
}

void delay_us(uint32_t us) {
  delay_cycles(us / CYCLES_PER_US);
}

void delay_ms(uint32_t ms) {
  delay_us(ms * 1000);
}

void delay_s(uint32_t s) {
  delay_ms(s * 1000);
}

static void _delay_cycles(uint32_t cycles) {
  for (int i=0; i<cycles; i++) {
    asm("nop");
  }
}
