#ifndef SYSTIC_H_INCLUDED
#define SYSTIC_H_INCLUDED

#include <compiler.h>

#ifdef __cplusplus
extern "C" {
#endif

// initialize system tic
void systic_init(void);

// advance the millisecond counter.  called at interrupt level.
void systic_tic(void);

// fetch the millisecond counter.  interrupt safe.
uint16_t systic_get_ms(void);

#ifdef __cplusplus
}
#endif

#endif  // #ifndef SYSTIC_H_INCLUDED