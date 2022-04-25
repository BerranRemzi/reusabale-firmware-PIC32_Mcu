#ifndef DATASTREAM_H
#define	DATASTREAM_H

#include "system/system.h"
#include <sys/kmem.h>
#include "nvm.h"

#ifdef	__cplusplus
extern "C" {
#endif

typedef enum {
  FLASH_MEM1 = (0),
  FLASH_MEM2 = (1),
  FLASH_CFG =  (2)
}FlashMemType;



uint32_t FLASH_CalculateCrc(FlashMemType flashType);
bool FLASH_UpdateFromBackup() ;
bool FLASH_EraseMemory(FlashMemType flashType);
bool FLASH_SaveSerialNumber(uint32_t s0,uint32_t s1,uint32_t s2,uint32_t s3);



#ifdef	__cplusplus
}
#endif

#endif

