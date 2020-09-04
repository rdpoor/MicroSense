/**
 * MicroSense firmware for LACH project.
 * Robert Poor <rdpoor@gmail.com>
 * May 2020
 *
 * See ReadMe.md for overview and details.
 */

#include <atmel_start.h>
#include <stdio.h>
#include "micro_sense.h"

int main(void) {
	atmel_start_init();
	printf("\r\n# ===============\r\n# MicroSense v1.0\r\n");

  micro_sense_init();

	while (1) {
    micro_sense_step();
  }
}
