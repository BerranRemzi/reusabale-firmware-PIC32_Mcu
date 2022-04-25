#include <stdint.h>
#include <xc.h>
#include "wdt.h"

void clearWdt(){
    volatile uint16_t * wdtclrkey;

    // get address of upper 16-bit word of the WDTCON SFR
    wdtclrkey = ( (volatile uint16_t *)&WDTCON ) + 1;
    *wdtclrkey = 0x5743;
}