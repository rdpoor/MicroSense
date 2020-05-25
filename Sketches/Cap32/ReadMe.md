# Sketches/Cap32

This directory contains demonstration of measuring a pulse input using a 32 bit
counter.

IDE: Atmel Studio 7
Framework: Atmel Start
Target: XMEGA A1U Xplained Pro development board

## To run:

1. Connect XMEGA A1U Xplained Pro USB cable to a serial terminal emulator,
   configured 115200 baud / 8n1.
2. Set the signal generator for a rectangular wave, 0-3Vpp, at around 1 Hz.
3. Connect a signal generator to connector EXT3 pin 4 with ground on EXT3 pin 2.
4. Vary the duty cycle of the rectangular wave.

On the terminal emulator, you will see the width of the rectangular wave
expressed as seconds / 32000000 (the speed of the processor clock).

Internally, the system uses two built-in 16 bit timers, TCC0 and TCC1, running
in pulse width capture mode, ganged together to form a 32 bit counter.  A full
description of the implementation can be found in:

    https://community.atmel.com/forum/how-capture-pulse-width-32-bit-resolution-xmega

This particular code example takes an interrupt when the TCC0 capture completes
and sets some shared variables from interrupt level.  Code at the foreground
notices the update and prints it out -- see `src/micro_sense.c`

rdpoor@gmail.com
May 2020
