# Sketches/Sample32

This directory contains a demonstration of measuring dv/dt of a ramp wave.

In short, it uses a comparator to measure dt between the time the ramp wave
exceeds a threshold (internal bandcap in this case) and when it resets.  It
measures dv by capturing the value of the ramp wave when the comparator goes
true and "just before" the ramp wave gets reset.

IDE: Atmel Studio 7
Framework: Atmel Start
Target: XMEGA A1U Xplained Pro development board

## To run:

* Connect XMEGA A1U Xplained Pro USB cable to a serial terminal emulator,
  configured 115200 baud / 8n1.
* Set the signal generator channel 1 as a sawtooth wave, 60Hz, ~0-3vpp,
  connected to EXT1.03 (PA0).
* Set the signal generator channel 2 as a square wave, 60Hz, 0-3vpp, and set its
  phase so it goes true just before the sawtooth wave falls.
* Monitor the comparator output on EXT3.04 (PA7).
* Monitor the ADC sampling interrupt on EXT3.06 (PK1)

## Pin assignments

|Name      |16D Port|A1U Port|Xplained Pro pin| |Note            |
|----------|--------|--------|----------------|-|----------------|
|V_RAMP    |xxx     |PA0     |EXT1.03         | |Comp +          |
|V_RAMP    |xxx     |PA3     |EXT3.03         | |ADC +           |
|V_REF     |xxx     |-na-    |-na-            |x|                |
|V_SYNC    |xxx     |PD0     |EXT3.15         | |Drives Event Ch1|
|TP_0      |xxx     |PK1     |EXT3.06         |x|ADC sample done |
|COMP_OUT  |xxx     |PA7     |EXT3.04         | |                |

## Overview

When V_RAMP exceeds bandgap threshold, the comparator output goes true.

When the comparator output goes true, it generates an event that starts the
pulse-width counters.

It also generates an event that starts an ADC conversion.

When the ADC conversion completes, it generates an interrupt, which we use to
capture the ADC value.

When V_SYNC goes true, it generates an interrupt that initiates a second ADC
conversion.

When the ADC completes conversion, it generates an interrupt.  We use that to
capture the ADC value and to briefly pulse TP_0 (for monitoring).

## However...

The system doesn't quite work as laid out.  The ADC samples on the rising and
falling edge of the comparator since both edges generate events on EV Chan 0.

Next version re-works events and interrupts somewhat...

rdpoor@gmail.com
May 2020
