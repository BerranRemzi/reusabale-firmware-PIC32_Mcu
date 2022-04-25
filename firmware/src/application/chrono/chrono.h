/*!
* @file chrono\chrono.h
* @author D.Chikov
* @date 10/15/2020, 10:24:38
* @brief ...tbd...
*/


#ifndef CHRONO_H
#define CHRONO_H
#include "typedef_global.h"



  #include "_table1.h"    
  #include "_table4.h"  
    #include "systmr.h" 
#include <xc.h>


      
/*!
* MACRO:...tbd...
*/
#define DIVIDER_1_1     SYSTMRB_PRESCALE1_1
/*!
* MACRO:...tbd...
*/
#define DIVIDER_1_2     SYSTMRB_PRESCALE1_2
/*!
* MACRO:...tbd...
*/
#define DIVIDER_1_4     SYSTMRB_PRESCALE1_4
/*!
* MACRO:...tbd...
*/
#define DIVIDER_1_8     SYSTMRB_PRESCALE1_8
/*!
* MACRO:...tbd...
*/
#define DIVIDER_1_16    SYSTMRB_PRESCALE1_16
/*!
* MACRO:...tbd...
*/
#define DIVIDER_1_32    SYSTMRB_PRESCALE1_32
/*!
* MACRO:...tbd...
*/
#define DIVIDER_1_64    SYSTMRB_PRESCALE1_64
/*!
* MACRO:...tbd...
*/
#define DIVIDER_1_256   SYSTMRB_PRESCALE1_256



    
//    CHRONO1 (uses PIC32.TM2)
//-----------------------------------------------------------------------------------------------------
#define CHRONO1_MAX  (TBL1_MAX)
/*!
* MACRO:...tbd...
*/
 #define CHRONO1_SET_DIVIDER(_DIVIDER_)  systmrB_enable(TIMER6, (_DIVIDER_), 0)
/*!
* MACRO:...tbd...
*/
 #define CHRONO1_START() do{T6CONbits.ON=1;TMR6=0;IFS0bits.T6IF=0;}while(0)
/*!
* MACRO:...tbd...
*/
 #define CHRONO1_STOP() do{T6CONbits.ON=0;}while(0)
/*!
* MACRO:...tbd...
*/
 #define CHRONO1_IS_TIMEOUT() ( IFS0bits.T6IF)
/*!
* ...tbd...
*/
 #define CHRONO1_SET_TIMEOUT(_TIMEOUT_) do{ CHRONO1_SET_TIMEOUT_TICKS( TBL1[ (_TIMEOUT_) ] );}while(0)
/*!
* ...tbd...
*/
 #define CHRONO1_SET_TIMEOUT_TICKS(_TIMEOUT_) do{PR6=(_TIMEOUT_); }while(0);
/*!
* MACRO:...tbd...
*/
 #define CHRONO1_ELAPSED_TICKS()  ((uint32_t)TMR6)
/*!
* MACRO:...tbd...
*/
 #define CHRONO1_ELAPSED()  0 //TBD
/*!
* MACRO:...tbd...
*/
  #define CHRONO1_DELAY(_DELAY_) do{\
   CHRONO1_DELAY_TICKS(TBL1[_DELAY_]);\
 }while(0)
/*!
* MACRO:...tbd...
*/
 #define CHRONO1_DELAY_TICKS(_DELAY_) do{\
   CHRONO1_SET_TIMEOUT_TICKS(_DELAY_);\
   CHRONO1_START();\
   while(!CHRONO1_IS_TIMEOUT());\
 }while(0)
/*!
* MACRO:...tbd...
*/
#define CHRONO1_RESTART() do{ IFS0bits.T6IF=0;  }while(0)




//     TMR2
//-----------------------------------------------------------------------------------------------------
#define CHRONO2_MAX     (TBL4_MAX)
/*!
* MACRO:...tbd...
*/
 #define CHRONO2_SET_DIVIDER(_DIVIDER_) systmrB_enable(TIMER8_TIMER9, (_DIVIDER_) , 0)
/*!
* MACRO:...tbd...
*/
 #define CHRONO2_START() do{  T9CONbits.ON=1; TMR9=0; TMR8=0; IFS1bits.T9IF=0;  }while(0)
/*!
* MACRO:...tbd...
*/
 #define CHRONO2_STOP()  do{  T9CONbits.ON=0; }while(0)
/*!
* MACRO:...tbd...
*/
 #define CHRONO2_IS_TIMEOUT() IFS1bits.T9IF
/*!
* ...tbd...
*/
 #define CHRONO2_SET_TIMEOUT(_TIMEOUT_) do{CHRONO2_SET_TIMEOUT_TICKS( TBL4[_TIMEOUT_] );}while(0)
/*!
* ...tbd...
*/
 #define CHRONO2_SET_TIMEOUT_TICKS(_TIMEOUT_) do{ PR9=(_TIMEOUT_)>>16;PR8=(_TIMEOUT_);}while(0);
/*!
* MACRO:...tbd...
*/
#define CHRONO2_ELAPSED_TICKS()  ( (uint32_t)TMR8)|(uint32_t)TMR9<<16)
/*!
* MACRO:...tbd...
*/
#define CHRONO2_RESTART() do{IFS1bits.T9IF =0;  }while(0)

/*!
* MACRO:...tbd...
*/
#define CHRONO2_ELAPSED()  //TBD
/*!
* MACRO:...tbd...
*/
#define CHRONO2_DELAY(_DELAY_) do{\
   CHRONO2_DELAY_TICKS( TBL4[_DELAY_] );\
 }while(0)
/*!
* MACRO:...tbd...
*/
 #define CHRONO2_DELAY_TICKS(_DELAY_) do{\
   CHRONO2_SET_TIMEOUT_TICKS(_DELAY_);\
   CHRONO2_START();\
   while(!CHRONO2_IS_TIMEOUT());\
 }while(0)
//-----------------------------------------------------------------------------------------------------






/*!
* ...tbd...
*/
void chrono_init();




#endif
