/*!
* @file common\rd_buffer.h
* @author D.Chikov
* @date 10/15/2020, 09:37:34
* @brief ...tbd...
*/


#ifndef __RD_BUFFER_H__
#define __RD_BUFFER_H__

#include "typedef_global.h"

/*Round buffer max size*/


typedef struct {
/*last added record*/
    int32_t  last;  
/*current unread rcord*/
    int32_t  first;
    int32_t  size;
    uint8_t   *pdata;
} RoundBuffer;


/*!
* ...tbd...
*/
uint32_t rd_buffer_capacity(RoundBuffer *pbuffer);
/*init*/
/*!
* ...tbd...
*/
bool rd_buffer_init(RoundBuffer *pbuffer,  uint8_t *pbuffer_data,uint32_t size);

/*gets count of records in buffer*/
/*!
* ...tbd...
*/
uint32_t rd_buffer_cnt(RoundBuffer *pbuffer);

/*!
* ...tbd...
*/
bool rd_buffer_contains(RoundBuffer *pbuffer, uint8_t byte);

/*!
* ...tbd...
*/
void rd_buffer_reset(RoundBuffer *pbuffer);

/*checks if buffer is empty */
/*!
* ...tbd...
*/
bool rd_buffer_is_empty(RoundBuffer *pbuffer);

/*checks if buffer is full */
/*!
* ...tbd...
*/
bool rd_buffer_is_full(RoundBuffer *pbuffer);

/*put/get*/
/*gets next record*/
/*!
* ...tbd...
*/
bool rd_buffer_get(RoundBuffer *pbuffer,uint8_t *pbyte);
/*!
* ...tbd...
*/
uint8_t rd_buffer_first(RoundBuffer *pbuffer);
//
/*!
* ...tbd...
*/
bool rd_buffer_getn(RoundBuffer *pbuffer,uint8_t *pdata, uint32_t count);

/*puts record to periodical data buffer*/
/*!
* ...tbd...
*/
bool rd_buffer_put(RoundBuffer *pbuffer, const uint8_t byte);


#endif 

