/*!
* @file modules\cap.c
* @author D.Chikov
* @date 10/15/2020, 10:24:38
* @brief ...tbd...
*/



#include "typedef_global.h"
#include "cap.h"
#include "app.h"
#include "dio.h"
#include "system.h"
#include "chrono.h"
#include <sys/kmem.h>
#include <xc.h>


#define STREAM_SIZE 0xffff

  static enum {
      CAP_FIN1
  }sync;
  
  static enum{
      CAP_TRIG,
      CAP_TMR,
      CAP_PIN
  }trig;
  
  static enum{
      CAP_D1_D2,
      CAP_TIMER2
  }src;

  static int samples;
  
bool cap_conf(const char *ptext){
  char *item = 0;
  int n = 0;
  samples = 0xffff;
  src = CAP_D1_D2;
  
  FOREACH_BEGIN(item, ptext,  ',')  {     
     switch (n)
     {
     
    //[SYNC]
    case 0:    
        if(strcmp("FIN1",item)==0){
            sync = CAP_FIN1;

        }
        else {
            printf("(Wrong sync)");
            return 0;
        }
        break;
        
    //[TRIG]
    case 1:
        if(strcmp("TRIG",item)==0){
            trig = CAP_TRIG;
        }   
        else {
            printf("(Wrong trig)");
            return 0;
        }
        break;
    
    // [SOURCE]
    case 2:     
        if(strcmp("CAPD32",item) == 0){
            src = CAP_D1_D2;
                       
        }
        else if(strcmp("TIMER2",item)==0){
            src = CAP_TIMER2;
        }
        else{
            printf("(Wrong source)");
            return 0;
        }
        break;
        
    //[EDGE]
    case 3:
        if(strcmp("RISING",item)==0){
             INTCONbits.INT2EP =1;   
        }
        else if(strcmp("FALLING",item)==0){
             INTCONbits.INT2EP =0;   
        }
        break;
        
    case 4:
        samples = StrToUInt(item);
        break;
        
     default:
       break;
     }
     n++;
  }  FOREACH_END(item);
    


        

  return 1;
}

bool cap_trig(){

     // FIN1 - configure
            gpio_enable( GPIO('C',3), GPIO_IN|GPIO_CUSTOM_INPUT(INPUT_FUNC_INT2)|CN_ENABLE|CN_PULLUP);           
            INT2R = 0b1100;
            gpio_enable( GPIO('B',3), GPIO_IN|CN_ENABLE|CN_PULLUP );
            gpio_enable( GPIO('B',6), GPIO_IN|CN_ENABLE|CN_PULLUP);            
            
    APP_Clear();
    // DMACON    - configure DMA
    DMACON =0;
    DMACONbits.ON = 1;    // DMA module on
    
    // DMA Channel 0
    DCH0CON =0;
    DCH0INT=0;
    DCH0CONbits.CHPRI=3;        
    DCH0SSA = KVA_TO_PA((uint32_t)&PORTB);
    DCH0DSA = KVA_TO_PA(application_data);
    DCH0SSIZ = 1;//or 4
    DCH0DSIZ = samples;//block size
    DCH0CSIZ = 1;    
    
    //DCHxINT    
    DCH0INT =0;
    DCH0INTbits.CHDDIE =1;
    
    //DCHxECON
    DCH0ECON =0;    
    DCH0ECONbits.CHSIRQ =13;
    DCH0ECONbits.SIRQEN=1;
    
    
    //clearWdt();    

    
    bool result=0;
    const uint8_t *pstream = (uint8_t*)KVA0_TO_KVA1(&application_data[0]);

    if(trig == CAP_TRIG){        
        
        // enable DMA
        DCH0INTbits.CHDDIF =0;
        DCH0CONbits.CHEN=1;
        
        // wait trigger  
        CHRONO1_SET_DIVIDER(DIVIDER_1_256); // 256 *200us
        CHRONO1_SET_TIMEOUT(200);
        bool timeout=false;
        CHRONO1_START();
        while(!DCH0INTbits.CHDDIF && timeout==0) timeout = CHRONO1_IS_TIMEOUT();    
        if(timeout ==1) {
            printf("(timeout)");
           DCH0CONbits.CHEN=0;
           return false;
        }
        DCH0CONbits.CHEN=0;// turn off    
        DCH0INTbits.CHDDIF =0; // reset flag
        
        //decode
        int i=0;
        BitArray array;
        array.data = &application_data[0];
        array.size =0;
        for( ;i<samples;i++){ 
            const uint8_t byte = pstream[i];                              
            add_bit(&array,(byte>>3)&1);            
            add_bit(&array,(byte>>6)&1);  
        }        
        result = 1;
        app_result_count = array.size_bytes;
    }

    return result;
}

bool cap_result(const char *ptext){

     bool result = false;     
  if (app_result_count > 0)
  {      
      printf("=");      
      int i;
      for (i = 0; i < app_result_count; i++)
      {                             
            printf("%02x",application_data[i]);            
      }
      printf(":%d",app_result_count);
    result = true;
    app_result_count =0;
  }
  return result;
}
