#ifndef PWM_H_INCLUDED
#define PWM_H_INCLUDED

#include <compiler.h>

#ifdef __cplusplus
extern "C" {
#endif

// initialize pwm
void pwm_init(void);

// set the PWM duty cycle (takes effect at the next interrupt)
void pwm_set_ratio(float ratio);

// get the pending (or current) PWM ratio
float pwm_get_ratio();

// called from interrupt level when the PWM overflows.  Update ratio.
void pwm_overflow_cb();

#ifdef __cplusplus
}
#endif

#endif  // #ifndef PWM_H_INCLUDED
