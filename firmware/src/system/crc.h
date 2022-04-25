/*!
* @file crc.h
* @author D.Chikov
* @date 10/15/2020, 09:37:34
* @brief ...tbd...
*/


#ifndef CRC_H
#define CRC_H
    #include "typedef_global.h"

/*!
* ...tbd...
*/
  uint8_t crc8(const uint8_t *pdata, uint32_t bytes, uint32_t poly, uint32_t seed);

#endif