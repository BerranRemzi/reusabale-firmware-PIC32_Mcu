/*!
* @file system_comm.c
* @author D.Chikov
* @date 10/15/2020, 09:37:34
* @brief ...tbd...
*/


#include <xc.h>
#include <sys/attribs.h>
#include "wdt.h"
#include "board.h"
#include "rd_buffer.h"
#include "app_config.h"
#include "usart.h"
#include "system.h"
#include "app.h"
#include "parser.h"

static RoundBuffer buffer_rx;

static RoundBuffer buffer_tx;

static uint8_t _rx_data[COMM_BUFFER_SIZE];

static uint8_t _tx_data[COMM_BUFFER_SIZE];

static volatile int _reset_counter;
//command
static char _buf_command[COMM_BUFFER_SIZE];


/*!
* 	 void _mon_putc (char c)
* 
* 	...tbd...
* 	\param char c -...
* 	\return void -...
*/
void _mon_putc (char c)
 {
    rd_buffer_put(&buffer_tx,c);    
 }




// communication initialization

bool SYSTEM_SetBaudRate(uint32_t baudrate){
    uart_enable(UART3,baudrate);
    return true;
}

/*!
* 	 void  SYS_CommInit()
* 
* 	...tbd...
* 	\return void -...
*/
void  SYSTEM_CommInit() {
    _reset_counter =0;
    
    // enable RX interrupt
    uart_enable_rx_interrupt(UART3, TRUE, 6, 0);
    
    // clear RX interrupt flag
    uart_clear_rx_flag(UART3);
    
    // DMA init for send
    
    // DMA for read
    
    // initialize buffer RX and TX
    if( rd_buffer_init(&buffer_rx, _rx_data, COMM_BUFFER_SIZE) == false) {
        SYSTEM_MakeError(SYS_ERROR_MEMORY,0);
        return;
    }
    if( rd_buffer_init(&buffer_tx, _tx_data, COMM_BUFFER_SIZE) == false) {
        SYSTEM_MakeError(SYS_ERROR_MEMORY,0);
        return;
    }
}



// [TASK]
// this task is intended to put TX data to buffer

/*!
* 	 void SYS_WriteUART()
* 
* 	Write sll data to physical UART port
*/
void SYSTEM_WriteUART() {        
    
    // read data from TX buffer and put to UART port
    if (rd_buffer_cnt(&buffer_tx) > 0) {
        uint8_t byte;
        while (rd_buffer_get(&buffer_tx, &byte) == true) {
            
            // wait while wart port is busy while sending TX byte
            while (uart_putc(UART3, byte) == RES_BUSY);
        }
    }    
}

// [TASK]
// this task reads data from buffer and parses data from protocol


/*!
* 	 void SYS_ReadUART()
* 
* 	Reads physical UART port to round buffer
*/
void SYSTEM_ReadUART() 
{
    // scan while buffer have atleast 8 bytes for protocol                
    int i = 0;

    while (rd_buffer_cnt(&buffer_rx) > 0 
            && (rd_buffer_contains(&buffer_rx, '\r') == true || rd_buffer_contains(&buffer_rx, '\n') == true)) {
        
        SYSTEM_Activity(1);
        uint8_t byte;
        // read from rx buffer
        if (rd_buffer_get(&buffer_rx, &byte) == false) {

            // unhandled error occurs we can't read from buffer 
            // (this should never happen)
            rd_buffer_reset(&buffer_rx);
            SYSTEM_MakeError(SYS_ERROR_COMMUNICATION, 0);
            break;
        }

            _buf_command[i] = 0;
            if(byte == '\r' && rd_buffer_first(&buffer_rx) == '\n') 
            {
                parse_string(_buf_command,"\r\n");
                i=0;
            }
            else if(byte=='\r') {
                parse_string(_buf_command,"\r");
                i=0;
            }
            else if(byte=='\n') {
                parse_string(_buf_command,"\n");
                i=0;
            }
            else {
                _buf_command[i++] = (char) byte;
            }
            
           SYSTEM_Activity(0);
    }
}

void SYSTEM_Activity(bool on){
    if(on==1 && KEY1==0){
        LED1(1);
    }
    else LED1(0);
}


/*! enquiry*/

#define SER_ENQ		(0x05)
/*! acknowlege*/
#define SER_ACK		(0x06)
/*! break*/
#define SER_BREAK     (0x15) //break
/*! restart */
#define SER_RESTART	(0x18) //ascii code CAN

// this is interrupt routine for UART3 RX

/*!
* 	 void __ISR(_UART3_RX_VECTOR, IPL6AUTO) CommunicationInterrupt(void)
* 
* 	Communcation interrupt. reads byte by byte
*/
void __ISR(_UART3_RX_VECTOR, IPL6AUTO) CommunicationInterrupt(void) {
           
    // check if some data in RX buffer data
    while (uart_data_available(UART3)) 
    {
        char byte=0;        
        
        // read byte from UART3
        if (uart_getc(UART3, &byte) >= 0 ) {            
            
            switch(byte)
            {                                                
                case SER_ENQ:
                    _reset_counter =0;
                    uart_putc(UART3, SER_ACK);
                    break;
                    
                case SER_RESTART:
                    if(_reset_counter++ >= 3)
                        softwareReset() ;
                    break;
                    
                case SER_BREAK:
                    APP_Break();
                    break;
                    
                
                default:
                _reset_counter =0;
                // put byte to queue                
                if (rd_buffer_put(&buffer_rx, (uint8_t) byte) == FALSE) {
                
                    // if fail to write to port maybe it is full or something wrong
                    rd_buffer_reset(&buffer_rx);                
                    // generate error code
                    SYSTEM_MakeError(SYS_ERROR_COMMUNICATION,0);                
                } 
            }
                                    
            
        }
    }

    // need to clear interrupt flag for UART3 RX
    uart_clear_rx_flag(UART3);
}
