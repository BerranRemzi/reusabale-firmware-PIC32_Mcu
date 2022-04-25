/*!
* @file modules\sw_spi.h
* @author D.Chikov
* @date 10/15/2020, 10:24:38
* @brief ...tbd...
*/


#ifndef MOD_SWSPI_H
#define MOD_SWSPI_H

#include "typedef_global.h"

/*!
* MACRO:...tbd...
*/
#define FUNC_SWSPI  (1)

/*!
* ...tbd...
*/
bool function_swspi(const char *ptext);

/*!
* ...tbd...
*/
bool function_swspiconf(const char *ptext,int);

/*!
* ...tbd...
*/
bool function_swspi_result();

/*!
* ...tbd...
*/
bool function_swspics(const char* ptext, int);

#endif