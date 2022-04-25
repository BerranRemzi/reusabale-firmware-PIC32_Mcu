#include "debug.h"

#include <xc.h>
#include <stdio.h>
#include "usart.h"
#include "system_config.h"
#include "board.h"
void _mon_putc (char c)
 {
    while(uart_txline_busy(DBG_UART));
    uart_putc(DBG_UART,c);    
 }
