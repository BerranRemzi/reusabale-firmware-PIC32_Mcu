/*!
* @file refclk\refclk.h
* @author D.Chikov
* @date 10/15/2020, 09:37:33
* @brief ...tbd...
*/



#ifndef _DRV_REFCLK_H
#define _DRV_REFCLK_H

#include <xc.h>

#ifdef __cplusplus  // Provide C++ Compatibility
    extern "C" {
#endif
#include "typedef_global.h"       
        
     
typedef enum {
#ifdef REFO1CON
          REFCLKO1,
    #endif
    
#ifdef REFO2CON
      REFCLKO2,      
#endif

#ifdef REFO3CON
      REFCLKO3,
#endif
                  
#ifdef REFO4CON
      REFCLKO4,    
#endif
      REFCLK_COUNT
}RefClk;

// REFCLK sources
typedef enum {
    REFCLK_SYSCLK=0,
    REFCLK_PBCLK1=1,
    REFCLK_POSC=2,
    REFCLK_FRC=3,
    REFCLK_LPRC=4,
    REFCLK_SOSC=5,
    REFCLK_SPLL=7,
    REFCLK_REFCLKI=8,
    REFCLK_BFRC=9,
}RefClkSource;

/*!
* Configure REFLCK OUT. not configurates GPIO
*/
int refclk_out_cfg(RefClk num, RefClkSource src, uint32_t div, uint32_t trim);
/*!
* Enables REFCLKO output
*/
void refclk_out_enable(RefClk num, bool enable);


#ifdef __cplusplus
}
#endif

#endif
