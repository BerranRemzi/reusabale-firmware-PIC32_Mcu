#include <xc.h>
#include <sys/attribs.h>

#include "system/system.h"
#include "app.h"
#include <stdio.h>
#include "board.h"
#include "wdt.h"
#include "planner.h"


// dummy goto instead of bootloader
__attribute__((section(".start_BFC00000"))) void start_app (void)
{    
   asm("j 0x9D000000");
}


int main ( void )
{   
        
    // initiaize board specific things
    BOARD_Initialize();   
    
    // initialize system planner, memory, timers
   SYSTEM_Initialize();        
   if(SYSTEM_ErrorCount() >0){
       LED2(1);       LED1(0);
   }   
   else{
       LED1(0);        LED2(1);
   }
   
   while(1) {
       
       // dispatch actual task
       APP_Run();
       
       // kick watch dog
       clearWdt();
   }
   

   //dummy
   start_app ();         

   
   return 1;
}
