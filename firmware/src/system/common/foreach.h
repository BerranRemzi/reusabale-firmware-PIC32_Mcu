#ifndef FOREACH_H    /* Guard against multiple inclusion */
#define FOREACH_H

#include "string_utils.h"
/*!
* MACRO:This is intended to process text string separated with ','. 
*        BEGIN, END
*/
#define FOREACH_BEGIN(ITEM,TXT,DELIM) \
        do{\
        int __n;\
        static char __tmp[1000];\
        const int __count =split_text(__tmp,TXT,DELIM);\
        ITEM = __tmp;\
        for(__n=0;__n<__count;__n++){


#define FOREACH_END(ITEM) \
        ITEM += strlen(ITEM) + 1;}\
		}while(0)

#endif 
