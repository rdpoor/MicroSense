/**
 * MicroSense firmware for LACH project - A1U dev platform.
 * Robert Poor <rdpoor@gmail.com>
 * May 2019
 *
 * See ReadMe.md for overview and details.
 */

#include <atmel_start.h>
#include <stdio.h>
#include "systic.h"
#include "micro_sense.h"

int main(void) {
  atmel_start_init();
  printf("MicroSense v0.1\r\n");

  systic_init();
  micro_sense_init();

  while (1) {
    micro_sense_step();
  }
}
