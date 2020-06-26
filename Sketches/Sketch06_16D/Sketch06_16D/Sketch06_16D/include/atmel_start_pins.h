/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef ATMEL_START_PINS_H_INCLUDED
#define ATMEL_START_PINS_H_INCLUDED

#include <port.h>

/**
 * \brief Set ADC_1 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void ADC_1_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTA_set_pin_output_pull_mode(1, output_pull_mode);
}

/**
 * \brief Set ADC_1 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void ADC_1_set_dir(const enum port_dir dir)
{
	PORTA_set_pin_dir(1, dir);
}

/**
 * \brief Set ADC_1 input/sense configuration
 *
 * Enable/disable ADC_1 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void ADC_1_set_isc(const PORT_ISC_t isc)
{
	PORTA_pin_set_isc(1, isc);
}

/**
 * \brief Set ADC_1 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on ADC_1 is inverted
 *                     false = I/O on ADC_1 is not inverted
 */
static inline void ADC_1_set_inverted(const bool inverted)
{
	PORTA_pin_set_inverted(1, inverted);
}

/**
 * \brief Set ADC_1 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void ADC_1_set_level(const bool level)
{
	PORTA_set_pin_level(1, level);
}

/**
 * \brief Toggle output level on ADC_1
 *
 * Toggle the pin level
 */
static inline void ADC_1_toggle_level()
{
	PORTA_toggle_pin_level(1);
}

/**
 * \brief Get level on ADC_1
 *
 * Reads the level on a pin
 */
static inline bool ADC_1_get_level()
{
	return PORTA_get_pin_level(1);
}

/**
 * \brief Set ADC_1 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void ADC_1_int_level(const uint8_t level)
{
	PORTA_set_int_level(level);
}

/**
 * \brief Set ADC_1 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void ADC_1_int0_mask(const uint8_t value)
{
	PORTA_write_int0_mask(value);
}

/**
 * \brief Set ADC_1 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void ADC_1_int1_mask(const uint8_t value)
{
	PORTA_write_int1_mask(value);
}

/**
 * \brief Set V_SYNC output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void V_SYNC_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTA_set_pin_output_pull_mode(3, output_pull_mode);
}

/**
 * \brief Set V_SYNC data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void V_SYNC_set_dir(const enum port_dir dir)
{
	PORTA_set_pin_dir(3, dir);
}

/**
 * \brief Set V_SYNC input/sense configuration
 *
 * Enable/disable V_SYNC digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void V_SYNC_set_isc(const PORT_ISC_t isc)
{
	PORTA_pin_set_isc(3, isc);
}

/**
 * \brief Set V_SYNC inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on V_SYNC is inverted
 *                     false = I/O on V_SYNC is not inverted
 */
static inline void V_SYNC_set_inverted(const bool inverted)
{
	PORTA_pin_set_inverted(3, inverted);
}

/**
 * \brief Set V_SYNC level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void V_SYNC_set_level(const bool level)
{
	PORTA_set_pin_level(3, level);
}

/**
 * \brief Toggle output level on V_SYNC
 *
 * Toggle the pin level
 */
static inline void V_SYNC_toggle_level()
{
	PORTA_toggle_pin_level(3);
}

/**
 * \brief Get level on V_SYNC
 *
 * Reads the level on a pin
 */
static inline bool V_SYNC_get_level()
{
	return PORTA_get_pin_level(3);
}

/**
 * \brief Set V_SYNC interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void V_SYNC_int_level(const uint8_t level)
{
	PORTA_set_int_level(level);
}

/**
 * \brief Set V_SYNC interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void V_SYNC_int0_mask(const uint8_t value)
{
	PORTA_write_int0_mask(value);
}

/**
 * \brief Set V_SYNC interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void V_SYNC_int1_mask(const uint8_t value)
{
	PORTA_write_int1_mask(value);
}

/**
 * \brief Set ADC_4 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void ADC_4_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTA_set_pin_output_pull_mode(4, output_pull_mode);
}

/**
 * \brief Set ADC_4 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void ADC_4_set_dir(const enum port_dir dir)
{
	PORTA_set_pin_dir(4, dir);
}

/**
 * \brief Set ADC_4 input/sense configuration
 *
 * Enable/disable ADC_4 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void ADC_4_set_isc(const PORT_ISC_t isc)
{
	PORTA_pin_set_isc(4, isc);
}

/**
 * \brief Set ADC_4 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on ADC_4 is inverted
 *                     false = I/O on ADC_4 is not inverted
 */
static inline void ADC_4_set_inverted(const bool inverted)
{
	PORTA_pin_set_inverted(4, inverted);
}

/**
 * \brief Set ADC_4 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void ADC_4_set_level(const bool level)
{
	PORTA_set_pin_level(4, level);
}

/**
 * \brief Toggle output level on ADC_4
 *
 * Toggle the pin level
 */
static inline void ADC_4_toggle_level()
{
	PORTA_toggle_pin_level(4);
}

/**
 * \brief Get level on ADC_4
 *
 * Reads the level on a pin
 */
static inline bool ADC_4_get_level()
{
	return PORTA_get_pin_level(4);
}

/**
 * \brief Set ADC_4 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void ADC_4_int_level(const uint8_t level)
{
	PORTA_set_int_level(level);
}

/**
 * \brief Set ADC_4 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void ADC_4_int0_mask(const uint8_t value)
{
	PORTA_write_int0_mask(value);
}

/**
 * \brief Set ADC_4 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void ADC_4_int1_mask(const uint8_t value)
{
	PORTA_write_int1_mask(value);
}

/**
 * \brief Set V_RESET output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void V_RESET_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTA_set_pin_output_pull_mode(5, output_pull_mode);
}

/**
 * \brief Set V_RESET data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void V_RESET_set_dir(const enum port_dir dir)
{
	PORTA_set_pin_dir(5, dir);
}

/**
 * \brief Set V_RESET input/sense configuration
 *
 * Enable/disable V_RESET digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void V_RESET_set_isc(const PORT_ISC_t isc)
{
	PORTA_pin_set_isc(5, isc);
}

/**
 * \brief Set V_RESET inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on V_RESET is inverted
 *                     false = I/O on V_RESET is not inverted
 */
static inline void V_RESET_set_inverted(const bool inverted)
{
	PORTA_pin_set_inverted(5, inverted);
}

/**
 * \brief Set V_RESET level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void V_RESET_set_level(const bool level)
{
	PORTA_set_pin_level(5, level);
}

/**
 * \brief Toggle output level on V_RESET
 *
 * Toggle the pin level
 */
static inline void V_RESET_toggle_level()
{
	PORTA_toggle_pin_level(5);
}

/**
 * \brief Get level on V_RESET
 *
 * Reads the level on a pin
 */
static inline bool V_RESET_get_level()
{
	return PORTA_get_pin_level(5);
}

/**
 * \brief Set V_RESET interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void V_RESET_int_level(const uint8_t level)
{
	PORTA_set_int_level(level);
}

/**
 * \brief Set V_RESET interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void V_RESET_int0_mask(const uint8_t value)
{
	PORTA_write_int0_mask(value);
}

/**
 * \brief Set V_RESET interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void V_RESET_int1_mask(const uint8_t value)
{
	PORTA_write_int1_mask(value);
}

/**
 * \brief Set TEST_PT_A output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void TEST_PT_A_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTA_set_pin_output_pull_mode(6, output_pull_mode);
}

/**
 * \brief Set TEST_PT_A data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void TEST_PT_A_set_dir(const enum port_dir dir)
{
	PORTA_set_pin_dir(6, dir);
}

/**
 * \brief Set TEST_PT_A input/sense configuration
 *
 * Enable/disable TEST_PT_A digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void TEST_PT_A_set_isc(const PORT_ISC_t isc)
{
	PORTA_pin_set_isc(6, isc);
}

/**
 * \brief Set TEST_PT_A inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on TEST_PT_A is inverted
 *                     false = I/O on TEST_PT_A is not inverted
 */
static inline void TEST_PT_A_set_inverted(const bool inverted)
{
	PORTA_pin_set_inverted(6, inverted);
}

/**
 * \brief Set TEST_PT_A level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void TEST_PT_A_set_level(const bool level)
{
	PORTA_set_pin_level(6, level);
}

/**
 * \brief Toggle output level on TEST_PT_A
 *
 * Toggle the pin level
 */
static inline void TEST_PT_A_toggle_level()
{
	PORTA_toggle_pin_level(6);
}

/**
 * \brief Get level on TEST_PT_A
 *
 * Reads the level on a pin
 */
static inline bool TEST_PT_A_get_level()
{
	return PORTA_get_pin_level(6);
}

/**
 * \brief Set TEST_PT_A interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void TEST_PT_A_int_level(const uint8_t level)
{
	PORTA_set_int_level(level);
}

/**
 * \brief Set TEST_PT_A interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void TEST_PT_A_int0_mask(const uint8_t value)
{
	PORTA_write_int0_mask(value);
}

/**
 * \brief Set TEST_PT_A interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void TEST_PT_A_int1_mask(const uint8_t value)
{
	PORTA_write_int1_mask(value);
}

/**
 * \brief Set MUX_A0 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void MUX_A0_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTB_set_pin_output_pull_mode(0, output_pull_mode);
}

/**
 * \brief Set MUX_A0 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void MUX_A0_set_dir(const enum port_dir dir)
{
	PORTB_set_pin_dir(0, dir);
}

/**
 * \brief Set MUX_A0 input/sense configuration
 *
 * Enable/disable MUX_A0 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void MUX_A0_set_isc(const PORT_ISC_t isc)
{
	PORTB_pin_set_isc(0, isc);
}

/**
 * \brief Set MUX_A0 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on MUX_A0 is inverted
 *                     false = I/O on MUX_A0 is not inverted
 */
static inline void MUX_A0_set_inverted(const bool inverted)
{
	PORTB_pin_set_inverted(0, inverted);
}

/**
 * \brief Set MUX_A0 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void MUX_A0_set_level(const bool level)
{
	PORTB_set_pin_level(0, level);
}

/**
 * \brief Toggle output level on MUX_A0
 *
 * Toggle the pin level
 */
static inline void MUX_A0_toggle_level()
{
	PORTB_toggle_pin_level(0);
}

/**
 * \brief Get level on MUX_A0
 *
 * Reads the level on a pin
 */
static inline bool MUX_A0_get_level()
{
	return PORTB_get_pin_level(0);
}

/**
 * \brief Set MUX_A0 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void MUX_A0_int_level(const uint8_t level)
{
	PORTB_set_int_level(level);
}

/**
 * \brief Set MUX_A0 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void MUX_A0_int0_mask(const uint8_t value)
{
	PORTB_write_int0_mask(value);
}

/**
 * \brief Set MUX_A0 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void MUX_A0_int1_mask(const uint8_t value)
{
	PORTB_write_int1_mask(value);
}

/**
 * \brief Set MUX_A1 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void MUX_A1_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTB_set_pin_output_pull_mode(1, output_pull_mode);
}

/**
 * \brief Set MUX_A1 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void MUX_A1_set_dir(const enum port_dir dir)
{
	PORTB_set_pin_dir(1, dir);
}

/**
 * \brief Set MUX_A1 input/sense configuration
 *
 * Enable/disable MUX_A1 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void MUX_A1_set_isc(const PORT_ISC_t isc)
{
	PORTB_pin_set_isc(1, isc);
}

/**
 * \brief Set MUX_A1 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on MUX_A1 is inverted
 *                     false = I/O on MUX_A1 is not inverted
 */
static inline void MUX_A1_set_inverted(const bool inverted)
{
	PORTB_pin_set_inverted(1, inverted);
}

/**
 * \brief Set MUX_A1 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void MUX_A1_set_level(const bool level)
{
	PORTB_set_pin_level(1, level);
}

/**
 * \brief Toggle output level on MUX_A1
 *
 * Toggle the pin level
 */
static inline void MUX_A1_toggle_level()
{
	PORTB_toggle_pin_level(1);
}

/**
 * \brief Get level on MUX_A1
 *
 * Reads the level on a pin
 */
static inline bool MUX_A1_get_level()
{
	return PORTB_get_pin_level(1);
}

/**
 * \brief Set MUX_A1 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void MUX_A1_int_level(const uint8_t level)
{
	PORTB_set_int_level(level);
}

/**
 * \brief Set MUX_A1 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void MUX_A1_int0_mask(const uint8_t value)
{
	PORTB_write_int0_mask(value);
}

/**
 * \brief Set MUX_A1 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void MUX_A1_int1_mask(const uint8_t value)
{
	PORTB_write_int1_mask(value);
}

/**
 * \brief Set SERIAL_RX output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void SERIAL_RX_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTC_set_pin_output_pull_mode(2, output_pull_mode);
}

/**
 * \brief Set SERIAL_RX data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void SERIAL_RX_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(2, dir);
}

/**
 * \brief Set SERIAL_RX input/sense configuration
 *
 * Enable/disable SERIAL_RX digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void SERIAL_RX_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(2, isc);
}

/**
 * \brief Set SERIAL_RX inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on SERIAL_RX is inverted
 *                     false = I/O on SERIAL_RX is not inverted
 */
static inline void SERIAL_RX_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(2, inverted);
}

/**
 * \brief Set SERIAL_RX level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void SERIAL_RX_set_level(const bool level)
{
	PORTC_set_pin_level(2, level);
}

/**
 * \brief Toggle output level on SERIAL_RX
 *
 * Toggle the pin level
 */
static inline void SERIAL_RX_toggle_level()
{
	PORTC_toggle_pin_level(2);
}

/**
 * \brief Get level on SERIAL_RX
 *
 * Reads the level on a pin
 */
static inline bool SERIAL_RX_get_level()
{
	return PORTC_get_pin_level(2);
}

/**
 * \brief Set SERIAL_RX interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void SERIAL_RX_int_level(const uint8_t level)
{
	PORTC_set_int_level(level);
}

/**
 * \brief Set SERIAL_RX interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void SERIAL_RX_int0_mask(const uint8_t value)
{
	PORTC_write_int0_mask(value);
}

/**
 * \brief Set SERIAL_RX interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void SERIAL_RX_int1_mask(const uint8_t value)
{
	PORTC_write_int1_mask(value);
}

/**
 * \brief Set SERIAL_TX output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void SERIAL_TX_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTC_set_pin_output_pull_mode(3, output_pull_mode);
}

/**
 * \brief Set SERIAL_TX data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void SERIAL_TX_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(3, dir);
}

/**
 * \brief Set SERIAL_TX input/sense configuration
 *
 * Enable/disable SERIAL_TX digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void SERIAL_TX_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(3, isc);
}

/**
 * \brief Set SERIAL_TX inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on SERIAL_TX is inverted
 *                     false = I/O on SERIAL_TX is not inverted
 */
static inline void SERIAL_TX_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(3, inverted);
}

/**
 * \brief Set SERIAL_TX level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void SERIAL_TX_set_level(const bool level)
{
	PORTC_set_pin_level(3, level);
}

/**
 * \brief Toggle output level on SERIAL_TX
 *
 * Toggle the pin level
 */
static inline void SERIAL_TX_toggle_level()
{
	PORTC_toggle_pin_level(3);
}

/**
 * \brief Get level on SERIAL_TX
 *
 * Reads the level on a pin
 */
static inline bool SERIAL_TX_get_level()
{
	return PORTC_get_pin_level(3);
}

/**
 * \brief Set SERIAL_TX interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void SERIAL_TX_int_level(const uint8_t level)
{
	PORTC_set_int_level(level);
}

/**
 * \brief Set SERIAL_TX interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void SERIAL_TX_int0_mask(const uint8_t value)
{
	PORTC_write_int0_mask(value);
}

/**
 * \brief Set SERIAL_TX interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void SERIAL_TX_int1_mask(const uint8_t value)
{
	PORTC_write_int1_mask(value);
}

/**
 * \brief Set PWM_OUT output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void PWM_OUT_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTD_set_pin_output_pull_mode(0, output_pull_mode);
}

/**
 * \brief Set PWM_OUT data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PWM_OUT_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(0, dir);
}

/**
 * \brief Set PWM_OUT input/sense configuration
 *
 * Enable/disable PWM_OUT digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void PWM_OUT_set_isc(const PORT_ISC_t isc)
{
	PORTD_pin_set_isc(0, isc);
}

/**
 * \brief Set PWM_OUT inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on PWM_OUT is inverted
 *                     false = I/O on PWM_OUT is not inverted
 */
static inline void PWM_OUT_set_inverted(const bool inverted)
{
	PORTD_pin_set_inverted(0, inverted);
}

/**
 * \brief Set PWM_OUT level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PWM_OUT_set_level(const bool level)
{
	PORTD_set_pin_level(0, level);
}

/**
 * \brief Toggle output level on PWM_OUT
 *
 * Toggle the pin level
 */
static inline void PWM_OUT_toggle_level()
{
	PORTD_toggle_pin_level(0);
}

/**
 * \brief Get level on PWM_OUT
 *
 * Reads the level on a pin
 */
static inline bool PWM_OUT_get_level()
{
	return PORTD_get_pin_level(0);
}

/**
 * \brief Set PWM_OUT interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void PWM_OUT_int_level(const uint8_t level)
{
	PORTD_set_int_level(level);
}

/**
 * \brief Set PWM_OUT interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void PWM_OUT_int0_mask(const uint8_t value)
{
	PORTD_write_int0_mask(value);
}

/**
 * \brief Set PWM_OUT interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void PWM_OUT_int1_mask(const uint8_t value)
{
	PORTD_write_int1_mask(value);
}

/**
 * \brief Set USR_LED output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void USR_LED_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTD_set_pin_output_pull_mode(7, output_pull_mode);
}

/**
 * \brief Set USR_LED data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void USR_LED_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(7, dir);
}

/**
 * \brief Set USR_LED input/sense configuration
 *
 * Enable/disable USR_LED digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void USR_LED_set_isc(const PORT_ISC_t isc)
{
	PORTD_pin_set_isc(7, isc);
}

/**
 * \brief Set USR_LED inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on USR_LED is inverted
 *                     false = I/O on USR_LED is not inverted
 */
static inline void USR_LED_set_inverted(const bool inverted)
{
	PORTD_pin_set_inverted(7, inverted);
}

/**
 * \brief Set USR_LED level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void USR_LED_set_level(const bool level)
{
	PORTD_set_pin_level(7, level);
}

/**
 * \brief Toggle output level on USR_LED
 *
 * Toggle the pin level
 */
static inline void USR_LED_toggle_level()
{
	PORTD_toggle_pin_level(7);
}

/**
 * \brief Get level on USR_LED
 *
 * Reads the level on a pin
 */
static inline bool USR_LED_get_level()
{
	return PORTD_get_pin_level(7);
}

/**
 * \brief Set USR_LED interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void USR_LED_int_level(const uint8_t level)
{
	PORTD_set_int_level(level);
}

/**
 * \brief Set USR_LED interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void USR_LED_int0_mask(const uint8_t value)
{
	PORTD_write_int0_mask(value);
}

/**
 * \brief Set USR_LED interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void USR_LED_int1_mask(const uint8_t value)
{
	PORTD_write_int1_mask(value);
}

/**
 * \brief Set FUTURE_SDA output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void FUTURE_SDA_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTE_set_pin_output_pull_mode(0, output_pull_mode);
}

/**
 * \brief Set FUTURE_SDA data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void FUTURE_SDA_set_dir(const enum port_dir dir)
{
	PORTE_set_pin_dir(0, dir);
}

/**
 * \brief Set FUTURE_SDA input/sense configuration
 *
 * Enable/disable FUTURE_SDA digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void FUTURE_SDA_set_isc(const PORT_ISC_t isc)
{
	PORTE_pin_set_isc(0, isc);
}

/**
 * \brief Set FUTURE_SDA inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on FUTURE_SDA is inverted
 *                     false = I/O on FUTURE_SDA is not inverted
 */
static inline void FUTURE_SDA_set_inverted(const bool inverted)
{
	PORTE_pin_set_inverted(0, inverted);
}

/**
 * \brief Set FUTURE_SDA level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void FUTURE_SDA_set_level(const bool level)
{
	PORTE_set_pin_level(0, level);
}

/**
 * \brief Toggle output level on FUTURE_SDA
 *
 * Toggle the pin level
 */
static inline void FUTURE_SDA_toggle_level()
{
	PORTE_toggle_pin_level(0);
}

/**
 * \brief Get level on FUTURE_SDA
 *
 * Reads the level on a pin
 */
static inline bool FUTURE_SDA_get_level()
{
	return PORTE_get_pin_level(0);
}

/**
 * \brief Set FUTURE_SDA interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void FUTURE_SDA_int_level(const uint8_t level)
{
	PORTE_set_int_level(level);
}

/**
 * \brief Set FUTURE_SDA interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void FUTURE_SDA_int0_mask(const uint8_t value)
{
	PORTE_write_int0_mask(value);
}

/**
 * \brief Set FUTURE_SDA interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void FUTURE_SDA_int1_mask(const uint8_t value)
{
	PORTE_write_int1_mask(value);
}

/**
 * \brief Set FUTURE_SCL output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void FUTURE_SCL_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTE_set_pin_output_pull_mode(1, output_pull_mode);
}

/**
 * \brief Set FUTURE_SCL data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void FUTURE_SCL_set_dir(const enum port_dir dir)
{
	PORTE_set_pin_dir(1, dir);
}

/**
 * \brief Set FUTURE_SCL input/sense configuration
 *
 * Enable/disable FUTURE_SCL digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void FUTURE_SCL_set_isc(const PORT_ISC_t isc)
{
	PORTE_pin_set_isc(1, isc);
}

/**
 * \brief Set FUTURE_SCL inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on FUTURE_SCL is inverted
 *                     false = I/O on FUTURE_SCL is not inverted
 */
static inline void FUTURE_SCL_set_inverted(const bool inverted)
{
	PORTE_pin_set_inverted(1, inverted);
}

/**
 * \brief Set FUTURE_SCL level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void FUTURE_SCL_set_level(const bool level)
{
	PORTE_set_pin_level(1, level);
}

/**
 * \brief Toggle output level on FUTURE_SCL
 *
 * Toggle the pin level
 */
static inline void FUTURE_SCL_toggle_level()
{
	PORTE_toggle_pin_level(1);
}

/**
 * \brief Get level on FUTURE_SCL
 *
 * Reads the level on a pin
 */
static inline bool FUTURE_SCL_get_level()
{
	return PORTE_get_pin_level(1);
}

/**
 * \brief Set FUTURE_SCL interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void FUTURE_SCL_int_level(const uint8_t level)
{
	PORTE_set_int_level(level);
}

/**
 * \brief Set FUTURE_SCL interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void FUTURE_SCL_int0_mask(const uint8_t value)
{
	PORTE_write_int0_mask(value);
}

/**
 * \brief Set FUTURE_SCL interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void FUTURE_SCL_int1_mask(const uint8_t value)
{
	PORTE_write_int1_mask(value);
}

#endif /* ATMEL_START_PINS_H_INCLUDED */
