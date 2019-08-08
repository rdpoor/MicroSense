/*
 * micro_sense.h
 *
 * Created: 5/3/2019 6:58:26 AM
 * Author: Robert Poor <rdpoor@gmail.com>
 */


#ifndef MICRO_SENSE_H_
#define MICRO_SENSE_H_

// ============================================================================
// micro_sense contains all the logic for the micro_sense application

// called once at initialization
void micro_sense_init(void);

// called repeatedly in foreground
void micro_sense_step(void);

// Called on completion of ADC conversion
void micro_sense_adc_complete_cb(void);

// Called on each low-to-high transition on SYNC_IN (60Hz)
void micro_sense_sync_cb(void);

#endif /* MICRO_SENSE_H_ */
