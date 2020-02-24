/**
 * \file
 *
 * \brief Driver initialization.
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

/*
 * Code generated by START.
 *
 * This file will be overwritten when reconfiguring your START project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <system.h>

/* configure pins and initialize registers */
void SLEEP_initialization(void)
{
	SLEEP_init();
}

void EVENT_SYSTEM_0_initialization(void)
{

	EVENT_SYSTEM_0_init();
}

/* configure pins and initialize registers */
void AC_0_initialization(void)
{

	// Disable pull-up resistor
	PA1_set_output_pull_mode(PORT_CONFIGURATION_TOTEM);
	// Disable digital         // Disable digital input buffer
	PA1_set_isc(PORT_ISC_INPUT_DISABLE_gc);

	// Disable pull-up resistor
	PA3_set_output_pull_mode(PORT_CONFIGURATION_TOTEM);
	// Disable digital         // Disable digital input buffer
	PA3_set_isc(PORT_ISC_INPUT_DISABLE_gc);

	AC_0_init();
}

/**
 * \brief System initialization
 */
void system_init()
{
	mcu_init();

	OSC_init();

	CLK_init();

	PMIC_init();

	SLEEP_initialization();

	EVENT_SYSTEM_0_initialization();

	AC_0_init();
}