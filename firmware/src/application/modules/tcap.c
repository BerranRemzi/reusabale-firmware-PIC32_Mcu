/*!
* @file modules\tcap.c
* @author D.Chikov
* @date 10/15/2020, 10:24:38
* @brief ...tbd...
*/


// TIME CAPTURE
// format
// 1- DIOxx is pin to read
// 2- capture time in us
// 3 - data F- falling edge R-rising edge E- all edge
// 4 - start trig 1 or 0
// 5 - divider 1- 2 , 2-8 3-32 4-128
#define TCAP_FORMAT "DIO??,?????,?,?,???,?"


#include "tcap.h"

#include "application.h"
#include "modules/dio.h"
#include "string_utils.h"
#include "tmrwatch.h"









/*!
* 	 define READ()      (*pin & pin_mask )
* 
* 	...tbd...
* 	\param )      (*pin & pin_mask -...
* 	\return define -...
*/
#define READ()      (*pin & pin_mask )
static volatile uint32_t *pin;
static uint32_t pin_mask;

static uint32_t dio ;
static int32_t timestop;
static uint32_t type;
static uint32_t trigger ;
static uint32_t trigger_time ;
static uint16_t *pout_buf;
static uint32_t out_buf_count;
static uint32_t stop_mode;
static uint16_t __tmrs[10];

enum {STOP_ON_TIMEOUT, STOP_ON_COUNT};




/*!
* 	 bool tcap_set(const char *ptext)
* 
* 	...tbd...
* 	\param const char *ptext -...
* 	\return bool -...
*/
bool tcap_set(const char *ptext)
{

  bool result = false;
   bool initialized = false;
   char *item = 0;
   int n = 0;
   application_in_index = 0;
   application_in_bit_index = 0;

   //uint32_t current=0;
   // read in the IO to measure on



   out_buf_count = 0;
   uint32_t prev_state=0;
   uint32_t divider = 0;
   FOREACH_BEGIN(item, ptext, ',')
   {

     switch (n)
     {
      case 0:
      dio = ascii2bin(item[3]) * 10 + ascii2bin(item[4 ]);
      pin = (volatile uint32_t *)(&PORTB+-0x100*dio_gpio(dio) / 32);
      pin_mask = (1 << (dio_gpio(dio)  % 32));
      if (dio <= 0 || dio > DIO_COUNT) return 0;
      break;

      case 1:
      if (item[0] == 'T') {
        timestop = atoi(&item[1]);
        stop_mode = STOP_ON_TIMEOUT;
      }
      else if (item[0] == 'C')
      {
        stop_mode = STOP_ON_COUNT;
        timestop = atoi(&item[1]);
        if (timestop > APPLICATION_SIZE) timestop = APPLICATION_SIZE;// because 16bit 2 bytes
      }
      break;

    case 2:
      type = item[0];
      if (type != 'F' && type != 'R' && type != 'E') return 0;
      break;

    case 3:
      trigger = atoi(item);
      break;

    case 4:
      trigger_time = atoi(item);
      break;

    case 5:
      divider = atoi(item);
      if (divider <= 0 || divider >= 5)  return 0;
      break;


    default:
      break;
    }
    n++;
  }
  FOREACH_END(item);

  pout_buf = (uint16_t*)&application_in[0];

  //wdt_disable();
 //Disable_global_interrupt();
 //if (initialized )
  do {


    uint32_t pulse = trigger_time;
    // trigger_time = TBL_LIST[divider][pulse];
    // PRINTF("%d",trigger_time);
    // initialize timer
   
    TMR1_SET_TIMEOUT_TICKS(65535); //set maximum in order to calc time
    TMR1_START();


    //trigger_time = 1038;
    // initialize timer 2 for range

    bool timeout = 0;


    if (stop_mode == STOP_ON_COUNT)
    {
 		bool started = false;
      // wait for start condition
      if (trigger == 0)
      {
        //wait for LOG 0
        while (!READ() && !timeout) timeout = TMR1_IS_TIMEOUT(); // wait until trigger
        while (READ() && !timeout) timeout = TMR1_IS_TIMEOUT(); // wait until trigger
        TMR1_RESTART();
      }
      else
      {
        //wait for LOG 1
        while (READ() && !timeout) timeout = TMR1_IS_TIMEOUT(); // wait until trigger
        while (!READ() && !timeout) timeout = TMR1_IS_TIMEOUT(); // wait until trigger
        prev_state |= pin_mask;
        TMR1_RESTART();
      }

      // no start TRIGGER detected
      if (timeout)
      {
        printf("(timeout)");
        break;
      }


      if (type == 'F')
      {
        while ( timestop-- )
        {
          TMR1_RESTART();
          timeout = 0;
          while (!READ() && !timeout) timeout = TMR1_IS_TIMEOUT(); // wait until line is high again
          while (READ() && !timeout) timeout = TMR1_IS_TIMEOUT(); // wait for falling_edge
          pulse = TMR1_ELAPSED_TICKS();
          if (started)
          {
            if (timeout) pout_buf[out_buf_count++] = 0xffff;
            else pout_buf[out_buf_count++] = pulse;
          }
          else  if (trigger_time < pulse)
          {
            started = true;
            pout_buf[out_buf_count++] = pulse;
          }
        }
        result = true;
      }
      // catch Rising EDGE
      else if (type == 'R')
      {
        while ( timestop-- )
        {
          TMR1_RESTART();
          timeout = 0;
          while (READ() && !timeout) timeout = TMR1_IS_TIMEOUT(); // wait until line is high again
          while (!READ() && !timeout) timeout = TMR1_IS_TIMEOUT(); // wait for falling_edge
          pulse = TMR1_ELAPSED_TICKS();
          if (started)
          {
            if (timeout) pout_buf[out_buf_count++] = 0xffff;
            else pout_buf[out_buf_count++] = pulse;
          }
          else  if (trigger_time < pulse)
          {
            started = true;
            pout_buf[out_buf_count++] = pulse;
          }
        }
        result = true;
      }

      // catch EDGE
      else if (type == 'E')
      {
        while (!TMR2_IS_TIMEOUT()) // max is 10edges/frame, so 10*amount is what we need in the buffer. Take margin for synchronisation and output of the last frame.
        {
          TMR1_RESTART();
          while (READ() == prev_state && !TMR1_IS_TIMEOUT()); // wait until line is high again
          prev_state = READ()  ;
          pout_buf[out_buf_count++] = TMR1_ELAPSED_TICKS();
        }
        result = true;
      }

      //UNKNOWN return error
      else
      {
        result = false;
      }

    }


 // on time stop
    else
    {

      if (type == 'F')
      {        
//        TMR2_INIT(DIV128);
         int c = timestop/50000 +((timestop%50000)>0?1:0);
       
        // wait for start
        while (!TMR1_IS_TIMEOUT()) if(!READ()) break;
        while (!TMR1_IS_TIMEOUT()) if(READ()) break;
       
        TMR1_RESTART();
//        TMR2_SET_TIMEOUT_TICKS(TBL_LIST[DIV128][50000]);
        while (c--)
        {
 	        TMR2_RESTART();
 	        while (!TMR2_IS_TIMEOUT())
 	        {
 		        TMR1_RESTART();
 		        while (!TMR1_IS_TIMEOUT()) if(READ()) break;
 		        while (!TMR1_IS_TIMEOUT()) if(!READ()) break;
 		        pout_buf[out_buf_count++] = TMR1_ELAPSED_TICKS();
 	        }
        }
        result = true;
      }

      else if (type == 'R')
      {        
       
   //     TMR2_INIT(DIV128);        
        int c = timestop/50000 +((timestop%50000)>0?1:0);
		
 		// wait for start
 		while (!TMR1_IS_TIMEOUT()) if(!READ()) break;
 		while (!TMR1_IS_TIMEOUT()) if(READ()) break; 		
 		TMR1_RESTART();
 		//TMR2_SET_TIMEOUT_TICKS(TBL_LIST[DIV128][50000]);
        while (c--)
        {          
          TMR2_RESTART();
          while (!TMR2_IS_TIMEOUT())
          {
            TMR1_RESTART();
            while (!TMR1_IS_TIMEOUT()) if(!READ()) break; 
            while (!TMR1_IS_TIMEOUT()) if(READ()) break;            
            pout_buf[out_buf_count++] = TMR1_ELAPSED_TICKS();           
          }
        }
 		result = true;
      }


   }





 } while (0);
// wdt_reenable();
////Enable_global_interrupt();
  return result;
}





/*!
* 	 bool tcap_data(char *ptext)
* 
* 	...tbd...
* 	\param char *ptext -...
* 	\return bool -...
*/
bool tcap_data(char *ptext)
{
  bool result = false;
 if (out_buf_count > 0)
 {
   int i;
   for (i = 0; i <= out_buf_count; i++)
   {
     if (i < out_buf_count)
     {
       printf("%04x", pout_buf[i]);
     }
     else
     {
       printf(":");
     }
    // wdt_clear();
   }
   sprintf(ptext, "%d", out_buf_count);
   result = true;
 }

  return result;
}
