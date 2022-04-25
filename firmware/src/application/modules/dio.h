/*!
* @file modules\dio.h
* @author D.Chikov
* @date 10/15/2020, 18:16:01
* @brief ...tbd...
*/


#ifndef DIO_H
#define DIO_H

#include "gpio.h"
#include "typedef_global.h"

/*!
* DIO pins count
*/
#define DIO_COUNT (54u)

typedef enum{
  DIODIR_OUTPUT=0,
  DIODIR_INPUT=1,    
  DIODIR_UNDEF=9999,
} DioDirection_t;


/*!
* ...tbd...
*/
void dio_init(void);
/*!
* ...tbd...
*/
bool dio_conf(uint32_t dio, uint32_t dir);
/*!
* ...tbd...
*/
int dio_get(uint32_t dio);
/*!
* ...tbd...
*/
bool dio_set(int32_t dio, char* value);
/*!
* ...tbd...
*/
bool dio_set_direction(uint32_t dio, DioDirection_t  direction);
/*!
* ...tbd...
*/
DioDirection_t dio_get_direction(uint32_t dio);
/*!
* ...tbd...
*/
int dio_get_output(uint32_t dio);
/*!
* ...tbd...
*/
uint32_t dio_gpio(uint32_t dio);



/*!
* MACRO:...tbd...
*/
#define DIO_Valid(X) ( (X) > 0 && (X) <= DIO_COUNT)

enum {
    DIOREG_ANSEL = 0,
    
    DIOREG_TRIS    = 0x10,
    DIOREG_TRISCLR = 0x14,
    DIOREG_TRISSET = 0x18,
    DIOREG_TRISINV = 0x1C,

    DIOREG_PORT    = 0x20,

    DIOREG_LAT     = 0x30,
    DIOREG_LATCLR  = 0x34,
    DIOREG_LATSET  = 0x38,
    DIOREG_LATINV  = 0x3C,

    DIOREG_ODC     = 0x40,
    DIOREG_CNPU    = 0x50,
    DIOREG_CNPD    = 0x60,
    DIOREG_CNCON   = 0x70,
    DIOREG_CNEN    = 0x80,
    DIOREG_CNSTAT  = 0x90,
    DIOREG_CNNE    = 0xA0,
    DIOREG_CNF     = 0xB0,
    DIOREG_SRCON0  = 0xC0,
    DIOREG_SRCON1  = 0xD0    
};

enum{
    DIO_GPIOA=0,
    DIO_GPIOB=1,
    DIO_GPIOC=2,
    DIO_GPIOD=3,
    DIO_GPIOE=4,
    DIO_GPIOF=5,
    DIO_GPIOG=6,
};
/*!
* MACRO:...tbd...
*/
#define  DioPortAdr(_REG_,_GPIO_)  ((volatile uint32_t*)(0xBF860000+ (_GPIO_) *0x100 + (_REG_)))

extern  const uint32_t dio_table[DIO_COUNT + 1] ;

#endif // DIO_H