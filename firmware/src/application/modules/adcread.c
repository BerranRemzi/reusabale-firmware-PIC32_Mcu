#include "adcread.h"

#include "application.h"
#include "asf.h"
#include "modules.h"
#include "dio.h"
#include "string_utils.h"

#define FUNC_READADC_FORMAT "DIO??,DIO??,DIO??,DIO??,?????,?????"

static uint32_t gpio_cnv;
static uint32_t gpio_sdo;
static uint32_t gpio_sck;
static uint32_t gpio_sdi;
static uint32_t delay;
static uint32_t count;
static uint32_t count_got;
static uint16_t *pdata;

#define CNV(V) do{\
  if(V==1)    gpio_set_pin_high(gpio_cnv);\
  else gpio_set_pin_low(gpio_cnv);\
}while(0)

#define SDO() gpio_get_pin_value(gpio_sdo)

#define SCK(V)do{\
  if(V==1)    gpio_set_pin_high(gpio_sck);\
  else gpio_set_pin_low(gpio_sck);\
}while(0)

#define SCK_TGL() gpio_toggle_pin(gpio_sck);


#define SDI(V) do{\
  if(V==1)    gpio_set_pin_high(gpio_sdi);\
  else gpio_set_pin_low(gpio_sdi);\
}while(0)


bool function_adcread(const char *ptext)
{
  bool result = 0;
  uint32_t data;
  int i, n = 0;
  char *item = 0;
  function_in_index = 0;
  function_in_bit_index = 0;
  if ( string_utils_strncmp(ptext, FUNC_READADC_FORMAT, sizeof(FUNC_READADC_FORMAT), 0) )
  {

    FOREACH_BEGIN(item, ptext, function_out, ',')
    {
      switch (n)
      {
      case 0:
        gpio_cnv = dio_gpio(ascii2bin(item[3]) * 10 + ascii2bin(item[4]));
        break;

      case 1:
        gpio_sdo = dio_gpio(ascii2bin(item[3]) * 10 + ascii2bin(item[4]));
        break;

      case 2:
        gpio_sck = dio_gpio(ascii2bin(item[3]) * 10 + ascii2bin(item[4]));
        break;

      case 3:
        gpio_sdi = dio_gpio(ascii2bin(item[3]) * 10 + ascii2bin(item[4]));
        break;

      case 4:
        delay = atoi(item);
        break;

      case 5:
        count = atoi(item);

        break;
      default:
        break;
      }
      n++;
    }
    FOREACH_END(item);

    pdata = (uint16_t*)&function_in[0];
    CNV(0);
    SCK(0);
    int j;
    for (j = 0; j < count; j++)
    {
      pdata[j] = 0;
      SDI(1);
      CNV(1);
      SDI(0);
      TMR_DELAY(2);
      if (SDO() != 0) { result = 0; break;      }
      SCK(1); SCK(0);
      TMR_SET_TIMEOUT_TICKS(2);
      for (i = 0; i < 16; i++)
      {
		  
        SCK(1);
        pdata[j] |= (SDO() << (15 - i));
		
		TMR_START();
		while (!TMR_IS_TIMEOUT());
               
        SCK(0);        
		TMR_START();
		while (!TMR_IS_TIMEOUT());
      }
      CNV(0);
      result = 1;
      if (delay > 0)
      { delay_us(delay); }

    }
	count_got = j;
  }
  
  return result;
}

bool function_adcread_result(char *ptext,int index)
{
  bool result = false;     
  if(count_got>0 && (index*100)<count_got)
  {
    int remains = count_got-(index*100) ;
    remains = remains>100 ?100:remains;
   for(int i=0;i<remains;i++)
   {    
     sprintf(&ptext[i*4],"%0004x",pdata[index*100+i])   ; 
   }
    result = true;
  }
  return result;

}