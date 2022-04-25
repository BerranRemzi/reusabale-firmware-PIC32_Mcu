/*!
* @file modules\i2c.c
* @author D.Chikov
* @date 10/15/2020, 18:16:01
* @brief I2C module ONMCUv2
*/



#include "mod_i2c.h"
#include "i2c.h"



/*!
* 	 int32_t i2c_conf(uint32_t i2c_number)
* 
* 	...tbd...
* 	\param uint32_t i2c_number -...
* 	\return int32_t -...
*/
int32_t mod_i2c_conf(uint32_t i2c_number)
{
//	status_code_t result = STATUS_OK;
//	
//	if(i2c_number==MPU_I2C1)
//	{
//		gpio_enable_gpio_pin(AVR32_PIN_PC04);
//		gpio_enable_gpio_pin(AVR32_PIN_PC05);
//		
//		const gpio_map_t TWIM_GPIO_MAP = {
//			{AVR32_PIN_PC04, AVR32_TWIMS1_TWCK_FUNCTION},
//			{AVR32_PIN_PC05, AVR32_TWIMS1_TWD_FUNCTION}};
//		gpio_enable_module (TWIM_GPIO_MAP, sizeof (TWIM_GPIO_MAP) / sizeof (TWIM_GPIO_MAP[0]));
//		
//		/*//Pins now controlled by periphery 
//		AVR32_GPIO.port[2].gperc=(1<<(AVR32_PIN_PC04%32))|(1<<(AVR32_PIN_PC05%32));
//		// Set peripheral mux									
//		AVR32_GPIO.port[2].pmr0c=(1<<(AVR32_PIN_PC04%32))|(1<<(AVR32_PIN_PC05%32));
//		AVR32_GPIO.port[2].pmr1c=(1<<(AVR32_PIN_PC04%32))|(1<<(AVR32_PIN_PC05%32));
//		AVR32_GPIO.port[2].pmr2s=(1<<(AVR32_PIN_PC04%32))|(1<<(AVR32_PIN_PC05%32));*/
//  
//		twim_master_init (MODULE_TWI1, &opt1);
//		
//	}
//	else if(i2c_number==MPU_I2C2)
//	{
//		gpio_enable_gpio_pin(AVR32_PIN_PC06);
//		gpio_enable_gpio_pin(AVR32_PIN_PC07);
//				
//		const gpio_map_t TWIM_GPIO_MAP = {
//			{AVR32_PIN_PC06, AVR32_TWIMS2_TWCK_FUNCTION},
//			{AVR32_PIN_PC07, AVR32_TWIMS2_TWD_FUNCTION}};
//			gpio_enable_module (TWIM_GPIO_MAP, sizeof (TWIM_GPIO_MAP) / sizeof (TWIM_GPIO_MAP[0]));
//					
//		
//		/*//Pins now controlled by periphery 
//		AVR32_GPIO.port[2].gperc=(1<<(AVR32_PIN_PC06%32))|(1<<(AVR32_PIN_PC07%32));
//		// Set peripheral mux
//		AVR32_GPIO.port[2].pmr0c=(1<<(AVR32_PIN_PC06%32))|(1<<(AVR32_PIN_PC07%32));
//		AVR32_GPIO.port[2].pmr1c=(1<<(AVR32_PIN_PC06%32))|(1<<(AVR32_PIN_PC07%32));
//		AVR32_GPIO.port[2].pmr2s=(1<<(AVR32_PIN_PC06%32))|(1<<(AVR32_PIN_PC07%32));*/
//		
//		twim_master_init (MODULE_TWI2, &opt2);	
//	}
//	else
//	{
//		result = ERR_IO_ERROR;
//	}
//	
	return 0;
}



/*!
* 	 int32_t i2c_speed(uint32_t i2c_number, uint32_t speed)
* 
* 	...tbd...
* 	\param uint32_t i2c_number -...
* 	\param uint32_t speed -...
* 	\return int32_t -...
*/
int32_t mod_i2c_speed(uint32_t i2c_number, uint32_t speed)
{
//	int32_t result = STATUS_OK;
//	
//	if (i2c_number == MPU_I2C1)
//	{
//		opt1.pba_hz = sysclk_get_pba_hz();
//		switch (speed)
//		{
//			case MPU_I2C_SPEED_100k:
//			opt1.speed = 100000;
//			break;
//			case MPU_I2C_SPEED_400k:
//			opt1.speed = 400000;
//			break;
//			case MPU_I2C_SPEED_1M:
//			opt1.speed = 1000000;
//			break;
//			case MPU_I2C_SPEED_1k:
//			opt1.speed = 1000;
//			break;
//			default:
//			result = ERR_IO_ERROR;
//			break;
//		}
//		result += twim_set_speed (MODULE_TWI1, opt1.speed, opt1.pba_hz);
//	}
//	else if (i2c_number == MPU_I2C2)
//	{
//		opt2.pba_hz = sysclk_get_pba_hz();
//		switch (speed)
//		{
//			case MPU_I2C_SPEED_100k:
//			opt2.speed = 100000;
//			break;
//			case MPU_I2C_SPEED_400k:
//			opt2.speed = 400000;
//			break;
//			case MPU_I2C_SPEED_1M:
//			opt2.speed = 1000000;
//			break;
//			case MPU_I2C_SPEED_1k:
//			opt1.speed = 1000;
//			break;
//			default:
//			result = ERR_IO_ERROR;
//			break;
//		}
//		result += twim_set_speed (MODULE_TWI2, opt2.speed, opt2.pba_hz);
//	}
//	else
//	{
//		result = ERR_IO_ERROR;
//	}
	return 1;
}


/*!
* 	 int32_t i2c_readwrite_data(uint32_t i2c_number, uint32_t i2c_addr, const uint8_t *pdata_write, uint8_t *pdata_read, uint32_t len_write, uint32_t len_read)
* 
* 	...tbd...
* 	\param uint32_t i2c_number -...
* 	\param uint32_t i2c_addr -...
* 	\param const uint8_t *pdata_write -...
* 	\param uint8_t *pdata_read -...
* 	\param uint32_t len_write -...
* 	\param uint32_t len_read -...
* 	\return int32_t -...
*/
int32_t mod_i2c_readwrite_data(uint32_t i2c_number, uint32_t i2c_addr, const uint8_t *pdata_write, uint8_t *pdata_read, uint32_t len_write, uint32_t len_read)
{
//	int32_t result = STATUS_OK;
//	twim_transfer_t transfer_first;
//	twim_transfer_t transfer_second;
//	
//	transfer_first.buffer = (void*)pdata_write;
//	transfer_first.chip = i2c_addr;
//	transfer_first.length = len_write;
//	transfer_first.read = false;
//	
//	transfer_second.buffer = pdata_read;
//	transfer_second.chip = i2c_addr;
//	transfer_second.length = len_read;
//	transfer_second.read = true;
//	
//	if (i2c_number == MPU_I2C1)
//	{
//		result = twim_chained_transfer(MODULE_TWI1, &transfer_first, &transfer_second, false);
//	}
//	else if (i2c_number == MPU_I2C2)
//	{
//		result = twim_chained_transfer(MODULE_TWI2, &transfer_first, &transfer_second, false);
//	}
//	else
//	{
//		result = ERR_IO_ERROR;
//	}
//	
//	if (result == STATUS_OK)
//		return len_read;
//	else
//		return result;
    return 0;
}



/*!
* 	 int32_t i2c_write_data(uint32_t i2c_number,uint32_t i2c_addr, const uint8_t *pdata, uint32_t len)
* 
* 	...tbd...
* 	\param uint32_t i2c_number -...
* 	\param uint32_t i2c_addr -...
* 	\param const uint8_t *pdata -...
* 	\param uint32_t len -...
* 	\return int32_t -...
*/
int32_t mod_i2c_write_data(uint32_t i2c_number,uint32_t i2c_addr, const uint8_t *pdata, uint32_t len)
{
	//status_code_t result = STATUS_OK;
	
//	if (i2c_number == MPU_I2C1)
//	{
//		result = twim_write (MODULE_TWI1, pdata, len, i2c_addr, false);		
//	}
//	else if (i2c_number == MPU_I2C2)
//	{
//		result = twim_write (MODULE_TWI2, pdata, len, i2c_addr, false);		
//	}
//	else
//	{
//		return ERR_IO_ERROR;
//	}
	
	return 0;
}



/*!
* 	 int32_t i2c_read_data(uint32_t i2c_number, uint32_t i2c_addr, uint8_t *pdata, uint32_t len)
* 
* 	...tbd...
* 	\param uint32_t i2c_number -...
* 	\param uint32_t i2c_addr -...
* 	\param uint8_t *pdata -...
* 	\param uint32_t len -...
* 	\return int32_t -...
*/
int32_t mod_i2c_read_data(uint32_t i2c_number, uint32_t i2c_addr, uint8_t *pdata, uint32_t len)
{
//	int32_t result = 1;
	
//	if (i2c_number == MPU_I2C1)
//	{
//		result =  twim_read (MODULE_TWI1, pdata, len, i2c_addr, false);
//	}
//	else if (i2c_number == MPU_I2C2)
//	{
//		result =  twim_read (MODULE_TWI2, pdata, len, i2c_addr, false);
//	}
//	else
//	{
//		result = ERR_IO_ERROR;
//	}
//		
//	if (result == STATUS_OK)
//	{
//		result = len;		
//	}
	
	return 0;
	

}