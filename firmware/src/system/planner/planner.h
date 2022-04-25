/*!
* @file planner\planner.h
* @author D.Chikov
* @date 10/15/2020, 09:37:34
* @brief ...tbd...
*/


#ifndef PLANNER_H
#define PLANNER_H
#include "typedef_global.h"


/*!
* Maximum tasks in planner 
*/
#define MAX_TASKS      20              

typedef enum { TaskService, TaskNormal}TaskMode;
typedef struct
{
   void (*pFunc) (void*);
   void *pData;
   TaskMode mode;
   volatile uint32_t tmr;
   uint32_t period; // in us
   bool continuous;
   volatile bool suspended;
   volatile bool run;
   volatile bool active;
}Task_t;

Task_t *PLANNER_closestTask();
/*!
* ...tbd...
*/
void PLANNER_Init ();
/*!
* ...tbd...
*/
bool PLANNER_AddTask (Task_t *pTask);

bool PLANNER_hasTask( Task_t *pTask);
/*!
* ...tbd...
*/
void PLANNER_SuspendTask (Task_t *pTask);
/*!
* ...tbd...
*/
void PLANNER_RestartTask (Task_t *pTask);
/*!
* ...tbd...
*/
void PLANNER_SetTaskData (Task_t *pTask, void *pData);
/*!
* ...tbd...
*/
void PLANNER_DeleteTask (Task_t *pTask);
/*!
* ...tbd...
*/
void PLANNER_DispatchTask (void);



#endif
