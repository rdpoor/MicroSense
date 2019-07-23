#include <systic.h>

static volatile uint16_t s_systic;

void systic_init(void) {
	s_systic = 0;
}

// advance the millisecond counter.  called at interrupt level.
void systic_tic(void) {
	s_systic += 1;
}

// fetch the millisecond counter.  interrupt safe.
uint16_t systic_get_ms(void) {
	uint16_t tmp = s_systic;
	while (s_systic != tmp) {
		tmp = s_systic;
	}
	return tmp;
}
