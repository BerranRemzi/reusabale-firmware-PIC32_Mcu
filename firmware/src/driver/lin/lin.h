/*!
* @file lin\lin.h
* @author D.Chikov
* @date 10/15/2020, 09:37:33
* @brief ...tbd...
*/


#ifndef _LIN_H
#define _LIN_H

typedef enum{
  LIN1,
  LIN2,
  SWLIN1,
  SWLIN2,
}LINCom;

/*!
* ...tbd...
*/
void lin_init(LINCom lin);
/*!
* ...tbd...
*/
ResultError_t lin_transfer(LINCom lin,uint32_t pid, uint32_t sync, uint32_t *pdata,uint32_t bytes);

#endif