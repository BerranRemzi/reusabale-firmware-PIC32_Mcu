#ifndef DEBUG_H
#define DEBUG_H

#include <xc.h>
#include <stdio.h>
#include "system_config.h"

#ifdef DEBUG_VER
#define PRINTF(...) do{ \
    if(DBG_PIN==1) printf(__VA_ARGS__); \
    }while(0);
#else
    #define PRINTF(...) do{     }while(0);
#endif


#endif
