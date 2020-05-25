# Sketches/Cmp32

This directory contains a demonstration of measuring the width of a comparator
output using a 32 bit counter.  The signal chain is:

    ramp wave => comparator => pulse wave => pulse width capture

IDE: Atmel Studio 7
Framework: Atmel Start
Target: XMEGA A1U Xplained Pro development board

## To run:

1. Connect XMEGA A1U Xplained Pro USB cable to a serial terminal emulator,
   configured 115200 baud / 8n1.
2. Set the signal generator for a sawtooth wave, ~1Hz, 0-3vpp, to EXT1.03 (PA0).
3. Monitor the comparator output with an oscilloscope on EXT3.04 (PA7).

The comparator output will go true when the ramp wave exceeds the
internal bandgap voltage reference and will false when the ramp wave
drops below that value.  Its output appears on PA7 (EXT3.04 on the XMEGA
XPlained Pro board).

The comparator generates an Event on Event Channel 0 on both rising and falling
outputs.  Event Channel 0 in turn gates the pulse width capture module.

rdpoor@gmail.com
May 2020
