/**
 * \file
 *
 * \brief USART basic driver.
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
 * \defgroup doc_driver_usart_basic USART Basic
 * \ingroup doc_driver_usart
 *
 * \section doc_driver_usart_basic_rev Revision History
 * - v0.0.0.1 Initial Commit
 *
 *@{
 */
#include <compiler.h>
#include <clock_config.h>
#include <usart_basic.h>
#include <atomic.h>

#include <stdio.h>

#if defined(__GNUC__)

int EDBG_printCHAR(char character, FILE *stream)
{
	EDBG_write(character);
	return 0;
}

FILE EDBG_stream = FDEV_SETUP_STREAM(EDBG_printCHAR, NULL, _FDEV_SETUP_WRITE);

#elif defined(__ICCAVR__)

int putchar(int outChar)
{
	USART_0_write(outChar);
	return outChar;
}
#endif

/* Static Variables holding the ringbuffer used in IRQ mode */
static uint8_t          EDBG_rxbuf[EDBG_RX_BUFFER_SIZE];
static volatile uint8_t EDBG_rx_head;
static volatile uint8_t EDBG_rx_tail;
static volatile uint8_t EDBG_rx_elements;
static uint8_t          EDBG_txbuf[EDBG_TX_BUFFER_SIZE];
static volatile uint8_t EDBG_tx_head;
static volatile uint8_t EDBG_tx_tail;
static volatile uint8_t EDBG_tx_elements;

void EDBG_default_rx_isr_cb(void);
void (*EDBG_rx_isr_cb)(void) = &EDBG_default_rx_isr_cb;
void EDBG_default_udre_isr_cb(void);
void (*EDBG_udre_isr_cb)(void) = &EDBG_default_udre_isr_cb;

void EDBG_default_rx_isr_cb(void)
{
	uint8_t data;
	uint8_t tmphead;

	/* Read the received data */
	data = USARTE0.DATA;
	/* Calculate buffer index */
	tmphead = (EDBG_rx_head + 1) & EDBG_RX_BUFFER_MASK;

	if (tmphead == EDBG_rx_tail) {
		/* ERROR! Receive buffer overflow */
	} else {
		/* Store new index */
		EDBG_rx_head = tmphead;

		/* Store received data in buffer */
		EDBG_rxbuf[tmphead] = data;
		EDBG_rx_elements++;
	}
}

void EDBG_default_udre_isr_cb(void)
{
	uint8_t tmptail;

	/* Check if all data is transmitted */
	if (EDBG_tx_elements != 0) {
		/* Calculate buffer index */
		tmptail = (EDBG_tx_tail + 1) & EDBG_TX_BUFFER_MASK;
		/* Store new index */
		EDBG_tx_tail = tmptail;
		/* Start transmission */
		USARTE0.DATA = EDBG_txbuf[tmptail];
		EDBG_tx_elements--;
	}

	if (EDBG_tx_elements == 0) {
		/* Disable UDRE interrupt */
		USARTE0.CTRLA &= ~(USART_DREINTLVL_gm);
	}
}

/**
 * \brief Set call back function for EDBG
 *
 * \param[in] cb The call back function to set
 *
 * \param[in] type The type of ISR to be set
 *
 * \return Nothing
 */
void EDBG_set_ISR_cb(usart_cb_t cb, usart_cb_type_t type)
{
	switch (type) {
	case RX_CB:
		EDBG_rx_isr_cb = cb;
		break;
	case UDRE_CB:
		EDBG_udre_isr_cb = cb;
		break;
	default:
		// do nothing
		break;
	}
}

/* Interrupt service routine for RX complete */
ISR(USARTE0_RXC_vect)
{
	if (EDBG_rx_isr_cb != NULL)
		(*EDBG_rx_isr_cb)();
}

/* Interrupt service routine for Data Register Empty */
ISR(USARTE0_DRE_vect)
{
	if (EDBG_udre_isr_cb != NULL)
		(*EDBG_udre_isr_cb)();
}

bool EDBG_is_tx_ready()
{
	return (EDBG_tx_elements != EDBG_TX_BUFFER_SIZE);
}

bool EDBG_is_rx_ready()
{
	return (EDBG_rx_elements != 0);
}

bool EDBG_is_tx_busy()
{
	return (!(USARTE0.STATUS & USART_TXCIF_bm));
}

/**
 * \brief Read one character from EDBG
 *
 * Function will block if a character is not available.
 *
 * \return Data read from the EDBG module
 */
uint8_t EDBG_read(void)
{
	uint8_t tmptail;

	/* Wait for incoming data */
	while (EDBG_rx_elements == 0)
		;
	/* Calculate buffer index */
	tmptail = (EDBG_rx_tail + 1) & EDBG_RX_BUFFER_MASK;
	/* Store new index */
	EDBG_rx_tail = tmptail;
	ENTER_CRITICAL(R);
	EDBG_rx_elements--;
	EXIT_CRITICAL(R);

	/* Return data */
	return EDBG_rxbuf[tmptail];
}

/**
 * \brief Write one character to EDBG
 *
 * Function will block until a character can be accepted.
 *
 * \param[in] data The character to write to the USART
 *
 * \return Nothing
 */
void EDBG_write(const uint8_t data)
{
	uint8_t tmphead;

	/* Calculate buffer index */
	tmphead = (EDBG_tx_head + 1) & EDBG_TX_BUFFER_MASK;
	/* Wait for free space in buffer */
	while (EDBG_tx_elements == EDBG_TX_BUFFER_SIZE)
		;
	/* Store data in buffer */
	EDBG_txbuf[tmphead] = data;
	/* Store new index */
	EDBG_tx_head = tmphead;
	ENTER_CRITICAL(W);
	EDBG_tx_elements++;
	EXIT_CRITICAL(W);
	/* Enable UDRE interrupt */
	USARTE0.CTRLA |= USART_DREINTLVL_LO_gc;
}

/**
 * \brief Initialize USART interface
 * If module is configured to disabled state, the clock to the USART is disabled
 * if this is supported by the device's clock system.
 *
 * \return Initialization status.
 * \retval 0 the USART init was successful
 * \retval 1 the USART init was not successful
 */
int8_t EDBG_init()
{

	int8_t   exp;
	uint32_t div;
	uint32_t limit;
	uint32_t ratio;
	uint32_t min_rate;
	uint32_t max_rate;

	uint32_t cpu_hz = F_CPU;
	uint32_t baud   = 115200;

	/*
	 * Check if the hardware supports the given baud rate
	 */
	/* 8 = (2^0) * 8 * (2^0) = (2^BSCALE_MIN) * 8 * (BSEL_MIN) */
	max_rate = cpu_hz / 8;
	/* 4194304 = (2^7) * 8 * (2^12) = (2^BSCALE_MAX) * 8 * (BSEL_MAX+1) */
	min_rate = cpu_hz / 4194304;

	/* double speed is disabled. */
	max_rate /= 2;
	min_rate /= 2;

	if ((baud > max_rate) || (baud < min_rate)) {
		/* the hardware doesn't supports the given baud rate */
		return -1;
	}

	/* double speed is disabled. */
	baud *= 2;

	/* Find the lowest possible exponent. */
	limit = 0xfffU >> 4;
	ratio = cpu_hz / baud;

	for (exp = -7; exp < 7; exp++) {
		if (ratio < limit) {
			break;
		}

		limit <<= 1;

		if (exp < -3) {
			limit |= 1;
		}
	}

	/*
	 * Depending on the value of exp, scale either the input frequency or
	 * the target baud rate. By always scaling upwards, we never introduce
	 * any additional inaccuracy.
	 *
	 * We are including the final divide-by-8 (aka. right-shift-by-3) in
	 * this operation as it ensures that we never exceeed 2**32 at any
	 * point.
	 *
	 * The formula for calculating BSEL is slightly different when exp is
	 * negative than it is when exp is positive.
	 */
	if (exp < 0) {
		/* We are supposed to subtract 1, then apply BSCALE. We want to
		 * apply BSCALE first, so we need to turn everything inside the
		 * parenthesis into a single fractional expression.
		 */
		cpu_hz -= 8 * baud;

		/* If we end up with a left-shift after taking the final
		 * divide-by-8 into account, do the shift before the divide.
		 * Otherwise, left-shift the denominator instead (effectively
		 * resulting in an overall right shift.)
		 */
		if (exp <= -3) {
			div = ((cpu_hz << (-exp - 3)) + baud / 2) / baud;
		} else {
			baud <<= exp + 3;
			div = (cpu_hz + baud / 2) / baud;
		}
	} else {
		/* We will always do a right shift in this case, but we need to
		 * shift three extra positions because of the divide-by-8.
		 */
		baud <<= exp + 3;
		div = (cpu_hz + baud / 2) / baud - 1;
	}

	USARTE0.BAUDCTRLB = (uint8_t)(((div >> 8) & 0X0F) | (exp << 4));
	USARTE0.BAUDCTRLA = (uint8_t)div;

	USARTE0.CTRLA = USART_RXCINTLVL_LO_gc    /* Low Level */
	                | USART_TXCINTLVL_OFF_gc /* Off */
	                | USART_DREINTLVL_LO_gc; /* Low Level */

	// USARTE0.CTRLC = USART_PMODE_DISABLED_gc /* No Parity */
	//		 | 0 << USART_SBMODE_bp /* Stop Bit Mode: disabled */
	//		 | USART_CHSIZE_8BIT_gc /* Character size: 8 bit */
	//		 | 0 << USART_CHSIZE2_bp /* SPI Master Mode, Data Order: disabled */
	//		 | 1 << USART_CHSIZE1_bp /* SPI Master Mode, Clock Phase: enabled */
	//		 | USART_CMODE_ASYNCHRONOUS_gc; /* Async IRQ Mode */

	USARTE0.CTRLB = 0 << USART_CLK2X_bp   /* Double transmission speed: disabled */
	                | 0 << USART_MPCM_bp  /* Multi-processor Communication Mode: disabled */
	                | 1 << USART_RXEN_bp  /* Receiver Enable: enabled */
	                | 1 << USART_TXEN_bp; /* Transmitter Enable: enabled */

	uint8_t x;

	/* Initialize ringbuffers */
	x = 0;

	EDBG_rx_tail     = x;
	EDBG_rx_head     = x;
	EDBG_rx_elements = x;
	EDBG_tx_tail     = x;
	EDBG_tx_head     = x;
	EDBG_tx_elements = x;

#if defined(__GNUC__)
	stdout = &EDBG_stream;
#endif

	return 0;
}

/**
 * \brief Enable RX and TX in EDBG
 * 1. If supported by the clock system, enables the clock to the USART
 * 2. Enables the USART module by setting the RX and TX enable-bits in the USART control register
 *
 * \return Nothing
 */
void EDBG_enable()
{
	USARTE0.CTRLB |= USART_RXEN_bm | USART_TXEN_bm;
}

/**
 * \brief Enable RX in EDBG
 * 1. If supported by the clock system, enables the clock to the USART
 * 2. Enables the USART module by setting the RX enable-bit in the USART control register
 *
 * \return Nothing
 */
void EDBG_enable_rx()
{
	USARTE0.CTRLB |= USART_RXEN_bm;
}

/**
 * \brief Enable TX in EDBG
 * 1. If supported by the clock system, enables the clock to the USART
 * 2. Enables the USART module by setting the TX enable-bit in the USART control register
 *
 * \return Nothing
 */
void EDBG_enable_tx()
{
	USARTE0.CTRLB |= USART_TXEN_bm;
}

/**
 * \brief Disable EDBG
 * 1. Disables the USART module by clearing the enable-bit(s) in the USART control register
 * 2. If supported by the clock system, disables the clock to the USART
 *
 * \return Nothing
 */
void EDBG_disable()
{
	USARTE0.CTRLB &= ~(USART_RXEN_bm | USART_TXEN_bm);
}

/**
 * \brief Get recieved data from EDBG
 *
 * \return Data register from EDBG module
 */
uint8_t EDBG_get_data()
{
	return USARTE0.DATA;
}
