/*!
* @file crc.c
* @author D.Chikov
* @date 10/15/2020, 09:37:34
* @brief ...tbd...
*/


#include "crc.h"


/*!
* 	 uint8_t crc8(const uint8_t *pdata, uint32_t len, uint32_t poly, uint32_t seed)
* 
* 	...tbd...
* 	\param const uint8_t *pdata -...
* 	\param uint32_t len -...
* 	\param uint32_t poly -...
* 	\param uint32_t seed -...
* 	\return uint8_t -...
*/
uint8_t crc8(const uint8_t *pdata, uint32_t len, uint32_t poly, uint32_t seed)
{
    uint32_t crc = seed;
    int i=0;
    int j=0;
    for (; i < len; i++)
        {
            crc ^= pdata[i];
            for (j = 0; j < 8; j++)
            {
                if (crc & 0x80)
                    crc = (crc << 1) ^ poly;
                else
                    crc <<= 1;
            }
        }
    return (uint8_t)(crc&0xff);
}