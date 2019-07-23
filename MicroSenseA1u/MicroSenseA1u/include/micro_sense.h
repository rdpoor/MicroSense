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

// called once every millisecond at interrupt level
void micro_sense_sample_cb(void);

#endif /* MICRO_SENSE_H_ */
