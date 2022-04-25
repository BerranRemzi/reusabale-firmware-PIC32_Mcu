/*!
* @file i2c\i2c.h
* @author D.Chikov
* @date 10/15/2020, 09:37:33
* @brief ...tbd...
*/


#ifndef _I2C_H
#define _I2C_H

typedef enum {
   I2C1,
   I2C2,
   I2C3,
   I2C4,
   SW_I2C1,
   SW_I2C2,
   SW_I2C3,
   SW_I2C4,
}I2CCom;

/*!
* ...tbd...
*/
void i2c_init(I2CCom i2c);

// for software i2C
/*!
* ...tbd...
*/
void swi2c_configure(uint32_t gpio_sdc, uint32_t gpio_sda);

/*!
* ...tbd...
*/
ResultError_t i2c_write(I2CCom i2c, uint8_t *pdata, uint32_t bytes);
/*!
* ...tbd...
*/
ResultError_t i2c_read(I2CCom i2c, uint8_t *pdata, uint32_t bytes);
/*!
* ...tbd...
*/
void i2c_ack(I2CCom i2c);
/*!
* ...tbd...
*/
void i2c_nak(I2CCom i2c);

#endif