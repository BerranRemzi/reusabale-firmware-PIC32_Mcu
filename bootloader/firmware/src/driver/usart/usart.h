/*!
* @file usart\usart.h
* @author D.Chikov
* @date 10/15/2020, 09:37:33
* @brief ...tbd...
*/



#ifndef _DRV_USART_H
#define _DRV_USART_H

#include "xc.h"

#ifdef __cplusplus  // Provide C++ Compatibility
    extern "C" {
#endif
#include "typedef_global.h"     

typedef enum {

    #ifdef U1MODE
        UART1,        
    #else
        #error "This device doesn't support UART"
    #endif

    #ifdef U2MODE
        UART2,        
    #endif

    #ifdef U3MODE
        UART3,
    #endif
    
    #ifdef U4MODE
        UART4,
    #endif

    #ifdef U5MODE
        UART5,
    #endif

    #ifdef U6MODE
        UART6,
    #endif

    UART_COUNT
}Uart;        

// [STATUS] - valid for all PIC32MZ
#define  UxSTA_RX_HAS_DATA                        (1<<0)
#define  UxSTA_OVERRUN_ERROR                      (1<<1)
#define  UxSTA_FRAME_ERROR                        (1<<2)
#define  UxSTA_PARITY_ERROR                       (1<<3)
#define  UxSTA_IS_IDLE                            (1<<4)
#define  UxSTA_ADDR_DETECT_ENABLED                (1<<5)
#define  UxSTA_INTERRUPT_RX_NOT_EMPTY             (0<<6)
#define  UxSTA_INTERRUPT_RX_HALF                  (1<<6)
#define  UxSTA_INTERRUPT_RX_3_FROM_4              (2<<6)
#define  UxSTA_TX_IS_EMPTY                        (1<<8)
#define  UxSTA_TX_FULL                            (1<<9)
#define  UxSTA_TX_ENABLED                         (1<<10)
#define  UxSTA_TX_BREAK                           (1<<11)
#define  UxSTA_RX_ENABLED                         (1<<12)
#define  UxSTA_TX_INV                             (1<<13)
#define  UxSTA_INTERRUPT_TX_1_FREE                (0<<14)
#define  UxSTA_INTERRUPT_TX_ALL_FREE              (1<<14)
#define  UxSTA_INTERRUPT_TX_BUF_FREE              (2<<14)
#define  UxSTA_DEV_ADDR(VAL)                          ((VAL)<<16)
#define  UxSTA_DEV_ADDR_DETECT_ENABLE                 (1<<24)


//[MODE]
#define  UxMODE_STOP_BIT_x2                       (1<<0)
#define  UxMODE_STOP_BIT_x1                       (0<<0)
#define  UxMODE_PDSEL_8xDATA_NO_PARITY            (0<<1)
#define  UxMODE_PDSEL_8xDATA_EVEN_PARITY          (1<<1)
#define  UxMODE_PDSEL_8xDATA_ODD_PARITY           (2<<1)
#define  UxMODE_PDSEL_9xDATA_NO_PARITY            (3<<1)
#define  UxMODE_BAUD_HIGH                         (1<<3)
#define  UxMODE_BAUD_STANDARD                     (0<<3)
#define  UxMODE_RX_INV                            (1<<4)
#define  UxMODE_AUTOBAUD_ENABLE                   (1<<5)
#define  UxMODE_LOOP_BACK                         (1<<6)
#define  UxMODE_WAKE_UP_ENABLE                    (1<<7)
#define  UxMODE_ENABLE                            (1<<15)



/*!
* ...tbd...
*/
int  uart_enable(Uart num, uint32_t baudrate);
/*!
* ...tbd...
*/
int  uart_putc(Uart num, const char byte);
/*!
* ...tbd...
*/
bool uart_txline_busy(Uart num) ;
/*!
* ...tbd...
*/
bool uart_txline_empty(Uart num) ;
/*!
* ...tbd...
*/
bool uart_rxline_error(Uart num);
/*!
* ...tbd...
*/
void uart_reset(Uart num);
/*!
* ...tbd...
*/
int uart_getc(Uart num ,char *pbyte);
/*!
* ...tbd...
*/
bool uart_data_available(Uart num);
/*!
* ...tbd...
*/
void uart_flush(Uart n);
/*!
* ...tbd...
*/
void uart_configure(Uart num, uint32_t cfgUxSTA, uint32_t cfgUxMODE, uint32_t cfgUxBRG);


/*!
* ...tbd...
*/
void uart_enable_rx_interrupt(Uart num,bool enable, uint32_t priority, uint32_t sub_priority);
/*!
* ...tbd...
*/
void uart_disable_rx_interrupt(Uart num);

/*!
* ...tbd...
*/
void uart_enable_tx_interrupt(Uart num,bool enable, uint32_t priority, uint32_t sub_priority);
/*!
* ...tbd...
*/
void uart_disable_tx_interrupt(Uart num);

/*!
* ...tbd...
*/
void uart_clear_rx_flag(Uart num);

/*!
* ...tbd...
*/
void uart_clear_tx_flag(Uart num);
          
        
        
#ifdef __cplusplus
}
#endif



#endif // #ifndef _DRV_USART_H

