/**
 * \file
 *
 * \brief Driver ISR.
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

#include <driver_init.h>
#include <compiler.h>
#include "micro_sense.h"

ISR(TCD0_CCA_vect)
{
  // reload the PWM count
  micro_sense_on_pwm_irq();
}

ISR(TCC1_CCA_vect)
{
  // TCC1 starts counting when the comparator goes true (V_OUT exceeds V_REF)
  // and stops counting and generates an interrupt when the comparator goes
  // false (V_OUT falls below V_REF after reset_v_out() is called).
  micro_sense_on_tcc1_cca_irq();
}

ISR(TCC1_ERR_vect)
{
  // TCC1 generates an error interrupt if a start counting event is received
  // before the previously captured TCC1.CCA is read.
  micro_sense_on_tcc1_err_irq();
}

ISR(ADCA_CH0_vect)
{
  // ADC generates an interrupt when it has finished converting a sample.
  micro_sense_on_adc_complete_irq();
}

ISR(PORTA_INT0_vect)
{
  // V_SYNC generates an interrupt when its GPIO pin goes true.  It uses the
  // Event System to initiate an ADC read, so this interrupt isn't strictly
  // necessary, but we use it for gathering statistics.
  micro_sense_on_vsync_irq();
  PORTA_INTFLAGS = PORT_INT0IF_bm;
}
