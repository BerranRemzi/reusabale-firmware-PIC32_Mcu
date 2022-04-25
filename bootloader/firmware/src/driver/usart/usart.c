/*!
* @file usart\usart.c
* @author D.Chikov
* @date 10/15/2020, 09:37:33
* @brief ...tbd...
*/


#include "usart.h"
#include "xc.h"
#include "system.h"
#include "board.h"



#define UxMODE_ADDR(NUM)  (volatile uint32_t*)((uint32_t)&U1MODE + num *0x200);
#define UxSTA_ADDR(NUM)   (volatile uint32_t*)((uint32_t)&U1MODE + num *0x200 + 0x10);
#define UxTXREG_ADDR(NUM) (volatile uint32_t*)((uint32_t)&U1MODE + num *0x200 + 0x20);
#define UxRXREG_ADDR(NUM) (volatile uint32_t*)((uint32_t)&U1MODE + num *0x200 + 0x30);
#define UxBRG_ADDR(NUM)   (volatile uint32_t*)((uint32_t)&U1MODE + num *0x200 + 0x40);





/*!
* 	 int uart_enable(Uart num, uint32_t baudrate)
* 
* 	...tbd...
* 	\param Uart num -...
* 	\param uint32_t baudrate -...
* 	\return int -...
*/
int uart_enable(Uart num, uint32_t baudrate) {        
    int result = -1;    
    
    if(num <UART_COUNT)
    {
        volatile uint32_t *UxSTA = UxSTA_ADDR(num);
        volatile uint32_t *UxMODE = UxMODE_ADDR(num);
        volatile uint32_t *UxBRG = UxBRG_ADDR(num)
        *UxSTA =0;
        *UxBRG = ( (SYS_CLK_FREQ/2)/(16*baudrate)) -1;                                                         
        *UxMODE =0;
        *UxMODE = UxMODE_ENABLE;                         
        *UxSTA = UxSTA_TX_ENABLED|UxSTA_RX_ENABLED;// Enable UART transmission                                
        result = 0;       
    }
    return result;
}



/*!
* 	 bool uart_data_available(Uart num)
* 
* 	...tbd...
* 	\param Uart num -...
* 	\return bool -...
*/
bool uart_data_available(Uart num){        
    if(num <UART_COUNT){
        volatile __U1STAbits_t *pUxSTA = (__U1STAbits_t *)UxSTA_ADDR(num);            
        if(pUxSTA->URXDA== TRUE)
            return true;
    }
    return  false;
}

/*!
* 	 int uart_getc(Uart num,char *pbyte)
* 
* 	...tbd...
* 	\param Uart num - uart number    
* 	\param char *pbyte -...
* 	\return int - reads byte from UART port 
*/
int uart_getc(Uart num,char *pbyte) {
    int result = RES_ERROR;
    if(num <UART_COUNT){
        const volatile uint32_t *UxSTA = UxSTA_ADDR(num);
        const volatile uint32_t *UxRXREG = UxRXREG_ADDR(num);
        if(*UxSTA & UxSTA_RX_HAS_DATA){
           char c;
           c = (char)*UxRXREG;
           if(pbyte) *pbyte = (char)c&0x000000ff;
           result = RES_NO_ERROR;            
        }
        else 
            result =    RES_EMPTY;
    }
    return result;
}



/*!
* 	 int uart_putc(Uart num, const char byte)
* 
* 	puts character if buffer is not busy
* 	\param Uart num -...
* 	\param const char byte -byte goes directly to port FIFO
* 	\return int -...
*/
int uart_putc(Uart num, const char byte) {    
    int result = RES_ERROR;
    volatile uint32_t *UxSTA = UxSTA_ADDR(num);
    volatile uint32_t *UxTXREG = UxTXREG_ADDR(num);    
    if( (*UxSTA & UxSTA_TX_FULL) ==0) {
        *UxTXREG = byte;    
        result = RES_NO_ERROR;           
    }     
    else result = RES_BUSY;
    
    return result;
}

/* ********************************************************************* 
@Function name:  uart_flush
@Return: (void) 
@Parameters: 
    int num - uart number
@Description: clears uart port directly to port
 ********************************************************************* */

/*!
* 	 void uart_flush(Uart num)
* 
* 	...tbd...
* 	\param Uart num -...
* 	\return void -...
*/
void uart_flush(Uart num) {
     volatile uint32_t *UxMODE = UxMODE_ADDR(num);
     volatile uint32_t *UxSTA = UxSTA_ADDR(num);
     volatile uint32_t *UxRXREG = UxRXREG_ADDR(num);
     if ( uart_rxline_error(num) ) {        
        /* reenable and read*/
        *UxMODE &= ~UxMODE_ENABLE;
        *UxRXREG;*UxRXREG;
        *UxMODE |= UxMODE_ENABLE;
    }
     while((*UxSTA & UxSTA_TX_IS_EMPTY)==0);
}


/*!
* 	 void uart_reset(Uart num)
* 
* 	...tbd...
* 	\param Uart num -...
* 	\return void -...
*/
void uart_reset(Uart num)
{
    volatile uint32_t *UxSTA = UxSTA_ADDR(num);
    volatile uint32_t *UxRXREG = UxRXREG_ADDR(num);
    *UxSTA &= ~(UxSTA_TX_ENABLED|UxSTA_RX_ENABLED);  
    *UxSTA &= ~(UxSTA_FRAME_ERROR);
    while(*UxSTA & UxSTA_RX_HAS_DATA) *UxRXREG;
    *UxSTA |= (UxSTA_TX_ENABLED|UxSTA_RX_ENABLED);
}

/* ********************************************************************* 
@Function name:  uart_rxline_error
@Return: (bool) - true = busy
@Parameters: 
    int num - uart number    
@Description: 
 ********************************************************************* */

/*!
* 	 bool uart_rxline_error(Uart num)
* 
* 	...tbd...
* 	\param Uart num -...
* 	\return bool -...
*/
bool uart_rxline_error(Uart num){
    volatile uint32_t *UxSTA = UxSTA_ADDR(num);
    return (*UxSTA & (UxSTA_OVERRUN_ERROR|UxSTA_FRAME_ERROR|UxSTA_PARITY_ERROR)) !=0;
}

/* ********************************************************************* 
@Function name:  uart_txline_busy
@Return: (bool) - true = busy
@Parameters: 
    int num - uart number    
@Description: 
 ********************************************************************* */

/*!
* 	 bool uart_txline_busy(Uart num)
* 
* 	...tbd...
* 	\param Uart num -...
* 	\return bool -...
*/
bool uart_txline_busy(Uart num){   
   volatile uint32_t *UxSTA = UxSTA_ADDR(num);    
   return (*UxSTA & UxSTA_TX_FULL)!=0;
}


/*!
* 	 bool uart_txline_empty(Uart num)
* 
* 	...tbd...
* 	\param Uart num -...
* 	\return bool -...
*/
bool uart_txline_empty(Uart num){   
   volatile uint32_t *UxSTA = UxSTA_ADDR(num);    
   return (*UxSTA & UxSTA_TX_IS_EMPTY)!=0;
}




/*!
* 	 void uart_configure(Uart num, uint32_t cfgUxSTA, uint32_t cfgUxMODE, uint32_t cfgUxBRG)
* 
* 	...tbd...
* 	\param Uart num -...
* 	\param uint32_t cfgUxSTA -...
* 	\param uint32_t cfgUxMODE -...
* 	\param uint32_t cfgUxBRG -...
* 	\return void -...
*/
void uart_configure(Uart num, uint32_t cfgUxSTA, uint32_t cfgUxMODE, uint32_t cfgUxBRG){
     volatile uint32_t *UxMODE = UxMODE_ADDR(num);
     volatile uint32_t *UxSTA = UxSTA_ADDR(num);
     volatile uint32_t *UxRXREG = UxRXREG_ADDR(num);
     volatile uint32_t *UxBRG = UxBRG_ADDR(num);
     
     *UxBRG =  cfgUxBRG;     
     *UxSTA = cfgUxSTA;
     *UxMODE = cfgUxMODE;
     while(*UxSTA & UxSTA_RX_HAS_DATA)     *UxRXREG;     
}



/* ********************************************************************* 
@Function name:  serial_port_put_data
@Return: (void) 
@Parameters: 
    int port_number   -port number
    const char *pbuffer - buffer pointer
    SIZE size - size of data
@Description: This puts data to uart port buffer

 ********************************************************************* */

/*!
* 	 void uart_put_data(Uart port_number, const uint8_t *pbuffer, int size)
* 
* 	...tbd...
* 	\param Uart port_number -...
* 	\param const uint8_t *pbuffer -...
* 	\param int size -...
* 	\return void -...
*/
void uart_put_data(Uart port_number, const uint8_t *pbuffer, int size) {
//    RdBuffer *pbuf = &uart_port[port_number].tx_buf;
    while (size--) {
//        if (rd_buffer_put(pbuf, (RdBufferRecord*) pbuffer) != TRUE) {
        //    error_set(ERROR_UART_BUFFER_FULL);
 //           break;
//        }
        pbuffer++;
    }
}

/* ********************************************************************* 
@Function name:  serial_port_puts
@Return: (void) 
@Parameters: 
    int port_number -  port number 
    const char *pstr - string to text
@Description: this puts string to port

 ********************************************************************* */

/*!
* 	 void uart_puts(Uart port_number, const char *pstr)
* 
* 	...tbd...
* 	\param Uart port_number -...
* 	\param const char *pstr -...
* 	\return void -...
*/
void uart_puts(Uart port_number, const char *pstr) {
    while (pstr != NULL && *pstr != '\0') {
        uart_putc(port_number, *pstr);
        pstr++;
    }
}


/*!
* 	 void uart_enable_rx_interrupt(Uart num, bool enable, uint32_t priority, uint32_t sub_priority)
* 
* 	...tbd...
* 	\param Uart num -...
* 	\param bool enable -...
* 	\param uint32_t priority -...
* 	\param uint32_t sub_priority -...
* 	\return void -...
*/
void uart_enable_rx_interrupt(Uart num, bool enable, uint32_t priority, uint32_t sub_priority){
   switch(num)
   {
      case UART1:
        IEC3bits.U1RXIE = enable !=0;
          IPC28bits.U1RXIP =priority;
          IPC28bits.U1RXIS =sub_priority;
      break;
      case UART2:
          IEC4bits.U2RXIE = enable !=0;
          IPC36bits.U2RXIP =priority;
          IPC36bits.U2RXIS =sub_priority;
      break;
      case UART3:	
          IEC4bits.U3RXIE = enable !=0;
          IPC39bits.U3RXIP =priority;
          IPC39bits.U3RXIS =sub_priority;
      break;
      case UART4:
          IEC5bits.U4RXIE = enable !=0;
          IPC42bits.U4RXIP =priority;
          IPC42bits.U4RXIS =sub_priority;
      break;
      case UART5:
          IEC5bits.U5RXIE = enable !=0;
          IPC45bits.U5RXIP =priority;
          IPC45bits.U5RXIS =sub_priority;
      break;
      case UART6:
          IEC5bits.U6RXIE = enable !=0;
          IPC47bits.U6RXIP =priority;
          IPC47bits.U6RXIS =sub_priority;
      break;
       default:
           break;
   }
}


/*!
* 	 void uart_enable_tx_interrupt(Uart num, bool enable, uint32_t priority, uint32_t sub_priority)
* 
* 	...tbd...
* 	\param Uart num -...
* 	\param bool enable -...
* 	\param uint32_t priority -...
* 	\param uint32_t sub_priority -...
* 	\return void -...
*/
void uart_enable_tx_interrupt(Uart num, bool enable, uint32_t priority, uint32_t sub_priority){
   switch(num)
   {
     case UART1:
        IEC3bits.U1TXIE = enable !=0;
        IPC28bits.U1TXIP =priority;
          IPC28bits.U1TXIS =sub_priority;
      break;
      case UART2:
          IEC4bits.U2TXIE = enable !=0;
           IPC36bits.U2TXIP =priority;
          IPC36bits.U2TXIS =sub_priority;
      break;
      case UART3:	
          IEC4bits.U3TXIE = enable !=0;
          IPC39bits.U3TXIP =priority;
          IPC39bits.U3TXIS =sub_priority;
      break;
      case UART4:
          IEC5bits.U4TXIE = enable !=0;
          IPC43bits.U4TXIP =priority;
          IPC43bits.U4TXIS =sub_priority;
      break;
      case UART5:
          IEC5bits.U5TXIE = enable !=0;
         IPC45bits.U5TXIP =priority;
          IPC45bits.U5TXIS =sub_priority;
      break;
      case UART6:
          IEC5bits.U6TXIE = enable !=0;
          IPC47bits.U6TXIP =priority;
          IPC47bits.U6TXIS =sub_priority;
      break;
      default:
           break;
   }
}



/*!
* 	 void uart_disable_tx_interrupt(Uart num)
* 
* 	...tbd...
* 	\param Uart num -...
* 	\return void -...
*/
void uart_disable_tx_interrupt(Uart num){
   uart_enable_tx_interrupt(num,0,0,0);
}

/*!
* 	 void uart_disable_rx_interrupt(Uart num)
* 
* 	...tbd...
* 	\param Uart num -...
* 	\return void -...
*/
void uart_disable_rx_interrupt(Uart num){
   uart_enable_rx_interrupt(num,0,0,0);
}


/*!
* 	 void uart_clear_rx_flag(Uart num)
* 
* 	...tbd...
* 	\param Uart num -...
* 	\return void -...
*/
void uart_clear_rx_flag(Uart num){
 switch(num)
   {
      case UART1:   IFS3bits.U1RXIF=0 ;      break;
      case UART2:   IFS4bits.U2RXIF=0 ;      break;
      case UART3:   IFS4bits.U3RXIF=0 ;      break;
      case UART4:   IFS5bits.U4RXIF=0 ;      break;
      case UART5:   IFS5bits.U5RXIF=0 ;      break;
      case UART6:   IFS5bits.U6RXIF =0;      break;
       default:
           break;
   }
}


/*!
* 	 void uart_clear_tx_flag(Uart num)
* 
* 	...tbd...
* 	\param Uart num -...
* 	\return void -...
*/
void uart_clear_tx_flag(Uart num){
   switch(num)
   {
      case UART1:    IFS3bits.U1TXIF =0;      break;
      case UART2:    IFS4bits.U2TXIF =0;      break;
      case UART3:    IFS4bits.U3TXIF =0;      break;
      case UART4:    IFS5bits.U4TXIF =0;      break;
      case UART5:    IFS5bits.U5TXIF =0;      break;
      case UART6:    IFS5bits.U6TXIF =0;      break;
       default:
           break;
   } 
}
