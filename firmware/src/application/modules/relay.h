/*!
* @file modules\relay.h
* @author D.Chikov
* @date 10/15/2020, 10:24:38
* @brief Relay module header
*/


#ifndef RELAY_H
#define RELAY_H

#include "typedef_global.h"

/*!
 *  CHIP_AMIS39100 - 
 *  CHIP_74HC595 - 
 *  all this methods has dedicated  pins
 */
typedef enum {CHIP_AMIS39100,CHIP_74HC595} ChipType;

/*!
* Configure relay method
*/
bool relay_conf(ChipType chip_type, int32_t size);
/*!
* Sets relay value
*/
bool relay_set(int32_t relay, bool value);
/*!
* Reads relay value
*/
bool relay_get(int32_t relay_out);

#endif