#include "hello_world.h"
#include <atmel_start.h>
#include <stdbool.h>
#include <stdio.h>

bool s_adc_ready = false;
bool s_porta_int = false;

void hello_world_init() {
  printf("\r\nHello World\r\n");
}

void hello_world_process() {
  if (s_adc_ready) {
    printf("\r\ngot adc");
    s_adc_ready = false;
  }
  if (s_porta_int) {
    printf("\r\ngot porta");
    s_porta_int = false;
  }
}

void hello_world_adc_result_ready_cb() {
  STATUS_LED_toggle_level();
  s_adc_ready = true;
}

void hello_world_porta_int_cb() {
  s_porta_int = true;
}
