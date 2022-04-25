/*!
* @file system_dbg.c
* @author D.Chikov
* @date 10/15/2020, 09:37:34
* @brief ...tbd...
*/


#include "usart.h"
#include "system.h"
#include "board.h"
#include "rd_buffer.h"
#include "wdt.h"

void debug_putc(char c){
     while (uart_txline_busy(DEBUG_UART));
        uart_putc(DEBUG_UART, c);
        clearWdt();
}
