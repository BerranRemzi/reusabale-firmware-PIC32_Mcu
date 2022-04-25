/*!
* @file modules\genclk.c
* @author D.Chikov
* @date 10/15/2020, 10:24:38
* @brief ...tbd...
*/


// Clock generator
//                          DIOxx,xxxx,x,xx
// 1 - output pin -----------|     |   | |
// 2 - count ----------------------|   | |
// 3 - inverted -----------------------| |

/*!
* 	  time delay (if 0 - is off)
* 
* 	...tbd...
* 	\param if 0 - is off -...
* 	\return time -...
*/
// 4 - time delay (if 0 - is off) -------|
 
#include "typedef_global.h"
#include "genclk.h"
#include "app.h"
#include "dio.h"
#include "string_utils.h"
#include "system.h"
#include "chrono.h"


/*!
* 	 bool function_genclk(const char *ptext)
* 
* 	...tbd...
* 	\param const char *ptext -...
* 	\return bool -...
*/
bool function_genclk(const char *ptext)
{
  bool inverted=false; 
  int timeout=0;
  int count;
  volatile uint32_t * port_set=0;  
  volatile uint32_t * port_clr=0;
  volatile uint32_t * port_inv=0;
  uint32_t pin_mask=0;
  
  char *item = 0;
  int n = 0;
  bool valid=false;


  FOREACH_BEGIN(item, ptext,  ',')
  {
     uint32_t tmp;
     switch (n)
     {
     //[DIO]
     case 0:       
       if ( (item[0]=='D' || item[0]=='d')
               && (item[1]=='I' || item[1]=='i')
               && (item[2]=='O' || item[2]=='o') )
       {
           const uint32_t dio = (item[3]-'0')*10 + item[4]-'0';
           if(DIO_Valid(dio)){
                tmp = GPIO_PIN( dio_table[dio] );       
                port_set = gpio_reg(REG_LAT,dio_table[dio],'s');
                port_clr = gpio_reg(REG_LAT,dio_table[dio],'c');
                port_inv = gpio_reg(REG_LAT,dio_table[dio],'i');
                pin_mask = (1<<(tmp&0x1F));
           }
       }
       else {
           printf("(error DIO)");
           return false;
       }
       break;
    //[count]   
     case 1:
       count = StrToUInt( item );
       valid = true;
       break;
    //[inverted]   
     case 2:
       inverted = (item[0]=='1');
       break;
    //[timeput]   
     case 3:
       timeout = StrToUInt(item);		
       if(timeout==0) timeout=1;
       break;
       
     }
     n++;      
  }FOREACH_END(item);	
  
  CHRONO1_SET_TIMEOUT(timeout);
  CHRONO1_START();

  if(valid) 
    {
    if (inverted)
      *port_set = pin_mask;
    else
      *port_clr = pin_mask;

    count *= 2;
    if (timeout > 0 && timeout <CHRONO1_MAX)
    {
      // generate toggles count with dalay in us            
      while(!CHRONO1_IS_TIMEOUT());
      CHRONO1_RESTART();
      
      while (count--)
      {
        *port_inv = pin_mask;
        while(!CHRONO1_IS_TIMEOUT());
        CHRONO1_RESTART();
      }
    }   
    return true;
  }
  
  return false;
}
