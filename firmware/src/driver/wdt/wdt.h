/*!
* @file wdt\wdt.h
* @author D.Chikov
* @date 10/15/2020, 09:37:34
* @brief ...tbd...
*/


#ifndef WDT_H
#define WDT_H
#include <xc.h>



/*!
* Clear WDT (WatchDog)
*/
void clearWdt();
/*!
* Enables WDT (WatchDog)
*/
#define enableWdt() WDTCONbits.ON=1;    
/*!
* Disables WDT
*/
#define disableWdt() WDTCONbits.ON=0;    
/*!
* Make software reset. Restart MCU
*/
void softwareReset();
#endif
