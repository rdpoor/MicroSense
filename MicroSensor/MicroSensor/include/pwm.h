/**
 * \file pwm.h
 *
 * \brief Using TCD0 for Pulse Width Modulation
 */

#ifndef PWM_H_INCLUDED
#define PWM_H_INCLUDED

#include <compiler.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initialize TCD0 to generate Pulse Width Modulated signals.
 */
void pwm_init(void);

/**
 * @brief Set the duty cycle of the PWM.
 *
 * @param ratio A float between 0.0 (for 0% duty cycle) and 1.0 (for 100%).
 */
void pwm_set_ratio(float ratio);

/**
 * @brief Get the duty cycle of the PWM.
 *
 * @return A float between 0.0 (for 0% duty cycle) and 1.0 (for 100%).
 */
float pwm_get_ratio();

/**
 * @brief Interrupt-level callback invoked when TCD0 overflows from 0xffff to 0.
 *
 * Note: see driver_isr.c.
 */
void pwm_overflow_cb();

#ifdef __cplusplus
}
#endif

#endif  // #ifndef PWM_H_INCLUDED
