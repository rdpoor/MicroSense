/**
 * \file
 *
 * \brief ADC Basic driver implementation.
 *
 (c) 2018 Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms,you may use this software and
    any derivatives exclusively with Microchip products.It is your responsibility
    to comply with third party license terms applicable to your use of third party
    software (including open source software) that may accompany Microchip software.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

/**
 * \defgroup doc_driver_adc_basic ADC Basic Driver
 * \ingroup doc_driver_adc
 *
 * \section doc_driver_adc_rev Revision History
 * - v0.0.0.1 Initial Commit
 *
 *@{
 */
#include <adc_basic.h>

/** Function pointer to callback function called by IRQ.
    NULL=default value: No callback function is to be used.
*/
adc_irq_cb_t ADC_0_cb = NULL; /**
                               * \brief Initialize ADC interface
                               * If module is configured to disabled state, the clock to the ADC is disabled
                               * if this is supported by the device's clock system.
                               *
                               * \return Initialization status.
                               * \retval 0 the ADC init was successful
                               * \retval 1 the ADC init was not successful
                               */
int8_t ADC_0_init()
{

	// ADCA.CAL = 0x0; /* Calibration Value: 0x0 */

	ADCA.CH0.CTRL = ADC_CH_GAIN_1X_gc           /* 1x gain */
	                | ADC_CH_INPUTMODE_DIFF_gc; /* Differential input, no gain */

	ADCA.CH0.MUXCTRL = ADC_CH_MUXPOS_PIN0_gc    /* Input pin 0 */
	                   | ADC_CH_MUXNEG_PIN2_gc; /* Input pin 2 (Input Mode = 2) */

	ADCA.CH0.INTCTRL = ADC_CH_INTMODE_COMPLETE_gc /* Interrupt on conversion complete */
	                   | ADC_CH_INTLVL_LO_gc;     /* Low level */

	// ADCA.CH0.SCAN = 0x0 << ADC_CH_COUNT_gp; /* Number of Channels included in scan: 0x0 */

	// ADCA.CTRLB = ADC_CURRLIMIT_NO_gc /* No limit */
	//		 | 0 << ADC_CONMODE_bp /* Conversion Mode: disabled */
	//		 | 0 << ADC_FREERUN_bp /* Free Running Mode Enable: disabled */
	//		 | ADC_RESOLUTION_12BIT_gc; /* 12-bit right-adjusted result */

	ADCA.EVCTRL = ADC_EVSEL_0123_gc   /* Event Channel 0,1,2,3 */
	              | ADC_EVACT_CH0_gc; /* First event triggers channel 0 */

	// ADCA.SAMPCTRL = 0x0 << ADC_SAMPVAL_gp; /* Sampling Time Control: 0x0 */

	// ADCA.REFCTRL = ADC_REFSEL_INT1V_gc /* Internal 1V */
	//		 | 0 << ADC_BANDGAP_bp /* Bandgap enable: disabled */
	//		 | 0 << ADC_TEMPREF_bp; /* Temperature Reference Enable: disabled */

	// ADCA.PRESCALER = ADC_PRESCALER_DIV4_gc; /* Divide clock by 4 */

	// ADCA.CMP = 0x0; /* Compare Value: 0x0 */

	ADCA.CTRLA = 0 << ADC_FLUSH_bp /* Flush Pipeline: disabled */
	             | 1 << ADC_ENABLE_bp /* Enable ADC: enabled */;

	return 0;
}

/**
 * \brief Enable ADC_0
 * 1. If supported by the clock system, enables the clock to the ADC
 * 2. Enables the ADC module by setting the enable-bit in the ADC control register
 *
 * \return Nothing
 */
void ADC_0_enable()
{
	ADCA.CTRLA |= ADC_ENABLE_bm;
}
/**
 * \brief Disable ADC_0
 * 1. Disables the ADC module by clearing the enable-bit in the ADC control register
 * 2. If supported by the clock system, disables the clock to the ADC
 *
 * \return Nothing
 */
void ADC_0_disable()
{
	ADCA.CTRLA &= ~ADC_ENABLE_bm;
}

/**
 * \brief Start a conversion on ADC_0
 *
 * \param[in] channel The ADC channel to start conversion on
 *
 * \return Nothing
 */
void ADC_0_start_conversion(adc_0_channel_t channel)
{
	ADCA.CH0.MUXCTRL = channel << ADC_CH_MUXPOS_gp;
	ADCA.CH0.CTRL    = ADC_CH_INPUTMODE_SINGLEENDED_gc;
	ADCA.CH0.CTRL |= ADC_CH_START_bm;
}

/**
 * \brief Check if the ADC conversion is done
 *
 * \return The status of ADC converison done check
 * \retval true The ADC conversion is done
 * \retval false The ADC converison is not done
 */
bool ADC_0_is_conversion_done()
{
	return (ADCA.INTFLAGS & ADC_CH0IF_bm);
}

/**
 * \brief Read a conversion result from ADC_0
 *
 * \return Conversion result read from the ADC_0 ADC module
 */
adc_result_t ADC_0_get_conversion_result(void)
{
	return (ADCA.CH0RES);
}

/**
 * \brief Start a conversion, wait until ready, and return the conversion result
 *
 * \return Conversion result read from the ADC_0 ADC module
 */
adc_result_t ADC_0_get_conversion(adc_0_channel_t channel)
{
	adc_result_t res;

	ADC_0_start_conversion(channel);
	while (!ADC_0_is_conversion_done())
		;
	res           = ADC_0_get_conversion_result();
	ADCA.INTFLAGS = ADC_CH0IF_bm;
	return res;
}

/**
 * \brief Return the number of bits in the ADC conversion result
 *
 * \return The number of bits in the ADC conversion result
 */
uint8_t ADC_0_get_resolution()
{
	return (ADCA.CTRLA & ADC_RESOLUTION_gm) ? 12 : 8;
}

/**
 * \brief Register a callback function to be called at the end of the ADC ISR.
 *
 * \param[in] f Pointer to function to be called
 *
 * \return Nothing.
 */
void ADC_0_register_callback(adc_irq_cb_t f)
{
	ADC_0_cb = f;
}

ISR(ADCA_CH0_vect)
{
	// Clear the interrupt flag
	ADCA.INTFLAGS = ADC_CH0IF_bm;

	if (ADC_0_cb != NULL) {
		ADC_0_cb();
	}
}
