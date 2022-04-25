/*!
* @file nvm.h
* @author D.Chikov
* @date 10/15/2020, 09:37:33
*/


#ifndef _NVM_H
#define _NVM_H

#ifdef __cplusplus
    extern "C" {
#endif
        
#include "typedef_global.h"
#include <xc.h>

        
/*!
* ...tbd...
*/
ResultError_t nvm_erase_page(uint32_t addr);
/*!
* ...tbd...
*/
ResultError_t nvm_write_page(uint32_t addr, uint8_t *pdata);
/*!
* ...tbd...
*/
ResultError_t nvm_write_word(uint32_t addr, uint32_t word);
/*!
* ...tbd...
*/
ResultError_t nvm_write_row(uint32_t addr, uint8_t *pdata);
/*!
* ...tbd...
*/
ResultError_t nvm_clear_error();                               
/*!
* ...tbd...
*/
ResultError_t nvm_operation_result();
/*!
* ...tbd...
*/
void nvm_unlock_bootmem();
/*!
* ...tbd...
*/
void nvm_lock_bootmem();



/* NVM Flash Memory programming
 * key 1*/
/*!
* NVM (FLASH) unlock sequence 1 (refer PIC32 Datasheet)
*/
#define NVM_PROGRAM_UNLOCK_KEY1     0xAA996655

/* NVM Driver Flash Memory programming
 * key 1*/
/*!
* NVM (FLASH) unlock sequence 2 (refer PIC32 Datasheet)
*/
#define NVM_PROGRAM_UNLOCK_KEY2     0x556699AA

#ifdef	__cplusplus
}
#endif

#endif
