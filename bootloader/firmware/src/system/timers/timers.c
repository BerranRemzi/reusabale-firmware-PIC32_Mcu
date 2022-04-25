/**********************************************************************

  @File:timers.c
 
  @Project: ORHAMA Flower D.Chikov
  @Date: 
  @Description: Timers is module which has 10 position table with timers
  each timer has shot periodically or single shot.
  on call back function of timer use shortest command
 
**********************************************************************/

#include "timers.h"
#include "config.h"



typedef volatile struct {

/*private*/
  UINT8   __shot;
  UINT16  __timer;

/*public*/
  UINT8   option;
  UINT16  interval;
  TimerCallbackPtr_t callback_function;
} DelayTimer_t;


PRIVATE
DelayTimer_t g_timer[TIMERS_COUNT]={0};


/* ********************************************************************* 
@Function name:  timer_start
@Return: void
@Parameters: 
 UINT8 timer_n - timer number
 UINT8 option  - option
@Description: This starts timer timer start 

********************************************************************* */
void timer_start(UINT8 timer_n, UINT8 option) {
  g_timer[timer_n].__timer = g_timer[timer_n].interval;
  g_timer[timer_n].option = option;
}

/* ********************************************************************* 
@Function name:  timer_setup
@Return: BOOL
@Parameters: 
UINT8 timer_n -- timer number
UINT16 interval -- timer interval
TimerCallback_t callback_function  -- function which will be called 
                            after timer timeout
@Description: setup of timer with numer timer_n

********************************************************************* */
BOOL timer_setup(UINT8 timer_n, UINT16 interval, TimerCallbackPtr_t callback_function){
  if(callback_function != NULL){
    g_timer[timer_n].interval = interval;
    g_timer[timer_n].callback_function = callback_function;
    return TRUE;
  }
  else {
    return FALSE;
  }
}

/* ********************************************************************* 
@Function name:  timer_change_interval
@Return: void
@Parameters: 
UINT8 timer_n
UINT16 interval 
@Description: Timer change interval

********************************************************************* */
void timer_change_interval(UINT8 timer_n, UINT16 interval){
  g_timer[timer_n].interval= interval;
}

/* ********************************************************************* 
@Function name:  delay_process_timers
@Return: inline void
@Parameters: 
void 
@Description: this function need to be placed to thread or scheduler job

********************************************************************* */
__SCHEDULER_EVENT__(EVENT_TIMERS_PROCESS) {
  UINT8 timer_n;
  for (timer_n = 0u; timer_n < TIMERS_COUNT; timer_n++) {
    if (g_timer[timer_n].__shot) {
      g_timer[timer_n].__shot = FALSE;
      if (g_timer[timer_n].callback_function == NULL) {
        continue;
      }
      g_timer[timer_n].callback_function();
    }

  }
}

/* ********************************************************************* 
@Function name:  delay_timer_service
@Return: inline void 
@Parameters: 
void 
@Description: this function needs to be placed to interrupt
lookup timer in list and set shot to

********************************************************************* */
INTERRUPT_SERVICE timer_service(void) {
  BOOL shot = FALSE;
  UINT8 timer_n;
  for (timer_n = 0u; timer_n < TIMERS_COUNT; timer_n++) {
    if ((g_timer[timer_n].option & TIMER_RUN) == 0u) {
      continue;
    }

    if (g_timer[timer_n].__timer == 0u) {
      g_timer[timer_n].__shot = TRUE;            
      shot |= TRUE;
      if ((g_timer[timer_n].option & TIMER_SINGLESHOT) == TIMER_SINGLESHOT){
        g_timer[timer_n].option &= ~TIMER_RUN;
      }
/*restart interval*/
      g_timer[timer_n].__timer = g_timer[timer_n].interval;
    } else {
      g_timer[timer_n].__timer--;
    }
  }
  /* any shot found generate scheduler task to process timer events*/
  if(shot ){
    scheduler_event_set( EVENT_TIMERS_PROCESS,NULL);
  }
}