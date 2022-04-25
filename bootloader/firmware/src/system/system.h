#ifndef _SYSTEM_H
#define _SYSTEM_H

#ifdef __cplusplus  // Provide C++ Compatibility
    extern "C" {
#endif

 #include "system_config.h"       



        
/*!
* System initialize
*/
        
void SYS_Initialize();

/*!
* System tasks init
*/
void SYS_Tasks();

/*!
* System time start
*/
void SYSTEM_timer_start(int period);

void SYSTEM_delay_init();

/*!
* System timer is timeout
*/
bool SYSTEM_timer_timeout();

/*!
* System timer elapsed flag
*/
uint32_t SYSTEM_timer_elapsed();


//extern Status_t g_Status;
#ifdef __cplusplus
}
#endif


#include "system_config.h"
#endif // _SYSTEM_H

