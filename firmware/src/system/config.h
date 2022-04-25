/*!
* @file config.h
* @author D.Chikov
* @date 10/15/2020, 09:37:34
* @brief ...tbd...
*/


#ifndef SYS_CONFIG_H
#define SYS_CONFIG_H

#include "app_config.h"

#include "typedef_global.h"

typedef struct{
    APP_CONFIG;
}Config_t;

typedef struct {
    uint32_t cfg_crc;
    uint32_t app_crc1;
    uint32_t app_crc2;
    uint32_t app_build1;
    uint32_t app_build2;
    uint32_t bldr_crc;
    uint32_t bldr_build;
    
    Config_t cfg;
            
}SysInfo_t;


/*!
* ...tbd...
*/
ResultError_t device_config_load(void);
/*!
* ...tbd...
*/
ResultError_t device_config_save(void);

extern volatile const  SysInfo_t SYSINFO;
/*!
* ...tbd...
*/
inline const Config_t *config();


/*!
* ...tbd...
*/
void    device_config_set_locked(bool on);

#endif 