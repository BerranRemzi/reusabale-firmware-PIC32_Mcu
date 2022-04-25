/*!
* @file modules\scanchain1.h
* @author D.Chikov
* @date 10/15/2020, 10:24:38
* @brief ...tbd...
*/


#ifndef SCANCHAIN_H
#define SCANCHAIN_H
#include "typedef_global.h"



/*!
* ...tbd...
*/
bool scanchan1_transfer(const char *ptext);
/*!
* ...tbd...
*/
bool scanchain1_result();


/*!
* ...tbd...
*/
bool scanchain2_transfer(const char *ptext);
/*!
* ...tbd...
*/
bool scanchain2_result(int scanchain_number );
/*!
* ...tbd...
*/
bool scanchain3_transfer(const char *ptext);
/*!
* ...tbd...
*/
bool scanchain3_result(int scanchain_number);

bool scanchain_conf(const char *p);

#endif