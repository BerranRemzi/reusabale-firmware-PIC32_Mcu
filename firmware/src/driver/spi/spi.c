/*!
* @file spi.c
* @author D.Chikov
* @date 12/28/2020, 13:45:30
* @brief SPI control driver
*/


#include "spi.h" 
#include "refclk.h"
#include "system.h"
#include "board.h"




#define REG_CON     (0x00u)
#define REG_CON2     (0x40u)
#define REG_STAT    (0x10u)
#define REG_BUF     (0x20u)
#define REG_BRG     (0x30u)



#define REG_ADDR(_NUM_,_OFFS_)  (volatile uint32_t*)((uint32_t)&SPI1CON + (uint32_t)(_NUM_) *0x200 + (_OFFS_))




/*!
* 	 ResultError_t spi_enable(Spi num, uint32_t options)
* 
* 	This function enables SPI 
* 	\param Spi num -...
* 	\param uint32_t options -...
* 	\return ResultError_t -...
*/
ResultError_t spi_enable(Spi num, uint32_t options){
    int result = RES_INVALID_IDENTIFIER;
    if(num < SPI_COUNT){
        volatile __SPI1CONbits_t *pCON =  (__SPI1CONbits_t *)REG_ADDR((uint32_t)num,REG_CON);
        volatile uint32_t *pCON2 =  REG_ADDR((uint32_t)num,REG_CON2);        
        pCON->w = options;   
        pCON->ON = 1;
        *pCON2 = 0;
        result = RES_NO_ERROR;    
    }
    return result;
}


/*!
* 	 void spi_disable(Spi num)
* 
* 	...tbd...
* 	\param Spi num -...
* 	\return ResultError_t -...
*/
ResultError_t spi_disable(Spi num){
     if( num < SPI_COUNT ){
        volatile __SPI1CONbits_t *pCON=  (__SPI1CONbits_t *)REG_ADDR((uint32_t)num,REG_CON);        
        pCON->ON=0;         
        return RES_NO_ERROR;   
    }
     return RES_INVALID_IDENTIFIER;
}


/*!
* 	 void  spi_set_baud(Spi num, uint32_t baud)
* 
* 	...tbd...
* 	\param Spi num -...
* 	\param uint32_t baud -...
* 	\return void -...
*/
void  spi_set_baud(Spi num, uint32_t baud){
    if( num < SPI_COUNT ){
        volatile uint32_t *BRG =  REG_ADDR((uint32_t)num, REG_BRG);
        *BRG = baud;
    }    
}


/*!
* 	 void  spi_set_clock(Spi num, uint32_t clock)
* 
* 	...tbd...
* 	\param Spi num -...
* 	\param uint32_t clock -...
* 	\return void -...
*/
void  spi_set_clock(Spi num, uint32_t clock){
    if(num<SPI_COUNT){
        volatile uint32_t *BRG =  REG_ADDR((uint32_t)num, REG_BRG);
        const uint32_t Fpb = SYS_CLK_FREQ/2;
        *BRG = Fpb/(clock*2) - 1;
    }    
}



/*!
* 	 ResultError_t spi_transfer(Spi num, const void *pdata_out, void *pdata_in, int data_size)
* 
* 	...tbd...
* 	\param Spi num -...
* 	\param const void *pdata_out -...
* 	\param void *pdata_in -...
* 	\param int data_size -...
* 	\return ResultError_t -...
*/
ResultError_t spi_transfer(Spi num, const void *pdata_out, void *pdata_in, int data_size)
{
    int result = RES_INVALID_IDENTIFIER;
    volatile __SPI1CONbits_t *pCON =  (__SPI1CONbits_t *)REG_ADDR((uint32_t)num, REG_CON);
    const volatile __SPI1STATbits_t *pSTAT =  (__SPI1STATbits_t *)REG_ADDR((uint32_t)num,REG_STAT);
    volatile uint32_t *BUF =  REG_ADDR((uint32_t)num,REG_BUF);
    
    while( pSTAT->SPIBUSY);
    
    if(num <SPI_COUNT)
    {
        int i;
        for(i=0;i<data_size;i++)
        {
            // 16 bits 
            if(pCON->MODE16)
            {
                while(pSTAT->SPITBF);
                *BUF = ((uint16_t*)pdata_out)[i];                
                if( pdata_in != 0 ){
                    while( pSTAT->SPIBUSY);
                    ((uint16_t*)pdata_in)[i] = *BUF;      
                }
            }
            // 32 bits
            else if(pCON->MODE32)
            {
                while(pSTAT->SPITBF);
                *BUF = ((uint32_t*)pdata_out)[i];                                
                if( pdata_in != 0 ){
                    while( pSTAT->SPIBUSY);
                    ((uint32_t*)pdata_in)[i] = *BUF;
                }
            }
            // 8 bits
            else{
                while(pSTAT->SPITBF);
                *BUF = ((uint8_t*)pdata_out)[i];                
                if( pdata_in != 0){
                    while( pSTAT->SPIBUSY);
                    ((uint8_t*)pdata_in)[i] = *BUF;
                }
            }
        }
        result =RES_NO_ERROR;
    }
    return result;  
}


/*!
* 	 bool    spi_transfer_complete(Spi num)
* 
* 	...tbd...
* 	\param Spi num -...
* 	\return bool -...
*/
bool    spi_transfer_complete(Spi num){    
    const volatile __SPI1STATbits_t *pSTAT =  (__SPI1STATbits_t*)REG_ADDR((uint32_t)num,REG_STAT);
    return (pSTAT->SPITBE == 1 && !pSTAT->SPIBUSY);
}


/*!
* 	 bool    spi_busy(Spi num)
* 
* 	Check is SPI port busy
* 	\param Spi num - SPI port number
* 	\return bool - TRUE if SPI Error
*/
bool    spi_busy(Spi num){
    const volatile __SPI1STATbits_t *pSTAT =  (__SPI1STATbits_t*)REG_ADDR((uint32_t)num,REG_STAT);
    return pSTAT->SPIBUSY !=0;
}

/*!
* 	 bool    spi_error(Spi num)
* 
* 	Check if SPI port is error
* 	\param Spi num - SPI port number
* 	\return bool -  if some SPI port error
*/
bool    spi_error(Spi num){
    const volatile __SPI1STATbits_t *pSTAT =  (__SPI1STATbits_t*)REG_ADDR((uint32_t)num,REG_STAT);
    return pSTAT->SPIROV || pSTAT->FRMERR;
}

/*!
* 	 void    spi_reset(Spi num)
* 
* 	Resets SPI port
* 	\param Spi num - SPI port number
*/
void    spi_reset(Spi num){
    volatile __SPI1STATbits_t *pSTAT =  (__SPI1STATbits_t*)REG_ADDR((uint32_t)num,REG_STAT);
    pSTAT->SPIROV =0;
}
