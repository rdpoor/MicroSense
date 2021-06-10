/*
 * micro_sensor.h
 *
 * Created: 5/3/2019 6:58:26 AM
 * Author: Robert Poor <rdpoor@gmail.com>
 */


#ifndef MICRO_SENSOR_H_
#define MICRO_SENSOR_H_

// ============================================================================
// micro_sensor contains all the logic for the micro_sensor application

// called once at initialization
void micro_sensor_init(void);

// called repeatedly in foreground
void micro_sensor_step(void);

// Called when comparator match goes true
void micro_sensor_ac_match_cb(void);

// Called on completion of ADC conversion
void micro_sensor_adc_complete_cb(void);

// Called on each low-to-high transition on SYNC_IN (60Hz)
void micro_sensor_sync_cb(void);

#endif /* MICRO_SENSOR_H_ */
