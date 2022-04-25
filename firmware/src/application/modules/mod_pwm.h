/*!
* @file mod_pwm.h
* @author D.Chikov
* @date 10/15/2020, 18:16:01
* @brief  PWM module header
*/



#ifndef MOD_PWM_H
#define MOD_PWM_H

#include "typedef_global.h"

typedef enum {
    MODULE_PWM1,
    MODULE_PWM2,
    MODULE_PWM3,
    MODULE_PWM4,
    MODULE_PWM5,
}PwmModule;

/*!
* ...tbd...
*/
void mod_pwm_init(void);

/*!
* ...tbd...
*/
bool mod_pwm_conf(PwmModule number);

/*!
* ...tbd...
*/
bool mod_pwm_polarity_set(PwmModule number, uint32_t pol);

/*!
* ...tbd...
*/
bool mod_pwm_set_freq(PwmModule number, uint32_t freq);

/*!
* ...tbd...
*/
bool mod_pwm_set_duty(PwmModule number, uint32_t duty);

/*!
* ...tbd...
*/
bool mod_pwm_enable(PwmModule number, bool enable);

bool mod_pwm_is_enabled(PwmModule number);


#endif