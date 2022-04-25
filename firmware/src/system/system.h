/*!
 * @file system.h
 * @author D.Chikov
 * @date 10/15/2020, 09:37:34
 * @brief System routines header
 */


#ifndef _SYSTEM_H
#define _SYSTEM_H


#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif

#include "int.h"

#include <xc.h>
#include "typedef_global.h"
#include "stdio.h"
#include "assert.h"
#include "board.h"



#ifdef __DEBUG_MODE__
#define ASSERT(X)   assert(X)

#else 
#define ASSERT(X)
#endif

    void debug_putc(char c);
#define PRINTF(...) do{\
    static char __tmp__[200]={0};\
    int i=0,count = sprintf(__tmp__, __VA_ARGS__);\
    for (;i<count;i++) {\
       debug_putc(__tmp__[i]);\
       }\
    }while (0);



#define PAGE_SIZE                       (4096)
#define PAGE_SIZE_BYTES                  (4 * PAGE_SIZE)
#define ROW_SIZE                        (512)
#define ROW_SIZE_BYTES                   (4 * ROW_SIZE)
#define NUM_ROWS_PAGE                   (PAGE_SIZE/ROW_SIZE)      
#define APP_FLASH_BASE_ADDR             (0x9D000000UL)

#define MAIN_APP_ADDR                   (APP_FLASH_BASE_ADDR)
#define MAIN_APP_SIZE_BYTES             (0x80000UL)
#define BACK_APP_ADDR                   (APP_FLASH_BASE_ADDR +MAIN_APP_SIZE_BYTES)

#define SYSINFO_MEM_ADDR                 (0xBFC70000ul)

/* Address of  the Flash from where the application starts executing */
/* Rule: Set APP_FLASH_BASE_ADDRESS to _RESET_ADDR value of application linker script*/
#define APP_RESET_ADDRESS               (APP_FLASH_BASE_ADDR)


/*!
 *  writes bytes to configuration memory area
 */
int SYSTEM_config_write(uint8_t *pdata);

//
/*!
 * reads bytes from configuration memory area
 */
int SYSTEM_config_read(uint8_t *pdata);



/*!
 * delay routine
 */
inline void SYSTEM_delay_ms(int delay_ms);

inline void SYSTEM_delay_us(int delay_us);


void SYSTEM_delay_init();

/*!
 * MACRO:Delay in milliseconds
 */
#define delay_ms(_T_) SYSTEM_delay_ms(_T_)
#define delay_us(_T_) SYSTEM_delay_us(_T_)
/*!
 * System time start
 */
void SYSTEM_timer_start(int period);

/*!
 * System timer is timeout
 */
bool SYSTEM_timer_timeout();

/*!
 * System timer elapsed flag
 */
uint32_t SYSTEM_timer_elapsed();


void SYSTEM_Activity(bool on);


/*!
 * Initialise system 
 */
void SYSTEM_Initialize();

/*!
 * Initialises UART communication
 */
void SYSTEM_CommInit();
/*!
 * Reads data from UART to round buffer 
 */
void SYSTEM_ReadUART();
/*!
 * Writes data from round buffer to UART
 */
void SYSTEM_WriteUART();
/*!
 * Sets baud rate for communication UART 
 */
bool SYSTEM_SetBaudRate(uint32_t baudrate);

// -------- ERRORS --------------
#include "system_error_codes.h"

/*!
 * Logs system error
 */
void SYSTEM_MakeError(uint32_t error_code, char *pdescription);

/*!
 * Assign system error function handler
 */
void SYSTEM_AssignHandler(uint32_t error_code, void (*error_handler)(void));

/*!
 * System error count
 */
uint32_t SYSTEM_ErrorCount();

/*!
 * System errors -clear
 */
void SYSTEM_ClearErrors();


//extern Status_t g_Status;
#ifdef __cplusplus
}
#endif


#endif // _SYSTEM_H

