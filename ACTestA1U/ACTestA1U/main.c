/**
 * Test comparator output.
 *
 * Comparator+ on PA1 (aka EXT2.3), connected to 1.15 v reference
 * Comparator- on PA3 (aka EXT3.3), connected to 0..3.3 v ramp wave
 * Comparator out on PA7 (aka EXT3.4), monitored on a scope
 *
 * PA7 should go high whenever ramp drops below 1.15 V
 */
#include <atmel_start.h>

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	/* Replace with your application code */
	while (1) {
		asm("nop");
	}
}
