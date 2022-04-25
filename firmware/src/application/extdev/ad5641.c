#include "ad5641.h"
#include "gpio.h"


bool ad5641_write(AD5641 *pdev,  uint32_t value)
{
    int i;
    value &= (0x3fff);
    pdev->value = value;
    switch(pdev->output_type){
        case  AD5641_NormalOperation:            
            break;
        case AD5641_1k_toGND:            
            value = (1<<14);
            break;
        case AD5641_100k_toGND:            
            value = (1<<15);
            break;
        case AD5641_ThreeState:            
            value = (1<<15)|(1<<14);
            break;
    }
    
    gpio_set(pdev->sync_pin,0);
    gpio_set(pdev->clk_pin,0);
    for(i=0;i<16;i++){
        
        gpio_set(pdev->data_pin, ((1<<(15-i) &value)!=0) );
        gpio_set(pdev->clk_pin, 1);
        gpio_set(pdev->clk_pin, 0);
    }
    gpio_set(pdev->sync_pin,1);
    return true;
}