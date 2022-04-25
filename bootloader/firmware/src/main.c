#include "system/system.h"
#include "bootloader.h"
#include <xc.h>
#include <stdio.h>
#include "board.h"

int main ( void )
{
    
   SYS_Initialize();
   
   BOOTLOADER_Initialize();
   
   if(!BOOTLOADER_AppExist() || BOOTLOADER_WaitSequence() == true )
   {       
       // start Bootloader 1
       BOOTLOADER_ExecuteUartUpdater();
   }
   
#ifdef USE_LIVEUPDATE
   else  // check backup firmware 
   {
       #ifdef DEBUG_VER
         bool need_update = DBG_PIN2;
       #else
         bool need_update = BOOTLOADER_CheckNeedUpdate() ;
       #endif

       if( need_update )
       {
           // start Bootloader 2
           BOOTLOADER_ExecuteLiveUpdater();
       }
   }
#endif
   
   asm("j 0x9d000000");
   
   return 1;
}



