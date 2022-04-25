/*!
* @file spi.h
* @author D.Chikov
* @date 10/15/2020, 09:37:33
* @brief HW SPI driver header
*/



#ifndef _DRV_SPI_H
#define _DRV_SPI_H

#include <xc.h>

#ifdef __cplusplus  // Provide C++ Compatibility
    extern "C" {
#endif
#include "typedef_global.h"     
        
// ------ SPIxCON register -------
// TX Interrupt mode
#define SPIxCON_INT_TX_MODE1                    (0<<0)
#define SPIxCON_INT_TX_MODE2                    (1<<0)
#define SPIxCON_INT_TX_MODE3                    (2<<0)
#define SPIxCON_INT_TX_MODE4                    (3<<0)

// RX Interrupt mode
#define SPIxCON_INT_RX_MODE1                    (0<<2)
#define SPIxCON_INT_RX_MODE2                    (1<<2)
#define SPIxCON_INT_RX_MODE3                    (2<<2)
#define SPIxCON_INT_RX_MODE4                    (3<<2)

// Disable SDI pin 
#define SPIxCON_SDI_DISABLE                     (1<<4)

// when 1== is Master
#define SPIxCON_MASTER_MODE                     (1<<5)
#define SPIxCON_SLAVE_MODE                     (0<<5)

// CPOL when 0 : IDLE is low level and ACTIVE is high level
//      when 1 : IDLE is high level and ACTIVE is low level
#define SPIxCON_CPOL0                           (0<<6)
#define SPIxCON_CPOL1                           (1<<6)

// when 1 used as CS in Slave mode(only)
#define SPIxCON_SLAVE_SELECT_ENABLE             (1<<7)

// CPHA when 0 : data changes on IDLE to ACTIVE
//      when 1: data changes from ACTIVE to IDLE      
#define SPIxCON_CPHA0                           (0<<8)
#define SPIxCON_CPHA1                           (1<<8)

//0- data sampled at the end
//1- data sampled at the middle
#define SPIxCON_SDI_MODE0                       (0<<9)
#define SPIxCON_SDI_MODE1                       (1<<9)

// MODE 
#define SPIxCON_MODE_8BIT                       (0<<10)
#define SPIxCON_MODE_16BIT                      (1<<10)
#define SPIxCON_MODE_32BIT                      (2<<10)      

// SDo pin disable when 1
#define SPIxCON_SDO_DISABLE                     (1<<12)

// Disable operartion in IDLE
#define SPIxCON_IDLE_DISABLED                    (1<<13)

// SPI module Enable -turns ON
#define SPIxCON_ENABLE                          (1<<15)
#define SPIxCON_ON                              (1<<15)

// Enables buffer
#define SPIxCON_BUFFER_EN                       (1<<17)

//clock source 0 - PBCLK/2,  1-REFCLKO1
#define CLKSRC_PBCLK                            (0<<23)
#define CLKSRC_REFCLKO1                         (1<<23)

// slave mode enabled
#define SPIxCON_MASTER_SLAVE_SELECT_ENABLE       (1<<28)

// Slave select (CS) polarity in slave mode
#define SPIxCON_SLAVE_SS_POL0                   (1>>29)
#define SPIxCON_SLAVE_SS_POL1                   (0>>29)
       
        
        
        
        
// ---------SPIxSTAT -------
#define SPIxSTAT_TX_BUF_EMPTY               (1<<3)
#define SPIxSTAT_RX_BUF_FULL                (1<<0)
#define SPIxSTAT_TX_BUF_FULL                (1<<1)
#define SPIxSTAT_RX_FIFO_EMPTY              (1<<5)
#define SPIxSTAT_RCV_OVERFLOW               (1<<6)
#define SPIxSTAT_SHIFTREG_EMPTY             (1<<7)
#define SPIxSTAT_TRMT_UNDERRUN              (1<<8)
#define SPIxSTAT_BUSY                       (1<<8)
#define SPIxSTAT_TXBUF_ELM_CNT_MASK         (0x1F<<16)
#define SPIxSTAT_RXBUF_ELM_CNT_MASK         (0x1F<<24)
        
        
        
// Available SPI modules
typedef enum {

    #ifdef SPI1STAT
      SPI1,
    #endif

    #ifdef SPI2STAT
      SPI2,
    #endif

    #ifdef SPI3STAT
      SPI3,
    #endif

    #ifdef SPI4STAT
      SPI4,
    #endif

    #ifdef SPI5STAT
      SPI5,
    #endif

    #ifdef SPI6STAT
    SPI6,
    #endif
    SPI_COUNT
}Spi;

/*!
* Enables SPI module. Doesn't configure GPIO
*/
ResultError_t     spi_enable(Spi num, uint32_t options);

ResultError_t spi_disable(Spi num);

/*!
* Transfer data by SPI. Portn need to be configured
*/
ResultError_t     spi_transfer(Spi num, const void *pdata_out,void *pdata_in, int data_size);
/*!
* Check if SPI is busy
*/
bool    spi_busy();
/*!
* Checl SPI error
*/
bool    spi_error();
/*!
* Make SPI reset
*/
void    spi_reset();
/*!
* Set SPI baudrate
*/
void    spi_set_baud(Spi num, uint32_t baud);
/*!
* set SPI clock
*/
void    spi_set_clock(Spi num, uint32_t clock);



#ifdef __cplusplus
}
#endif



#endif // #ifndef _DRV_USART_H


