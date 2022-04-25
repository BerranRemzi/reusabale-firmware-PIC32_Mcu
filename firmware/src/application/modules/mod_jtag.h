/*!
* @file modules\jtag.h
* @author D.Chikov
* @date 10/15/2020, 10:24:38
* @brief ...tbd...
*/


#ifndef JTAG_H
#define JTAG_H


#include "typedef_global.h"


/*!
* ...tbd...
*/
bool jtag_conf(const char *ptext);
/*!
* ...tbd...
*/
bool jtag_set(const char *ptext);
/*!
* ...tbd...
*/
bool jtag_data(char *ptext);



#endif