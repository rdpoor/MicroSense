# MicroSensor User Notes

## Serial Output

The serial output is configured for 115200 baud, 8-bit, one stop bit, no parity.
It prints a CSV record once every 250 milliseconds.  The format is:

```
<auto>, <gain>, <count>, <vneg>, <vpos>

<auto>  is either 'M' or 'A' for Manual or Autoranging gain.
<gain>  system gain: 1 for minimum gain, 4 for 4x gain, 16 for maximum gain.
<count> Conductivity as a unit-less value.  To account for the gain,
        normalize the count by dividing by the system gain, e.g. <count>/<gain>.
<vneg>  used for diagnostics
<vpos>  used for diagnostics
```

## Analog Output

The analog output provide a quick way to visualize rapid changes to the
measured conductance.  It outputs a voltage between 0 and 3.3 volts.  

# MicroSensor Developer Notes

## Documentation links

* [Atmel XMEGA 16D4 Overview](https://www.microchip.com/wwwproducts/en/ATxmega16D4)
* [Atmel AVR XMEGA D - Complete Datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-8210-8-and-16-bit-AVR-Microcontrollers-XMEGA-D_Manual.pdf)
* [ATxmega128D4/64D4/32D4/16D4 - CompleteÂ Datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-8135-8-and-16-bit-AVR-microcontroller-ATxmega16D4-32D4-64D4-128D4_datasheet.pdf)
* [Differential and Single-Ended ADC](https://ww1.microchip.com/downloads/en/DeviceDoc/Differential-and-Single-Ended-ADC-WhitePaper-DS00003197A.pdf)

## Gain Settings

If SDA and SCL are left open or connected to Vcc, the system works on autoscale.
Otherwise:

```
SDA  SCL  Gain
  0    0  01: col3 = V_OUT * 2047 * 15 * 1
  0    1  04: col3 = V_OUT * 2047 * 15 * 4
  1    0  16: col3 = V_OUT * 2047 * 15 * 16
  1    1  Autoranging: Gain automatically switches between 01, 04, 16
```

## On Units

The SoulPhone firmware emits a string on the serial line once every 250 mSec, or more precisely, once every 15 complete samples.  (Some samples may be dropped
if the 60Hz sync pulse is absent.)

The third column is an indication of the conductance between the electrodes.

Assuming 0 volts on Vinn (aka V_REF), a 1 volt output on Vinp (aka V_OUT)
results in an ADC count of 2047.  The resulting string on the serial output is:

   V_OUT (avg) = column_3 / (2047 * 15)

Note: a future version of the code will support variable gain, in which case the
gain factor must be taken into account.

## GPIO Assignments

```
Processor: ATXMEGA16D4-AU

GPIO assignments and descriptions

GPIO F/W Name   Schem Name   Description
----+---------+------------+-------------------------------------------
PA0  Vinp       VOUT         Analog ramp, 0 - 1.0 vpp
PA1  unused     VOUT
PA2  Vinn       VREF         Analog reference for differential without gain
PA3  V_SYNC     16mSEC       60 Hz Sync Pulse, interrupt on ^ edge
PA4  Vinn       VREF         Analog reference for differential with gain
PA5             RESET_A      Pulse 200 uS high to reset integrator
PA6             PA6          Test point
PA7             PA7          Test point

PB0  unused     MUXA0        (Was gain)
PB1  unused     MUXA1        (Was gain)
PB2  unused     -
PB3  unused     -

PC0  unused     -
PC1  unused     -
PC2             RXDC         Serial Rx
PC3             TXDC         Serial Tx  
PC4  unused     -
PC5  unused     -
PC6  unused     -
PC7  unused     -

PD0             PWM          PWM
PD1  unused     -
PD2  unused     RXDD         Future expansion IRDA
PD3  unused     TXDD         Future expansion IRDA
PD4  unused     SDD          Future expansion IRDA
PD5  unused     -
PD6  unused     -
PD7  LED        STATUS       High true

PE0  GAIN_IN0   SDA
PE1  GAIN_IN1   SCL
PE2  unused     -
PE3  unused     -

PR0             XTAL2
PR1             XTAL1
```

## About ADC

The ADC is configured for:
* Differential input on PA0 (+) and PA2 (-)
* 12-bit signed output in the range -2048 ... 2047.
* Switchable gain.
* Internal voltage reference is the 1V bandgap

The ADC's differential inputs must not exceed the internal voltage reference of
1.0 v.  Vinn sits around 0.0v ("noise"), Vinp ramps from 0.0v to 1.0 v (signal +
noise), so this condition is satisfied.

Since the ADC is in differential mode:
* When configured for no gain stage, Vinn MUST be on PA0 PA1 PA2 or PA3
* When configured with gain, Vinn MUST be on PA4 PA5 PA6 or PA7

Note that Vinn connects to both PA2 and PA4, so we can switch between these two
modes:

To configure gain = 1:
```
ADCA.CH0.CTRL = ADC_CH_GAIN_1X_gc | ADC_CH_INPUTMODE_DIFF_gc;
ADCA.CH0.MUXCTRL = ADC_CH_MUXPOS_PIN0_gc | ADC_CH_MUXNEG_PIN2_gc;
```

To configure gain = 4
```
ADCA.CH0.CTRL = ADC_CH_GAIN_4X_gc | ADC_CH_INPUTMODE_DIFFWGAIN_gc;
ADCA.CH0.MUXCTRL = ADC_CH_MUXPOS_PIN0_gc | ADC_CH_MUXNEG_PIN4_gc;
```

To configure gain = 16
```
ADCA.CH0.CTRL = ADC_CH_GAIN_16X_gc | ADC_CH_INPUTMODE_DIFFWGAIN_gc;
ADCA.CH0.MUXCTRL = ADC_CH_MUXPOS_PIN0_gc | ADC_CH_MUXNEG_PIN4_gc;
```
