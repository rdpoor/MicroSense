/**
 * MicroSensor firmware for LACH project.
 * R. D. Poor <rdpoor@gmail.com>
 *
 * See docs/ReadMe.md for overview and details.
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
