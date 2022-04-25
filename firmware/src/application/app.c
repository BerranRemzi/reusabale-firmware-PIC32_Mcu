/*!
* @file app.c
* @author D.Chikov
* @date 10/15/2020, 09:37:33
* @brief ...tbd...
*/


#include "app.h"
#include <sys/kmem.h>
#include "typedef_global.h"
#include "string_utils.h"
#include "chrono.h"
#include "nvm.h"
#include "dio.h"
#include "usart.h"
#include "stdio.h"
#include "string.h"
#include "rd_buffer.h"
#include "systmr.h"
#include "system.h"
#include "config.h"
#include "system.h"

#include "build.h"




volatile const uint32_t __attribute__((section(".sw_version"))) VERSION = BUILD;




volatile  bool APP_BREAK =0;
volatile static int APP_func_count = 0;
volatile static APP_Task APP_TASKS[5];

/*!
* 	 void APP_Break()
* 
* 	...tbd...
* 	\return void -...
*/
void APP_Break(){
    APP_BREAK = 1;
}

void APP_function_run();


uint32_t app_result_count;

uint8_t application_data[APPLICATION_SIZE];




/*!
* 	 void APP_print_inf()
* 
* 	...tbd...
* 	\return void -...
*/
void APP_print_inf()
{
    printf("ON Semiconductor,%s,0x%.8x,%s [V2]\n",PROJECT, BUILD, BUILD_DATE);
}


/*!
* 	 void  APP_Initialize()
* 
* 	...tbd...
* 	\return void -...
*/
void  APP_Initialize()
{
    
   APP_BREAK =0 ;   
   dio_init();

	
	int32_t i = 0;		
    
	//check memory for buffers
	for (i = 0; i < APPLICATION_SIZE; i++)
	{
		application_data[i] = 0xaa;
		if (application_data[i] == 0xaa )
		{
			application_data[i] = 0x00;
		}
		else
		{			
            SYSTEM_MakeError(SYS_ERROR_MEMORY, "Error application memory");
			break;
		}
	}	
             	   
    
    APP_print_inf();    
}









/*!
* 	 void APP_Run()
* 
* 	This is main application routine. This application just Reads text commands from UART and Writes response to UART.
*/
void APP_Run()
{   
    // read lines from uart if possible
    SYSTEM_ReadUART();
    // write data to UART if something in buffer
    SYSTEM_WriteUART();    
    APP_function_run();
    
    if(KEY1==1){
        LED2(0);
    }else LED2(1);
}

void APP_function_run(){
    int i=0;
    for(i=0;i<APP_func_count;i++){        
        if(APP_TASKS[i].func != 0 ){
            bool timeout = false;
            const uint32_t start_tmr = APP_TASKS[i].start_tmr;
            const uint32_t timer = _CP0_GET_COUNT();
            const uint32_t scale = SYS_CLK_FREQ/1000/2;
            if( start_tmr >timer)
            {
                timeout = (timer + (0xffffffff - start_tmr)) > APP_TASKS[i].delay*scale;
            }
            else{
                timeout = (timer - start_tmr) > APP_TASKS[i].delay*scale;
            }
            if(timeout==true){
                (*APP_TASKS[i].func)();
                APP_TASKS[i].start_tmr = timer;
            }
        }
    }
    
}

void add_function_to_loop(AppFunc func,int delay){
    if(APP_func_count<5){        
        APP_TASKS[APP_func_count].func = func;
        APP_TASKS[APP_func_count].delay = delay;
        APP_TASKS[APP_func_count].start_tmr = _CP0_GET_COUNT();
        APP_func_count++;
    }    
}

bool function_in_loop(AppFunc func){
    int i;
    for(i=0;i<5;i++){
        if(APP_TASKS[i].func== func) return true;        
    }
    return false;
}

void remove_function_from_loop(AppFunc func){
    int i=0;
    int i2=0;
    for(i=0;i<5;i++){
        APP_Task tmp = APP_TASKS[i];
        APP_TASKS[i].func=0;
        APP_TASKS[i].delay =0;

        if(tmp.func != func)   {
            APP_TASKS[i2++] = tmp;
        }
        else APP_func_count--;
    }    
}

void kick_function_timers(){
    if(APP_func_count>0){
        int i=0;    
        for(i=0;i<APP_func_count;i++){               
            APP_TASKS[i].start_tmr = _CP0_GET_COUNT();
        }    
    }
}

void add_bit(BitArray *parr, bool bit_value){
    BUF_ADD_BIT(parr->data, parr->size, bit_value);
    parr->size_bytes = CALC_BYTE_COUNT(parr->size);
}
