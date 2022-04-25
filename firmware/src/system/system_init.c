/*!
* @file system_init.c
* @author D.Chikov
* @date 10/15/2020, 09:37:34
* @brief System initialization 
*/


#include "system.h"
#include <xc.h>
#include "usart.h"
#include "gpio.h"
#include <stdio.h>
#include "nvm.h"
#include "wdt.h"
#include "systmr.h"
#include "system.h"
#include "adc.h"
#include "pwm.h"
#include "board.h"
#include "config.h"
#include "app.h"
#include "chrono.h"
#include "sys.h"
#include "planner/planner.h"



/*!
* 	 void  SYS_Initialize( )
* 
* 	This functin makes hardware setup and buffer clear
*/
void  SYSTEM_Initialize( )
{       
    
    sys_unlock();
    CFGCONbits.DMAPRI = 0; 
    CFGCONbits.CPUPRI = 0; 
    CFGCONbits.ICACLK = 0;
    CFGCONbits.OCACLK = 1;
    CFGCONbits.IOLOCK = 0;                         
    CFGCONbits.PMDLOCK = 0;                           
    CFGCONbits.PGLOCK = 0;                            
    CFGCONbits.USBSSEN = 0;
    CFGCONbits.IOANCPN = 0; 
    CFGCONbits.ECCCON = 0b11;                            
    CFGCONbits.JTAGEN = 0;   
    CFGCONbits.TROEN = 0;
    CFGCONbits.TDOEN = 0;
       
    INT_SetMultivectoredMode(1);
    sys_lock();
    
    SYSTEM_delay_init();
    
    chrono_init();    	           
    
    SYSTEM_CommInit(); 
    
    enableWdt();
    INT_EnableInterrupts();  
                  
    PLANNER_Init(100);// 100us
    APP_Initialize();	    
 

}

