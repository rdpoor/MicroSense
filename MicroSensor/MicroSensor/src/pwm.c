/*
 * \file pwm.c
 *
 * Author: R. D. Poor <rdpoor@gmail.com>
 */

#include <pwm.h>

// About the Pulse Width Modulator:
//
// The PWM is implemented using TCD0, a 16 bit timer driven by the system clock.
// It has 16-bit resolution and updates once every (1<<16)/12Mhz = 5.461 mS or
// at a rate of 183 Hz.

#define PWM_MAX_COUNT (0xffff)
#define PWM_RATIO_TO_COUNT(ratio) (int)((ratio) * PWM_MAX_COUNT)
#define PWM_COUNT_TO_RATIO(count) ((float)(count) / PWM_MAX_COUNT)

void pwm_init(void) {
  pwm_set_ratio(0.5);
}

void pwm_set_ratio(float ratio) {
  // clamp...
  if (ratio < 0.0) {
    ratio = 0.0;
  } else if (ratio > 1.0) {
    ratio = 1.0;
  }
  // It's safe to set CCA at any time: the TC hardware buffers the value and
  // transfers it it at an "update", i.e. when the counter hits max count.
  uint16_t count = PWM_RATIO_TO_COUNT(ratio);
  TCD0.CCA = count;
}

float pwm_get_ratio() {
  return PWM_COUNT_TO_RATIO(TCD0.CCA);
}

// called from interrupt level at the end of a PWM cycle.
void pwm_overflow_cb() {
  asm("nop");
}
