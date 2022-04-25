/*!
* @file modules\mod_spi.h
* @author D.Chikov
* @date 10/15/2020, 18:16:01
* @brief SPI module header
*/


#ifndef MOD_SPI_H
#define MOD_SPI_H

#include "typedef_global.h"
#include "spi.h"

typedef struct {
    uint32_t spi_sdi_pin;
    uint32_t spi_sdo_pin;    
    uint32_t spi_port;    
    struct {
        volatile uint32_t *gpio_cs_port;
        uint32_t gpio_cs_mask;
        int cpha;  
        int cpol;  
        int cs_delay1;
        int cs_delay2;
        int configured;
        int speed;
        int fmt;
        } settings[4];
}ModSpiConfig;

extern ModSpiConfig hwSpiConfig[2];

typedef enum{
    MODULE_SPI1,
    MODULE_SPI2
}SpiModule;

typedef enum{
    CS1=0,
    CS2=1,
    CS3=2,
    CS4=3
}SpiModuleCs;

bool mod_spi_conf(SpiModule spi_number, int cs_number, char *ptext);
void mod_spi_off(SpiModule spi_number, int cs_number);

bool mod_spi_set_speed(SpiModule spi_number, int cs_number,  uint32_t baud);

bool mod_spi_transfer(SpiModule spi_number, int cs_number, char *ptext);

void mode_spi_cs(SpiModule spi_number, int cs_number);

bool mod_spi_result(SpiModule spi_number, int cs_number);

#endif
