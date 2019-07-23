#include <pwm.h>

// About the Pulse Width Modulator:
//
// The PWM is implemented using TCD0, a 16 bit timer driven by the system clock.
// We want the PWM to update once every millisecond, so we set TCDO's period to
// the system clock / 1000.  At present the system clock is 2MHz, so we set the
// timer's period to 2000.
//
// This also means the PWM can be set to one of 2000 different states (well, a
// few less for reaons explained below).  To convert a ratio to a compare value,
// we multiply by 2000.

#define PWM_MAX_COUNT (2000)
#define PWM_RATIO_TO_COUNT(ratio) (int)((ratio) * PWM_MAX_COUNT)
#define PWM_COUNT_TO_RATIO(count) ((float)(count) / PWM_MAX_COUNT)

static uint16_t s_ratio;

void pwm_init(void) {
	s_ratio = 0.5;
}

void pwm_set_ratio(float ratio) {
  uint16_t tmp = PWM_RATIO_TO_COUNT(ratio);
	// TODO: figure out if there's a minimum or maximum value.  This may depend
	// on how quickly the interrupt service routine can update TCD0.CCA
	if (tmp > PWM_MAX_COUNT) {
		tmp = PWM_MAX_COUNT;
	} else if (tmp < 0) {
		tmp = 0;
	}
	// Race condition alert: it's possible that TCD0 will interrupt when s_ratio
	// is only half-updated -- this will cause a glitch.  We choose to ignore this
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
	s_ratio = tmp;
}

float pwm_get_ratio() {
  return PWM_COUNT_TO_RATIO(s_ratio);
}

// called from interrupt level when the PWM overflows.  Update ratio.
void pwm_overflow_cb() {
	TCD0.CCA = s_ratio;
}
