/*
 * profiling.h
 *
 * Created: 5/11/2019 8:38:57 PM
 *  Author: Robert
 */


#ifndef PROFILING_H_
#define PROFILING_H_

#ifdef __cplusplus
extern "C" {
#endif

// comment this out to disable profiling
// #define PROFILING

// These should really be defined in an application-specific file.
#define PROFILED_PINS \
  DEF_PROFILED_PIN(CONVERTING_SAMPLE, PORTA, 2) \
  DEF_PROFILED_PIN(PROCESSING_SAMPLE, PORTA, 2) \
  DEF_PROFILED_PIN(PROCESSING_FRAME, PORTA, 2)


#ifdef PROFILING

  #define PROFILING_INIT() profiling_init()
  #define PROFILING_SET(name) name_port.OUTSET == 1 << name_pin
  #define PROFILING_CLR(name) name_port.OUTCLR == 1 << name_pin
  #define PROFILING_SET(name) name_port.OUTTGL == 1 << name_pin

#else

  #define PROFILING_INIT(...) do {} while(0)
  #define PROFILING_SET(...) do {} while(0)
  #define PROFILING_CLR(...) do {} while(0)
  #define PROFILING_TGL(...) do {} while(0)

#endif // #ifdef PROFILING


#ifdef __cplusplus
}
#endif

#endif /* PROFILING_H_ */
