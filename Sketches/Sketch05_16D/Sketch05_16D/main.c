#include <atmel_start.h>
#include "micro_sense.h"

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
  micro_sense_init();

	/* Replace with your application code */
	while (1) {
    micro_sense_step();
	}
}
