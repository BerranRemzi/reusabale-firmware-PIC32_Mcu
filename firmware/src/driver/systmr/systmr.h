/*!
* @file systmr\systmr.h
* @author D.Chikov
* @date 10/15/2020, 09:37:33
* @brief ...tbd...
*/


 #ifndef _SYSTMR_H
#define _SYSTMR_H

#include "xc.h"


#ifdef __cplusplus  // Provide C++ Compatibility
    extern "C" {
#endif
#include "typedef_global.h"     

        
// ------------------------- TIMER A
typedef enum {
     SYSTMRA_PRESCALE1_1,
     SYSTMRA_PRESCALE1_8,
     SYSTMRA_PRESCALE1_64,
     SYSTMRA_PRESCALE1_256,
}SysTmrA_Prescaler;

/*!
* ...tbd...
*/
void systmrA_enable( SysTmrA_Prescaler prescaler, uint32_t period);
/*!
* ...tbd...
*/
void systmrA_disable();

/*!
* ...tbd...
*/
void systmrA_interrupt_disable();
/*!
* ...tbd...
*/
void systmrA_interrupt_enable(bool enable, uint32_t priority, uint32_t sub_priority);

/*!
* ...tbd...
*/
void systmrA_clear_flag();



// ------------------------- TIMER B
typedef enum {
     SYSTMRB_PRESCALE1_1,
     SYSTMRB_PRESCALE1_2,
     SYSTMRB_PRESCALE1_4,
     SYSTMRB_PRESCALE1_8,
     SYSTMRB_PRESCALE1_16,
     SYSTMRB_PRESCALE1_32,
     SYSTMRB_PRESCALE1_64,
     SYSTMRB_PRESCALE1_256,
}SysTmrB_Prescaler;

typedef enum {
    TIMER2,    
    TIMER2_TIMER3,
    TIMER3,
    TIMER4,
    TIMER4_TIMER5,    
    TIMER5,
    TIMER6,
    TIMER6_TIMER7,    
    TIMER7,
    TIMER8,
    TIMER8_TIMER9,    
    TIMER9,
}TimerB;
/*!
* ...tbd...
*/
void systmrB_enable(TimerB num, SysTmrB_Prescaler prescaler, uint32_t period);
/*!
* ...tbd...
*/
void systmrB_enableInterrupt(TimerB num, uint32_t priority, uint32_t sub_priority); 
/*!
* ...tbd...
*/
void systmrB_set_period(TimerB num, uint32_t tmr);
        
/*!
* ...tbd...
*/
void systmrB_disable(TimerB num);

/*!
* ...tbd...
*/
void systmrB_restart(TimerB num);
/*!
* ...tbd...
*/
bool systmrB_timeout(TimerB num);
/*!
* ...tbd...
*/
uint32_t systmrB_freq(TimerB num);
/*!
* ...tbd...
*/
uint32_t systmrB_elapsed(TimerB num);



#ifdef __cplusplus
}
#endif



#endif // #ifndef _DRV_USART_H
