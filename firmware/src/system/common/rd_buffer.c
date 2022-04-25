/*!
* @file common\rd_buffer.c
* @author D.Chikov
* @date 10/15/2020, 09:37:34
* @brief ...tbd...
*/




#include "rd_buffer.h"



/* ********************************************************************* 
@Function name: rd_buffer_init
@Return: (bool) 
@Parameters: 
  RdBuffer *pbuffer - buffer pointer
  uint32_t size - size of buffer 
  bool stream - make buffer overwritable
@Description: rround buffer initialize

********************************************************************* */

/*!
* 	 bool rd_buffer_init(RoundBuffer *pbuffer , uint8_t *pbuffer_data, const uint32_t size)
* 
* 	...tbd...
* 	\param RoundBuffer *pbuffer -...
* 	\param uint8_t *pbuffer_data -...
* 	\param const uint32_t size -...
* 	\return bool -...
*/
bool rd_buffer_init(RoundBuffer *pbuffer , uint8_t *pbuffer_data, const uint32_t size)
{    
  uint32_t i;
  bool result = FALSE;
  if(pbuffer != NULL && pbuffer_data != NULL ){
    pbuffer->first = 0;
    pbuffer->last = 0;
    /* one element will be everytime lost ind points to next */
    pbuffer->size = size;
    pbuffer->pdata = pbuffer_data;
    for(i=0;i<size;i++){
       pbuffer->pdata[i] =0xaa;
       if(pbuffer->pdata[i] == 0xaa) {
        pbuffer->pdata[i]=0;
        result = TRUE;
      }
       else {
        result = FALSE;
        break;
       }
   }    
  }
  return result;
}


/*!
* 	 uint8_t rd_buffer_first(RoundBuffer *pbuffer)
* 
* 	...tbd...
* 	\param RoundBuffer *pbuffer -...
* 	\return uint8_t -...
*/
uint8_t rd_buffer_first(RoundBuffer *pbuffer){
    return pbuffer->pdata[pbuffer->first];
}


/* ********************************************************************* 
@Function name: rd_buffer_cnt
@Return: (uint32_t)  count of elements
@Parameters: 
  RdBuffer *pbuffer  - buffer pointer
@Description: return number of elements in round buffer

********************************************************************* */

/*!
* 	 uint32_t rd_buffer_cnt(RoundBuffer *pbuffer)
* 
* 	...tbd...
* 	\param RoundBuffer *pbuffer -...
* 	\return uint32_t -...
*/
uint32_t rd_buffer_cnt(RoundBuffer *pbuffer){
  int32_t sz;
  sz = pbuffer->last - pbuffer->first;
  if(sz < 0) {
    sz += pbuffer->size;
  }
  return (uint32_t)sz;
}


/*!
* 	 bool rd_buffer_contains(RoundBuffer *pbuffer, uint8_t byte )
* 
* 	...tbd...
* 	\param RoundBuffer *pbuffer -...
* 	\param uint8_t byte -...
* 	\return bool -...
*/
bool rd_buffer_contains(RoundBuffer *pbuffer, uint8_t byte ){        
    int i;
    if(pbuffer->first > pbuffer->last){
        for( i= pbuffer->first; i<pbuffer->size;i++)
            if(pbuffer->pdata[i] == byte) return true;        

        for(i=0;i<pbuffer->last;i++)
            if(pbuffer->pdata[i] == byte) return true;        
    }else{
        for( i= pbuffer->first; i<pbuffer->last;i++){            
            if(pbuffer->pdata[i] == byte) return true;        
        }
    }
    return false;
}

/* ********************************************************************* 
@Function name: rd_buffer_reset
@Return: (void) 
@Parameters: 
  RdBuffer *pbuffer - buffer pointer
@Description: resets buffer 

********************************************************************* */

/*!
* 	 void rd_buffer_reset(RoundBuffer *pbuffer)
* 
* 	...tbd...
* 	\param RoundBuffer *pbuffer -...
* 	\return void -...
*/
void rd_buffer_reset(RoundBuffer *pbuffer){

  pbuffer->first = pbuffer->last;   
}

/* ********************************************************************* 
@Function name: rd_buffer_is_empty
@Return: (bool) 
@Parameters: 
  RdBuffer *pbuffer
@Description: if buffer contains no elements
********************************************************************* */

/*!
* 	 bool rd_buffer_is_empty(RoundBuffer *pbuffer)
* 
* 	...tbd...
* 	\param RoundBuffer *pbuffer -...
* 	\return bool -...
*/
bool rd_buffer_is_empty(RoundBuffer *pbuffer){
  bool result = (rd_buffer_cnt(pbuffer) == 0);
  return result;
}

/* ********************************************************************* 
@Function name: rd_buffer_is_full
@Return: (bool) 
@Parameters: 
  RdBuffer *pbuffer  - buffer pointer
@Description: buffer is full

********************************************************************* */

/*!
* 	 bool rd_buffer_is_full(RoundBuffer *pbuffer)
* 
* 	...tbd...
* 	\param RoundBuffer *pbuffer -...
* 	\return bool -...
*/
bool rd_buffer_is_full(RoundBuffer *pbuffer){
  bool result;
  result = (bool)(rd_buffer_cnt(pbuffer) == (uint32_t)pbuffer->size);  
  return result;
}

/* ********************************************************************* 
@Function name: rd_buffer_get
@Return: (bool) 
@Parameters: 
  RdBuffer *pbuffer - buffer pointer
  uint8_t * prec 
@Description: Get Record from buffer

********************************************************************* */

/*!
* 	 bool rd_buffer_get(RoundBuffer *pbuffer, uint8_t *pbyte)
* 
* 	...tbd...
* 	\param RoundBuffer *pbuffer -...
* 	\param uint8_t *pbyte -...
* 	\return bool -...
*/
bool rd_buffer_get(RoundBuffer *pbuffer, uint8_t *pbyte){
  bool result = FALSE;
  int32_t first = pbuffer->first;
  int32_t last = pbuffer->last;
  if(first  != last)  {
    (*pbyte) = pbuffer->pdata[first ];
    first  ++;
    pbuffer->first = first ;/*DMEM_WRITE*/
    if(first  == pbuffer->size){
        pbuffer->first = 0;/*DMEM_WRITE*/
    }
    result = TRUE;
  }
  return result;
}


/* ********************************************************************* 
@Function name: rd_buffer_put
@Return: (bool) 
@Parameters: 
  RdBuffer *pbuffer - buffer pointer
  uint8_t *prec 
@Description: buffer put element
********************************************************************* */

/*!
* 	 bool rd_buffer_put(RoundBuffer *pbuffer, const uint8_t byte)
* 
* 	...tbd...
* 	\param RoundBuffer *pbuffer -...
* 	\param const uint8_t byte -...
* 	\return bool -...
*/
bool rd_buffer_put(RoundBuffer *pbuffer, const uint8_t byte){    
  bool result = FALSE;
  int32_t sz = pbuffer->last - pbuffer->first;
  /* detecting size*/
  if(sz < 0 )    {
    sz += pbuffer->size;
  }
     if(sz < (pbuffer->size - 1)){      
       int32_t ind = pbuffer->last;
       pbuffer->pdata[ind] = byte;      
       ind++;
      if(ind == pbuffer->size ) {
        ind = 0;
      }    
       pbuffer->last = ind;
       result = TRUE;   
     }  
  return result;
}

