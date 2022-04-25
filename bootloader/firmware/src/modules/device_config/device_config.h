
#ifndef DEVICE_CONFIG_H
#define	DEVICE_CONFIG_H

#include "typedef_global.h"
#include "nvm.h"


typedef struct {
    uint32_t crc;
    uint32_t app_crc_1;
    uint32_t app_crc_2;     
    // TODO configuration for Application
    uint32_t tmp[1];
}Config_t;


ResultError_t device_config_load(void);
ResultError_t device_config_save(void);
Config_t *currentConfig();


// set default config
void    device_config_set_default(void);

// lock / unlock / is slocked
bool    device_config_is_locked(void);
void    device_config_lock(void);
void  device_config_unlock(uint32_t password);

#endif	/* DEVICE_CONFIG_H */

