#include <atmel_start.h>
#include <stdio.h>
#include "hello_world.h"

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	hello_world_init();

	while (1) {
		hello_world_process();
	}
}
