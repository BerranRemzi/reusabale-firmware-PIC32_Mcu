/*!
* @file refclk\refclk.c
* @author D.Chikov
* @date 10/15/2020, 09:37:33
* @brief ...tbd...
*/


#include "refclk.h"

#define REG_CON     (0x00u)
#define REG_TRIM    (0x10u)

#define REG_ADDR(_NUM_, _OFFS_)  (volatile uint32_t*)((uint32_t)&REFO1CON + (_NUM_)*0x20 + (_OFFS_) )



/*!
* 	 int refclk_cfg(RefClk num, RefClkSource src, uint32_t div, uint32_t trim)
* 
* 	...tbd...
* 	\param RefClk num -...
* 	\param RefClkSource src -...
* 	\param uint32_t div -...
* 	\param uint32_t trim -...
* 	\return int -...
*/
int refclk_out_cfg(RefClk num, RefClkSource src, uint32_t div, uint32_t trim)
{    
        volatile __REFO1CONbits_t *pCON = (__REFO1CONbits_t *) REG_ADDR(num, REG_CON);
        volatile __REFO1TRIMbits_t *pTRIM = (__REFO1TRIMbits_t*) REG_ADDR(num, REG_TRIM);    
        while(pCON->ACTIVE != pCON->ON);
        pCON->ON =0;
        pCON->RODIV = div;   
        pCON->ROSEL = src;        
        pTRIM->ROTRIM = trim;
        while(pCON->ACTIVE != pCON->ON);
        pCON->ON =1;     

    return 0;
}

void refclk_out_enable(RefClk num, bool enable){
    volatile __REFO1CONbits_t *pCON = (__REFO1CONbits_t *) REG_ADDR(num, REG_CON);
    pCON->OE = enable;
}
