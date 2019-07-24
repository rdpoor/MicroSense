/**
 * MicroSense firmware for LACH project.
 * Robert Poor <rdpoor@gmail.com>
 * May 2019
 *
 * See ReadMe.md for overview and details.
 */

#include <atmel_start.h>
#include <stdio.h>
#include "micro_sense.h"

int main(void) {
	atmel_start_init();
	printf("MicroSense v0.1\r\n");

  micro_sense_init();

	while (1) {
    micro_sense_step();
  }
}
