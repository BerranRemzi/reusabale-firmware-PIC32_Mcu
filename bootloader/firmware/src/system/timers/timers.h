/**********************************************************************

  @File:timers.h
 
  @Project: ORHAMA Flower D.Chikov
  @Date: 2014\04\24 15-56-48
  @Description: Timers is module which has 10 position table with timers
  each timer has shot periodically or single shot.
  on call back function of timer use shortest command
  
**********************************************************************/


#ifndef TIMERS_H
#define TIMERS_H
#include "compiler.h"
#include "typedef_global.h"
#include    "scheduler.h"


#define __TIMER_NAME__(v)   timer_##v
#define __TIMER_EVENT__(v)  void __TIMER_NAME__(v)(void)

typedef void(*TimerCallbackPtr_t)(void) ;

typedef enum {
    TIMER_RUN = 1,
    TIMER_SINGLESHOT = 3,
} DelayTimerState_t;


BOOL timer_setup(UINT8 timer_n, UINT16 interval, TimerCallbackPtr_t callback_function);
void timer_change_interval(UINT8 timer_n, UINT16 interval);
void timer_start(UINT8 timer_n, UINT8 option);


__SCHEDULER_EVENT__(EVENT_TIMERS_PROCESS);
INTERRUPT_SERVICE timer_service(void);

#endif