/*!
* @file planner\planner.c
* @author D.Chikov
* @date 10/15/2020, 09:37:34
* @brief ...tbd...
*/


#include "planner.h"
#include <sys/attribs.h>
#include "systmr.h"
#include "int.h"
#include "board.h"



static Task_t  *taskArray[MAX_TASKS];  
volatile static uint32_t  arrayTail;             
static Task_t *_closest_task=0;

static struct{
    int period;
}config;

/*!
* 	 void PLANNER_Init()
*    int period - in us
* 	...tbd...
* 	\return void -...
*/
void PLANNER_Init(int period)
{
    int i=0;
    arrayTail = 0;
    for(i=0;i<MAX_TASKS;i++){
        taskArray[i] =0;
    }
    if(period > 500){
        systmrA_enable( SYSTMRA_PRESCALE1_1, SYS_CLK_FREQ/2/1e6*period);
    }
    else if(period <= 4000){
        systmrA_enable( SYSTMRA_PRESCALE1_8, SYS_CLK_FREQ/2/8/1e6*period);
    }else{
        // ERROR
    }
    config.period = period;
    systmrA_interrupt_enable(true, 7,  1);
}

Task_t *PLANNER_closestTask(){
    return _closest_task;
}

bool PLANNER_hasTask( Task_t *pTask){
    int i=0;
    for(; i < arrayTail; i++)  {
       if(taskArray[i] == pTask)
               return true;
    }
    return false;
}


/*!
* 	 bool PLANNER_AddTask (Task_t *pTask)
* 
* 	...tbd...
* 	\param Task_t *pTask -...
* 	\return bool -...
*/
bool PLANNER_AddTask (Task_t *pTask)
{
   uint32_t result = 0;
   
   if(pTask) 
   {
       pTask->tmr =0;
       pTask->suspended =0;
       pTask->run =0;
       // check if task is already in queue
        if(PLANNER_hasTask(pTask)) return 0;

        if (arrayTail < MAX_TASKS)   
        {                            
           INT_DisableInterrupts();   
           taskArray[arrayTail++] = pTask;
          INT_EnableInterrupts();
           result = 1;
        }
   }
   return result;
}


/*!
* 	 void PLANNER_DeleteTask (Task_t *pTask)
* 
* 	...tbd...
* 	\param Task_t *pTask -...
* 	\return void -...
*/
void PLANNER_DeleteTask (Task_t *pTask)
{
   uint32_t i=0;
   
   for (; i<arrayTail; i++)
   {
      if(taskArray[i] == pTask)           
      {         
          INT_DisableInterrupts();
         if(i != (arrayTail - 1))         
         {                                
            taskArray[i] = taskArray[arrayTail - 1];
         }
         arrayTail--;                     
         INT_EnableInterrupts();
         return;
      }
   }
}

/*!
* 	 void PLANNER_SetTaskData (Task_t *pTask, void *pData)
* 
* 	...tbd...
* 	\param Task_t *pTask -...
* 	\param void *pData -...
* 	\return void -...
*/
void PLANNER_SetTaskData (Task_t *pTask, void *pData){
   uint32_t i=0;
   
   for (; i<arrayTail; i++)
   {
         if(taskArray[i] == pTask){
            taskArray[i]->pData = pData;
            return ;
         }
 	}    
}


/*!
* 	 void PLANNER_DispatchTask()
* 
* 	...tbd...
* 	\return void -...
*/
void PLANNER_DispatchTask()
{
   uint32_t i=0;
   void (*pFunction) (void*);
   void *pData;
   for (; i<arrayTail; i++)    
   {       
        if(taskArray[i]->run == 1 && taskArray[i]->suspended==0)
        {
            taskArray[i]->run =0;
             pFunction = taskArray[i]->pFunc;
             pData =     taskArray[i]->pData;
             taskArray[i]->active = 1;
             (*pFunction)(pData);
             taskArray[i]->active = 0;


             if(taskArray[i]->continuous ==0)
                PLANNER_DeleteTask(taskArray[i]);
        }
   }
}


/*!
* 	 void PLANNER_RestartTask (Task_t *pTask)
* 
* 	...tbd...
* 	\param Task_t *pTask -...
*/
void PLANNER_RestartTask (Task_t *pTask)
{
  uint32_t i=0;
 for (; i<arrayTail; i++)    
   {
      if(taskArray[i] == pTask)
           taskArray[i]->suspended = 0;
  }
}


/*!
* 	 void PLANNER_SuspendTask (Task_t *pTask)
* 
* 	...tbd...
* 	\param Task_t *pTask -...
*/
void PLANNER_SuspendTask (Task_t *pTask){
uint32_t i=0;
 for (; i<arrayTail; i++)    
   {
      if(taskArray[i] == pTask)
           taskArray[i]->suspended = 1;
   }
}





#include "system.h"

/*!
 * 	 void __ISR(_TIMER_1_VECTOR, IPL7AUTO) PLANNER_Run(void)
 * 
 * 	...tbd...
 * 	\param _TIMER_1_VECTOR -...
 * 	\param IPL7AUTO) PLANNER_Run(void -...
 */
void __ISR(_TIMER_1_VECTOR, IPL7AUTO) PLANNER_Run(void) {
    systmrA_clear_flag();
    uint32_t i;
    uint32_t min = 0xffffffff;
    for (i = 0; i < arrayTail; i++) {
        if (taskArray[i]->suspended == 1) continue;

        taskArray[i]->tmr += config.period;
        if (taskArray[i]->tmr >= taskArray[i]->period) {
            // service
            if (taskArray[i]->mode == TaskService) {
                taskArray[i]->active=1;
                (taskArray[i]->pFunc)(taskArray[i]->pData);
                taskArray[i]->active=0;
            }                // normal
            else {
                taskArray[i]->run = 1;
            }
            taskArray[i]->tmr = 0;
        }

        const uint32_t remain_time = taskArray[i]->period - taskArray[i]->tmr;
        if (min > remain_time) {
            min = remain_time;
            _closest_task = taskArray[i];
        }
    }
}



