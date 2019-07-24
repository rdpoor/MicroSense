# L.A.C.H MicroSense


## Hardware Configuration:

SYNC_IN (PA3) is driven from the 60 Hz line detection circuitry.  A low-to-high
transition on SYNC_IN does two things (configured via Atmel START):

- It generates an event on Channel 0 (configured via Atmel START in the
  EVENT_SYSTEM_0 component).
- It generates a high-level interrupt on port 0 (configured via Atmel START in
  the PINMUX Configurator).


## Program Structure:


On SYNC_IN (60Hz) low-to-high transition (at interrupt level):
- Trigger an event on Channel 0.  This initiates an ADC reading.
- wait for D1 microseconds
- set A low for D2 microseconds
- set A high

On ADC completion (at interrupt level):
- update PWM to track ADC sample
- add sample to running average
- after N samples set "has_frame"

At foreground level:
- if "has_frame" true, process frame and set has_frame false

## I/O Assignments

The product is defined to run on an ATXMEGA16D4, but we used an XMEGA A1U
XPlained development board for prototyping the system.  As a result, during the
development process, there are two sets of I/O assignments:

```
signal name  ATMEGA16D4  XMEGA A1U        XMEGA A1U Connector
------------+-----------+----------------+--------------------
```

## To Modify and Rebuild the MicroSense firmware

### Tools Required

* Atmel Studio 7
* Access to https://start.atmel.com/

If you need to modify the processor configuration (clock rate, I/O pins,
firmware components, interrupt structure, etc), see `Modifying Configuration`
below.  If you need only to modify source code, skip to the `Modifying Code`
section.

### Modifying Configuration

1. In your browser, navigate to https://start.atmel.com/
2. Scroll to the section labeled `Load Existing Project`
3. Browse to and open `MicroSense.atzip` (two directories up from this ReadMe).
4. Make any modifications as needed
5. Select `Export Project` => `Download Pack` and write over `MicroSense.atzip`
6. Launch Studio 7, open ``

### Modifying Code

1. Launch Studio 7 and open `MicroSense.atsln`
2. Edit code as needed
3. Select [Build] => [Build MicroSense] to rebuild the project

## Profiling

The profiling module provides a means to wiggle GPIO pins in order to trace
program execution in real-time through the following constructs:

    PROFILE_INIT()
    PROFILE_SET(PIN_DESCRIPTOR)
    PROFILE_CLR(PIN_DESCRIPTOR)
    PROFILE_TGL(PIN_DESCRIPTOR)

If the compile-time constant PROFILING is undefined, these constructs don't
generate any code.  Otherwise, code is emitted to set, clear or toggle the
designated GPIO pin.


### How it works

The construct:

    #define PROFILED_PINS \
      DEF_PROFILED_PIN(CONVERTING_SAMPLE, PORTA, 4) \
      DEF_PROFILED_PIN(PROCESSING_SAMPLE, PORTB, 5) \
      DEF_PROFILED_PIN(PROCESSING_FRAME, PORTC, 6)

defines and names the GPIO pins to use for profiling.  Then,

    PROFILE_INIT()

expands into:

    do {
      profile_init(PORTA, 4);
      profile_init(PORTB, 5);
      profile_init(PORTC, 6);
    } while(0);

which initializes the named GPIO pins as outputs, initially low.  And:

    PROFILE_SET(CONVERTING_SAMPLE);

expands into:

      profile_set(PORTA, 4);
