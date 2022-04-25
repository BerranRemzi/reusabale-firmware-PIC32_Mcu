/*!
* @file nvm.c
* @author D.Chikov
* @date 10/15/2020, 09:37:33
* @brief ...tbd...
*/


#include "nvm.h"
#include "system.h"
#include <sys/kmem.h>
#include <xc.h>
#include "board.h"





#define NVMOP_WORD_PGM          0x1      // Word program operation
#define NVMOP_PAGE_ERASE        0x4      // Page erase operation
#define NVMOP_ROW_PGM           0x3      // Row program operation
#define NVMOP_NOP               0x0      // NOP operation


/*!
* 	 void delay(uint32_t us)
* 
* 	...tbd...
* 	\param uint32_t us -...
*/
void delay(uint32_t us)
{
    const uint32_t countPerMicroSec  = (SYS_CLK_FREQ) / 1e6;
    uint32_t targetCount;  
    uint32_t bakupCount; 
   // uint32_t loop = 0;
    // backup current count of the core timer.
    bakupCount = _CP0_GET_COUNT();
    // Core timer increments every 2 sys clock cycles.
    // Calculate the counts required to complete "us". 
    targetCount = countPerMicroSec * us;      
    // Restart core timer.
    _CP0_SET_COUNT(0);  
    // Wait till core timer completes the count.    
    while(_CP0_GET_COUNT() < targetCount);
    
    // Restore count back.
    _CP0_SET_COUNT(bakupCount + targetCount);
} 



/*!
* 	 void nvm_unlock_bootmem()
* 
* 	...tbd...
*/
void nvm_unlock_bootmem(){
    NVMKEY    = 0x00000000;    
    NVMKEY 		= 0xAA996655;    
    NVMKEY 		= 0x556699AA;
    NVMBWP = _NVMBWP_UBWPULOCK_MASK|_NVMBWP_LBWPULOCK_MASK;    
    NVMKEY    = 0x00000000;    
    NVMKEY 		= 0xAA996655;    
    NVMKEY 		= 0x556699AA;
    NVMBWP = _NVMBWP_UBWPULOCK_MASK|_NVMBWP_LBWPULOCK_MASK;    
}


/*!
* 	 void nvm_lock_bootmem()
* 
* 	...tbd...
*/
void nvm_lock_bootmem(){
    NVMKEY    = 0x00000000;    
    NVMKEY 		= 0xAA996655;    
    NVMKEY 		= 0x556699AA;
    NVMBWP = _NVMBWP_UBWPULOCK_MASK|_NVMBWP_LBWPULOCK_MASK
            |_NVMBWP_UBWP0_MASK|_NVMBWP_UBWP1_MASK|_NVMBWP_UBWP2_MASK|_NVMBWP_UBWP3_MASK|_NVMBWP_UBWP4_MASK
            |_NVMBWP_LBWP0_MASK|_NVMBWP_LBWP1_MASK|_NVMBWP_LBWP2_MASK|_NVMBWP_LBWP3_MASK|_NVMBWP_LBWP4_MASK;
    
    NVMKEY    = 0x00000000;    
    NVMKEY 		= 0xAA996655;    
    NVMKEY 		= 0x556699AA;
    NVMBWP = 
            _NVMBWP_UBWP0_MASK|_NVMBWP_UBWP1_MASK|_NVMBWP_UBWP2_MASK|_NVMBWP_UBWP3_MASK|_NVMBWP_UBWP4_MASK
            |_NVMBWP_LBWP0_MASK|_NVMBWP_LBWP1_MASK|_NVMBWP_LBWP2_MASK|_NVMBWP_LBWP3_MASK|_NVMBWP_LBWP4_MASK;
    
}



/*!
* 	 ResultError_t __attribute__((nomips16)) nvm_operation(uint32_t oper)
* 
* 	...tbd...
* 	\param (nomips16)) nvm_operation(uint32_t oper -...
* 	\return ResultError_t -...
*/
ResultError_t __attribute__((nomips16)) nvm_operation(uint32_t oper)
{

    // Enable Flash Write/Erase Operations        
    NVMCONbits.PROGOP =  oper;
    NVMCONbits.WREN = 1;
    
    // Data sheet prescribes 6us delay for LVD to become stable.
    // To be on the safer side, we shall set 7us delay.    
    
    delay(7);
    
    NVMKEY 		= 0x00000000;    
    NVMKEY 		= 0xAA996655;    
    NVMKEY 		= 0x556699AA;
       
    NVMCONSET = _NVMCON_WR_MASK;            

    // Wait for WR bit to clear
    while(NVMCON&_NVMCON_WR_MASK);

    NVMCONbits.WREN =0;
     NVMCONbits.PROGOP =  0;

    return (nvm_operation_result());
}

/*********************************************************************
 * Function:        unsigned int nvm_erase_page(void* address)
 * Description:     A page erase will erase a single page of program flash,
 *                  which equates to 1k instructions (4KBytes). The page to
 *                  be erased is selected using NVMADDR. The lower bytes of
 *                  the address given by NVMADDR are ignored in page selection.
 * PreCondition:    None
 * Inputs:          address:  Destination page address to Erase.
 * Output:          '0' if operation completed successfully.
 * Example:         NVMemErasePage((void*) 0xBD000000)
 ********************************************************************/

/*!
* 	 ResultError_t nvm_erase_page(uint32_t address)
* 
* 	...tbd...
* 	\param uint32_t address -...
* 	\return ResultError_t -...
*/
ResultError_t nvm_erase_page(uint32_t address)
{
    ResultError_t res;    
    nvm_clear_error();
    // Convert Address to Physical Address
    NVMADDR = KVA_TO_PA((uint32_t)address);
    // Unlock and Erase Page   
    res = nvm_operation(NVMOP_PAGE_ERASE);
    // Return WRERR state.    
    return res;
}


/*!
* 	 ResultError_t nvm_operation_result()
* 
* 	...tbd...
* 	\return ResultError_t -...
*/
ResultError_t nvm_operation_result(){    
    if (NVMCONbits.LVDERR || NVMCONbits.WRERR){         
        return RES_ERROR;
    }
    return RES_NO_ERROR;
}
/*********************************************************************
 * Function:        unsigned int NVMWriteWord(void* address, unsigned int data)
 *
 * Description:     The smallest block of data that can be programmed in
 *                  a single operation is 1 instruction word (4 Bytes).  The word at
 *                  the location pointed to by NVMADDR is programmed.
 * PreCondition:    None
 * Inputs:          address:   Destination address to write.
 *                  data:      Word to write.
 * Output:          '0' if operation completed successfully.
 * Example:         NVMWriteWord((void*) 0xBD000000, 0x12345678)
 ********************************************************************/
#include "systmr.h"


/*!
* 	 ResultError_t nvm_write_word(uint32_t addr, uint32_t data)
* 
* 	...tbd...
* 	\param uint32_t addr -...
* 	\param uint32_t data -...
* 	\return ResultError_t -...
*/
ResultError_t nvm_write_word(uint32_t addr, uint32_t data){    
   ResultError_t result;
    NVMADDR = KVA_TO_PA((uint32_t)addr);
    // Load data into NVMDATA register
    NVMDATA0 = data;
    // Unlock and Write Word            
    result = nvm_operation(NVMOP_WORD_PGM);       
    if(result == RES_NO_ERROR){        
        volatile  const uint32_t* pu32_data = (volatile const uint32_t*)(addr|0x20000000);
        if(*pu32_data != data) result = RES_ERROR;
    }    
    return result;      
}

/*********************************************************************
 * Function:        unsigned int NVMWriteRow(void* address, void* data)
 *
 * Description:     The largest block of data that can be programmed in
 *                  a single operation is 1 row 128 instructions (512 Bytes).  The row at
 *                  the location pointed to by NVMADDR is programmed with the data buffer
 *                  pointed to by NVMSRCADDR.
 * PreCondition:    The row of data must be pre-loaded into a buffer in RAM.
 * Inputs:          address:  Destination Row address to write.
 *                  data:  Location of data to write.
 * Output:          '0' if operation completed successfully.
 * Example:         NVMWriteRow((void*) 0xBD000000, (void*) 0xA0000000)
 ********************************************************************/

/*!
* 	 ResultError_t nvm_write_row(uint32_t address, uint8_t *pdata)
* 
* 	...tbd...
* 	\param uint32_t address -...
* 	\param uint8_t *pdata -...
* 	\return ResultError_t -...
*/
ResultError_t nvm_write_row(uint32_t address, uint8_t *pdata)
{
   ResultError_t result;
    // Set NVMADDR to Address of row t program
    NVMADDR = KVA_TO_PA(address);
    // Set NVMSRCADDR to the SRAM data buffer Address
    NVMSRCADDR = KVA_TO_PA((uint32_t)pdata);
    // Unlock and Write Row
    result = nvm_operation(NVMOP_ROW_PGM);

    return result;
}


/*!
* 	 ResultError_t nvm_write_page(uint32_t addr, uint8_t *pdata)
* 
* 	...tbd...
* 	\param uint32_t addr -...
* 	\param uint8_t *pdata -...
* 	\return ResultError_t -...
*/
ResultError_t nvm_write_page(uint32_t addr, uint8_t *pdata){
    uint32_t rows  = PAGE_SIZE/ROW_SIZE;
    uint32_t i;
    for( i=0;i<rows;i++){
        if(nvm_write_row(addr+i*ROW_SIZE, &pdata[i*ROW_SIZE]) == RES_ERROR)
            return RES_ERROR;
    }
    return RES_NO_ERROR;
}


/*!
* 	 ResultError_t nvm_clear_error(void)
* 
* 	...tbd...
* 	\return ResultError_t -...
*/
ResultError_t nvm_clear_error(void)
{
    ResultError_t res;
    res = nvm_operation(NVMOP_NOP);
    return res;
}

