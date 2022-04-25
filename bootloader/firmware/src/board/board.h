
#ifndef _BOARD_H
#define _BOARD_H

#ifdef __cplusplus  // Provide C++ Compatibility
    extern "C" {
#endif

#include "p32xxxx.h"

// choose baord
#define BASE_BOARD       
//#define LDM_BOARD
        
        
// [debug]       
#if defined(BASE_BOARD)
  #define SYS_CLK_FREQ                    250000000ul
  #define LED2(_ON_)    gpio_set(GPIO('A',0), (_ON_)==0)
  #define LED1(_ON_)    gpio_set(GPIO('G',9), (_ON_)==0) 
  #define DBG_PIN                         !PORTBbits.RB2      // key
  #define DBG_UART                        UART3

#elif defined(LDM_BOARD)
  #define SYS_CLK_FREQ                    50000000ul
  #define DBG_PIN                         !PORTAbits.RA4  // jumper
  #define LED1(_ON_)  if(DBG_PIN)   gpio_set(GPIO('G', 15), (_ON_)==0)
  #define LED2(_ON_)  if(DBG_PIN)   gpio_set(GPIO('A', 5),  (_ON_)==0)     
  #define DBG_UART                        UART3
#else 
  #error "Define board!"
#endif

void BOARD_init();

#ifdef __cplusplus
}
#endif

#endif
