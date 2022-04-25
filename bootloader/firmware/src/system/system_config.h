#ifndef SYSTEM_CONFIG_H
#define SYSTEM_CONFIG_H

#include "gpio.h"
#include <xc.h>






#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif


//#define DEBUG_VER
//#define USE_LIVEUPDATE


// flash memory
// [common]
#define PAGE_SIZE                       (4096)
#define PAGE_SIZE_BYTES                  (4 * PAGE_SIZE)
#define ROW_SIZE                        (512)
#define ROW_SIZE_BYTES                   (4 * ROW_SIZE)
#define NUM_ROWS_PAGE                   (PAGE_SIZE/ROW_SIZE)

//[application]
#define APP_FLASH_BASE_ADDR             (0x9D000000UL)
#define APP_RESET_ADDRESS               (APP_FLASH_BASE_ADDR)
#define MAIN_APP_ADDR                   (APP_FLASH_BASE_ADDR)
#define APP_SIZE_BYTES                  (0x80000UL)
#define BACK_APP_ADDR                   (APP_FLASH_BASE_ADDR + APP_SIZE_BYTES)

//[system config]
#define CONFIG_UNLOCK_PSW               (0x12345678ul)
#define CONFIG_MEM_ADDR                 (0xBFC20000ul)
#define CONFIG_MEM_SIZE                 (0x1000UL)

//[device config]
#define DEV_CONFIG_REG_BASE_ADDRESS     (0x9FC02FF0)
#define DEV_CONFIG_REG_END_ADDRESS      (0x9FC02FFF)







#ifdef __cplusplus
}
#endif


#endif
