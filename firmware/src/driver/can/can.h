/*!
* @file can\can.h
* @author D.Chikov
* @date 10/15/2020, 09:37:33
* @brief ...tbd...
*/


#ifndef _CAN_H
#define _CAN_H
#include "typedef_global.h"


typedef enum{
    CAN1,
    CAN2
}Can;

/*!
* ...tbd...
*/
void can_enable(Can cann);
/*!
* ...tbd...
*/
ResultError_t can_write(Can cann);
/*!
* ...tbd...
*/
ResultError_t can_read(Can cann);

#endif