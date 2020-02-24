# L.A.C.H MicroSense

## 16D vs A1U configuration

The production board is built with an XMEGA D chip.  But for testing and
development, we're using an XMEGA Xplained A1U board, built around an XMEGA AU
chip.  Ideally, we'd use the same configuration on both systems, but since some
of the GPIO pins on the XMEGA Xplained board are either hard-wired for other
functions or not conveniently available on the I/O connectors, some remapping
is needed.

The following table shows the symbolic signal name and where it appears on the
production board (16D Part) and where it appears on the development board (A1U
Part).

|Name      |16D Port|A1U Port|Xplained Pro pin| |Note            |
|----------|--------|--------|----------------|-|----------------|
|V_RAMP    |PA0     |PA0     |EXT1.03         | |ADC Input       |
|COMP_N    |PA1     |PA1     |EXT2.03         | |Comp -, ADC Ref |
|V_REF     |PA2     |PA6     |EXT2.04         |x|Comp +, ADC REF |
|SYNC_IN   |PA3     |PA3     |EXT3.03         | |Drives Event Ch1|
|RESET_B   |PA4     |PA4     |EXT1.04         | |                |
|RESET_A   |PA5     |PE7     |EXT1.06         |x|                |
|TP_0      |PA6     |PR1     |EXT1.10         |x|Test Point 0    |
|COMP_OUT  |PA7     |PA7     |EXT3.04         | |                |
|GAIN_A0   |PB0     |PB4     |EXT2.05         |x|                |
|GAIN_A1   |PB1     |PB5     |EXT2.06         |x|                |
|TP_1      |PB2     |PB6     |EXT2.09         |x|Test Point 1    |
|TP_2      |PB3     |PB7     |EXT2.10         |x|Test Point 2    |
|RXCD      |PC2     |PC2     |EXT1.13         | |                |
|TXDC      |PC3     |PC3     |EXT1.14         | |                |
|PWM_OUT   |PD0     |PD0     |EXT3.15         | |                |
|RXD       |PD2     |PD2     |(note 1)        | |                |
|TXD       |PD3     |PD3     |(note 1)        | |                |
|STATUS_LED|PD7     |PQ3     |                |x|on-board LED    |
|SDA       |PE0     |PE0     |EXT1.08         | |                |
|SCL       |PE1     |PE1     |EXT1.07         | |                |

note1: On Xplained Pro, Serial I/O appears on the embedded debugger

## Simulating the production system

The production system has an analog integrator (`V_OUT`) that is reset by
asserting A and B signals.  It also has a 60 Hz sync signal that goes false
once every 16.7 milliseconds.

To simulate the analog circuitry, we configure our dual-channel signal generator
to produce a 60 Hz ramp on channel 1 and a 60 Hz rectangle wave on channel 2,
configured with a 90% duty cycle.  Channel 1 feeds `V_OUT` and channel 2 and
feeds `SYNC_IN`. This way, channel 2 goes false slightly before the ramp on
channel 1 reaches maximum value.  We should see A and B pulse when channel 2
falls.

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
