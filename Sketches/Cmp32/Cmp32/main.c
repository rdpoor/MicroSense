#include <atmel_start.h>
#include <stdio.h>
#include "micro_sense.h"

int main(void)
{
  atmel_start_init();
  micro_sense_init();

  printf("\r\n=====\r\nMicroSense %s %s", __DATE__, __TIME__);

  while (1) {
    micro_sense_step();
  }
}
