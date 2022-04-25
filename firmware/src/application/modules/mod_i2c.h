/*!
* @file modules\i2c.h
* @author D.Chikov
* @date 10/15/2020, 18:16:01
* @brief ...tbd...
*/



#ifndef MOD_I2C_H
#define MOD_I2C_H

#include "typedef_global.h"



/*!
* Modules I2C
*/
void mod_i2c_init(void);

/************************************************************************/
/*	Sets up I2C pin outs   
*	Parameter (i2c_number): I2C_NUMBER
*	Return (-1): PARAM_ERR, (0): OK                                     */
/************************************************************************/
/*!
* ...tbd...
*/
int32_t mod_i2c_conf(uint32_t i2c_number);

/************************************************************************/
/*	Sets up I2C speed       
*	Parameter (i2c_number): I2C_NUMBER, (speed): MPU_I2C_SPEED macro
*	Return (-1): PARAM_ERR, (-8): ERR_INVALID_ARG, (0): OK                    */
/************************************************************************/
/*!
* ...tbd...
*/
int32_t mod_i2c_speed(uint32_t i2c_number, uint32_t speed);

/************************************************************************/
//	END OF CONFIGURATION PART OF THE FILE

//	START OF COMMUNICATION PART OF THE FILE


/************************************************************************************/
/*	Function to send write and read data to slave device via I2C
*	Parameter (i2c_number): I2C_NUMBER, (i2c_addr): SLAVE_ADDRESS
*	Parameter (pdata_write): DATA TO WRITE, (pdata_read): READ DATA BUFFER
*	Parameter (len_write): LENGTH OF WRITE DATA, (len_read): LENGTH OF READ DATA
*	Return (-1): PARAM_ERR or ERR_IO_ERROR
*	Return (0 ): OK			    */
/************************************************************************************/
/*!
* ...tbd...
*/
int32_t mod_i2c_readwrite_data(uint32_t i2c_number, uint32_t i2c_addr, const uint8_t *pdata_write, uint8_t *pdata_read, uint32_t len_write, uint32_t len_read);

/************************************************************************************/
/*	Function to send data to slave device via I2C	
*	Parameter (i2c_number): I2C_NUMBER, (i2c_addr): SLAVE_ADDRESS
*	Parameter (pdata): DATA_BUFFER, (len): BUFFER_LENGHT 							
*	Return (-1): PARAM_ERR or ERR_IO_ERROR
*	Return (0 ): OK			    */
/************************************************************************************/ 
/*!
* ...tbd...
*/
int32_t mod_i2c_write_data(uint32_t i2c_number, uint32_t i2c_addr, const uint8_t *pdata, uint32_t len);

/************************************************************************************/
/*	Function to read data from slave device via I2C				
*	Parameter (i2c_number): I2C_NUMBER, (i2c_addr): SLAVE_ADDRESS
*	Parameter (pdata): DATA_BUFFER, (len): BUFFER_LENGHT					
*	Return (-1): PARAM_ERR or ERR_IO_ERROR
*	Return (n ): working correctly returns number of send bytes			   */
/************************************************************************************/
/*!
* ...tbd...
*/
int32_t mod_i2c_read_data(uint32_t i2c_number, uint32_t i2c_addr, uint8_t *pdata, uint32_t len);

/************************************************************************************/
//	END OF COMMUNICATION PART OF THE FILE
#endif
