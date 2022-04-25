/*!
* @file modules\pwm.c
* @author D.Chikov
* @date 10/15/2020, 18:16:01
* @brief ...tbd...
*/



#include "mod_pwm.h"
#include "pwm.h"
#include "systmr.h"
#include "gpio.h"
#include "board.h"
#include "stdio.h"


typedef struct 
{
    bool configured;	
    bool enabled;
	uint32_t frequency;	 //in Hz    
    uint32_t duty;
    
}PwmChannel_t;

static PwmChannel_t pwm[3] = {};
	






/*!
* 	 bool pwm_conf(uint32_t number)
* 
* 	Configures PWM memory
* 	\param uint32_t number -PWM module number
* 	\return bool - True of ok
*/
bool mod_pwm_conf(PwmModule number)
{
    bool result = false;
    
    switch(number)
    {
        case MODULE_PWM1:  // PWM1 - RPD12 OC8(hw PWM8)    
            gpio_enable(GPIO('D',12), GPIO_CUSTOM_OUTPUT(OUTPUT_FUNC_OC8));
            pwm_init(PWM8, PWM_SRC_TIMERY,  false);                
            systmrB_enable(TIMER7, SYSTMRB_PRESCALE1_2, (SYS_CLK_FREQ)/4/1e3);// set 1khz freq
            systmrB_restart(TIMER7);
            pwm_enable(PWM8, 0);
            pwm_set_duty(PWM8,  50);  
            pwm[0].configured = 1;
            pwm[0].enabled = 0;
            pwm[0].duty = 50;
            result = true;
        break;
        
        case MODULE_PWM2:  // PWM2 - RPD4 OC5 (hw PWM5) 
            gpio_enable(GPIO('D',4), GPIO_CUSTOM_OUTPUT(OUTPUT_FUNC_OC5));                        
            pwm_init(PWM5, PWM_SRC_TIMERX,  false);                                       
            systmrB_enable(TIMER2, SYSTMRB_PRESCALE1_2, (SYS_CLK_FREQ)/4/1e3);// set 1khz freq
            systmrB_restart(TIMER2);            
            pwm_enable(PWM5, 0);
            pwm_set_duty(PWM5,  50); 
            pwm[1].configured = 1;
            pwm[1].enabled = 0;
            pwm[1].duty = 50;
            result = true;
        break;
        
        case MODULE_PWM3:  // PWM3 - RPF0 OC4 (hw PWM4) 
            gpio_enable(GPIO('F',0), GPIO_CUSTOM_OUTPUT(OUTPUT_FUNC_OC4));
            pwm_init(PWM4, PWM_SRC_TIMERY,  false);                
            systmrB_enable(TIMER3, SYSTMRB_PRESCALE1_2, (SYS_CLK_FREQ)/4/1e3);// set 1khz freq
            systmrB_restart(TIMER3);
            pwm_enable(PWM4, 0);
            pwm_set_duty(PWM4,  50);
            pwm[2].configured = 1;
            pwm[2].enabled = 0;
            pwm[2].duty = 50;
            result = true;
        break;
        
        default:
            printf("(not supported)");
        break;
    }	
    

	return result;
}




/*!
* 	 bool pwm_enable(uint32_t number, bool enable)
* 
* 	Enables signal on PWM
* 	\param uint32_t number - PWM module number
* 	\param bool enable - 1-Enable 0-Disable
* 	\return bool - true if ok
*/
bool mod_pwm_enable(PwmModule number, bool enable)
{
    bool result = false;
    
    switch(number)
    {
        case MODULE_PWM1:  // PWM1 - RPD12 OC8
            
            if(enable){
                if(pwm[0].configured== true){                
                    pwm_enable(PWM8, 1);    
                    result = true;
                }else printf("(unconfigured)");
            } else {pwm_enable(PWM8, 0);
            		result = true;}
        break;    
        
        case MODULE_PWM2:  // PWM2 - RPD4 OC5
            if(enable){                
                if(pwm[1].configured== true){                    
                    pwm_enable(PWM5, 1);
                    result = true;
                }else printf("(unconfigured)");
            }else {pwm_enable(PWM5, 0);
            		result = true;}
        break;        
            
        case MODULE_PWM3: // PWM4 - RPF0 OC4
            if(enable){  
                if(pwm[2].configured== true){
                    pwm_enable(PWM4, 1);
                    result = true;
                }else printf("(unconfigured)");
            }else {pwm_enable(PWM4, 0);
            		result = true;}
            break;
            
        default:
            printf("(not supported)");
        break;
    }	    
	return result;
}

/*!
* 	 bool mod_pwm_is_enabled(uint32_t numbere)
* 	Enables signal on PWM
* 	\param PwmModule number - PWM module number
* 	\return bool - true if ok
*/
bool mod_pwm_is_enabled(PwmModule number)
{   
    switch(number)
    {
        case MODULE_PWM1:  // PWM1 - RPD12 OC8                    
        case MODULE_PWM2:  // PWM2 - RPD4 OC5                     
        case MODULE_PWM3: // PWM4 - RPF0 OC4
            return pwm[number].enabled;
            break;
            
        default:
            printf("(not supported)");
        break;
    }
    return false;
}

/*!
* 	 bool pwm_freq_set(uint32_t number, uint32_t freq )
* 
* 	...tbd...
* 	\param uint32_t number - PWM module number
* 	\param uint32_t freq - 
* 	\return bool - True is OK;
*/
bool mod_pwm_set_freq(PwmModule number, uint32_t freq )
{	
   bool result = false;
   
   if(freq>=1000 && freq<=30e6){
    switch(number)
    {
        case MODULE_PWM1:  // PWM1 - RPD12 OC8             
            pwm[0].frequency  = freq;       
            systmrB_enable(TIMER7, SYSTMRB_PRESCALE1_2, (SYS_CLK_FREQ)/4/freq);// set 1khz freq
            systmrB_restart(TIMER7);            
            pwm_set_duty(PWM8, pwm[0].duty); 
            result = 1;
        break;      
        
        case MODULE_PWM2:  // PWM2 - RPD4 OC5            
            systmrB_enable(TIMER2, SYSTMRB_PRESCALE1_2, (SYS_CLK_FREQ)/4/freq);// set 1khz freq
            systmrB_restart(TIMER2);
            pwm[1].frequency  = freq;               
            pwm_set_duty(PWM5, pwm[1].duty);
            result = 1;
        break;        

        case MODULE_PWM3: // PWM4 - RPF0 OC4            
            systmrB_enable(TIMER3, SYSTMRB_PRESCALE1_2, (SYS_CLK_FREQ)/4/freq);// set 1khz freq
            systmrB_restart(TIMER3);
            pwm[2].frequency  = freq;               
            pwm_set_duty(PWM4, pwm[2].duty);
            result = 1;
        break;
        
        default:
            printf("(not supported)");
        break;
    }	
   }else{
       printf("(wrong frequency)");
   }
	return result;
}



/*!
* 	 bool pwm_duty_set(uint32_t number, uint32_t duty )
* 
* 	...tbd...
* 	\param uint32_t number - PWM module number
* 	\param uint32_t duty -...
* 	\return bool - True if OK
*/
bool mod_pwm_set_duty(PwmModule number, uint32_t duty )
{
    bool result = false;    
    switch(number)
    {
        case MODULE_PWM1:  // PWM1 - RPD12 OC8 
            if(pwm_set_duty(PWM8, duty) == RES_NO_ERROR){
                pwm[0].duty = duty;
                result = true;            
            }
        break;   
        
        case MODULE_PWM2:  // PWM2 - RPD4 OC5
            if(pwm_set_duty(PWM5, duty) == RES_NO_ERROR){
                pwm[1].duty = duty;
                result = true;
            }
        break;        
        
        case MODULE_PWM3: // PWM4 - RPF0 OC4            
            if(pwm_set_duty(PWM4, duty) == RES_NO_ERROR){
                pwm[2].duty = duty;
                result = true;
            }
             
        break;
        
        default:
            printf("(not supported)");
            break;
    }
    
	return result;
}
