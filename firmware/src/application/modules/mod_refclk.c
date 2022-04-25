#include "mod_refclk.h"
#include "refclk.h"
#include "typedef_global.h"
#include "app.h"



bool mod_refclk_conf(const char *ptext){
    enum {
        SRC_BFRC,
        SRC_SYSCLK,
        SRC_SPLL
    };

    char *item = 0;
    int n = 0;
    int src=-1,div=-1,trim=0;    
    FOREACH_BEGIN(item, ptext, ',') 
    {
        switch (n) 
        {
            case 0: 
            {
                if(strcmp("RC8MHZ", item)==0){
                    src = REFCLK_BFRC;
                }
                if(strcmp("RC32KHZ", item)==0){
                    src = REFCLK_LPRC;
                }
                else if(strcmp("CLK", item)==0){
                    src =  REFCLK_SPLL;
                }
                else if(strcmp("OSC", item)==0){
                    src = REFCLK_POSC;
                }
            }
            break;
            
            case 1:
            {
                div = StrToUInt(item);
                div = (div>>1)&0x3fff;
            }
            break;
            
            case 2:
            {
                trim = StrToUInt(item);
                trim &= 0xff;
            }
            break;
        }               
            
        n++;                    
    }
    FOREACH_END(item);
    
    if(src!=-1 && div!=-1){
        gpio_enable(GPIO('E',3), GPIO_CUSTOM_OUTPUT(OUTPUT_FUNC_REFCLKO3));
        refclk_out_cfg(REFCLKO3, src, div, trim);
        return true;
    }
            
    return false;
    
}

bool mod_refclk_enable(bool enable){
    refclk_out_enable(REFCLKO3, enable);
    return true; 

}
