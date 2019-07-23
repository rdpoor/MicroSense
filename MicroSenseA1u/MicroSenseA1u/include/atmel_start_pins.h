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
 * \brief Set CONVERTING_SAMPLE output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void CONVERTING_SAMPLE_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTB_set_pin_output_pull_mode(4, output_pull_mode);
}

/**
 * \brief Set CONVERTING_SAMPLE data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void CONVERTING_SAMPLE_set_dir(const enum port_dir dir)
{
	PORTB_set_pin_dir(4, dir);
}

/**
 * \brief Set CONVERTING_SAMPLE input/sense configuration
 *
 * Enable/disable CONVERTING_SAMPLE digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void CONVERTING_SAMPLE_set_isc(const PORT_ISC_t isc)
{
	PORTB_pin_set_isc(4, isc);
}

/**
 * \brief Set CONVERTING_SAMPLE inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on CONVERTING_SAMPLE is inverted
 *                     false = I/O on CONVERTING_SAMPLE is not inverted
 */
static inline void CONVERTING_SAMPLE_set_inverted(const bool inverted)
{
	PORTB_pin_set_inverted(4, inverted);
}

/**
 * \brief Set CONVERTING_SAMPLE level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void CONVERTING_SAMPLE_set_level(const bool level)
{
	PORTB_set_pin_level(4, level);
}

/**
 * \brief Toggle output level on CONVERTING_SAMPLE
 *
 * Toggle the pin level
 */
static inline void CONVERTING_SAMPLE_toggle_level()
{
	PORTB_toggle_pin_level(4);
}

/**
 * \brief Get level on CONVERTING_SAMPLE
 *
 * Reads the level on a pin
 */
static inline bool CONVERTING_SAMPLE_get_level()
{
	return PORTB_get_pin_level(4);
}

/**
 * \brief Set CONVERTING_SAMPLE interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void CONVERTING_SAMPLE_int_level(const uint8_t level)
{
	PORTB_set_int_level(level);
}

/**
 * \brief Set CONVERTING_SAMPLE interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void CONVERTING_SAMPLE_int0_mask(const uint8_t value)
{
	PORTB_write_int0_mask(value);
}

/**
 * \brief Set CONVERTING_SAMPLE interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void CONVERTING_SAMPLE_int1_mask(const uint8_t value)
{
	PORTB_write_int1_mask(value);
}

/**
 * \brief Set PROCESSING_SAMPLE output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void PROCESSING_SAMPLE_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTB_set_pin_output_pull_mode(5, output_pull_mode);
}

/**
 * \brief Set PROCESSING_SAMPLE data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PROCESSING_SAMPLE_set_dir(const enum port_dir dir)
{
	PORTB_set_pin_dir(5, dir);
}

/**
 * \brief Set PROCESSING_SAMPLE input/sense configuration
 *
 * Enable/disable PROCESSING_SAMPLE digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void PROCESSING_SAMPLE_set_isc(const PORT_ISC_t isc)
{
	PORTB_pin_set_isc(5, isc);
}

/**
 * \brief Set PROCESSING_SAMPLE inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on PROCESSING_SAMPLE is inverted
 *                     false = I/O on PROCESSING_SAMPLE is not inverted
 */
static inline void PROCESSING_SAMPLE_set_inverted(const bool inverted)
{
	PORTB_pin_set_inverted(5, inverted);
}

/**
 * \brief Set PROCESSING_SAMPLE level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PROCESSING_SAMPLE_set_level(const bool level)
{
	PORTB_set_pin_level(5, level);
}

/**
 * \brief Toggle output level on PROCESSING_SAMPLE
 *
 * Toggle the pin level
 */
static inline void PROCESSING_SAMPLE_toggle_level()
{
	PORTB_toggle_pin_level(5);
}

/**
 * \brief Get level on PROCESSING_SAMPLE
 *
 * Reads the level on a pin
 */
static inline bool PROCESSING_SAMPLE_get_level()
{
	return PORTB_get_pin_level(5);
}

/**
 * \brief Set PROCESSING_SAMPLE interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void PROCESSING_SAMPLE_int_level(const uint8_t level)
{
	PORTB_set_int_level(level);
}

/**
 * \brief Set PROCESSING_SAMPLE interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void PROCESSING_SAMPLE_int0_mask(const uint8_t value)
{
	PORTB_write_int0_mask(value);
}

/**
 * \brief Set PROCESSING_SAMPLE interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void PROCESSING_SAMPLE_int1_mask(const uint8_t value)
{
	PORTB_write_int1_mask(value);
}

/**
 * \brief Set PROCESSING_FRAME output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void PROCESSING_FRAME_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTB_set_pin_output_pull_mode(6, output_pull_mode);
}

/**
 * \brief Set PROCESSING_FRAME data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PROCESSING_FRAME_set_dir(const enum port_dir dir)
{
	PORTB_set_pin_dir(6, dir);
}

/**
 * \brief Set PROCESSING_FRAME input/sense configuration
 *
 * Enable/disable PROCESSING_FRAME digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void PROCESSING_FRAME_set_isc(const PORT_ISC_t isc)
{
	PORTB_pin_set_isc(6, isc);
}

/**
 * \brief Set PROCESSING_FRAME inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on PROCESSING_FRAME is inverted
 *                     false = I/O on PROCESSING_FRAME is not inverted
 */
static inline void PROCESSING_FRAME_set_inverted(const bool inverted)
{
	PORTB_pin_set_inverted(6, inverted);
}

/**
 * \brief Set PROCESSING_FRAME level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PROCESSING_FRAME_set_level(const bool level)
{
	PORTB_set_pin_level(6, level);
}

/**
 * \brief Toggle output level on PROCESSING_FRAME
 *
 * Toggle the pin level
 */
static inline void PROCESSING_FRAME_toggle_level()
{
	PORTB_toggle_pin_level(6);
}

/**
 * \brief Get level on PROCESSING_FRAME
 *
 * Reads the level on a pin
 */
static inline bool PROCESSING_FRAME_get_level()
{
	return PORTB_get_pin_level(6);
}

/**
 * \brief Set PROCESSING_FRAME interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void PROCESSING_FRAME_int_level(const uint8_t level)
{
	PORTB_set_int_level(level);
}

/**
 * \brief Set PROCESSING_FRAME interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void PROCESSING_FRAME_int0_mask(const uint8_t value)
{
	PORTB_write_int0_mask(value);
}

/**
 * \brief Set PROCESSING_FRAME interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void PROCESSING_FRAME_int1_mask(const uint8_t value)
{
	PORTB_write_int1_mask(value);
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

/**
 * \brief Set PE2 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void PE2_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTE_set_pin_output_pull_mode(2, output_pull_mode);
}

/**
 * \brief Set PE2 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PE2_set_dir(const enum port_dir dir)
{
	PORTE_set_pin_dir(2, dir);
}

/**
 * \brief Set PE2 input/sense configuration
 *
 * Enable/disable PE2 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void PE2_set_isc(const PORT_ISC_t isc)
{
	PORTE_pin_set_isc(2, isc);
}

/**
 * \brief Set PE2 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on PE2 is inverted
 *                     false = I/O on PE2 is not inverted
 */
static inline void PE2_set_inverted(const bool inverted)
{
	PORTE_pin_set_inverted(2, inverted);
}

/**
 * \brief Set PE2 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PE2_set_level(const bool level)
{
	PORTE_set_pin_level(2, level);
}

/**
 * \brief Toggle output level on PE2
 *
 * Toggle the pin level
 */
static inline void PE2_toggle_level()
{
	PORTE_toggle_pin_level(2);
}

/**
 * \brief Get level on PE2
 *
 * Reads the level on a pin
 */
static inline bool PE2_get_level()
{
	return PORTE_get_pin_level(2);
}

/**
 * \brief Set PE2 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void PE2_int_level(const uint8_t level)
{
	PORTE_set_int_level(level);
}

/**
 * \brief Set PE2 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void PE2_int0_mask(const uint8_t value)
{
	PORTE_write_int0_mask(value);
}

/**
 * \brief Set PE2 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void PE2_int1_mask(const uint8_t value)
{
	PORTE_write_int1_mask(value);
}

/**
 * \brief Set PE3 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void PE3_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTE_set_pin_output_pull_mode(3, output_pull_mode);
}

/**
 * \brief Set PE3 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PE3_set_dir(const enum port_dir dir)
{
	PORTE_set_pin_dir(3, dir);
}

/**
 * \brief Set PE3 input/sense configuration
 *
 * Enable/disable PE3 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void PE3_set_isc(const PORT_ISC_t isc)
{
	PORTE_pin_set_isc(3, isc);
}

/**
 * \brief Set PE3 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on PE3 is inverted
 *                     false = I/O on PE3 is not inverted
 */
static inline void PE3_set_inverted(const bool inverted)
{
	PORTE_pin_set_inverted(3, inverted);
}

/**
 * \brief Set PE3 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PE3_set_level(const bool level)
{
	PORTE_set_pin_level(3, level);
}

/**
 * \brief Toggle output level on PE3
 *
 * Toggle the pin level
 */
static inline void PE3_toggle_level()
{
	PORTE_toggle_pin_level(3);
}

/**
 * \brief Get level on PE3
 *
 * Reads the level on a pin
 */
static inline bool PE3_get_level()
{
	return PORTE_get_pin_level(3);
}

/**
 * \brief Set PE3 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void PE3_int_level(const uint8_t level)
{
	PORTE_set_int_level(level);
}

/**
 * \brief Set PE3 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void PE3_int0_mask(const uint8_t value)
{
	PORTE_write_int0_mask(value);
}

/**
 * \brief Set PE3 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void PE3_int1_mask(const uint8_t value)
{
	PORTE_write_int1_mask(value);
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
	PORTE_set_pin_output_pull_mode(6, output_pull_mode);
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
	PORTE_set_pin_dir(6, dir);
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
	PORTE_pin_set_isc(6, isc);
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
	PORTE_pin_set_inverted(6, inverted);
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
	PORTE_set_pin_level(6, level);
}

/**
 * \brief Toggle output level on MUXA0
 *
 * Toggle the pin level
 */
static inline void MUXA0_toggle_level()
{
	PORTE_toggle_pin_level(6);
}

/**
 * \brief Get level on MUXA0
 *
 * Reads the level on a pin
 */
static inline bool MUXA0_get_level()
{
	return PORTE_get_pin_level(6);
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
	PORTE_set_int_level(level);
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
	PORTE_write_int0_mask(value);
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
	PORTE_write_int1_mask(value);
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
	PORTE_set_pin_output_pull_mode(7, output_pull_mode);
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
	PORTE_set_pin_dir(7, dir);
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
	PORTE_pin_set_isc(7, isc);
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
	PORTE_pin_set_inverted(7, inverted);
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
	PORTE_set_pin_level(7, level);
}

/**
 * \brief Toggle output level on MUXA1
 *
 * Toggle the pin level
 */
static inline void MUXA1_toggle_level()
{
	PORTE_toggle_pin_level(7);
}

/**
 * \brief Get level on MUXA1
 *
 * Reads the level on a pin
 */
static inline bool MUXA1_get_level()
{
	return PORTE_get_pin_level(7);
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
	PORTE_set_int_level(level);
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
	PORTE_write_int0_mask(value);
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
	PORTE_write_int1_mask(value);
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
	PORTQ_set_pin_output_pull_mode(3, output_pull_mode);
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
	PORTQ_set_pin_dir(3, dir);
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
	PORTQ_pin_set_isc(3, isc);
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
	PORTQ_pin_set_inverted(3, inverted);
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
	PORTQ_set_pin_level(3, level);
}

/**
 * \brief Toggle output level on STATUS_LED
 *
 * Toggle the pin level
 */
static inline void STATUS_LED_toggle_level()
{
	PORTQ_toggle_pin_level(3);
}

/**
 * \brief Get level on STATUS_LED
 *
 * Reads the level on a pin
 */
static inline bool STATUS_LED_get_level()
{
	return PORTQ_get_pin_level(3);
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
	PORTQ_set_int_level(level);
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
	PORTQ_write_int0_mask(value);
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
	PORTQ_write_int1_mask(value);
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
	PORTR_set_pin_output_pull_mode(1, output_pull_mode);
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
	PORTR_set_pin_dir(1, dir);
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
	PORTR_pin_set_isc(1, isc);
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
	PORTR_pin_set_inverted(1, inverted);
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
	PORTR_set_pin_level(1, level);
}

/**
 * \brief Toggle output level on POLARITY
 *
 * Toggle the pin level
 */
static inline void POLARITY_toggle_level()
{
	PORTR_toggle_pin_level(1);
}

/**
 * \brief Get level on POLARITY
 *
 * Reads the level on a pin
 */
static inline bool POLARITY_get_level()
{
	return PORTR_get_pin_level(1);
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
	PORTR_set_int_level(level);
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
	PORTR_write_int0_mask(value);
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
	PORTR_write_int1_mask(value);
}

#endif /* ATMEL_START_PINS_H_INCLUDED */
