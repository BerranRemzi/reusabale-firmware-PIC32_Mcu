/*!
* @file pwm.h
* @author D.Chikov
* @date 10/15/2020, 09:37:33
* @brief PWM driver header
*/


#ifndef _PWM_H_
#define _PWM_H_

#include "typedef_global.h"

typedef enum{
   PWM1,
   PWM2,
   PWM3,
   PWM4,
   PWM5,
   PWM6,
   PWM7,
   PWM8,
   PWM9,
   PWM_COUNT
}PWMChannel;


typedef enum{    
    PWM_SRC_TIMERY,
    PWM_SRC_TIMERX
}PwmSource;

/*!
* PWM module initialization
*/
void pwm_init(PWMChannel pwm, PwmSource src,  bool enable_fault_pin);

/*!
* PWM Enable
*/
void pwm_enable(PWMChannel pwm, bool enable);

/*!
* PWM set duty
*/
ResultError_t pwm_set_duty(PWMChannel pwm, int32_t duty);

#endif