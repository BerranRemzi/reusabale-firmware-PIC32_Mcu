#include "device_config.h"
#include "typedef_global.h"
#include "system_config.h"
#include "systmr.h"
#include "flash_mem.h"



static bool locked;

// default config
const Config_t __attribute__((section(".dev_config"))) DEFAULT_CONFIG  = 
{
    // APP1    
    .app_crc_1 = 0, // application CRC        
    // APP2
    .app_crc_2 = 0,     //application backup CRC     
   .tmp={},
    
    
    
    
    // TODO define configuration
    
    
    
};

static Config_t _currentConfig;

Config_t *currentConfig(){
    return &_currentConfig;
}

ResultError_t device_config_save(void)
{
   int i;
   //calculate crc for config
   
   currentConfig()->crc = FLASH_CalculateCrc(FLASH_CFG);   
   nvm_clear_error();
   nvm_unlock_bootmem();   
   nvm_erase_page(CONFIG_MEM_ADDR) ;      
   const uint32_t *dstMemAddr = (const uint32_t *)CONFIG_MEM_ADDR;
   uint32_t *srcMemAddr = (uint32_t*)&_currentConfig;    
    for(i=0;i<sizeof(Config_t)/4;i++){
        if(nvm_write_word( (uint32_t)&dstMemAddr[i], srcMemAddr[i]) == RES_ERROR)
            return RES_ERROR;
   }
   nvm_lock_bootmem(); 
   
   return RES_NO_ERROR;
}


ResultError_t device_config_load(void) {
    int i;
    uint32_t calcCrc =  FLASH_CalculateCrc(FLASH_CFG);
    const uint32_t *memAddr = (const uint32_t*)CONFIG_MEM_ADDR;    
    for(i=0;i<sizeof(Config_t)/4;i++){        
        ((uint32_t *)&_currentConfig)[i] = memAddr[i];                
    }          
    if(currentConfig()->crc == calcCrc){
        return RES_NO_ERROR;
    }
    return RES_ERROR;
}


void device_config_set_default(void){
   
    
    // TODO
    
    
    
}



inline bool  device_config_is_locked(void)
{
    return locked;
}


void device_config_lock(void)
{
    locked = 1;
}

void device_config_unlock(uint32_t password)
{
    if(password == CONFIG_UNLOCK_PSW){
        locked = 0;
    }
    else {
        locked = TRUE;
    }
}


