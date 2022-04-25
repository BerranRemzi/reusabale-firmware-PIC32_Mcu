/*!
* @file chrono\chrono.c
* @author D.Chikov
* @date 10/16/2020, 16:09:28
* @brief ...tbd...
*/


#include <xc.h>
#include "systmr.h"
#include "chrono.h"
#include "board.h"




/*!
* 	 void chrono_init()
* 
* 	Chronometers initialize
*   Uses TIMER 6,TIMER8, TIMER9
*/
void chrono_init()
{           
   
    // 1 to 1 clock means 250Mhz -> PBCLK/2(divided by 2) -> 125mhz to Timer
    
    //here (1us == 125 ticks)
    //     This chronometer intended to measure time precisely 1..520us
    CHRONO1_SET_DIVIDER(DIVIDER_1_1);
    
    // here 250Mhz/2/4 = 1 tick 31.25 (31 ticks = ~1 us)
    //     This is less precise  chronometer 1..200000us
    CHRONO2_SET_DIVIDER(DIVIDER_1_4);
    
}