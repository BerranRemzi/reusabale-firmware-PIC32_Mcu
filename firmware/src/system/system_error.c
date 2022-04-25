/*!
* @file system_error.c
* @author D.Chikov
* @date 10/15/2020, 09:37:34
* @brief ...tbd...
*/


#include "system_error_codes.h"
#include "system.h"
#include "board.h"



typedef struct{
   void (*error_handler)(void);
   uint32_t error_code;
} ErrorHandlers;


static ErrorHandlers err_handlers[20];
static int err_handlers_count;

static uint32_t errors[100];
static uint32_t errors_count;




/*!
* 	 void SYS_MakeError(uint32_t error_code, char *pdescription)
* 
* 	...tbd...
* 	\param uint32_t error_code -...
* 	\param char *pdescription -...
* 	\return void -...
*/
void SYSTEM_MakeError(uint32_t error_code, char *pdescription){
    PRINTF("\nERROR:%d (%s)",error_code,pdescription);
    LED2(1);       
    LED1(0);
    if(errors_count<100){
        errors[errors_count++] = error_code;
    }
    
}


/*!
* 	 uint32_t SYS_ErrorCount()
* 
* 	...tbd...
* 	\return uint32_t -...
*/
uint32_t SYSTEM_ErrorCount(){
    return errors_count;
}


/*!
* 	 void SYS_ClearErrors()
* 
* 	...tbd...
*/
void SYSTEM_ClearErrors(){
    LED2(0);
    errors_count =0;
}


/*!
* 	 void SYS_AssignHandler(ErrorCodes error_code, void (*error_handler)(void))
* 
* 	...tbd...
* 	\param ErrorCodes error_code -...
* 	\param void (*error_handler)(void) -...
*/
void SYS_AssignHandler(ErrorCodes error_code, void (*error_handler)(void)){     
    err_handlers[err_handlers_count].error_code = error_code;
    err_handlers[err_handlers_count].error_handler = error_handler;
    err_handlers_count++;
    
}
