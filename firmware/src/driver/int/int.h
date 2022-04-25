/*!
* @file int\int.h
* @author D.Chikov
* @date 10/15/2020, 09:37:33
* @brief ...tbd...
*/


#ifndef INT_H
#define INT_H
#include "typedef_global.h"

/*!
* ...tbd...
*/
void INT_SetMultivectoredMode(bool on);

/*!
* ...tbd...
*/
void INT_SetSingleVectoredMode();

/*!
* Disable global Interrupts
*/
#define INT_DisableInterrupts() \
            asm volatile("di")

/*!
* Enable global interrupts
*/
#define INT_EnableInterrupts() \
            asm volatile("ei")


#endif 