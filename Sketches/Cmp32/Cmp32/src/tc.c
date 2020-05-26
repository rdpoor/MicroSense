/**
 * \file
 *
 * \brief TC related functionality implementation.
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
 */

/**
 * \addtogroup doc_driver_tc
 *
 * \section doc_driver_tc_rev Revision History
 * - v0.0.0.1 Initial Commit
 *
 *@{
 */
#include <tc.h>

/**
 * \brief Initialize tc interface
 * \return Initialization status.
 */
int8_t TIMER_LO_init()
{

	TCC0.CTRLB = 0 << TC0_CCDEN_bp      /* Compare or Capture D Enable: disabled */
	             | 0 << TC0_CCCEN_bp    /* Compare or Capture C Enable: disabled */
	             | 0 << TC0_CCBEN_bp    /* Compare or Capture B Enable: disabled */
	             | 1 << TC0_CCAEN_bp    /* Compare or Capture A Enable: enabled */
	             | TC_WGMODE_NORMAL_gc; /* Normal Mode */

	// TCC0.CTRLC = 0 << TC0_CMPD_bp /* Compare D Output Value: disabled */
	//		 | 0 << TC0_CMPC_bp /* Compare C Output Value: disabled */
	//		 | 0 << TC0_CMPB_bp /* Compare B Output Value: disabled */
	//		 | 0 << TC0_CMPA_bp /* Compare A Output Value: disabled */;

	TCC0.CTRLD = TC_EVACT_PW_gc      /* Pulse-width Capture */
	             | 0 << TC0_EVDLY_bp /* Event Delay: disabled */
	             | TC_EVSEL_CH0_gc;  /* Event Channel 0 */

	// TCC0.CTRLE = 0; /* Byte Mode: 0 */

	TCC0.INTCTRLB = TC_CCDINTLVL_OFF_gc   /* Interrupt Disabled */
	                | TC_CCCINTLVL_OFF_gc /* Interrupt Disabled */
	                | TC_CCBINTLVL_OFF_gc /* Interrupt Disabled */
	                | TC_CCAINTLVL_LO_gc /* Low Level */;

	TCC0.INTCTRLA = TC_ERRINTLVL_LO_gc     /* Low Level */
	                | TC_OVFINTLVL_OFF_gc; /* Interrupt Disabled */

	// TCC0.CCA = 0x0 /* Compare or Capture A: 0x0 */;

	// TCC0.CCB = 0x0 /* Compare or Capture B: 0x0 */;

	// TCC0.CCC = 0x0; /* Compare or Capture C: 0x0 */

	// TCC0.CCD = 0x0; /* Compare or Capture D: 0x0 */

	// TCC0.CNT = 0x0; /* Count: 0x0 */

	// TCC0.PER = 0xffff; /* Period: 0xffff */

	TCC0.CTRLA = TC_CLKSEL_DIV1_gc; /* System Clock */

	return 0;
}

/**
 * \brief Initialize tc interface
 * \return Initialization status.
 */
int8_t TIMER_HI_init()
{

	TCC1.CTRLB = 0 << TC1_CCBEN_bp      /* Compare or Capture B Enable: disabled */
	             | 1 << TC1_CCAEN_bp    /* Compare or Capture A Enable: enabled */
	             | TC_WGMODE_NORMAL_gc; /* Normal Mode */

	// TCC1.CTRLC = 0 << TC1_CMPB_bp /* Compare B Output Value: disabled */
	//		 | 0 << TC1_CMPA_bp; /* Compare A Output Value: disabled */

	TCC1.CTRLD = TC_EVACT_PW_gc      /* Pulse-width Capture */
	             | 1 << TC1_EVDLY_bp /* Event Delay: enabled */
	             | TC_EVSEL_CH0_gc;  /* Event Channel 0 */

	// TCC1.CTRLE = 0; /* Byte Mode: 0 */

	// TCC1.INTCTRLB = TC_CCBINTLVL_OFF_gc /* Interrupt Disabled */
	//		 | TC_CCAINTLVL_OFF_gc; /* Interrupt Disabled */

	// TCC1.INTCTRLA = TC_ERRINTLVL_OFF_gc /* Interrupt Disabled */
	//		 | TC_OVFINTLVL_OFF_gc; /* Interrupt Disabled */

	// TCC1.CCA = 0x0; /* Compare or Capture A: 0x0 */

	// TCC1.CCB = 0x0; /* Compare or Capture B: 0x0 */

	// TCC1.CNT = 0x0; /* Count: 0x0 */

	// TCC1.PER = 0xffff; /* Period: 0xffff */

	TCC1.CTRLA = TC_CLKSEL_EVCH1_gc; /* Event Channel 1 */

	return 0;
}