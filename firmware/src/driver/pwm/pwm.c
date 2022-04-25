/*!
 * @file pwm.c
 * @author D.Chikov
 * @date 10/15/2020, 09:37:33
 * @brief ...tbd...
 */


//   !!! This module should have
//   CFGCON[OCACLK] ==0



#include <xc.h>

#include "pwm.h"

/*!
 * 	 void pwm_enable(PWMChannel pwm, bool enable)
 * 
 * 	...tbd...
 * 	\param PWMChannel pwm -...
 * 	\param bool enable -...
 */
void pwm_enable(PWMChannel pwm, bool enable) {
    switch (pwm) {
        case PWM1: OC1CONbits.ON = enable;
            break;
        case PWM2: OC2CONbits.ON = enable;
            break;
        case PWM3: OC3CONbits.ON = enable;
            break;
        case PWM4: OC4CONbits.ON = enable;
            break;
        case PWM5: OC5CONbits.ON = enable;
            break;
        case PWM6: OC6CONbits.ON = enable;
            break;
        case PWM7: OC7CONbits.ON = enable;
            break;
        case PWM8: OC8CONbits.ON = enable;
            break;
        case PWM9: OC9CONbits.ON = enable;
            break;

        default:
            break;
    }
}

/*!
 * 	 void pwm_init(PWMChannel pwm,  PwmSource src, bool enable_fault_pin)
 * 
 * 	...tbd...
 * 	\param PWMChannel pwm - this parameter means pwm number PWM1,PWM2...PWM9
 * 	\param PwmSource src - Timer source TMR2,TMR3
 * 	\param bool enable_fault_pin - True - enable
 */
void pwm_init(PWMChannel pwm, PwmSource src, bool enable_fault_pin) {

    // OCM - mode is PWM with fault pin or without

    switch (pwm) {
        case PWM1:
            OC1CON = 6;
            if (enable_fault_pin == 1) OC1CONbits.OCM = 7;
            if (src == PWM_SRC_TIMERY) OC1CONbits.OCTSEL = 1;
            break;

        case PWM2:
            OC2CON = 6;
            if (enable_fault_pin == 1) OC2CONbits.OCM = 7;
            if (src == PWM_SRC_TIMERY) OC2CONbits.OCTSEL = 1;
            break;

        case PWM3:
            OC3CON = 6;
            if (enable_fault_pin == 1) OC3CONbits.OCM = 7;
            if (src == PWM_SRC_TIMERY) OC3CONbits.OCTSEL = 1;
            break;

        case PWM4:
            OC4CON = 6;
            if (enable_fault_pin == 1) OC4CONbits.OCM = 7;
            if (src == PWM_SRC_TIMERY) OC4CONbits.OCTSEL = 1;
            break;

        case PWM5:
            OC5CON = 6;
            if (enable_fault_pin == 1) OC5CONbits.OCM = 7;
            if (src == PWM_SRC_TIMERY) OC5CONbits.OCTSEL = 1;
            break;

        case PWM6:
            OC6CON = 6;
            if (enable_fault_pin == 1) OC6CONbits.OCM = 7;
            if (src == PWM_SRC_TIMERY) OC6CONbits.OCTSEL = 1;
            break;

        case PWM7:
            OC7CON = 6;
            if (enable_fault_pin == 1) OC7CONbits.OCM = 7;
            if (src == PWM_SRC_TIMERY) OC7CONbits.OCTSEL = 1;
            break;

        case PWM8:
            OC8CON = 6;
            if (enable_fault_pin == 1) OC8CONbits.OCM = 7;
            if (src == PWM_SRC_TIMERY) OC8CONbits.OCTSEL = 1;
            break;

        case PWM9:
            OC9CON = 6;
            if (enable_fault_pin == 1) OC9CONbits.OCM = 7;
            if (src == PWM_SRC_TIMERY) OC9CONbits.OCTSEL = 1;
            break;

        default: break;
    }

}

/*!
 * 	 ResultError_t pwm_set_duty(PWMChannel pwm,  uint32_t duty)
 * 
 * 	...tbd...
 * 	\param PWMChannel pwm - pwm number PWM1..PWM9
 * 	\param uint32_t duty - 
 * 	\return ResultError_t - NO_ERROR if ok
 */
ResultError_t pwm_set_duty(PWMChannel pwm, int32_t duty) {
    ResultError_t result = RES_NO_ERROR;
    switch (pwm) {
        
        // ---OC1---
        case PWM1:
            // TIMER 4,5
            if (CFGCONbits.OCACLK) {
                if (OC1CONbits.OCTSEL == 1) OC1RS = (PR5 * duty) / 100;
                else OC1RS = (PR4 * duty) / 100;
            } else {
                // TIMER 2,3
                if (OC1CONbits.OCTSEL == 1) OC1RS = (PR3 * duty) / 100;
                else OC1RS = (PR2 * duty) / 100;
            }
            break;
            
        // ---OC2---
        case PWM2:
            // TIMER 4,5
            if (CFGCONbits.OCACLK) {
                if (OC2CONbits.OCTSEL == 1) OC2RS = (PR5 * duty) / 100;
                else OC2RS = (PR4 * duty) / 100;

            } else {
                // TIMER 2,3
                if (OC2CONbits.OCTSEL == 1) OC2RS = (PR3 * duty) / 100;
                else OC2RS = (PR2 * duty) / 100;
            }
            break;
            
        // ---OC3---
        case PWM3:
            // TIMER 4,5
            if (CFGCONbits.OCACLK) {
                if (OC3CONbits.OCTSEL == 1) OC3RS = (PR5 * duty) / 100;
                else OC3RS = (PR4 * duty) / 100;

            } else {
                // TIMER 2,3
                if (OC3CONbits.OCTSEL == 1) OC3RS = (PR3 * duty) / 100;
                else OC3RS = (PR2 * duty) / 100;
            }
            break;
            
        // ---OC4---
        case PWM4:
            // TIMER 2,3
            if (OC4CONbits.OCTSEL == 1) OC4RS = (PR3 * duty) / 100;
            else OC4RS = (PR2 * duty) / 100;
            break;
            
        // ---OC5---
        case PWM5:
            // TIMER 2,3
            if (OC5CONbits.OCTSEL == 1) OC5RS = (PR3 * duty) / 100;
            else OC5RS = (PR2 * duty) / 100;
            break;
            
        // ---OC6---
        case PWM6:
            // TIMER 2,3
            if (OC6CONbits.OCTSEL == 1) OC6RS = (PR3 * duty) / 100;
            else OC6RS = (PR2 * duty) / 100;
            break;
            
        // ---OC7---
        case PWM7:
            // TIMER 6, 7
            if (CFGCONbits.OCACLK) {
                if (OC7CONbits.OCTSEL == 1) OC7RS = (PR7 * duty) / 100;
                else OC7RS = (PR6 * duty) / 100;

            } else {
            // TIMER 2,3
                if (OC7CONbits.OCTSEL == 1) OC7RS = (PR3 * duty) / 100;
                else OC7RS = (PR2 * duty) / 100;
            }
            break;
            
        // ---OC8---
        case PWM8:
            // TIMER 6, 7            
            if (CFGCONbits.OCACLK) {
                if (OC8CONbits.OCTSEL == 1) OC8RS = (PR7 * duty) / 100;
                else OC8RS = (PR6 * duty) / 100;

            } else {
            // TIMER 2,3
                if (OC8CONbits.OCTSEL == 1) OC8RS = (PR3 * duty) / 100;
                else OC8RS = (PR2 * duty) / 100;
            }
            break;
            
        // ---OC9---
        case PWM9:
            // TIMER 6, 7
            if (CFGCONbits.OCACLK) {
                if (OC9CONbits.OCTSEL == 1) OC8RS = (PR7 * duty) / 100;
                else OC8RS = (PR6 * duty) / 100;

            } else {
            // TIMER 2,3
                if (OC9CONbits.OCTSEL == 1) OC9RS = (PR3 * duty) / 100;
                else OC9RS = (PR2 * duty) / 100;
            }
            break;

        default:
            result = RES_INVALID_IDENTIFIER;
            break;
    }
    
    return result;
}