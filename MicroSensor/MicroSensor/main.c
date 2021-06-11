/**
 * MicroSensor firmware for LACH project.
 * Robert Poor <rdpoor@gmail.com>
 * May 2020
 *
 * See ReadMe.md for overview and details.
 */

#include "micro_sensor.h"
#include <atmel_start.h>
#include <stdio.h>

int main(void) {
  atmel_start_init();
  printf("\r\n# ===============\r\n# MicroSensor v2.0\r\n");

  micro_sensor_init();

  while (1) {
    micro_sensor_step();
  }
}
