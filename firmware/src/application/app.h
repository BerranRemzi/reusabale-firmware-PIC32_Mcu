/*!
* @file app.h
* @author D.Chikov
* @date 10/15/2020, 09:37:33
* @brief ...tbd...
*/


#ifndef _APP_H
#define _APP_H

#ifdef __cplusplus
    extern "C" {
#endif

#include "system.h"
#include "typedef_global.h"        
#include "foreach.h"

        
typedef void(*AppFunc)();
typedef struct{
    AppFunc func;
    int delay;
    uint32_t start_tmr;
}APP_Task;

void add_function_to_loop( AppFunc func, int delay);
void remove_function_from_loop(AppFunc);
bool function_in_loop(AppFunc func);
void kick_function_timers();


/*!
* MACRO:Streaming start 
*/
#define STREAM_START() do{\
  application_break = 0;\
  DisableWdt();\
  }while(0)
  
/*!
* MACRO:Streaming stop
*/
#define STREAM_STOP()  do{\
  EnableWdt();\
  application_break = 0;\
  }while(0)



#ifndef ABS
/*!
* Abs value
*/
  #define ABS(X) ( ((X) < 0 ) ? (-(X)) : (X))
#endif


/*!
* Calculate byte count from bits count
*/
#define CALC_BYTE_COUNT(VAL) (VAL)/8+(((VAL)%8)>0?1:0)  

   

/*!
* MACRO:Returns buffer bit (buffer is bytearray)
*/
#define BUF_BIT(_BUFFER_,_IDX_) ((_BUFFER_[(_IDX_)/8] & (1<<((_IDX_)%8)) )!=0)
 

/*!
* MACRO:Add bit to buffer (buffer is bytearray)
*/
#define BUF_ADD_BIT(_BUFFER_,_IDX_,_BIT_) do{\
  _BUFFER_[(_IDX_)>>3] &= ~((1)<<((_IDX_)&0x07));\
  _BUFFER_[(_IDX_)>>3] |= ((_BIT_)<<((_IDX_)&0x07));\
  (_IDX_)++;\
}while(0)


typedef struct{
    uint8_t *data;
    uint32_t size;
    uint32_t size_bytes;    
}BitArray;


void add_bit(BitArray *parr, bool bit_value);


/*!
* Application memory size 
*/
#define APPLICATION_SIZE		(500000)        


// some abstract variable which means result count
extern uint32_t app_result_count;

// all memory allocated for aplication data. 
//lets say it is application memory
extern uint8_t application_data[APPLICATION_SIZE];


/*!
* ...tbd...
*/
void APP_print_inf();

// initialization of application        
/*!
* ...tbd...
*/
void  APP_Initialize();

/*!
* ...tbd...
*/
void APP_Run();

/*!
* ...tbd...
*/
void APP_Break();




extern volatile  bool APP_BREAK;

#define APP_Clear() app_result_count=0





#include "genclk.h"


#ifdef  __cplusplus
}
#endif

#endif

