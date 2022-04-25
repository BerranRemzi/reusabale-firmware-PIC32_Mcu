/*!
* @file board.c
* @author D.Chikov
* @date 12/28/2020, 11:37:25
* @brief Board definition
*        Configuration of MCU  
*/


#include <xc.h>
#include <sys/attribs.h>
#include <xc.h>

/*!
*  Configuration WORD0
* DEVCFG0 
*/

#pragma config DEBUG =      OFF
#pragma config JTAGEN =     OFF
#pragma config ICESEL =     ICS_PGx1
#pragma config TRCEN =      OFF
#pragma config BOOTISA =    MIPS32
#pragma config FECCCON =    OFF_UNLOCKED
#pragma config FSLEEP =     OFF
#pragma config DBGPER =     PG_ALL
#pragma config SMCLR =      MCLR_NORM
#pragma config SOSCGAIN =   GAIN_2X
#pragma config SOSCBOOST =  ON
#pragma config POSCGAIN =   GAIN_2X
#pragma config POSCBOOST =  ON
#pragma config EJTAGBEN =   NORMAL
#pragma config CP =         OFF

/*!
*  Configuration WORD1
* DEVCFG1 
*/

#pragma config FNOSC =      SPLL
#pragma config DMTINTV =    WIN_127_128
#pragma config FSOSCEN =    OFF
#pragma config IESO =       OFF
#pragma config POSCMOD =    HS
#pragma config OSCIOFNC =   OFF
#pragma config FCKSM =      CSECME
#pragma config WDTPS =      PS32768
#pragma config WDTSPGM =    STOP
#pragma config FWDTEN =     ON
#pragma config WINDIS =     NORMAL
#pragma config FWDTWINSZ =  WINSZ_25
#pragma config DMTCNT =     DMT31
#pragma config FDMTEN =     OFF

/*!
*  Configuration WORD2
* DEVCFG2
*/

// XTAl = 20Mhz
#pragma config FPLLIDIV =   DIV_2
#pragma config FPLLRNG =    RANGE_5_10_MHZ
#pragma config FPLLICLK =   PLL_POSC
#pragma config FPLLMULT =   MUL_50
#pragma config FPLLODIV =   DIV_2
#pragma config UPLLFSEL =   FREQ_24MHZ

/*!
*  Configuration WORD3
* DEVCFG3 
*/

#pragma config USERID =     0xffff
#pragma config FMIIEN =     OFF
#pragma config FETHIO =     OFF
#pragma config PGL1WAY =    OFF
#pragma config PMDL1WAY =   OFF
#pragma config IOL1WAY =    OFF
#pragma config FUSBIDIO =   OFF



#include "board.h"
#include "system.h"


#include "usart.h"
#include "systmr.h"
#include "wdt.h"
#include "spi.h"
#include "gpio.h"



/*!
* MCU GPIO port map
*/
static struct GpioPort{
	uint32_t gpio;
	uint32_t opt;
    bool init_val;
}ports[] = { GPIO_MAP };




/*!
* 	 void BOARD_Initialize()
* 
* 	This function makes hardware initialization
*/
void BOARD_Initialize(){
    
    //     [ configure GPIOs ]
    uint32_t i=0;
	for (i =0;i<100;i++){
        if(ports[i].gpio != 0){
            gpio_enable(ports[i].gpio,  ports[i].opt );
            gpio_set(ports[i].gpio,     ports[i].init_val );
        }
        else break;
	}
    

    // TODO configure UART3 - for debug communication
    uart_enable(UART3, 115200);       
    	

    
}
