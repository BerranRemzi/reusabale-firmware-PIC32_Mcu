/*!
* @file gpio.h
* @author D.Chikov
* @date 10/15/2020, 09:37:33
* @brief GPIO output input driver header
*/


#ifndef GPIO_H
#define GPIO_H

#include "typedef_global.h"


// GPIO coded here A11 -> 0x410B whwere 0x41 is Ascci code of 'A' and B is 11
#define GPIO(A,B)               (((uint32_t)A<<8) |B)

// get PIN number
#define GPIO_PIN(G)             ((G) & 0x00ff)

// get port name
#define GPIO_PORT(G)            (((G)>>8) & 0x00ff)



// ----------[options]----------
#define GPIO_ANALOG                 (0x80000000UL)

//gpio common
#define GPIO_IN             (0x00000001)
#define GPIO_OUT            (0x00000002)
#define GPIO_OUT_HIGH       (0x00000004)
#define GPIO_OUT_LOW        (0x00000008)

// change notification
#define CN_PULLUP           (0x00000010)
#define CN_PULLDOWN         (0x00000020)
#define CN_INTERRUPT        (0x00000040)
#define CN_ENABLE           (0x00000080)

// gpio is peripheral output
#define GPIO_IS_CUSTOM_OUTPUT       (0x20000000UL)
#define GPIO_CUSTOM_OUTPUT(func)    ((func|0x2000)<<16)

// gpio is peripheral input
#define GPIO_IS_CUSTOM_INPUT        (0x40000000UL)
#define GPIO_CUSTOM_INPUT(func)     ((func|0x4000)<<16)


// custom port functions when for INPUT
typedef enum {

    INPUT_FUNC_INT1 = 0,
    INPUT_FUNC_INT2 = 1,
    INPUT_FUNC_INT3 = 2,
    INPUT_FUNC_INT4 = 3,
    INPUT_FUNC_T2CK = 5,
    INPUT_FUNC_T3CK = 6,
    INPUT_FUNC_T4CK = 7,
    INPUT_FUNC_T5CK = 8,
    INPUT_FUNC_T6CK = 9,
    INPUT_FUNC_T7CK = 10,
    INPUT_FUNC_T8CK = 11,
    INPUT_FUNC_T9CK = 12,
    INPUT_FUNC_IC1 = 13,
    INPUT_FUNC_IC2 = 14,
    INPUT_FUNC_IC3 = 15,
    INPUT_FUNC_IC4 = 16,
    INPUT_FUNC_IC5 = 17,
    INPUT_FUNC_IC6 = 18,
    INPUT_FUNC_IC7 = 19,
    INPUT_FUNC_IC8 = 20,
    INPUT_FUNC_IC9 = 21,
    INPUT_FUNC_OCFA = 23,
    INPUT_FUNC_U1RX = 25,
    INPUT_FUNC_U1CTS = 26,
    INPUT_FUNC_U2RX = 27,
    INPUT_FUNC_U2CTS = 28,
    INPUT_FUNC_U3RX = 29,
    INPUT_FUNC_U3CTS = 30,
    INPUT_FUNC_U4RX = 31,
    INPUT_FUNC_U4CTS = 32,
    INPUT_FUNC_U5RX = 33,
    INPUT_FUNC_U5CTS = 34,
    INPUT_FUNC_U6RX = 35,
    INPUT_FUNC_U6CTS = 36,
    INPUT_FUNC_SDI1 = 38,
    INPUT_FUNC_SS1 = 39,
    INPUT_FUNC_SDI2 = 41,
    INPUT_FUNC_SS2 = 42,
    INPUT_FUNC_SDI3 = 44,
    INPUT_FUNC_SS3 = 45,
    INPUT_FUNC_SDI4 = 47,
    INPUT_FUNC_SS4 = 48,
    INPUT_FUNC_C1RX = 55,
    INPUT_FUNC_C2RX = 56,
    INPUT_FUNC_REFCLKI1 = 57,
    INPUT_FUNC_REFCLKI3 = 59,
    INPUT_FUNC_REFCLKI4 = 60
} InputFunc_t;


// custom port functions for output
typedef enum {

    OUTPUT_FUNC_U3TX = 0x01,
    OUTPUT_FUNC_U4RTS = 0x02,
    OUTPUT_FUNC_SDO1 = 0x05,
    OUTPUT_FUNC_SDO2 = 0x06,
    OUTPUT_FUNC_SDO3 = 0x07,
    OUTPUT_FUNC_OC3 = 0x0B,
    OUTPUT_FUNC_OC6 = 0x0C,
    OUTPUT_FUNC_REFCLKO4 = 0x0D,
    OUTPUT_FUNC_C2OUT = 0x0E,
    OUTPUT_FUNC_C1TX = 0x0F,
    OUTPUT_FUNC_U1TX = 0x01,
    OUTPUT_FUNC_U2RTS = 0x02,
    OUTPUT_FUNC_U5TX = 0x03,
    OUTPUT_FUNC_U6RTS = 0x04,
    OUTPUT_FUNC_SDO4 = 0x08,
    OUTPUT_FUNC_OC4 = 0x0B,
    OUTPUT_FUNC_OC7 = 0x0C,
    OUTPUT_FUNC_REFCLKO1 = 0x0F,
    OUTPUT_FUNC_U3RTS = 0x01,
    OUTPUT_FUNC_U4TX = 0x02,
    OUTPUT_FUNC_U6TX = 0x04,
    OUTPUT_FUNC_SS1 = 0x05,
    OUTPUT_FUNC_SS3 = 0x07,
    OUTPUT_FUNC_SS4 = 0x08,
    OUTPUT_FUNC_OC5 = 0x0B,
    OUTPUT_FUNC_OC8 = 0x0C,
    OUTPUT_FUNC_C1OUT = 0x0E,
    OUTPUT_FUNC_REFCLKO3 = 0x0F,
    OUTPUT_FUNC_U1RTS = 0x01,
    OUTPUT_FUNC_U2TX = 0x02,
    OUTPUT_FUNC_U5RTS = 0x03,
    OUTPUT_FUNC_SS2 = 0x06,
    OUTPUT_FUNC_OC2 = 0x0B,
    OUTPUT_FUNC_OC1 = 0x0C,
    OUTPUT_FUNC_OC9 = 0x0D,
    OUTPUT_FUNC_C2TX = 0x0F,
    OUTPUT_FUNC_NO_CONNECT = 0x00,
    

} OutputFunc_t;



// unlock changes (needed for CUSTOM output/input)
/*!
* Unlock GPIO remapping 
*/
void gpio_unlockChanges();

// lock changes (needed for CUSTOM output/input)
/*!
* Lock GPIO remapping 
*/
void gpio_lockChanges();

// enable gpio
/*!
* GPIO Enable
*/
void gpio_enable(uint32_t gpio, uint32_t gpio_options);

//GPIO set 
/*!
* GPIO Set output HI/LO
*/
void gpio_set(uint32_t gpio, bool gpio_pin_value);

typedef enum {
    GPIO_DIR_INPUT =1,
    GPIO_DIR_OUTPUT=0
}GpioDir;

void gpio_set_dir(uint32_t gpio, GpioDir gpio_dir);

GpioDir gpio_direction(uint32_t gpio);

typedef enum{    
    REG_ANSEL,
    REG_TRIS,
    REG_PORT,
    REG_LAT,        
    REG_ODC,
    REG_CNPU,
    REG_CNPD,
    REG_CNCON,
    REG_EN,
    REG_CNSTAT,
    REG_CNEA,
    REG_CNF,
    REG_SRCON0A,
    REG_SRCON1A    
}RegType;


// gpio read
/*!
* ...tbd...
*/
bool gpio_get(uint32_t gpio);

/*!
* ...tbd...
*/
volatile uint32_t* gpio_reg(RegType reg_type,  uint32_t gpio, char set_type);

/*!
* ...tbd...
*/
void  gpio_toggle(uint32_t gpio);

/*!
* ...tbd...
*/
bool gpio_valid(uint32_t gpio);

// set directly to gpio pin (faster)
/*!
* ...tbd...
*/
#define gpio_setA(port,pin,val) do{LAT##port &=~(1<<pin);\
                                          LAT##port |=(val<<pin);\
                                  }while(0);
// read directly from GPIO (faster)
/*!
* MACRO:...tbd...
*/
#define gpio_getA(port,pin) ( (PORT##port & (1<<pin)) != 0))

#endif