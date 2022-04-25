/*!
* @file on_parameter_found.c
* @author D.Chikov
* @date 10/15/2020, 10:21:04
* @brief This is callback function which is called when protocol processing
*/



#include "wdt.h"


#include "dio.h"
#include "mod_pwm.h"
#include "app.h"
#include "mod_refclk.h"
#include "ain.h"
#include "aout.h"
#include "mod_spi.h"
#include "relay.h"
#include "cap.h"
#include "mod_swspi.h"
#include "mod_spi.h"
#include "genclk.h"
#include "scanchain.h"
#include "unisequencer.h"
#include "intadc.h"
#include "parser.h"
#include "app_commands.h"
#include "app.h"

#include "board.h"


#include "systmr.h"



inline static  void set_parameter(int32_t p_id,uint8_t *p);

inline static  void get_parameter(int32_t p_id,uint8_t *p);

inline static  void run_command(int32_t p_id,uint8_t *p);


// session key
static int32_t session_key;
static bool m_quet = false;
static bool m_error = false;



/*!
* 	  void on_parameter_found(SyntaxOperation_t operation , int32_t cmd_id, int32_t p_id  , const void* p)
* 
* 	This is callback function for text protocol parser. This function called on each item in text command.
* 
* 	\param SyntaxOperation_t operation - Parser operation
* 	\param int32_t cmd_id - Command identifier
* 	\param int32_t p_id - parameter identifier
* 	\param const void* p - data pointer if no parameter value p==NULL
*/
inline void on_parameter_found(SyntaxOperation_t operation , int32_t cmd_id, int32_t p_id  , const void* p)
{   
    
  switch(operation)
  {
      
      case  PARSER_START:
        m_error  = false;
        m_quet = false;
         switch (cmd_id)
        {
            case Command_set  :            
                APP_Clear();
                break;
            default:break;
         }
      break;
      
  
      case PARSER_PARAMETER:
  
        switch (cmd_id)
        {
            case Command_set  :
              set_parameter(p_id, (uint8_t*)p);
              break;

            case Command_get  :
              get_parameter(p_id, (uint8_t*)p);
              break;

            case Command_run  :
               run_command(p_id, (uint8_t*)p);
            break;      
            
           

            default:
              break;
        }
        break;
  
      
      case PARSER_STOP:  
	  	  
        switch (cmd_id)
        {
            case Command_reset:
                softwareReset();            
            break;		


            case Command_idn:            
                APP_print_inf();	  	              
            break;


            case Command_wait:
            { 
            int32_t delay_time =      StrToUInt((const char*)p);
            if(delay_time>0 && delay_time <= 2000)
              {
              //-- DelayMs(delay_time);       
              }      
              printf("wait:ok\n");
            }	
            break;       
              
        }        
        break;
      
      case PARSER_ERROR:  
        printf("(parser error)err\n");
      break;
    }
}


  



/*!
* 	  void set_parameter(int32_t p_id ,uint8_t *p)
* 
* 	SETTING PARAMETER  
* 	\param int32_t p_id -...
* 	\param uint8_t *p -...
*/
inline void set_parameter(int32_t p_id ,uint8_t *p)
{
  bool ok  = false;

  switch (p_id )
  {

  /*---------------------------------------------------------------------------    
    DIO -digital input output
  ---------------------------------------------------------------------------*/
  
  case Parameter_dio1://set
  {   
    const uint32_t dio_number = ((int32_t)(syntax_parameter_name()[3]) - '0');      
    if(p !=0)    
        ok = dio_set(dio_number, (char*)p);        
  }
  break;

  case Parameter_dio2://set
  {
    const uint32_t dio_number = ((int32_t)(syntax_parameter_name()[3]) - '0') * 10 
                                + ((int32_t)(syntax_parameter_name()[4]) - '0');    
    if(p !=0)
        ok = dio_set(dio_number,(char*)p); 
  }
  break;

  case Parameter_dioconf://set
  {
    const uint32_t dio_number = ((int32_t)(syntax_parameter_name()[3]) - '0');
    if(p !=0)
        ok = dio_conf(dio_number, StrToUInt((char*)p) );
    else ok = dio_conf(dio_number, 0);
  }
  break;

  case Parameter_dioconf2://set
  {
    const uint32_t dio_number = ((uint32_t)(syntax_parameter_name()[3]) - '0') * 10 
                                + ((uint32_t)(syntax_parameter_name()[4]) - '0');
    if(p !=0)
        ok = dio_conf(dio_number, StrToUInt((char*)p) );
    else ok = dio_conf(dio_number, 0);
  }
  break;
	
  case Parameter_diodir://set
  {
	const uint32_t dio_number = ((uint32_t)(syntax_parameter_name()[3]) - '0');        
    if(p !=0)
    {
        if( (p[0]=='I' && p[1]=='N') || (p[0]=='i' && p[1]=='n') ) 
            ok = dio_set_direction(dio_number, DIODIR_INPUT);	
        else if( (p[0]=='O' && p[1]=='U' && p[2]=='T') || (p[0]=='o' && p[1]=='u' && p[2]=='t') )
            ok = dio_set_direction(dio_number, DIODIR_OUTPUT);    
        else
            ok = dio_set_direction(dio_number, (DioDirection_t)StrToUInt((char*)p));
    }
  }
  break;
	
  case Parameter_diodir2://set
  {
      uint32_t dio_number = ((uint32_t)(syntax_parameter_name()[3]) - '0') * 10 
                            + ((uint32_t)(syntax_parameter_name()[4]) - '0');  
      if(p !=0)
      {
        if( (p[0]=='I' && p[1]=='N') || (p[0]=='i' && p[1]=='n') )                     
            ok = dio_set_direction(dio_number, DIODIR_INPUT);	
         else if( (p[0]=='O' && p[1]=='U' && p[2]=='T') || (p[0]=='o' && p[1]=='u' && p[2]=='t') )
            ok = dio_set_direction(dio_number, DIODIR_OUTPUT);    
         else       
            ok = dio_set_direction(dio_number, (DioDirection_t)StrToUInt((char*)p));
      }
  }
  break;


  
  /*---------------------------------------------------------------------------    
    RELAYS
  ---------------------------------------------------------------------------*/
  case Parameter_rel1:
  {
    const int32_t rel_number = ((int32_t)(syntax_parameter_name()[3]) - '0');
    if(p !=0)
        ok = relay_set(rel_number, StrToUInt((char*)p));
  }
  break;
  
  case Parameter_rel2:
  {
    const int32_t rel_number =  ((int32_t)(syntax_parameter_name()[3]) - '0') * 10
                          + ((int32_t)(syntax_parameter_name()[4]) - '0');
    if(p !=0)
        ok = relay_set(rel_number, StrToUInt((char*)p));
    
  }
  break;
  
  case Parameter_re:
  {
    const int32_t rel_number =  ((int32_t)(syntax_parameter_name()[2]) - '1');
    const int32_t rel_out_number =  ((int32_t)(syntax_parameter_name()[3]) - '0');
    if(p !=0 && rel_number>=0 && rel_number<=9 && rel_out_number>=0 && rel_out_number<8){
        
        ok = relay_set(rel_number*8+rel_out_number+1, StrToUInt((char*)p));
    }
    
  }
  break;
  
  case Parameter_relconf_hc595:
  {
    if(p !=0) 
        ok = relay_conf(CHIP_74HC595, StrToUInt((char*)p)/8 );
  }
  break;
  
  case Parameter_relconf:
  {
      if(p !=0)
        ok  = relay_conf(CHIP_AMIS39100,StrToUInt((char*)p)/8 );
  }
  break;
  
  
  /*---------------------------------------------------------------------------    
   SET
   APPLICATION
  ---------------------------------------------------------------------------*/
  case Parameter_swspi://set
  {    	  
    if(p !=0)
        ok = function_swspi((const char*)p);     
  }
  break;
  
  case Parameter_swspics://set
  {
	  const int32_t cs =((int32_t)(syntax_parameter_name()[7]) - '0');
      if(p !=0)
        ok = function_swspics((const char*)p, cs);
  }
  break;

  case Parameter_swspiconf://set
  {
	  const int32_t cs =((int32_t)(syntax_parameter_name()[11]) - '0');            
      if(p !=0)
        ok = function_swspiconf((const char*)p, cs);
  }
  break;


  case Parameter_sequenceconf://set  
      if(p !=0)
        ok = unisequencer_conf((const char*)p);            
  break;
  
  case Parameter_sequence://set  
      if(p !=0)
        ok = unisequencer_execute((const char*)p);            
  break;
  
  case Parameter_scanchain1://set
    if(p !=0)
    ok = scanchan1_transfer((const char*)p);          
  break;
  
  case Parameter_scanchain2:
    if(p !=0)
        ok =scanchain2_transfer((const char*)p);          
  break;
  
  case Parameter_scanchain3:
    if(p !=0)
        ok =scanchain3_transfer((const char*)p);          
  break;

  case Parameter_genclk://set
      if(p !=0)
     ok = function_genclk((const char*)p);
  break;
  
  case Parameter_scanchainconf:
      ok = scanchain_conf((const char*)p);
  break;
  
  /*---------------------------------------------------------------------------
    SET
    PWM -pulse width modulator
  ---------------------------------------------------------------------------*/
  case Parameter_pwmfreq:
  {               
      const int32_t pwm_number =((uint32_t)(syntax_parameter_name()[3]) - '0')-1; 
      if(p !=0)
        ok = mod_pwm_set_freq(pwm_number, StrToUInt((char*)p) );
  }
  break;

  case Parameter_pwmstart:
  {   
    const int32_t pwm_number = ((uint32_t)(syntax_parameter_name()[3]) - '0')-1; 
    ok = mod_pwm_enable(pwm_number, true) ;
  }
  break;
  
  case Parameter_pwmstop:
  {   
	  const int32_t pwm_number = ((uint32_t)(syntax_parameter_name()[3]) - '0')-1; 
	  ok = mod_pwm_enable(pwm_number, false) ;
  }
  break;
  
  case Parameter_pwmduty:
  {   
    const int32_t pwm_number = ((uint32_t)(syntax_parameter_name()[3]) - '0')-1; 
    if(p !=0)
        ok = mod_pwm_set_duty(pwm_number, StrToUInt((char*)p) );
  }
  break;

  case Parameter_pwmconf:
  {      
    const uint32_t pwm_number = ((uint32_t)(syntax_parameter_name()[3]) - '0')-1;      
        ok = mod_pwm_conf(pwm_number);    
  }
  break;

  case Parameter_pwmenable:
  {      
    const uint32_t pwm_number = ((uint32_t)(syntax_parameter_name()[3]) - '0')-1;      
    if(p !=0)
        ok = mod_pwm_enable(pwm_number, StrToUInt((char*)p));    
  }
  break;
  
  
  /*---------------------------------------------------------------------------
   DELAY 0..2000ms  
  ---------------------------------------------------------------------------*/
  case Parameter_delay:
    { 
    int delay_time =      (int)atoi((char*)p);
    if(delay_time>0 && delay_time<=2000)
      {
        delay_ms(delay_time);
        ok = true;
      }      
    }	
    break;


  case Parameter_intadc:
  {	  
     ok = intadc_read( (char*)p);      
  }
  break;
  


  /*---------------------------------------------------------------------------
    SET
    AIN - analog input
  ---------------------------------------------------------------------------*/
  case Parameter_baudrate:
  {
    const uint32_t baudrate = StrToUInt((char*)p);
    ok = SYSTEM_SetBaudRate(baudrate);
  }
  break;

  /*---------------------------------------------------------------------------
    SET
    AIN - analog input
  ---------------------------------------------------------------------------*/
  case Parameter_ainconf:
  {
    uint32_t ain = (uint32_t)(syntax_parameter_name()[3]) - '1';
    ok = ain_conf(ain, (char*)p);
  }
  break;


  /*---------------------------------------------------------------------------
    SET
    SPI - serial interface
  ---------------------------------------------------------------------------*/
  case Parameter_spidata:
  {
    uint32_t spi_number = (uint32_t)(syntax_parameter_name()[3]) - '1';
    int cs_number = (uint32_t)(syntax_parameter_name()[6]) - '1';    
    ok = mod_spi_transfer(spi_number, cs_number, (char*)p);
  }
  break;

  case Parameter_spispeed:
  {
    uint32_t spi_number = (uint32_t)(syntax_parameter_name()[3]) - '1';
    int cs_number = (uint32_t)(syntax_parameter_name()[6]) - '1';
    uint32_t value = StrToUInt((char*)p);
    ok = mod_spi_set_speed(spi_number, cs_number, value);
  }
  break;

  case Parameter_spicsconf:
  {
   uint32_t spi_number = (uint32_t)(syntax_parameter_name()[3]) - '1';
   int cs_number = (uint32_t)(syntax_parameter_name()[6]) - '1';
   const char *tmp =  (char*)p;
   if( (tmp[0]=='o' && tmp[1]=='f' && tmp[2]=='f') || (tmp[0]=='O' && tmp[1]=='F' && tmp[2]=='F')){
       ok = true;
       mod_spi_off(spi_number, cs_number);
   }
   else ok = mod_spi_conf(spi_number, cs_number,(char*)p);
  }
  break;



  /*---------------------------------------------------------------------------
    SET
    SERIAL serial port
  ---------------------------------------------------------------------------*/
  //sets serial data
  case Parameter_serdata:
  {
		// uint32_t ser_number = ((int32_t)(syntax_get_text()[3]) - '0');		
		// uint8_t *pdata = syntax_as_bytearray();
		// ok = (serial_set_data(ser_number, &pdata[1], pdata[0]) == STATUS_OK);
    ok = false;     
  }
  break;

  case Parameter_serconf:
  {
		// uint32_t ser_number = ((int32_t)(syntax_get_text()[3]) - '0');
		// ok = (serial_conf(ser_number) == STATUS_OK);
    ok = false; 
  }
  break;

  case Parameter_serbaud:
  {
	  // uint32_t ser_number = ((int32_t)(syntax_get_text()[3]) - '0');
	  // uint32_t baudrate = (uint32_t)(syntax_as_integer());
	  // ok = (serial_set_baud(ser_number, baudrate) == STATUS_OK);
    ok = false; 
  }
  break;

  case Parameter_sermode:
  {
	  // uint32_t ser_number = ((int32_t)(syntax_get_text()[3]) - '0');
	  // uint32_t mode = (uint32_t)(syntax_as_integer());
	  // ok = (serial_set_mode(ser_number, mode) == STATUS_OK);
    ok = false; 
  }
  break;

  case Parameter_serbits:
  {
	  // uint32_t ser_number = ((int32_t)(syntax_get_text()[3]) - '0');
	  // uint32_t bits = (uint32_t)(syntax_as_integer());
	  // ok = (serial_set_bits(ser_number, bits) == STATUS_OK);	  
    ok = false; 
  }
  break;
  
  case Parameter_serparity:
  {
	  // uint32_t ser_number = ((int32_t)(syntax_get_text()[3]) - '0');    
	  // uint32_t parity = (uint32_t)(syntax_as_integer());
	  // ok = (serial_set_parity(ser_number, parity) == STATUS_OK);	  
    ok = false; 
  }
  break;
  
  case Parameter_serstopb:
  {
	  // uint32_t ser_number = ((int32_t)(syntax_get_text()[3]) - '0');
	  // uint32_t stopb = (uint32_t)(syntax_as_integer());
	  // ok = (serial_set_stopb(ser_number, stopb) == STATUS_OK);
    ok = false; 
  }
  break; 
  

  /*---------------------------------------------------------------------------
    CAN
  ---------------------------------------------------------------------------*/
  case Parameter_candata:
  {
    // TODO
  }
  break;

  case Parameter_canconf:
  {
    // TODO
  }
  break;




  
  /*---------------------------------------------------------------------------
    AOUT - analog output
  ---------------------------------------------------------------------------*/
  case Parameter_aout:
  {	  
     int n =  (int)(syntax_parameter_name()[4]) - '1';
	 ok = aout_set(n, StrToUInt((char*)p));      
  }
  break;

  case Parameter_aoutconf:
  {
      int n =  (int)(syntax_parameter_name()[4]) - '1';
      if(p != 0)
            ok = aout_conf(n, (char*)p) ;
      else 
            ok = aout_conf(n, 0) ;
  }
  break;



  /*---------------------------------------------------------------------------
    I2C - interface
  ---------------------------------------------------------------------------*/
  case Parameter_i2cdata:
  {
//    uint8_t* pdata = syntax_as_bytearray();
//    uint32_t i2c_number = (uint32_t)syntax_get_text()[3] - '1';
//    ok = (i2c_write_data(i2c_number, (uint32_t)pdata[0], &(pdata[2]), (uint32_t)pdata[1]) == 0);
  }
  break;

  case Parameter_i2cspeed:
  {
//    uint32_t i2c_number = syntax_get_text()[3] - '1';
//    ok = ( i2c_speed(i2c_number, syntax_as_integer()) == RESULT_NO_ERROR);
  }
  break;

  case Parameter_i2cconf:
  {
//    uint32_t i2c_number = syntax_get_text()[3] - '1';
//    ok = (i2c_conf(i2c_number) > (-1));
  }
  break;
  
  case Parameter_refclkconf:
  {    
    ok = mod_refclk_conf((char*)p);
  }
  break;
  
  case Parameter_refclkenable:
  {    
      bool en = StrToUInt((char*)p);
      ok = mod_refclk_enable(en);
  }
  break;
  
  case Parameter_capconf:
  {    
      ok = cap_conf((char*)p);
  }
  break;

  case Parameter_captrig:
  {          
      ok = cap_trig();
  }
  break;


  }// END SWITCH
  
 
  if ( ok )
  {	
    printf( "%s:ok ",syntax_parameter_name() );		
  }
  else
  {	  	  
	m_error |= true;
	printf( "%s:err ",syntax_parameter_name() );			  
  }
    
}









/*!
* 	  void  get_parameter(int32_t p_id, uint8_t *p)
* 
* 	 GETTING PARAMETER    
* 	\param int32_t p_id -...
* 	\param uint8_t *p -...
*/
inline void  get_parameter(int32_t p_id, uint8_t *p)
{
  bool ok = false; 
  
  printf(syntax_parameter_name());
          
  switch (p_id )
  {

      
      
  /*---------------------------------------------------------------------------    
    DIO - digital input output
  ---------------------------------------------------------------------------*/
 case Parameter_dio1://get
  {
        int value;
        const uint32_t dio_number = ((uint32_t)(syntax_parameter_name()[3]) - '0');
        value =  dio_get(dio_number);
        ok  = (value != -1);
        if(ok) printf( "=%d",value);
  }
  break;
 
      case Parameter_dio2://get
  {
        int value;
        const uint32_t dio_number = ((uint32_t)(syntax_parameter_name()[3]) - '0') * 10 + ((uint32_t)(syntax_parameter_name()[4]) - '0');
        value =  dio_get(dio_number);
        ok  = (value != -1);        
        if(ok) printf("=%d", value);
  }
  break;

  case Parameter_diodir://get
  {
	  int value;
	  uint32_t dio_number = ((uint32_t)(syntax_parameter_name()[3]) - '0');
	  value = dio_get_direction(dio_number);
      ok =  (value != -1);
	  if(ok) printf("=%d", value);
  }
  break;
  
  case Parameter_diodir2://get
  {
	int value;
	uint32_t dio_number = ((uint32_t)(syntax_parameter_name()[3]) - '0') * 10 + ((uint32_t)(syntax_parameter_name()[4]) - '0');
    value = dio_get_direction(dio_number);
	ok =  (value != -1);
	if(ok) printf("=%d", value);
  }
  break;

  
  case Parameter_rel1://get
  {
    int32_t rel_number = ((int32_t)(syntax_parameter_name()[3]) - '0');    
    ok = 1;
     bool state = relay_get(rel_number);
    if(ok) printf("=%d",  state);
  }
  break;
  
  case Parameter_rel2://get
  {      
    int32_t rel_number =  ((int32_t)(syntax_parameter_name()[3]) - '0') * 10 
                        + ((int32_t)(syntax_parameter_name()[4]) - '0');   
    ok = 1;
    bool state = relay_get(rel_number);
    if(ok) printf("=%d", state);
  }
  break;

  case Parameter_re://get
  {      
    const int32_t rel_number =  ((int32_t)(syntax_parameter_name()[2]) - '1');
    const int32_t out_number =  ((int32_t)(syntax_parameter_name()[3]) - '0');
    if(rel_number >= 0 && rel_number<=9 && out_number>=0 && out_number<8){        
         bool state = relay_get(rel_number*8 + out_number + 1);
         ok = 1;
         printf("=%d", state);
    }
  }
  break;  
  
  /*---------------------------------------------------------------------------
    GET
    PWM
  ---------------------------------------------------------------------------*/
  case Parameter_pwmenable://get
  {
    // read if pwm is enabled    
    uint32_t pwm_number =  (uint32_t)(syntax_parameter_name()[3]) - '0';
    if(pwm_number == MODULE_PWM1 || pwm_number == MODULE_PWM2 || pwm_number == MODULE_PWM3 )
        printf( "=%u",  mod_pwm_is_enabled(pwm_number) );
    else ok = false;
  }    
  break;

  case Parameter_aout:
  {	  
     int n =  (int)(syntax_parameter_name()[4]) - '1';
     ok = (n==0 || n==1);
     if(ok) printf("=%d", aout_value(n));     
     
  }
  break;
  
  /*---------------------------------------------------------------------------
    GET
    VERSION
  ---------------------------------------------------------------------------*/
  case Parameter_version://get
  {    
    printf("=");
    APP_print_inf();
    ok = true;
  }
  break;


  /*---------------------------------------------------------------------------
    GET
    AIN - analog input
  ---------------------------------------------------------------------------*/
  case Parameter_ain://get
  {
     uint32_t ain_number = (syntax_parameter_name()[3]) - '1';       
     ok = ain_number == AIN1 || ain_number == AIN2 || ain_number == AIN3 ||ain_number == AIN4;
     if(ok) printf("=%d", ain_read(ain_number));    
  }
  break;


  /*---------------------------------------------------------------------------
    GET
    SPI
  ---------------------------------------------------------------------------*/
    case Parameter_spidata:
  {
    uint32_t spi_number = (uint32_t)(syntax_parameter_name()[3]) - '1';
    int cs_number = (uint32_t)(syntax_parameter_name()[6]) - '1';   
    ok = mod_spi_result(spi_number,cs_number  );
  }
    break;  


  /*---------------------------------------------------------------------------
    GET
    SERIAL port
  ---------------------------------------------------------------------------*/
  case Parameter_serdata://get
  {
 //    uint32_t ser_number = ((uint32_t)(syntax_get_text()[3]) - '0');
	// int32_t result;
	// uint32_t count = (uint32_t)syntax_as_bytearray()[0];
	// uint8_t *pdata_out = (uint8_t *)&parameter_out[300];
	
	// result = serial_get_data(ser_number, pdata_out, count);
	// if (result >= 0)
	// {
	// 	sprintf(parameter_out, "=%02x", (unsigned int)result);
	// 	string_utils_to_hex(&parameter_out[3], pdata_out, result);
	// 	ok = true;
	// }
    ok = false;
  }

  break;


 

  /*---------------------------------------------------------------------------
    GET
    KEY
  ---------------------------------------------------------------------------*/
  case Parameter_key://get
  {
   
    uint32_t key_number = ((int32_t)(syntax_parameter_name()[3]) - '0') ;
    if(key_number == 1) {
        printf("=%d",KEY1);
        ok = true;
    }else if(key_number == 2){
        printf( "=%d", KEY2);
        ok = true;
    }    
    else{
        ok = false;
    }
    
  }
  break;

  /*---------------------------------------------------------------------------
    GET
    CAN
  ---------------------------------------------------------------------------*/
  case Parameter_candata://get
  {
    //int32_t can_number = ((int32_t)(syntax_get_text()[3]) - '0');
    // TODO
  }
  break;


  /*---------------------------------------------------------------------------
    GET
    I2C
  ---------------------------------------------------------------------------*/
  case Parameter_i2cdata://get
  {
//    uint32_t i2c_number = ((uint32_t)(syntax_get_text()[3]) - '1');
//    int32_t result;
//    uint32_t i2c_addr = (uint32_t)syntax_as_bytearray()[0];
//    uint32_t data_length = (uint32_t)syntax_as_bytearray()[1];
//    uint8_t *pdata_out = (uint8_t*)&parameter_out[300];
//    result = i2c_read_data(i2c_number, i2c_addr, pdata_out, data_length);
//    if (result == data_length)
//    {
//      sprintf(parameter_out, "=%02x", (unsigned int)result);
//      string_utils_to_hex(&parameter_out[3], pdata_out, result);
//      ok = true;
//    }
  }
  break;
  
  case Parameter_i2cdatawr://get
  {
	  
//	int32_t i2c_number = ((uint32_t)(syntax_get_text()[3]) - '1');
//	int32_t result;
//	int32_t i2c_addr = (uint32_t)syntax_as_bytearray()[0];
//	int32_t write_length = (uint32_t)syntax_as_bytearray()[1];
//	int32_t read_length = (uint32_t)syntax_as_bytearray()[2];
//
//	uint8_t *pdata_out = (uint8_t*)&parameter_out[300];
//	uint8_t* wr_pdata = syntax_as_bytearray();
//	
//	result = i2c_readwrite_data(i2c_number, i2c_addr, &(wr_pdata[3]) , pdata_out, write_length, read_length);
//	//result = i2c_read_data(i2c_number, i2c_addr, pdata_out, data_length);
//	if (result == read_length)
//	{
//		sprintf(parameter_out, "=%02x", (unsigned int)result);
//		string_utils_to_hex(&parameter_out[3], pdata_out, result);
//		ok = true;
//	}
  }
  break;

 
	  
  /*---------------------------------------------------------------------------
    GET
    MISC
  ---------------------------------------------------------------------------*/

  case Parameter_session:
  {
     printf("=%u", (unsigned int)session_key);
     ok = true;
  }
  break;

  case Parameter_errors:
  {
    // TODO
  }
  break;

  case Parameter_swspi:
  {          
    ok = function_swspi_result();         
  }
  break;

  case Parameter_sequence:
  {  
     ok = unisequencer_result();
  }
  break;

 case Parameter_scanchain1:
  {     
     ok = scanchain1_result();     
  }
  break;

 case Parameter_scanchain2:
  {         
     ok = scanchain2_result(StrToUInt((const char*)p)); 
  }
  break;

  case Parameter_intadc://get
  {           
     const uint32_t index = StrToUInt((char*)p);
     ok = intadc_result( index);    
  }
  break;

  case Parameter_capres:
  {    
      ok = cap_result((char*)p);
  }
  break;
  
  }// END SWITCH

    
  if (ok)
  {
    printf(" ");
  }
  else
  {
    printf( ":err " );
  }  

}


/*!
* 	   void run_command(int32_t p_id,uint8_t *p)
* 
* 	...tbd...
* 	\param int32_t p_id -...
* 	\param uint8_t *p -...
*/
inline static  void run_command(int32_t p_id,uint8_t *p)
{


  bool ok  = false;
  printf( syntax_parameter_name() );
  
  switch (p_id )
  {
  case Parameter_scanchain2:
//  {
//     ok =function_scanchain2((const char*)p);          
//  }
  break;
  
// RUN SWSPI
  case Parameter_swspi:
  {    
    ok = function_swspi((const char*)p);     
    function_swspi_result();    
  }
  break;
  
  // RUN.SPI
 case Parameter_spidata:
  {
      uint32_t spi_number = (uint32_t)(syntax_parameter_name()[3]) - '1';
      int cs_number = (uint32_t)(syntax_parameter_name()[6]) - '1';   
      ok = mod_spi_transfer(spi_number, cs_number, (char*)p);
      mod_spi_result(spi_number,cs_number  );
      
  }
  break;
  
  case Parameter_sequence:
//  {
//    //ok =function_sequence((const char*)syntax_as_bytearray());          
//  }
  break;
  
// RUN SCANCHAIN  
  case Parameter_scanchain1:
//  {
//    ok =function_scanchain1((const char*)p);          
//  }
  break;

// RUN.GENCLK
  case Parameter_genclk:
  {
     ok = function_genclk((const char*)p);     
  }
  break;

//RUN. JTAG
    case Parameter_jtag:
	{
	//	ok = jtag_set((const char*)syntax_as_bytearray());
	}
	break;

  
  }// END SWITCH

  
  if (!ok)
  {	
      printf( ":err " );
  }else{
      printf( " " );
  }

}
