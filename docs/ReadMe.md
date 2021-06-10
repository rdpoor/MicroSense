# SoulPhone notes

## Documentation links

* [Overview](https://www.microchip.com/wwwproducts/en/ATxmega128D4)
* [Atmel AVR XMEGA D - Complete Datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-8210-8-and-16-bit-AVR-Microcontrollers-XMEGA-D_Manual.pdf)
* [ATxmega128D4/64D4/32D4/16D4 - Complete Datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-8135-8-and-16-bit-AVR-microcontroller-ATxmega16D4-32D4-64D4-128D4_datasheet.pdf)
* [Differential and Single-Ended ADC](https://ww1.microchip.com/downloads/en/DeviceDoc/Differential-and-Single-Ended-ADC-WhitePaper-DS00003197A.pdf)

## On Units

The SoulPhone firmware emits a string on the serial line once every 250 mSec,
or more precisely, once every 15 complete samples.  (Some samples may be dropped
if the 60Hz sync pulse is absent.)

The third column is an indication of the conductance between the electrodes.

Assuming 0 volts on Vinn (aka V_REF), a 1 volt output on Vinp (aka V_OUT)
results in an ADC count of 2047.  The resulting string on the serial output
is therefore:

   V_OUT (avg) = column_3 / (2047 * 15)

Note: a future version of the code will support variable gain, in which case
the gain factor must be taken into account.
