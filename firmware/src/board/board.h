/*!
* @file board.h
* @author D.Chikov
* @date 12/28/2020, 11:37:25
* @brief 
*/



#ifndef _BOARD_H
#define _BOARD_H

#ifdef __cplusplus  // Provide C++ Compatibility
    extern "C" {
#endif

#include "p32xxxx.h"

        
        
/*!
* MACRO: board definition
*/
#define BASE_BOARD       
//#define LDM_BOARD

        
        
        
// **** FREQUENCY****        
/*!
* MACRO: MCU clock frequency
*/
#define SYS_CLK_FREQ                    (250000000ul) 
 
/*!
* MACRO: PIC32MZ Memory page size in words
*/
#define PAGE_SIZE                       (4096)
/*!
* MACRO: Page size in bytes
*/
#define PAGE_SIZE_BYTES                  (4 * PAGE_SIZE)
        
/*!
* MACRO: ROW size
*/
#define ROW_SIZE                        (512)
/*!
* MACRO: ROW Size in bytes
*/
#define ROW_SIZE_BYTES                   (4 * ROW_SIZE)
        
#define NUM_ROWS_PAGE                   (PAGE_SIZE/ROW_SIZE)
        
/*!
* MACRO: Appplication flash base address (refer to Bootloader documentation)
*/
#define APP_FLASH_BASE_ADDR             (0x9D000000UL)
        
/*!
* MACRO: Main application base address  (refer to Bootloader documentation)
*/
#define MAIN_APP_ADDR                   (APP_FLASH_BASE_ADDR)
/*!
* MACRO: Main application size in bytes (refer to Bootloader documentation)
*/
#define MAIN_APP_SIZE_BYTES             (0x80000UL)
/*!
* MACRO: Address of application backup (refer to Bootloader documentation)
*/
#define BACK_APP_ADDR                   (APP_FLASH_BASE_ADDR +MAIN_APP_SIZE_BYTES)
        
        
/*!
* MACRO: Configuration unlock password (not implemented)
*/
#define CONFIG_UNLOCK_PSW               (0x12345678ul)

/*!
* MACRO: Configuration memory address  (refer to Bootloader documentation)
*/
#define CONFIG_MEM_ADDR                 (0xBFC70000ul)


  
#include "gpio_map.h"
       

#include "gpio.h"

/*!
* MACRO: LED1 on/off
*/
#define LED1(_ON_)      gpio_set(GPIO('A',0), (_ON_)==0)
/*!
* MACRO: LED2 on/off
*/
#define LED2(_ON_)      gpio_set(GPIO('G',9), (_ON_)==0) 

/*!
* MACRO: KEY1 on/off
*/
#define KEY1            gpio_get(GPIO('B',4))
/*!
* MACRO: KEY2 on/off
*/
#define KEY2            gpio_get(GPIO('B',2))

/*!
* MACRO: DEBUG_UART -is uart port for debug protocol 115200
*/
#define   DEBUG_UART    UART3


/*!
* \brief Board initialization
*/
void BOARD_Initialize();


#ifdef __cplusplus
}
#endif

#endif
