L.A.C.H MicroSense


Program Structure:

Once every millisecond ("sample interval"):
- TMR0 overflows
- TMR0 ISR updates system tic counter.
- TMR0 ISR clears ADCDone and toggles ClkOut1KHz.  (These GPIOs are only used
  for monitoring and debugging and have no other effect.)
- TMR0 triggers an event on Channel 0.  This initiates an ADC reading.
- ADC Completion calls an ISR where "all the processing" happens, including
  updating dv/dt and incrementing the systic counter.

Once every 250 milliseconds ("frame interval"):
- emits CSV record with dv/dt for this frame
- updates the PWM output (analog output)
- resets the dv/dt count

## I/O Assignments

The product is defined to run on an ATXMEGA16D, but we used an XMEGA A1U
XPlained development board for prototyping the system.  As a result, during the
development process, there are two sets of I/O assignments:

```
signal name  ATMEGA16D   XMEGA A1U        XMEGA A1U Connector
------------+-----------+----------------+--------------------
ANALOG_IN_P  PA0         PA0              EXT1.3
ANALOG_IN_M  PA2         PA4              EXT1.4
SERIAL_RX    PC2         PE2 (USARTE0)    EDBG / USB
SERIAL_TX    PC3         PE3 (USARTE0)    EDBG / USB
MUXA0        PB0         PE6              EXT1.5
MUXA1        PB1         PE7              EXT1.6
POLARITY     PA7         PR1              EXT1.10
LED          PD7         PQ3              on board
PWM_OUT-                 PE0 (TCE0 OC0A)  EXT1.8     works
PWM_OUT+     PD0         PE1 (TCE0 OC0B)  EXT1.7     doesn't work
I2C_SCL      PE1
IC2_SDA      PE0
IRDA_RX      PD2
IRDA_TX      PD3

CONVERTING_SAMPLE        PB4              EXT2.5
PROCESSING_SAMPLE        PB5              EXT2.6
PROCESSING_FRAME         PB6              EXT2.9
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
