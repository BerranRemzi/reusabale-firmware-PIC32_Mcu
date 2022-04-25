#include "aout.h"
#include "typedef_global.h"
#include "extdev/ad5641.h"
#include "gpio.h"
#include "string_utils.h"
#include "ad5641.h"



AD5641 aout[2]={
    { 
        .data_pin = GPIO('B',15),
        .clk_pin = GPIO('D',15),
        .sync_pin = GPIO('B',13)
    },
    { 
        .data_pin = GPIO('B',15),
        .clk_pin = GPIO('D',15),
        .sync_pin = GPIO('B',14)
    }
};

bool aout_conf(int channel, char *ptext)
{        
    if(channel ==0 || channel==1){
        if(compare_string(ptext,"NORM")){       
            aout[channel].output_type = AD5641_NormalOperation;
        }
        else if(compare_string(ptext,"1K")){
            aout[channel].output_type = AD5641_1k_toGND;
        }
        else if(compare_string(ptext,"100K")){
            aout[channel].output_type = AD5641_100k_toGND;
        }
        else if(compare_string(ptext,"3ST")){
            aout[channel].output_type = AD5641_ThreeState;
        }
        else{
            printf("(wrong mode)");
            return false;
        }
        aout[channel].value = 0;
        ad5641_write(&aout[channel] , 0);
        return true;
    }    
    printf("(wrong channel)");
    return false;
}

bool aout_set(int channel, uint32_t value)
{
      if(channel ==0 || channel==1){
        ad5641_write(&aout[channel],  value);
        return true;
    }    
    return false;    
}

uint32_t aout_value(int channel){
    if(channel ==0 || channel==1){
         return aout[channel].value;
    }
    return 0;
}
