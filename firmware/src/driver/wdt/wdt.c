/*!
* @file wdt\wdt.c
* @author D.Chikov
* @date 10/15/2020, 09:37:33
* @brief ...tbd...
*/


#include <stdint.h>
#include <xc.h>
#include "wdt.h"


/*!
* 	 void clearWdt()
* 
* 	...tbd...
* 	\return void -...
*/
void clearWdt(){
    volatile uint16_t * wdtclrkey;
    
    // get address of upper 16-bit word of the WDTCON SFR
    wdtclrkey = ( (volatile uint16_t *)&WDTCON ) + 1;
    *wdtclrkey = 0x5743;
}


/*!
* 	 void softwareReset()
* 
* 	...tbd...
* 	\return void -...
*/
void softwareReset() {
    SYSKEY    = 0x00000000;    
    SYSKEY 		= 0xAA996655;    
    SYSKEY 		= 0x556699AA;
    asm("nop");
    RSWRSTbits.SWRST = 1;    
    RSWRSTbits.SWRST = 1; 
    asm("nop");
    SYSKEY 		= 0x33333333;    
    
}