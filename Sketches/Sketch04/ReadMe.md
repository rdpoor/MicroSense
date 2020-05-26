# Sketches/Sketch04

This directory contains an experiment in using the XMEGA Event system for
handling (most) of the actions in MicroSense.

## Event System configuration

### Event Ch 0:

Event Ch 0 is generated on rising edge of Vsync on PA3 (EXT3.03).  It triggers
when Vsync goes true.

Event Ch 0 consumed by ADC_0 and initiates a conversion.

### Event Ch 6:

Event CH 6 is generated on a transition of AC_0, both rising and falling.

Event Ch 6 is consumed by TCC0 and TCC1 to start and stop pulse width counting.

### Event Ch 7:

Event Ch 7 is generated on an overflow of TCC0.

Event Ch 7 is consumed by TCC1 and triggers a count, ie, incrementing the high-
order bits of the counter.

## Interrupt System configuration

ADC_0 generates an interrupt upon conversion completion.

TCC0 generates an interrupt upon capturing pulse width.

PA3 (Vsync) generates an interrupt when Vsync goes true.

## Other configuration details

Route the output of AC_0 (comparator) to PA7 (EXT3.04) for scope probing.

## To run:

* Connect XMEGA A1U Xplained Pro USB cable to a serial terminal emulator,
  configured 115200 baud / 8n1.
* Set the signal generator channel 1 as a simulated Vramp (sawtooth wave, 60Hz,
  ~0-3vpp) connected to AC_0+ via PA0 (EXT1.03) and to ADC_0+ via PA4 (EXT1.03).
* Set the signal generator channel 2 as a simulated Vsync (square wave, 60Hz,
  0-3vpp), and set its phase so it rises just before the sawtooth wave falls.
* Connect signal generator channel 2 to PA3 (EXT3.03).
* Monitor the comparator output on COMP_OUT via PA7 (EXT3.04).
* Monitor the ADC sampling interrupt on TEST_PT0 via PK1 (EXT3.06)

## Pin assignments

|Name      |16D Port|A1U Port|Xplained Pro pin| |Note            |
|----------|--------|--------|----------------|-|----------------|
|V_RAMP_A  |xxx     |PA0     |EXT1.03         | |Comp +          |
|V_RAMP_B  |xxx     |PA4     |EXT1.04         | |ADC +           |
|V_REF     |xxx     |-na-    |-na-            |x|                |
|V_SYNC    |xxx     |PA3     |EXT3.03         | |Drives Event Ch1|
|TEST_PT0  |xxx     |PK1     |EXT3.06         |x|ADC sample done |
|COMP_OUT  |xxx     |PA7     |EXT3.04         | |                |

## Overview

When V_RAMP exceeds bandgap threshold, the comparator output goes true.

When the comparator output goes true, it generates an event that starts the
pulse-width counters (Event Ch 6).

It also routes its output to PA7.

PA7 is configured to generate an event on Event Ch 0 when it goes positive.

This initiates an ADC reading.

When the ADC conversion completes, it generates an interrupt, which we use to
capture the ADC value (v0)

When V_SYNC goes true, it generates an event on Event Ch 1.  This also initiates
an ADC reading.

When the ADC completes conversion, it generates an interrupt (v1);

rdpoor@gmail.com
May 2020
