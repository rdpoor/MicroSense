/**
 * \file
 *
 * \brief ADC related functionality implementation.
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
 * \defgroup doc_driver_adc_init ADC Init Driver
 * \ingroup doc_driver_adc
 *
 * \section doc_driver_adc_rev Revision History
 * - v0.0.0.1 Initial Commit
 *
 *@{
 */

#include <adc.h>

/**
 * \brief Initialize adc interface
 * \return Initialization status.
 */
int8_t ADC_0_init()
{

	// ADCA.CAL = 0x0; /* Calibration Value: 0x0 */

	// ADCA.CH0.CTRL = ADC_CH_GAIN_1X_gc /* 1x gain */
	//		 | ADC_CH_INPUTMODE_INTERNAL_gc; /* Internal inputs, no gain */

	ADCA.CH0.MUXCTRL = ADC_CH_MUXINT_TEMP_gc    /* Temperature Reference */
	                   | ADC_CH_MUXNEG_PIN4_gc; /* Input pin 4 (Input Mode = 3) */

	ADCA.CH0.INTCTRL = ADC_CH_INTMODE_COMPLETE_gc /* Interrupt on conversion complete */
	                   | ADC_CH_INTLVL_LO_gc;     /* Low level */

	// ADCA.CH0.SCAN = 0x0 << ADC_CH_COUNT_gp; /* Number of Channels included in scan: 0x0 */

	ADCA.CTRLB = ADC_CURRLIMIT_NO_gc        /* No limit */
	             | 1 << ADC_CONMODE_bp      /* Conversion Mode: enabled */
	             | 0 << ADC_FREERUN_bp      /* Free Running Mode Enable: disabled */
	             | ADC_RESOLUTION_12BIT_gc; /* 12-bit right-adjusted result */

	// ADCA.EVCTRL = ADC_EVSEL_0123_gc /* Event Channel 0,1,2,3 */
	//		 | ADC_EVACT_NONE_gc; /* No event action */

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
