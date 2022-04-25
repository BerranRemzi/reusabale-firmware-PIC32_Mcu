/*!
* @file typedef_global.h
* @author D.Chikov
* @date 10/15/2020, 09:37:34
* @brief ...tbd...
*/


#ifndef TYPEDEF_GLOBAL_H
#define TYPEDEF_GLOBAL_H

#include <stdint.h>
#include <stdbool.h>


#ifndef NULL
    #define NULL 0
#endif

#ifndef FALSE
    #define FALSE 0
#endif

#ifndef TRUE
    #define TRUE 1
#endif



#ifndef ABS
  #define ABS(X) ( ((X) < 0 ) ? (-(X)) : (X))
#endif

typedef enum {
    RES_NO_ERROR     = (0) ,
    RES_ERROR        = (-1),
    RES_EMPTY        = (-2),
    RES_BUSY         = (-3),
    RES_BROKEN_DATA  = (-4),
    RES_INVALID_POINTER  = (-5),
    RES_INVALID_IDENTIFIER=(-6),
    RES_COMM_ERROR = (-7),
    RES_SPIERR=(-7),
    
    /* define*/            
} ResultError_t;



#endif
