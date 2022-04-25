/*!
* @file dma\dma.c
* @author D.Chikov
* @date 10/15/2020, 09:37:33
* @brief   This dma driver is predefined for use with UART5,UART6,UART2,ADC
*  dma_send sends data to uart device
*  for adc dma_send is useless
*/


#include "dma.h"
#include "uart.h"

typedef struct {
  BOOL    busy;        /* busy indicator  */
  UINT32 count;        /* buffer data size */
  UINT8 buffer[100] ;  /* buffer data     */
}Dma_t;

PRIVATE Dma_t dma[DMA_COUNT] = {0};


/*!
* 	 void dma_init(void)
* 
* 	...tbd...
* 	\param void -...
* 	\return void -...
*/
void dma_init(void){
  UINT i;
/* [DMA1]*/
  DmaChnConfigure(DMA_CHANNEL1, DMA_CHN_PRI0, DMA_CONFIG_DEFAULT);
  DmaEvCtrl evCtrl;
  evCtrl.w = 0;
  evCtrl.SIRQEN = TRUE;
  evCtrl.CHSIRQ = 42; /* UART2 TX*/
  DmaChnWriteEventControlFlags(DMA_CHANNEL1, evCtrl.w);
  DmaChnSetEvEnableFlags(DMA_CHANNEL1, DMA_EV_BLOCK_DONE);
/* interrupts*/
  INTSetVectorPriority(INT_VECTOR_DMA(DMA_CHANNEL1), INT_PRIORITY_LEVEL_5);
  INTSetVectorSubPriority(INT_VECTOR_DMA(DMA_CHANNEL1), INT_SUB_PRIORITY_LEVEL_0);
  INTEnable(INT_DMA1, TRUE);

/* [DMA2] */
  DmaChnConfigure(DMA_CHANNEL2, DMA_CHN_PRI0, DMA_CONFIG_DEFAULT);
  evCtrl.w = 0;
  evCtrl.SIRQEN = TRUE;
  evCtrl.CHSIRQ = 75; /* UART5 TX*/
  DmaChnWriteEventControlFlags(DMA_CHANNEL2, evCtrl.w);
  DmaChnSetEvEnableFlags(DMA_CHANNEL2, DMA_EV_BLOCK_DONE);
/* interrupts*/
  INTSetVectorPriority(INT_VECTOR_DMA(DMA_CHANNEL2), INT_PRIORITY_LEVEL_5);
  INTSetVectorSubPriority(INT_VECTOR_DMA(DMA_CHANNEL2), INT_SUB_PRIORITY_LEVEL_0);
  INTEnable(INT_DMA1, TRUE);

/* [DMA3] */
  DmaChnConfigure(DMA_CHANNEL3, DMA_CHN_PRI0, DMA_CONFIG_DEFAULT);
  evCtrl.w = 0;
  evCtrl.SIRQEN = TRUE;
  evCtrl.CHSIRQ = 72; /* UART6 TX*/
  DmaChnWriteEventControlFlags(DMA_CHANNEL3, evCtrl.w);
  DmaChnSetEvEnableFlags(DMA_CHANNEL3, DMA_EV_BLOCK_DONE);
/* interrupts*/
  INTSetVectorPriority(INT_VECTOR_DMA(DMA_CHANNEL3), INT_PRIORITY_LEVEL_5);
  INTSetVectorSubPriority(INT_VECTOR_DMA(DMA_CHANNEL3), INT_SUB_PRIORITY_LEVEL_0);
  INTEnable(INT_DMA1, TRUE);

/* [DMA4] */
  DmaChnConfigure(DMA_CHANNEL0, DMA_CHN_PRI0, DMA_CONFIG_DEFAULT);
  evCtrl.w = 0;
  evCtrl.SIRQEN = TRUE;
  evCtrl.CHSIRQ = 33; /* ADC*/
  DmaChnWriteEventControlFlags(DMA_CHANNEL0, evCtrl.w);
  DmaChnSetEvEnableFlags(DMA_CHANNEL0, DMA_EV_BLOCK_DONE);
/* interrupts*/
  INTSetVectorPriority(INT_VECTOR_DMA(DMA_CHANNEL0), INT_PRIORITY_LEVEL_5);
  INTSetVectorSubPriority(INT_VECTOR_DMA(DMA_CHANNEL0), INT_SUB_PRIORITY_LEVEL_0);
  INTEnable(INT_DMA1, TRUE);
  
  for(i=0; i < DMA_COUNT; i++){
    dma[i].busy = FALSE;
    dma[i].count = 0;
  }

/* enable all dma*/
  DmaEnable(TRUE);
}



/*!
* 	 BOOL dma_push(UINT dma_number, BYTE byte )
* 
* 	...tbd...
* 	\param UINT dma_number -...
* 	\param BYTE byte -...
* 	\return BOOL -...
*/
BOOL dma_push(UINT dma_number, BYTE byte ){
  Dma_t *pdma = &dma[dma_number];
  if( !pdma->busy && pdma->count < DMA_BUFFER_SIZE ){
    pdma->buffer[pdma->count] = byte;         
    pdma->count ++; 
    return TRUE;
  }
  return FALSE;
}



/*!
* 	 void dma_send(UINT dma_number)
* 
* 	Start dma for sending data 
*		to UART port from local buffer
* 	\param UINT dma_number -...
* 	\return void -...
*/
void dma_send(UINT dma_number){
  Dma_t *pdma = &dma[dma_number];
  volatile UINT *pfrom = (void*)NULL;
  volatile UINT *pto = (void*)NULL;
  UINT data_size =0;
  UINT dev =0;
  if(!pdma->busy && pdma->count >0 ){
    pdma->busy = TRUE;
    switch(dma_number){
      case DMA_1:/*UART2*/
        dev = DMA_CHANNEL1;
        data_size = pdma->count;
        pfrom = (void*)pdma->buffer;
        pto = (void*)uartReg[UART2]->tx.reg;
      break;
      case DMA_2:/*UART5*/
        dev = DMA_CHANNEL2;
        data_size = pdma->count;
        pfrom = (void*)pdma->buffer;
        pto = (void*)uartReg[UART5]->tx.reg;
      break;
      case DMA_3:/*UART6*/
        dev = DMA_CHANNEL3;
        data_size = pdma->count;
        pfrom = (void*)pdma->buffer;
        pto = (void*)uartReg[UART6]->tx.reg;
      break;

      case DMA_4: /*ADC*/
      default:
      break;

    }
    /* if some data need to be processed*/
    if(data_size >0 && dev != 0 )
    {
      DmaChnSetTxfer(dev, (void*)pfrom, (void*)pto, data_size, 1, 1);
      DmaChnStartTxfer(dev, DMA_WAIT_NOT, 0);
      DmaChnEnable(dev);
    }
  }
}



/*!
* 	 BOOL dma_is_busy(UINT dma_number)
* 
* 	...tbd...
* 	\param UINT dma_number -...
* 	\return BOOL -...
*/
BOOL dma_is_busy(UINT dma_number){
  Dma_t *pdma = &dma[dma_number];
  return  pdma->busy;
}


/*!
* 	 INTERRUPT_SERVICE dma1_service(void)
* 
* 	...tbd...
* 	\param void -...
* 	\return INTERRUPT_SERVICE -...
*/
INTERRUPT_SERVICE dma1_service(void) {
    DmaChnDisable(DMA_CHANNEL1);
    dma[DMA_1].count = 0;
    dma[DMA_1].busy = FALSE;
}

/*!
* 	 INTERRUPT_SERVICE dma2_service(void)
* 
* 	...tbd...
* 	\param void -...
* 	\return INTERRUPT_SERVICE -...
*/
INTERRUPT_SERVICE dma2_service(void) {
    DmaChnDisable(DMA_CHANNEL2);
    dma[DMA_2].count = 0;
    dma[DMA_2].busy = FALSE;
}

/*!
* 	 INTERRUPT_SERVICE dma3_service(void)
* 
* 	...tbd...
* 	\param void -...
* 	\return INTERRUPT_SERVICE -...
*/
INTERRUPT_SERVICE dma3_service(void) {
    DmaChnDisable(DMA_CHANNEL3);
    dma[DMA_3].count = 0;
    dma[DMA_3].busy = FALSE;
}

/*!
* 	 INTERRUPT_SERVICE dma4_service(void)
* 
* 	...tbd...
* 	\param void -...
* 	\return INTERRUPT_SERVICE -...
*/
INTERRUPT_SERVICE dma4_service(void) {
    DmaChnDisable(DMA_CHANNEL0);
    dma[DMA_4].count = 0;
    dma[DMA_4].busy = FALSE;
}
