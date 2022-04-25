#ifndef _BOOTLOADER_H
#define _BOOTLOADER_H

    /*
     * Microchip standard protocol
     Request: 9/24/2012 1:01:41 AM.08664

     01 10 01 21 10 10 04                                   ...!...

    Answer: 9/24/2012 1:01:41 AM.10764 (+0.0200 seconds)

     01 10 01 10 01 00 10 01 10 04 04                  ...........
     * 
    Erase : 01 02 42 20 04 
    
     * 
     * 
     * 
     * {01}{10}{01}{21}{10}{10}{04}
     * {01}{10}{01}{00}{10}{01}{11}{27}{04}
     */


#ifdef __cplusplus
    extern "C" {
#endif

#include "system.h"
#include "typedef_global.h"        
        
        
ResultError_t  BOOTLOADER_Initialize();

// Updater 1 - standard microchip bootloader
bool BOOTLOADER_WaitSequence();
void BOOTLOADER_ExecuteUartUpdater();   

// Updater 2 - bootloader just copies memory from MEM2->MEM1 if it is newer
void BOOTLOADER_ExecuteLiveUpdater();
bool BOOTLOADER_CheckNeedUpdate();
bool BOOTLOADER_AppExist();

#ifdef  __cplusplus
}
#endif

#endif

