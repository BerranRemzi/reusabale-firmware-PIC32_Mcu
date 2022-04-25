#include "app.h"
#include "dio.h"
#include "string_utils.h"
#include "mod_spi.h"
#include "spi.h"

const uint32_t spi_number[2]={SPI1,SPI2};

ModSpiConfig hwSpiConfig[2] = {
    {
        .spi_port=SPI2,                
        .spi_sdi_pin=GPIO('G',7),
        .spi_sdo_pin=GPIO('C',4),
    },
    {
        .spi_port=SPI5,        /*not available*/
//        .spi_sdi_pin=GPIO('A',2),
//        .spi_sdo_pin=GPIO('A',3),
    }
};
  
void mod_spi_off(SpiModule spi_number, int cs_number){
    if( (spi_number==0 || spi_number==1) && (cs_number==0|| cs_number==1||cs_number==2||cs_number==3) ) 
    {
        hwSpiConfig[spi_number].settings[cs_number].configured = 0; 
        if(hwSpiConfig[spi_number].spi_port == SPI2)
        {                            
            spi_disable(hwSpiConfig[spi_number].spi_port); 
        }
    }
}

bool mod_spi_conf(SpiModule spi_number, int cs_number, char *ptext)
{
    char *item = 0;
    int n = 0;    
    
    if(spi_number==1){ // in this configuration is not available .use SW SPI
        printf("(not available)");
        return 0;
    }
    hwSpiConfig[spi_number].settings[cs_number].configured = 0;
    hwSpiConfig[spi_number].settings[cs_number].cs_delay1 =0;
    hwSpiConfig[spi_number].settings[cs_number].cs_delay2 =0;
    FOREACH_BEGIN(item, ptext, ',')
    {
        switch (n)
        {
            case 0:
            {
                const int dio = StrToUInt( &item[3] );
                if( DIO_Valid( dio) )
                {   
                    const uint32_t port = dio_table[ dio ];
                    hwSpiConfig[spi_number].settings[cs_number].gpio_cs_port = gpio_reg(REG_LAT, port ,0);
                    hwSpiConfig[spi_number].settings[cs_number].gpio_cs_mask = 1<<GPIO_PIN(port);                
                }else{
                    printf("(dio not valid)");
                    return false;
                }
            }
          break;        

        case 1:
            hwSpiConfig[spi_number].settings[cs_number].speed = StrToUInt(item);
            spi_set_clock(hwSpiConfig[spi_number].spi_port, hwSpiConfig[spi_number].settings[cs_number].speed);
            if(hwSpiConfig[spi_number].settings[cs_number].speed==0){
                printf("(error clock speed can't be 0)");
                return false;
            }
        break;
          
        case 2:
          hwSpiConfig[spi_number].settings[cs_number].fmt = StrToUInt(item);          
          if(hwSpiConfig[spi_number].settings[cs_number].fmt<0 || hwSpiConfig[spi_number].settings[cs_number].fmt>2){
              printf("(format error)");
              return false;
          }
          break;
          
        case 3:
          hwSpiConfig[spi_number].settings[cs_number].cpha = StrToUInt(item);          
          if(hwSpiConfig[spi_number].settings[cs_number].cpha!=0 && hwSpiConfig[spi_number].settings[cs_number].cpha!=1){
              printf("(error CPHA 0,1)");
              return false;
          }
          break;

        case 4:
          hwSpiConfig[spi_number].settings[cs_number].cpol = StrToUInt(item);
          if(hwSpiConfig[spi_number].settings[cs_number].cpol!=0 && hwSpiConfig[spi_number].settings[cs_number].cpol!=1){
              printf("(error CPOL 0,1)");
              return false;
          }
          break;

        case 5:
          hwSpiConfig[spi_number].settings[cs_number].cs_delay1 = StrToUInt(item);
          break;

        case 6:
          hwSpiConfig[spi_number].settings[cs_number].cs_delay2= StrToUInt(item);
          break;
    }
        n++;
    }
    FOREACH_END(item);
        
     hwSpiConfig[spi_number].settings[cs_number].configured = 1;
     
    if(hwSpiConfig[spi_number].spi_port ==SPI2){
        gpio_enable( hwSpiConfig[spi_number].spi_sdo_pin, GPIO_CUSTOM_OUTPUT(OUTPUT_FUNC_SDO2) );
        gpio_enable( hwSpiConfig[spi_number].spi_sdi_pin, GPIO_CUSTOM_INPUT(INPUT_FUNC_SDI2) );
        
            // configure SPI
        uint32_t options = SPIxCON_MODE_8BIT|SPIxCON_ON|CLKSRC_PBCLK|SPIxCON_MASTER_MODE;
        if(hwSpiConfig[spi_number].settings[cs_number].cpol==1)
            options |= SPIxCON_CPOL1;
        if(hwSpiConfig[spi_number].settings[cs_number].cpha==1)
            options |= SPIxCON_CPHA1;

        spi_enable(hwSpiConfig[spi_number].spi_port, options); 
    }
    
    return true;
}


bool mod_spi_set_speed(SpiModule spi_number, int cs_number,  uint32_t speed)
{
    hwSpiConfig[spi_number].settings[cs_number].speed = speed;
    spi_set_clock(hwSpiConfig[spi_number].spi_port, hwSpiConfig[spi_number].settings[cs_number].speed);
    return true;
}

bool mod_spi_transfer(SpiModule spi_number, int cs_number, char *ptext)
{
    char *item = 0;
    int n = 0;    
    unsigned char data_out[100];
    int bytes_count=0;
        
    if(hwSpiConfig[spi_number].settings[cs_number].configured ==0 ){
        printf("(not configured)");
        return false;
    }
    
    
    FOREACH_BEGIN(item, ptext, ',')
    {
        switch (n)
        {
            case 0:
            {                
                bytes_count = StrToUInt(item);
                if(bytes_count<=0 || bytes_count>10){
                    printf("(error bytes_count 1..10)");
                    return false;
                }
            }
            break;
            
            case 1:
            {          
                int i=0;
                int bytes=0;
                int j=0;
                uint32_t value;
                unsigned char *tmp= &application_data[1000];
                switch(hwSpiConfig[spi_number].settings[cs_number].fmt)
                {
                    case 0:// lsb first
                        bytes =bytes_from_hex(tmp, item);
                        if(bytes<bytes_count){
                            printf("(error bytes count");
                            return false;
                          }                        
                        // roll bytes because SPI module sends MSB first
                        for(i=0;i<bytes_count;i++){
                            for(j=0;j<8;j++)    {
                                if( (tmp[i] & (1<<j)) !=0)
                                    data_out[i] |= (1<<(7-j) );
                                else data_out[i] &= ~(1<<(7-j) );
                            }
                        }
                        break;

                    case 1:// Integer MSB first
                        value =  StrToUInt(item);                        
                        i=0;
                        switch(bytes_count)
                        {
                            case 4:
                            data_out[i++] = (value>>24)&0xff;
                            case 3:
                            data_out[i++] = (value>>16)&0xff;
                            case 2:
                            data_out[i++] = (value>>8)&0xff;
                            case 1:
                            data_out[i++] = value&0xff;
                            break;
                        }
                        
                        break;            
                    
                    case 2:// Integer MSB first
                        value =  StrToUInt(item);                        
                        data_out[3] = data_out[2] = data_out[1] = data_out[0] = 0;
                        for(i=0;i<bytes_count*8;i++){
                            const uint32_t bit0= (value&(1<<i)) !=0;
                            data_out[i/8] |= bit0<<(7-i%8);
                        }
                        
                        break;                                    
                }
            }
            break;
        }
        n++;
    }
    FOREACH_END(item);
    
    if(hwSpiConfig[spi_number].settings[cs_number].configured == 1)
    {
    
        unsigned char *data_in = application_data;
        // SET CS
        volatile uint32_t*cs_port = hwSpiConfig[spi_number].settings[cs_number].gpio_cs_port;
        const uint32_t cs_mask = hwSpiConfig[spi_number].settings[cs_number].gpio_cs_mask;
        const int data_size = app_result_count;
        // CS=1
        *cs_port &= ~cs_mask;   
        if(hwSpiConfig[spi_number].settings[cs_number].cs_delay1>0)
            delay_ms(hwSpiConfig[spi_number].settings[cs_number].cs_delay1);

        // transfer write and read bytes
        spi_transfer(hwSpiConfig[spi_number].spi_port, data_out, (unsigned char*)&data_in[data_size], bytes_count);

        // CS=0  
        if(hwSpiConfig[spi_number].settings[cs_number].cs_delay2>0)
            delay_ms(hwSpiConfig[spi_number].settings[cs_number].cs_delay2);
        *cs_port |= cs_mask;

        app_result_count += bytes_count;

        return true;
    }
    return false;
}

bool mod_spi_result(SpiModule spi_number, int cs_number)
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


void mode_spi_set_cs(SpiModule spi_number, int cs_number, bool state){
    volatile uint32_t*cs_port = hwSpiConfig[spi_number].settings[cs_number].gpio_cs_port;
    const uint32_t cs_mask = hwSpiConfig[spi_number].settings[cs_number].gpio_cs_mask;
    
    // CS=1
    if (state == 0){
        *cs_port &= ~cs_mask;    
    }else{
        *cs_port |= cs_mask;    
    }
}
