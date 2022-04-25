#include "system.h"

#include <stdio.h>
#include "debug.h"
#include "board.h"

#include "wdt.h"



// setup hardware
void SYS_Initialize( )
{       
    BOARD_init();
    
     // TIMER initialize system timers
    SYSTEM_delay_init();
    
    enableWdt();
    
}

