/*!
* @file dma\dma.h
* @author D.Chikov
* @date 10/15/2020, 09:37:33
* @brief DMA using module (not finished)
*/


#ifndef DMA_H
#define DMA_H
#include "compiler.h"
#include "typedef_global.h"
#include "config.h"

#define DMA_BUFFER_SIZE         (100u)

typedef enum{
    DMA_1,
    DMA_2,
    DMA_3,
    DMA_4,
    DMA_COUNT
}DmaEnum_t;


/*!
* ...tbd...
*/
void dma_init(void);

/*!
* ...tbd...
*/
void dma_send(UINT dma_number);
/*!
* ...tbd...
*/
BOOL dma_push(UINT dma_number, BYTE byte);
/*!
* ...tbd...
*/
BOOL dma_is_busy(UINT dma_number);
/*!
* ...tbd...
*/
INTERRUPT_SERVICE dma1_service(void);
/*!
* ...tbd...
*/
INTERRUPT_SERVICE dma2_service(void);
/*!
* ...tbd...
*/
INTERRUPT_SERVICE dma3_service(void);
/*!
* ...tbd...
*/
INTERRUPT_SERVICE dma4_service(void);


#endif