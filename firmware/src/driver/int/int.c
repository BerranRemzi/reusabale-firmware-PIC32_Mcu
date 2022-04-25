/*!
* @file int\int.c
* @author D.Chikov
* @date 10/15/2020, 09:37:33
* @brief ...tbd...
*/


#include <xc.h>

#include "int.h"
#include "typedef_global.h"


/*!
* 	 void INT_SetMultivectoredMode(bool on)
* 
* 	...tbd...
* 	\param bool on -...
* 	\return void -...
*/
void INT_SetMultivectoredMode(bool on){
    INTCONbits.MVEC = on;
}


/*!
* 	 void INT_SetSingleVectoredMode()
* 
* 	...tbd...
* 	\return void -...
*/
void INT_SetSingleVectoredMode(){
    INTCONbits.MVEC = 0;
}