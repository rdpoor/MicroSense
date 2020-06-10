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
 * \brief Set PA0 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void PA0_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTA_set_pin_output_pull_mode(0, output_pull_mode);
}

/**
 * \brief Set PA0 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PA0_set_dir(const enum port_dir dir)
{
	PORTA_set_pin_dir(0, dir);
}

/**
 * \brief Set PA0 input/sense configuration
 *
 * Enable/disable PA0 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void PA0_set_isc(const PORT_ISC_t isc)
{
	PORTA_pin_set_isc(0, isc);
}

/**
 * \brief Set PA0 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on PA0 is inverted
 *                     false = I/O on PA0 is not inverted
 */
static inline void PA0_set_inverted(const bool inverted)
{
	PORTA_pin_set_inverted(0, inverted);
}

/**
 * \brief Set PA0 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PA0_set_level(const bool level)
{
	PORTA_set_pin_level(0, level);
}

/**
 * \brief Toggle output level on PA0
 *
 * Toggle the pin level
 */
static inline void PA0_toggle_level()
{
	PORTA_toggle_pin_level(0);
}

/**
 * \brief Get level on PA0
 *
 * Reads the level on a pin
 */
static inline bool PA0_get_level()
{
	return PORTA_get_pin_level(0);
}

/**
 * \brief Set PA0 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void PA0_int_level(const uint8_t level)
{
	PORTA_set_int_level(level);
}

/**
 * \brief Set PA0 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void PA0_int0_mask(const uint8_t value)
{
	PORTA_write_int0_mask(value);
}

/**
 * \brief Set PA0 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void PA0_int1_mask(const uint8_t value)
{
	PORTA_write_int1_mask(value);
}

/**
 * \brief Set PA1 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void PA1_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTA_set_pin_output_pull_mode(1, output_pull_mode);
}

/**
 * \brief Set PA1 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PA1_set_dir(const enum port_dir dir)
{
	PORTA_set_pin_dir(1, dir);
}

/**
 * \brief Set PA1 input/sense configuration
 *
 * Enable/disable PA1 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void PA1_set_isc(const PORT_ISC_t isc)
{
	PORTA_pin_set_isc(1, isc);
}

/**
 * \brief Set PA1 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on PA1 is inverted
 *                     false = I/O on PA1 is not inverted
 */
static inline void PA1_set_inverted(const bool inverted)
{
	PORTA_pin_set_inverted(1, inverted);
}

/**
 * \brief Set PA1 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PA1_set_level(const bool level)
{
	PORTA_set_pin_level(1, level);
}

/**
 * \brief Toggle output level on PA1
 *
 * Toggle the pin level
 */
static inline void PA1_toggle_level()
{
	PORTA_toggle_pin_level(1);
}

/**
 * \brief Get level on PA1
 *
 * Reads the level on a pin
 */
static inline bool PA1_get_level()
{
	return PORTA_get_pin_level(1);
}

/**
 * \brief Set PA1 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void PA1_int_level(const uint8_t level)
{
	PORTA_set_int_level(level);
}

/**
 * \brief Set PA1 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void PA1_int0_mask(const uint8_t value)
{
	PORTA_write_int0_mask(value);
}

/**
 * \brief Set PA1 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void PA1_int1_mask(const uint8_t value)
{
	PORTA_write_int1_mask(value);
}

/**
 * \brief Set PA2 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void PA2_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTA_set_pin_output_pull_mode(2, output_pull_mode);
}

/**
 * \brief Set PA2 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PA2_set_dir(const enum port_dir dir)
{
	PORTA_set_pin_dir(2, dir);
}

/**
 * \brief Set PA2 input/sense configuration
 *
 * Enable/disable PA2 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void PA2_set_isc(const PORT_ISC_t isc)
{
	PORTA_pin_set_isc(2, isc);
}

/**
 * \brief Set PA2 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on PA2 is inverted
 *                     false = I/O on PA2 is not inverted
 */
static inline void PA2_set_inverted(const bool inverted)
{
	PORTA_pin_set_inverted(2, inverted);
}

/**
 * \brief Set PA2 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PA2_set_level(const bool level)
{
	PORTA_set_pin_level(2, level);
}

/**
 * \brief Toggle output level on PA2
 *
 * Toggle the pin level
 */
static inline void PA2_toggle_level()
{
	PORTA_toggle_pin_level(2);
}

/**
 * \brief Get level on PA2
 *
 * Reads the level on a pin
 */
static inline bool PA2_get_level()
{
	return PORTA_get_pin_level(2);
}

/**
 * \brief Set PA2 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void PA2_int_level(const uint8_t level)
{
	PORTA_set_int_level(level);
}

/**
 * \brief Set PA2 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void PA2_int0_mask(const uint8_t value)
{
	PORTA_write_int0_mask(value);
}

/**
 * \brief Set PA2 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void PA2_int1_mask(const uint8_t value)
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
 * \brief Set PA4 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void PA4_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTA_set_pin_output_pull_mode(4, output_pull_mode);
}

/**
 * \brief Set PA4 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PA4_set_dir(const enum port_dir dir)
{
	PORTA_set_pin_dir(4, dir);
}

/**
 * \brief Set PA4 input/sense configuration
 *
 * Enable/disable PA4 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void PA4_set_isc(const PORT_ISC_t isc)
{
	PORTA_pin_set_isc(4, isc);
}

/**
 * \brief Set PA4 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on PA4 is inverted
 *                     false = I/O on PA4 is not inverted
 */
static inline void PA4_set_inverted(const bool inverted)
{
	PORTA_pin_set_inverted(4, inverted);
}

/**
 * \brief Set PA4 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PA4_set_level(const bool level)
{
	PORTA_set_pin_level(4, level);
}

/**
 * \brief Toggle output level on PA4
 *
 * Toggle the pin level
 */
static inline void PA4_toggle_level()
{
	PORTA_toggle_pin_level(4);
}

/**
 * \brief Get level on PA4
 *
 * Reads the level on a pin
 */
static inline bool PA4_get_level()
{
	return PORTA_get_pin_level(4);
}

/**
 * \brief Set PA4 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void PA4_int_level(const uint8_t level)
{
	PORTA_set_int_level(level);
}

/**
 * \brief Set PA4 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void PA4_int0_mask(const uint8_t value)
{
	PORTA_write_int0_mask(value);
}

/**
 * \brief Set PA4 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void PA4_int1_mask(const uint8_t value)
{
	PORTA_write_int1_mask(value);
}

/**
 * \brief Set A output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void A_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTA_set_pin_output_pull_mode(5, output_pull_mode);
}

/**
 * \brief Set A data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void A_set_dir(const enum port_dir dir)
{
	PORTA_set_pin_dir(5, dir);
}

/**
 * \brief Set A input/sense configuration
 *
 * Enable/disable A digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void A_set_isc(const PORT_ISC_t isc)
{
	PORTA_pin_set_isc(5, isc);
}

/**
 * \brief Set A inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on A is inverted
 *                     false = I/O on A is not inverted
 */
static inline void A_set_inverted(const bool inverted)
{
	PORTA_pin_set_inverted(5, inverted);
}

/**
 * \brief Set A level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void A_set_level(const bool level)
{
	PORTA_set_pin_level(5, level);
}

/**
 * \brief Toggle output level on A
 *
 * Toggle the pin level
 */
static inline void A_toggle_level()
{
	PORTA_toggle_pin_level(5);
}

/**
 * \brief Get level on A
 *
 * Reads the level on a pin
 */
static inline bool A_get_level()
{
	return PORTA_get_pin_level(5);
}

/**
 * \brief Set A interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void A_int_level(const uint8_t level)
{
	PORTA_set_int_level(level);
}

/**
 * \brief Set A interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void A_int0_mask(const uint8_t value)
{
	PORTA_write_int0_mask(value);
}

/**
 * \brief Set A interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void A_int1_mask(const uint8_t value)
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
 * \brief Set PC2 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void PC2_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTC_set_pin_output_pull_mode(2, output_pull_mode);
}

/**
 * \brief Set PC2 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PC2_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(2, dir);
}

/**
 * \brief Set PC2 input/sense configuration
 *
 * Enable/disable PC2 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void PC2_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(2, isc);
}

/**
 * \brief Set PC2 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on PC2 is inverted
 *                     false = I/O on PC2 is not inverted
 */
static inline void PC2_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(2, inverted);
}

/**
 * \brief Set PC2 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PC2_set_level(const bool level)
{
	PORTC_set_pin_level(2, level);
}

/**
 * \brief Toggle output level on PC2
 *
 * Toggle the pin level
 */
static inline void PC2_toggle_level()
{
	PORTC_toggle_pin_level(2);
}

/**
 * \brief Get level on PC2
 *
 * Reads the level on a pin
 */
static inline bool PC2_get_level()
{
	return PORTC_get_pin_level(2);
}

/**
 * \brief Set PC2 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void PC2_int_level(const uint8_t level)
{
	PORTC_set_int_level(level);
}

/**
 * \brief Set PC2 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void PC2_int0_mask(const uint8_t value)
{
	PORTC_write_int0_mask(value);
}

/**
 * \brief Set PC2 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void PC2_int1_mask(const uint8_t value)
{
	PORTC_write_int1_mask(value);
}

/**
 * \brief Set PC3 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void PC3_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTC_set_pin_output_pull_mode(3, output_pull_mode);
}

/**
 * \brief Set PC3 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PC3_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(3, dir);
}

/**
 * \brief Set PC3 input/sense configuration
 *
 * Enable/disable PC3 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void PC3_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(3, isc);
}

/**
 * \brief Set PC3 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on PC3 is inverted
 *                     false = I/O on PC3 is not inverted
 */
static inline void PC3_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(3, inverted);
}

/**
 * \brief Set PC3 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PC3_set_level(const bool level)
{
	PORTC_set_pin_level(3, level);
}

/**
 * \brief Toggle output level on PC3
 *
 * Toggle the pin level
 */
static inline void PC3_toggle_level()
{
	PORTC_toggle_pin_level(3);
}

/**
 * \brief Get level on PC3
 *
 * Reads the level on a pin
 */
static inline bool PC3_get_level()
{
	return PORTC_get_pin_level(3);
}

/**
 * \brief Set PC3 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void PC3_int_level(const uint8_t level)
{
	PORTC_set_int_level(level);
}

/**
 * \brief Set PC3 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void PC3_int0_mask(const uint8_t value)
{
	PORTC_write_int0_mask(value);
}

/**
 * \brief Set PC3 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void PC3_int1_mask(const uint8_t value)
{
	PORTC_write_int1_mask(value);
}

/**
 * \brief Set PD0 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void PD0_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTD_set_pin_output_pull_mode(0, output_pull_mode);
}

/**
 * \brief Set PD0 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PD0_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(0, dir);
}

/**
 * \brief Set PD0 input/sense configuration
 *
 * Enable/disable PD0 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void PD0_set_isc(const PORT_ISC_t isc)
{
	PORTD_pin_set_isc(0, isc);
}

/**
 * \brief Set PD0 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on PD0 is inverted
 *                     false = I/O on PD0 is not inverted
 */
static inline void PD0_set_inverted(const bool inverted)
{
	PORTD_pin_set_inverted(0, inverted);
}

/**
 * \brief Set PD0 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PD0_set_level(const bool level)
{
	PORTD_set_pin_level(0, level);
}

/**
 * \brief Toggle output level on PD0
 *
 * Toggle the pin level
 */
static inline void PD0_toggle_level()
{
	PORTD_toggle_pin_level(0);
}

/**
 * \brief Get level on PD0
 *
 * Reads the level on a pin
 */
static inline bool PD0_get_level()
{
	return PORTD_get_pin_level(0);
}

/**
 * \brief Set PD0 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void PD0_int_level(const uint8_t level)
{
	PORTD_set_int_level(level);
}

/**
 * \brief Set PD0 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void PD0_int0_mask(const uint8_t value)
{
	PORTD_write_int0_mask(value);
}

/**
 * \brief Set PD0 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void PD0_int1_mask(const uint8_t value)
{
	PORTD_write_int1_mask(value);
}

/**
 * \brief Set PD2 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void PD2_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTD_set_pin_output_pull_mode(2, output_pull_mode);
}

/**
 * \brief Set PD2 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PD2_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(2, dir);
}

/**
 * \brief Set PD2 input/sense configuration
 *
 * Enable/disable PD2 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void PD2_set_isc(const PORT_ISC_t isc)
{
	PORTD_pin_set_isc(2, isc);
}

/**
 * \brief Set PD2 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on PD2 is inverted
 *                     false = I/O on PD2 is not inverted
 */
static inline void PD2_set_inverted(const bool inverted)
{
	PORTD_pin_set_inverted(2, inverted);
}

/**
 * \brief Set PD2 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PD2_set_level(const bool level)
{
	PORTD_set_pin_level(2, level);
}

/**
 * \brief Toggle output level on PD2
 *
 * Toggle the pin level
 */
static inline void PD2_toggle_level()
{
	PORTD_toggle_pin_level(2);
}

/**
 * \brief Get level on PD2
 *
 * Reads the level on a pin
 */
static inline bool PD2_get_level()
{
	return PORTD_get_pin_level(2);
}

/**
 * \brief Set PD2 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void PD2_int_level(const uint8_t level)
{
	PORTD_set_int_level(level);
}

/**
 * \brief Set PD2 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void PD2_int0_mask(const uint8_t value)
{
	PORTD_write_int0_mask(value);
}

/**
 * \brief Set PD2 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void PD2_int1_mask(const uint8_t value)
{
	PORTD_write_int1_mask(value);
}

/**
 * \brief Set PD3 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void PD3_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTD_set_pin_output_pull_mode(3, output_pull_mode);
}

/**
 * \brief Set PD3 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PD3_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(3, dir);
}

/**
 * \brief Set PD3 input/sense configuration
 *
 * Enable/disable PD3 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void PD3_set_isc(const PORT_ISC_t isc)
{
	PORTD_pin_set_isc(3, isc);
}

/**
 * \brief Set PD3 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on PD3 is inverted
 *                     false = I/O on PD3 is not inverted
 */
static inline void PD3_set_inverted(const bool inverted)
{
	PORTD_pin_set_inverted(3, inverted);
}

/**
 * \brief Set PD3 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PD3_set_level(const bool level)
{
	PORTD_set_pin_level(3, level);
}

/**
 * \brief Toggle output level on PD3
 *
 * Toggle the pin level
 */
static inline void PD3_toggle_level()
{
	PORTD_toggle_pin_level(3);
}

/**
 * \brief Get level on PD3
 *
 * Reads the level on a pin
 */
static inline bool PD3_get_level()
{
	return PORTD_get_pin_level(3);
}

/**
 * \brief Set PD3 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void PD3_int_level(const uint8_t level)
{
	PORTD_set_int_level(level);
}

/**
 * \brief Set PD3 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void PD3_int0_mask(const uint8_t value)
{
	PORTD_write_int0_mask(value);
}

/**
 * \brief Set PD3 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void PD3_int1_mask(const uint8_t value)
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
