/*!
* @file modules\sw_spi.c
* @author D.Chikov
* @date 10/15/2020, 10:24:38
* @brief ...tbd...
*/


// Sovftware SPI module
// Parameters                                          DIOxx,DIOxx,DIOxx,x,xxxx,xxxx,FFFFFF
//                                                      |    |      |    |   |    |    |
// 1- DIOxx - CLK---------------------------------------|    |      |    |   |    |    |
// 2- DIOxx - SDI on DUT (MCU out)---------------------------|      |    |   |    |    |
// 3- DIOxx - SDO on DUT (MCU in)-----------------------------------|    |   |    |    |
// 4-  falling/rising Edge/both------------------------------------------|   |    |    |
// 5-  t1/2 period in ms   --------------------------------------------------|    |    |
// 6 - bits count ----------------------------------------------------------------|    |
//     the rest is Hexademical data AA01BBCC...----------------------------------------|


#include "app.h"
#include "mod_swspi.h"
#include "dio.h"
#include "string_utils.h"
#include "board.h"
#include "chrono.h"
#include "stdio.h"
#define SEQ1_FORMAT "DIO??,DIO??,DIO??,?,????,????,"





    static int m_fmt;
    static int m_cpol;
    static int m_delay;
    static int m_cpha;
    static int m_bits_count;
    static int m_cs_delay1;
    static int m_cs_delay2;

  // for single
  volatile uint32_t * m_gpio_ck_port;
  volatile uint32_t * m_gpio_w_port;
  volatile uint32_t * m_gpio_r_port;
  volatile uint32_t * m_gpio_cs_port;
  
  volatile  uint32_t m_gpio_ck_mask;
  volatile  uint32_t m_gpio_w_mask;
  volatile  uint32_t m_gpio_r_mask;
  volatile  uint32_t m_gpio_cs_mask;
  
  
static struct SWSpiConf {
  volatile uint32_t * m_gpio_ck_port;
  volatile uint32_t * m_gpio_w_port;
  volatile uint32_t * m_gpio_r_port;
  volatile uint32_t * m_gpio_cs_port;
  uint32_t m_gpio_ck_mask;
  uint32_t m_gpio_w_mask;
  uint32_t m_gpio_r_mask;
  uint32_t m_gpio_cs_mask;
  int m_delay;
  int m_cpha;
  int m_bits_count;
  int m_cpol;
  int m_fmt;
  int m_cs_delay1;
  int m_cs_delay2;
  int m_configured;
} swSpiConfig[4] = {};



/*!
* 	 define DELAY(delay)    if(delay) {CHRONO1_DELAY(delay)
* 
* 	...tbd...
* 	\param delay)    if(delay) {CHRONO1_DELAY(delay -...
* 	\return define -...
*/
#define DELAY(delay)    if(delay) {CHRONO1_DELAY(delay);}


/*!
* 	 define DATA_HI()
* 
* 	...tbd...
* 	\return define -...
*/
#define DATA_HI() *m_gpio_w_port |= m_gpio_w_mask

/*!
* 	 define DATA_LO()
* 
* 	...tbd...
* 	\return define -...
*/
#define DATA_LO() *m_gpio_w_port &= ~m_gpio_w_mask


/*!
* 	 define CK_HI()
* 
* 	...tbd...
* 	\return define -...
*/
#define CK_HI() *m_gpio_ck_port |= m_gpio_ck_mask

/*!
* 	 define CK_LO()
* 
* 	...tbd...
* 	\return define -...
*/
#define CK_LO() *m_gpio_ck_port &= ~m_gpio_ck_mask


/*!
* 	 define READ()
* 
* 	...tbd...
* 	\return define -...
*/
#define READ() *m_gpio_r_port


/*!
* 	 define CS_HI()
* 
* 	...tbd...
* 	\return define -...
*/
#define CS_HI() *m_gpio_cs_port |= m_gpio_cs_mask;

/*!
* 	 define CS_LO()
* 
* 	...tbd...
* 	\return define -...
*/
#define CS_LO() *m_gpio_cs_port &= ~m_gpio_cs_mask;


static uint8_t *data_in;
static uint8_t *data_out;






/*!
* 	 bool function_swspi(const char *ptext)
* 
* 	...tbd...
* 	\param const char *ptext -...
* 	\return bool -...
*/
bool function_swspi(const char *ptext)
{
  bool result = false;  
  
  data_in = &application_data[0] ;
  data_out = &application_data[10000] ;
  
  uint32_t *pinput = (uint32_t*)&data_in[0];
  
  if ( compare_string_n(ptext, SEQ1_FORMAT, sizeof(SEQ1_FORMAT)) )
  {
    uint32_t dio_ck = (ascii2bin(ptext[3]) * 10 + ascii2bin(ptext[4]) );
    uint32_t dio_w = (ascii2bin(ptext[9])  * 10 + ascii2bin(ptext[10]) );
    uint32_t dio_r = (ascii2bin(ptext[15]) * 10 + ascii2bin(ptext[16]) );

    // change B->A
    m_gpio_ck_port = gpio_reg(REG_LAT, dio_table[dio_ck] ,0);        
    m_gpio_w_port = gpio_reg(REG_LAT, dio_table[dio_w] , 0);       
    m_gpio_r_port = gpio_reg(REG_PORT, dio_table[dio_r] ,0);         

    m_gpio_ck_mask = 1 << GPIO_PIN(dio_table[dio_ck]);
    m_gpio_w_mask = 1 <<  GPIO_PIN(dio_table[dio_w]);
    m_gpio_r_mask = 1 <<  GPIO_PIN(dio_table[dio_r]);

    m_cpha = ascii2bin(ptext[18]);

    m_delay = (ascii2bin(ptext[20]) * 1000 + ascii2bin(ptext[21]) * 100
                  + ascii2bin(ptext[22]) * 10   + ascii2bin(ptext[23]) )/2;

    m_bits_count = ascii2bin(ptext[25]) * 1000 + ascii2bin(ptext[26]) * 100
                 + ascii2bin(ptext[27]) * 10   + ascii2bin(ptext[28]);
	
    const char *hex_str_start = &ptext[30];
    if (m_bits_count <= 10000 && (m_bits_count / 8) <= bytes_from_hex(data_out, hex_str_start ))
    {
      CK_LO();   // clear CK
      
      const uint32_t masks[8] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80};
      int32_t  i = 0;

        //CLK
		  for (i = 0; i < m_bits_count; i++)
		   {             	        			
			//INF
			if (data_out[i / 8] & (masks[i % 8]))
                {  DATA_HI();  }
			else
                {  DATA_LO();  }
		        
		
			DELAY(m_delay);
            CK_HI();            							
			DELAY(m_delay);
            pinput[i] = READ();//now lets capture as is. then translate
            CK_LO();
			}		    
	       
      app_result_count = i+1;
      result = true;
    }
    else{
        printf("(wrong bits count)");
        return false;
    }
  }
  return result;
}









/*!
* 	 bool function_swspiconf(const char *ptext, int cs_number)
* 
* 	...tbd...
* 	\param const char *ptext -...
* 	\param int cs_number -...
* 	\return bool -...
*/
bool function_swspiconf(const char *ptext, int cs_number)
{
  
  char *item = 0;
  int n = 0;
  
  if(cs_number>0 && cs_number<=4)
      cs_number --;
    else return false;
  
  FOREACH_BEGIN(item, ptext, ',')
  {
    switch (n)
    {
    case 0:
        {
            const int dio = atoi( &item[3] );
            if( DIO_Valid( dio) )
            {   
                const uint32_t port = dio_table[ dio ];
                swSpiConfig[cs_number].m_gpio_ck_port = gpio_reg(REG_LAT, port ,0);  
                swSpiConfig[cs_number].m_gpio_ck_mask = 1<<GPIO_PIN(port);                
            }
        }
      break;

    case 1:
        {
            const int dio = atoi(&item[3]);
            if(DIO_Valid( dio) )
            {   
                const uint32_t port = dio_table[ dio ];
                swSpiConfig[cs_number].m_gpio_w_port = gpio_reg(REG_LAT, port ,0);
                swSpiConfig[cs_number].m_gpio_w_mask = 1<<GPIO_PIN(port);       
            }
        }
      break;

    case 2:  
        {
            const int dio = atoi(&item[3]);
            if(DIO_Valid( dio) )
            {        
                const uint32_t port = dio_table[ dio ];
                swSpiConfig[cs_number].m_gpio_r_port = gpio_reg(REG_PORT, port ,0);
                swSpiConfig[cs_number].m_gpio_r_mask = 1<<GPIO_PIN(port);     
            }
        }
      break;

    case 3:
        {
            const int dio = atoi(&item[3]);
            if( DIO_Valid(dio))
            {
                const uint32_t port = dio_table[ dio ];
                swSpiConfig[cs_number].m_gpio_cs_port = gpio_reg(REG_LAT, port ,0);
                swSpiConfig[cs_number].m_gpio_cs_mask = 1<<GPIO_PIN(port);     
            }
        }
      break;

    case 4:
      swSpiConfig[cs_number].m_delay = atoi(item);
      break;

    case 5:
      swSpiConfig[cs_number].m_bits_count = atoi(item);
      break;

    case 6:
      swSpiConfig[cs_number].m_cpha = atoi(item);
      break;

    case 7:
      swSpiConfig[cs_number].m_cpol = atoi(item);
      break;

    case 8:
      swSpiConfig[cs_number].m_fmt = atoi(item);
      swSpiConfig[cs_number].m_configured = 1;
      break;

      case 9:
      swSpiConfig[cs_number].m_cs_delay1 = atoi(item);
      break;

      case 10:
      swSpiConfig[cs_number].m_cs_delay2= atoi(item);
      break;
    }
    n++;
  }
  FOREACH_END(item);

  
  return n > 8;
}




/*!
* 	 bool function_swspi_result()
* 
* 	Function SW spi
* 	\return bool -...
*/
bool function_swspi_result()
{
    
  bool result = false;     
  if (app_result_count > 0)
  {      
      printf("=");      
      int i;
      for (i = 0; i < app_result_count; i++)
      {                             
            printf("%02x",application_data[i]);            
      }
    result = true;
    app_result_count =0;
  }
  return result;
 
}


/*!
* 	 bool function_swspics(const char *ptext, int cs_number)
* 
* 	...tbd...
* 	\param const char *ptext -...
* 	\param int cs_number -...
* 	\return bool -...
*/
bool function_swspics(const char *ptext, int cs_number)
{    
  bool result = false;
  uint32_t *pinput = (uint32_t*)&application_data[10000];
  uint8_t hex_data[1000];
  const uint32_t masks[8] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80};
  int32_t  n=0, i = 0;
  char *item = 0;
  

  if( cs_number>0 && cs_number<=4) 
      cs_number --;
  else return false;
  
  if (swSpiConfig[cs_number].m_configured == 1)
  {
    if(swSpiConfig[cs_number].m_bits_count <= 0)
    {        
       FOREACH_BEGIN(item, ptext, ',')
        {
          switch (n)
          {
          case 0:
            m_bits_count =   atoi(item);
            break;

          case 1:
             bytes_from_hex(hex_data, item);
            break;
          }
          n++;
        }
        FOREACH_END(item);
    }

    else{
	    m_bits_count = swSpiConfig[cs_number].m_bits_count;
        bytes_from_hex(hex_data, ptext);
	}    
    
    m_gpio_ck_port = swSpiConfig[cs_number].m_gpio_ck_port;
    m_gpio_w_port = swSpiConfig[cs_number].m_gpio_w_port;
    m_gpio_r_port = swSpiConfig[cs_number].m_gpio_r_port;
    m_gpio_cs_port = swSpiConfig[cs_number].m_gpio_cs_port;

    m_gpio_ck_mask = swSpiConfig[cs_number].m_gpio_ck_mask;
    m_gpio_w_mask = swSpiConfig[cs_number].m_gpio_w_mask;
    m_gpio_r_mask = swSpiConfig[cs_number].m_gpio_r_mask;
    m_gpio_cs_mask = swSpiConfig[cs_number].m_gpio_cs_mask;

    m_delay = swSpiConfig[cs_number].m_delay/2;
    m_cpha = swSpiConfig[cs_number].m_cpha;    
    m_cpol = swSpiConfig[cs_number].m_cpol;
    m_fmt = swSpiConfig[cs_number].m_fmt;
    m_cs_delay1 = swSpiConfig[cs_number].m_cs_delay1;
    m_cs_delay2 = swSpiConfig[cs_number].m_cs_delay2;
    
   
    if(m_cpol==0) {
        CK_LO();          
    }
    else     {
        CK_HI();        
    }
 
    CS_LO();
    

    DELAY(m_cs_delay1);

    if(m_cpol==0 && m_cpha==0)
    {
        //CLK
        for (i = 0; i < m_bits_count; i++)
        {          

          //INF
          if (hex_data[i / 8] & (masks[i % 8]))              DATA_HI();
          else              DATA_LO();


          DELAY(m_delay);
          CK_HI();
          pinput[i] = READ() ;//now lets capture as is. then translate
          DELAY(m_delay);          
          CK_LO();
        }
        DELAY(1);
		DATA_LO();
    }
    else if(m_cpol==0 && m_cpha==1)
    {
        //CLK
        for (i = 0; i < m_bits_count; i++)
        {
          
          //INF
          if (hex_data[i / 8] & (masks[i % 8]))             DATA_HI();
          else            DATA_LO();

          CK_HI();
          DELAY(m_delay);
          CK_LO();
          pinput[i] = READ();//now lets capture as is. then translate		            
          DELAY(m_delay);
        }        			
        DELAY(1);
		DATA_LO();
    }
    else if (m_cpol==1 && m_cpha==0)
    {
              //CLK
        for (i = 0; i < m_bits_count; i++)
        {          

          //INF
          if (hex_data[i / 8] & (masks[i % 8]))    DATA_HI();
          else             DATA_LO();
		 
          DELAY(m_delay);
          CK_LO();
          pinput[i] = READ();//now lets capture as is. then translate         
          DELAY(m_delay);		  
          CK_HI();       
        }		
        DELAY(1);
		DATA_HI();

    }
    else if (m_cpol==1 && m_cpha==1)
    {
        //CLK
        for (i = 0; i < m_bits_count; i++)
        {          
          //INF
          if (hex_data[i / 8] & (masks[i % 8]))     DATA_HI();
          else              DATA_LO();
          
          CK_LO();          
          DELAY(m_delay);          
          CK_HI();
          pinput[i] = READ();//now lets capture as is. then translate          
          DELAY(m_delay);
        }
		DELAY(1);
		DATA_HI();
      
    }

    
    DELAY(m_cs_delay2);
    CS_HI();

    
    
    // [DECODE]
    uint8_t byte=0;
    
    
    for (i = 0; i < m_bits_count; i++)
    {     
        const uint8_t bit1 = (pinput[i] & m_gpio_r_mask) != 0; 
        byte |= (bit1 <<(i%8));        
        if(i%8 == 7 || i == m_bits_count-1) {
            if(i>0)
                application_data[app_result_count++ ] =byte;
            byte=0;
        }  
      }
          
    result = true;
  }
   
  return result;
}
