/**
 * \file
 *
 * \brief Analog Comparator related functionality implementation.
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
 * \defgroup doc_driver_ac_init AC Init Driver
 * \ingroup doc_driver_ac
 *
 * \section doc_driver_ac_rev Revision History
 * - v0.0.0.1 Initial Commit
 *
 *@{
 */
#include <ac.h>

/**
 * \brief Initialize Analog Comparator
 *
 * \return Initialization status.
 */
int8_t AC_0_init()
{

	ACA.AC0MUXCTRL = AC_MUXNEG_PIN1_gc    /* Pin 1 */
	                 | AC_MUXPOS_PIN2_gc; /* Pin 2 */

	// ACA.AC1MUXCTRL = AC_MUXNEG_PIN0_gc /* Pin 0 */
	//		 | AC_MUXPOS_PIN0_gc; /* Pin 0 */

	ACA.CTRLA = 1 << AC_AC0OUT_bp /* Analog Comparator 0 Output Enable: enabled */;

	// ACA.CTRLB = 0; /* VCC Voltage Scaler Factor: 0 */

	// ACA.WINCTRL = AC_WINTLVL_OFF_gc /* Interrupt disabled */
	//		 | AC_WINTMODE_ABOVE_gc /* Interrupt on above window */
	//		 | 0 << AC_WEN_bp; /* Window Mode Enable: disabled */

	ACA.AC0CTRL = 1 << AC_ENABLE_bp       /* Enable: enabled */
	              | AC_HYSMODE_SMALL_gc   /* Small hysteresis */
	              | 0 << AC_HSMODE_bp     /* High-speed Mode: disabled */
	              | AC_INTLVL_LO_gc       /* Low level */
	              | AC_INTMODE_RISING_gc; /* Interrupt on rising edge */

	// ACA.AC1CTRL = 0 << AC_ENABLE_bp /* Enable: disabled */
	//		 | AC_HYSMODE_NO_gc /* No hysteresis */
	//		 | 0 << AC_HSMODE_bp /* High-speed Mode: disabled */
	//		 | AC_INTLVL_OFF_gc /* Interrupt disabled */
	//		 | AC_INTMODE_BOTHEDGES_gc; /* Interrupt on both edges */

	return 0;
}
