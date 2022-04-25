#ifndef WDT_H
#define WDT_H
#include <xc.h>



void clearWdt();
#define enableWdt() WDTCONbits.ON=1;    
#define disableWdt() WDTCONbits.ON=0;    

#endif
