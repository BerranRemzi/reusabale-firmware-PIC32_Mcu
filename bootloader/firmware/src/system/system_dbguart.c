#include "system.h"

//void uart_put_data(int num, const uint8_t *pbuffer, int size) ;
//void uart_puts(int num, const char *pstr);
//void uart_putc(int num, const char byte);
//bool uart_getc(int num, char *pbyte);
//int uart_bytes_available(int num);

/* ********************************************************************* 
@Function name:  serial_port_put_data
@Return: (void) 
@Parameters: 
    int port_number   -port number
    const char *pbuffer - buffer pointer
    SIZE size - size of data
@Description: This puts data to uart port buffer

 ********************************************************************* */
void uart_put_data(int port_number, const uint8_t *pbuffer, int size) {
//    RdBuffer *pbuf = &uart_port[port_number].tx_buf;
    while (size--) {
//        if (rd_buffer_put(pbuf, (RdBufferRecord*) pbuffer) != TRUE) {
        //    error_set(ERROR_UART_BUFFER_FULL);
 //           break;
//        }
        pbuffer++;
    }
}


void dbguart_putc(int port_number, const char byte) {
//    RdBuffer *pbuf = &uart_port[port_number].tx_buf;
//    if (rd_buffer_put(pbuf, (RdBufferRecord*) & byte) != TRUE) {
//        error_set(ERROR_UART_BUFFER_FULL);
//    }
}

bool dbguart_getc(int port_number, char *pbyte) {
//    RdBuffer *pbuf = &uart_port[port_number].rx_buf;
//    return rd_buffer_get(pbuf, pbyte);
    return FALSE;
}


int dbguart_bytes_available(int num) {
    RdBuffer *pbuf = &uart_port[num].rx_buf;
    return rd_buffer_cnt(pbuf);
    return 0;
}


///* ********************************************************************* 
//@Function name:  uart2_rx_sevice
//@Return: (void) 
//@Parameters: 
//  int port_number - port number
//@Description: this is service for receive from port
//
// ********************************************************************* */
//INTERRUPT_SERVICE uart2_rx_service() {  
//    int dev = UART2;
//    RdBuffer *pbuf = &uart_port[UART_1].rx_buf;
//    BYTE byte ;
//    bool error = uart_is_error_hw(dev);
//    if ( !error && uart_getc(dev, &byte ) ) {
//        rd_buffer_put(pbuf, (RdBufferRecord*) & byte);
//    } else {
//        uart_flush_hw(dev);
//    }
//}

void uart_putc(int port_number, const char byte) {
//    RdBuffer *pbuf = &uart_port[port_number].tx_buf;
//    if (rd_buffer_put(pbuf, (RdBufferRecord*) & byte) != TRUE) {
//        error_set(ERROR_UART_BUFFER_FULL);
//    }
}

bool uart_getc(int port_number, char *pbyte) {
//    RdBuffer *pbuf = &uart_port[port_number].rx_buf;
//    return rd_buffer_get(pbuf, pbyte);
    return FALSE;
}


int uart_bytes_available(int num) {
    RdBuffer *pbuf = &uart_port[num].rx_buf;
    return rd_buffer_cnt(pbuf);
    return 0;
}


///* ********************************************************************* 
//@Function name:  uart2_rx_sevice
//@Return: (void) 
//@Parameters: 
//  int port_number - port number
//@Description: this is service for receive from port
//
// ********************************************************************* */
//INTERRUPT_SERVICE uart2_rx_service() {  
//    int dev = UART2;
//    RdBuffer *pbuf = &uart_port[UART_1].rx_buf;
//    BYTE byte ;
//    bool error = uart_is_error_hw(dev);
//    if ( !error && uart_getc(dev, &byte ) ) {
//        rd_buffer_put(pbuf, (RdBufferRecord*) & byte);
//    } else {
//        uart_flush_hw(dev);
//    }
//}




INTERRUPT_SERVICE uart2_rx_service(void){

}