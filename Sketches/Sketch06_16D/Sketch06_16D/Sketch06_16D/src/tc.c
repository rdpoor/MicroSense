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
int8_t TIMER_0_init()
{

	// AWEXC.CTRL = 0 << AWEX_PGM_bp /* Pattern Generation Mode: disabled */
	//		 | 0 << AWEX_CWCM_bp /* Common Waveform Channel Mode: disabled */;

	// AWEXC.FDEMASK = 0x0; /* Fault Detection Event Mask: 0x0 */

	// AWEXC.FDCTRL = 0 << AWEX_FDDBD_bp /* Fault Detect on Debug break detection: disabled */
	//		 | 0 << AWEX_FDMODE_bp /* Fault Detect Mode: disabled */
	//		 | TC_AWEX_FDACT_NONE_gc; /* No Fault Protection */

	// AWEXC.DTBOTH = 0x0; /* Dead Time Both Sides: 0x0 */

	// AWEXC.DTBOTHBUF = 0x0; /* Dead Time Both Sides Buffer: 0x0 */

	// AWEXC.DTLS = 0x0; /* Dead Time Low Side: 0x0 */

	// AWEXC.DTHS = 0x0; /* Dead Time High Side: 0x0 */

	// AWEXC.DTLSBUF = 0x0; /* Dead Time Low Side Buffer: 0x0 */

	// AWEXC.DTHSBUF = 0x0; /* Dead Time High Side Buffer: 0x0 */

	// AWEXC.OUTOVEN = 0x0; /* Output Override Enable: 0x0 */

	return 0;
}
