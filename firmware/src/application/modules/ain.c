#include "ain.h"
#include "system.h"
#include "adc.h"



const int AIN_MAP[]= {48,49,5,6};

bool ain_conf(AnalogInput input_number, char *ptext)
{
    if(input_number == AIN1 || input_number == AIN2 || input_number == AIN3 || input_number == AIN4)
    {
        adc_init(AIN_MAP, 0, ADC_SRC_SOFTWARE_EDGE);
        return true;
    }
    return false;
}

uint32_t ain_read(AnalogInput input_number){
     if(input_number == AIN1 || input_number == AIN2 ){
         adc_trigger_measure();
         
         
         
         // TODO ADC 48,49
         
         
     }
     else if(input_number == AIN3|| input_number == AIN4)
     {
         uint32_t value;
         adc_trigger_measure();
         if( adc_read(AIN_MAP[input_number], &value) == RES_NO_ERROR)         
            return value;
     }
    return 0;
}