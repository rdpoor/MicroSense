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
 * \brief Set POLARITY output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void POLARITY_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTA_set_pin_output_pull_mode(7, output_pull_mode);
}

/**
 * \brief Set POLARITY data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void POLARITY_set_dir(const enum port_dir dir)
{
	PORTA_set_pin_dir(7, dir);
}

/**
 * \brief Set POLARITY input/sense configuration
 *
 * Enable/disable POLARITY digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void POLARITY_set_isc(const PORT_ISC_t isc)
{
	PORTA_pin_set_isc(7, isc);
}

/**
 * \brief Set POLARITY inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on POLARITY is inverted
 *                     false = I/O on POLARITY is not inverted
 */
static inline void POLARITY_set_inverted(const bool inverted)
{
	PORTA_pin_set_inverted(7, inverted);
}

/**
 * \brief Set POLARITY level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void POLARITY_set_level(const bool level)
{
	PORTA_set_pin_level(7, level);
}

/**
 * \brief Toggle output level on POLARITY
 *
 * Toggle the pin level
 */
static inline void POLARITY_toggle_level()
{
	PORTA_toggle_pin_level(7);
}

/**
 * \brief Get level on POLARITY
 *
 * Reads the level on a pin
 */
static inline bool POLARITY_get_level()
{
	return PORTA_get_pin_level(7);
}

/**
 * \brief Set POLARITY interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void POLARITY_int_level(const uint8_t level)
{
	PORTA_set_int_level(level);
}

/**
 * \brief Set POLARITY interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void POLARITY_int0_mask(const uint8_t value)
{
	PORTA_write_int0_mask(value);
}

/**
 * \brief Set POLARITY interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void POLARITY_int1_mask(const uint8_t value)
{
	PORTA_write_int1_mask(value);
}

/**
 * \brief Set MUXA0 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void MUXA0_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTB_set_pin_output_pull_mode(0, output_pull_mode);
}

/**
 * \brief Set MUXA0 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void MUXA0_set_dir(const enum port_dir dir)
{
	PORTB_set_pin_dir(0, dir);
}

/**
 * \brief Set MUXA0 input/sense configuration
 *
 * Enable/disable MUXA0 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void MUXA0_set_isc(const PORT_ISC_t isc)
{
	PORTB_pin_set_isc(0, isc);
}

/**
 * \brief Set MUXA0 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on MUXA0 is inverted
 *                     false = I/O on MUXA0 is not inverted
 */
static inline void MUXA0_set_inverted(const bool inverted)
{
	PORTB_pin_set_inverted(0, inverted);
}

/**
 * \brief Set MUXA0 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void MUXA0_set_level(const bool level)
{
	PORTB_set_pin_level(0, level);
}

/**
 * \brief Toggle output level on MUXA0
 *
 * Toggle the pin level
 */
static inline void MUXA0_toggle_level()
{
	PORTB_toggle_pin_level(0);
}

/**
 * \brief Get level on MUXA0
 *
 * Reads the level on a pin
 */
static inline bool MUXA0_get_level()
{
	return PORTB_get_pin_level(0);
}

/**
 * \brief Set MUXA0 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void MUXA0_int_level(const uint8_t level)
{
	PORTB_set_int_level(level);
}

/**
 * \brief Set MUXA0 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void MUXA0_int0_mask(const uint8_t value)
{
	PORTB_write_int0_mask(value);
}

/**
 * \brief Set MUXA0 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void MUXA0_int1_mask(const uint8_t value)
{
	PORTB_write_int1_mask(value);
}

/**
 * \brief Set MUXA1 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void MUXA1_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTB_set_pin_output_pull_mode(1, output_pull_mode);
}

/**
 * \brief Set MUXA1 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void MUXA1_set_dir(const enum port_dir dir)
{
	PORTB_set_pin_dir(1, dir);
}

/**
 * \brief Set MUXA1 input/sense configuration
 *
 * Enable/disable MUXA1 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void MUXA1_set_isc(const PORT_ISC_t isc)
{
	PORTB_pin_set_isc(1, isc);
}

/**
 * \brief Set MUXA1 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on MUXA1 is inverted
 *                     false = I/O on MUXA1 is not inverted
 */
static inline void MUXA1_set_inverted(const bool inverted)
{
	PORTB_pin_set_inverted(1, inverted);
}

/**
 * \brief Set MUXA1 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void MUXA1_set_level(const bool level)
{
	PORTB_set_pin_level(1, level);
}

/**
 * \brief Toggle output level on MUXA1
 *
 * Toggle the pin level
 */
static inline void MUXA1_toggle_level()
{
	PORTB_toggle_pin_level(1);
}

/**
 * \brief Get level on MUXA1
 *
 * Reads the level on a pin
 */
static inline bool MUXA1_get_level()
{
	return PORTB_get_pin_level(1);
}

/**
 * \brief Set MUXA1 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void MUXA1_int_level(const uint8_t level)
{
	PORTB_set_int_level(level);
}

/**
 * \brief Set MUXA1 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void MUXA1_int0_mask(const uint8_t value)
{
	PORTB_write_int0_mask(value);
}

/**
 * \brief Set MUXA1 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void MUXA1_int1_mask(const uint8_t value)
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
 * \brief Set STATUS_LED output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void STATUS_LED_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTD_set_pin_output_pull_mode(7, output_pull_mode);
}

/**
 * \brief Set STATUS_LED data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void STATUS_LED_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(7, dir);
}

/**
 * \brief Set STATUS_LED input/sense configuration
 *
 * Enable/disable STATUS_LED digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void STATUS_LED_set_isc(const PORT_ISC_t isc)
{
	PORTD_pin_set_isc(7, isc);
}

/**
 * \brief Set STATUS_LED inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on STATUS_LED is inverted
 *                     false = I/O on STATUS_LED is not inverted
 */
static inline void STATUS_LED_set_inverted(const bool inverted)
{
	PORTD_pin_set_inverted(7, inverted);
}

/**
 * \brief Set STATUS_LED level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void STATUS_LED_set_level(const bool level)
{
	PORTD_set_pin_level(7, level);
}

/**
 * \brief Toggle output level on STATUS_LED
 *
 * Toggle the pin level
 */
static inline void STATUS_LED_toggle_level()
{
	PORTD_toggle_pin_level(7);
}

/**
 * \brief Get level on STATUS_LED
 *
 * Reads the level on a pin
 */
static inline bool STATUS_LED_get_level()
{
	return PORTD_get_pin_level(7);
}

/**
 * \brief Set STATUS_LED interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void STATUS_LED_int_level(const uint8_t level)
{
	PORTD_set_int_level(level);
}

/**
 * \brief Set STATUS_LED interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void STATUS_LED_int0_mask(const uint8_t value)
{
	PORTD_write_int0_mask(value);
}

/**
 * \brief Set STATUS_LED interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void STATUS_LED_int1_mask(const uint8_t value)
{
	PORTD_write_int1_mask(value);
}

/**
 * \brief Set PE0 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void PE0_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTE_set_pin_output_pull_mode(0, output_pull_mode);
}

/**
 * \brief Set PE0 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PE0_set_dir(const enum port_dir dir)
{
	PORTE_set_pin_dir(0, dir);
}

/**
 * \brief Set PE0 input/sense configuration
 *
 * Enable/disable PE0 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void PE0_set_isc(const PORT_ISC_t isc)
{
	PORTE_pin_set_isc(0, isc);
}

/**
 * \brief Set PE0 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on PE0 is inverted
 *                     false = I/O on PE0 is not inverted
 */
static inline void PE0_set_inverted(const bool inverted)
{
	PORTE_pin_set_inverted(0, inverted);
}

/**
 * \brief Set PE0 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PE0_set_level(const bool level)
{
	PORTE_set_pin_level(0, level);
}

/**
 * \brief Toggle output level on PE0
 *
 * Toggle the pin level
 */
static inline void PE0_toggle_level()
{
	PORTE_toggle_pin_level(0);
}

/**
 * \brief Get level on PE0
 *
 * Reads the level on a pin
 */
static inline bool PE0_get_level()
{
	return PORTE_get_pin_level(0);
}

/**
 * \brief Set PE0 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void PE0_int_level(const uint8_t level)
{
	PORTE_set_int_level(level);
}

/**
 * \brief Set PE0 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void PE0_int0_mask(const uint8_t value)
{
	PORTE_write_int0_mask(value);
}

/**
 * \brief Set PE0 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void PE0_int1_mask(const uint8_t value)
{
	PORTE_write_int1_mask(value);
}

/**
 * \brief Set PE1 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void PE1_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTE_set_pin_output_pull_mode(1, output_pull_mode);
}

/**
 * \brief Set PE1 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PE1_set_dir(const enum port_dir dir)
{
	PORTE_set_pin_dir(1, dir);
}

/**
 * \brief Set PE1 input/sense configuration
 *
 * Enable/disable PE1 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void PE1_set_isc(const PORT_ISC_t isc)
{
	PORTE_pin_set_isc(1, isc);
}

/**
 * \brief Set PE1 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on PE1 is inverted
 *                     false = I/O on PE1 is not inverted
 */
static inline void PE1_set_inverted(const bool inverted)
{
	PORTE_pin_set_inverted(1, inverted);
}

/**
 * \brief Set PE1 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PE1_set_level(const bool level)
{
	PORTE_set_pin_level(1, level);
}

/**
 * \brief Toggle output level on PE1
 *
 * Toggle the pin level
 */
static inline void PE1_toggle_level()
{
	PORTE_toggle_pin_level(1);
}

/**
 * \brief Get level on PE1
 *
 * Reads the level on a pin
 */
static inline bool PE1_get_level()
{
	return PORTE_get_pin_level(1);
}

/**
 * \brief Set PE1 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void PE1_int_level(const uint8_t level)
{
	PORTE_set_int_level(level);
}

/**
 * \brief Set PE1 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void PE1_int0_mask(const uint8_t value)
{
	PORTE_write_int0_mask(value);
}

/**
 * \brief Set PE1 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void PE1_int1_mask(const uint8_t value)
{
	PORTE_write_int1_mask(value);
}

#endif /* ATMEL_START_PINS_H_INCLUDED */
