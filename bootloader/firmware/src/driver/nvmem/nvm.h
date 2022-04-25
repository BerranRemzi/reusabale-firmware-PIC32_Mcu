#ifndef _NVM_H
#define _NVM_H

#ifdef __cplusplus
    extern "C" {
#endif
        
#include "typedef_global.h"
#include <xc.h>

        
ResultError_t nvm_erase_page(uint32_t addr);
ResultError_t nvm_write_page(uint32_t addr, uint8_t *pdata);
ResultError_t nvm_write_word(uint32_t addr, uint32_t word);
ResultError_t nvm_write_row(uint32_t addr, uint8_t *pdata);
ResultError_t nvm_clear_error();                               
ResultError_t nvm_operation_result();
void nvm_unlock_bootmem();
void nvm_lock_bootmem();



/* NVM Flash Memory programming
 * key 1*/
#define NVM_PROGRAM_UNLOCK_KEY1     0xAA996655

/* NVM Driver Flash Memory programming
 * key 1*/
#define NVM_PROGRAM_UNLOCK_KEY2     0x556699AA

#ifdef	__cplusplus
}
#endif

#endif
