/*!
* @file system_time.c
* @author D.Chikov
* @date 10/15/2020, 09:37:34
* @brief ...tbd...
*/


#include "system.h"
#include "systmr.h"
#include <xc.h>
#include "board.h"

/*!
* 	 define TIME_1MS   (125*1000)
* 
* 	...tbd...
* 	\param 125*1000 -...
* 	\return define -...
*/


#define TIME_1US   (SYS_CLK_FREQ/2e6)
#define TIME_1MS   (TIME_1US*1000)


/*!
* 	 void SYS_timer_start(int period)
* 
* 	...tbd...
* 	\param int period -...
*/
void SYSTEM_timer_start(int period)
{
    systmrB_disable(TIMER4_TIMER5);
    systmrB_set_period(TIMER4_TIMER5,  period * TIME_1MS);
    systmrB_restart(TIMER4_TIMER5);
}


/*!
* 	 bool SYS_timer_timeout()
* 
* 	...tbd...
* 	\return bool -...
*/
bool SYSTEM_timer_timeout(){
    return systmrB_timeout(TIMER4_TIMER5);
}


/*!
* 	 uint32_t SYS_timer_elapsed()
* 
* 	...tbd...
* 	\return uint32_t -...
*/
uint32_t SYSTEM_timer_elapsed(){
    return systmrB_elapsed(TIMER4_TIMER5)/(TIME_1MS);
}

void SYSTEM_delay_init(){
    // for SYS delay
    systmrB_enable(TIMER4_TIMER5, SYSTMRB_PRESCALE1_2, TIME_1US);
}

/*!
* 	 void SYS_delay_ms(int ms)
* 
* 	...tbd...
* 	\param int ms -...
*/
void SYSTEM_delay_ms(int ms){    
    systmrB_disable(TIMER4_TIMER5);
    systmrB_set_period(TIMER4_TIMER5,  ms * TIME_1MS);
    systmrB_restart(TIMER4_TIMER5);
    while (!systmrB_timeout(TIMER4_TIMER5));    
}

void SYSTEM_delay_us(int us){    
    systmrB_disable(TIMER4_TIMER5);
    systmrB_set_period(TIMER4_TIMER5,  us * TIME_1US);
    systmrB_restart(TIMER4_TIMER5);
    while (!systmrB_timeout(TIMER4_TIMER5));    
}


