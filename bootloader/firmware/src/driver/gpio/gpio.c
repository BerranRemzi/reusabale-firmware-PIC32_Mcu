/*!
* @file gpio.c
* @author D.Chikov
* @date 10/15/2020, 09:37:33
* @brief ...tbd...
*/


#include "gpio.h" 
#include <xc.h>
#include "sys.h"





/*!
* 	 bool gpio_valid(uint32_t gpio)
* 
* 	...tbd...
* 	\param uint32_t gpio -...
* 	\return bool -...
*/
bool gpio_valid(uint32_t gpio){
    switch((char)GPIO_PORT(gpio)){
        #ifdef PORTA
        case 'A': return true;                                
        #endif  

        #ifdef PORTB
        case 'B': return true;
        #endif                    
        
        #ifdef PORTC
        case 'C':  return true;                        
        #endif          

        #ifdef PORTD
        case 'D':  return true;            
        #endif  
                
        #ifdef PORTE
        case 'E':  return true;            
        #endif          
        
        #ifdef PORTF
        case 'F':  return true;            
        #endif          
        
        #ifdef PORTG
        case 'G':  return true;            
        #endif  
        
        #ifdef PORTH
        case 'H':  return true;
        #endif          
        
        #ifdef PORTJ
        case 'J':  return true;            
        #endif          
            
        default:break;        
    }
    return false;
}


/*!
* 	 void gpio_enable(uint32_t gpio , uint32_t gpio_options)
* 
* 	...tbd...
* 	\param uint32_t gpio -...
* 	\param uint32_t gpio_options -...
* 	\return void -...
*/
void gpio_enable(uint32_t gpio , uint32_t gpio_options)
{
    
  volatile uint32_t *tris_port = NULL;
  volatile uint32_t *rp_port = NULL;
  volatile uint32_t *lat_port = NULL;
  volatile uint32_t *ansel_port = NULL;
  
  // change notice
  volatile uint32_t *cnpu = NULL;
  volatile uint32_t *cnpd = NULL;
  volatile uint32_t *cncon = NULL;
  volatile uint32_t *cnen = NULL;
  volatile uint32_t *cnne = NULL;
  
  int  input_func=-1;;

        switch(GPIO_PORT(gpio)){
            
            #ifdef TRISA
            case('A'):       
            {                       /*0      1       2       3       4       5       6       7       8       9       10      11      12      13      14      15*/   
                const int dict[] = {-1      ,-1     ,-1     ,-1     ,-1     ,-1     ,-1     ,-1     ,-1     ,-1     ,-1     ,-1     ,-1     ,-1     ,0b1101 ,0b1101};
                tris_port = &TRISA;   
                ansel_port = &ANSELA;
                lat_port =  &LATA;
                if(GPIO_PIN(gpio)<sizeof(dict)) input_func = dict[GPIO_PIN(gpio)];
                rp_port = (&RPA14R +GPIO_PIN(gpio)-14);
                
                cnpu = &CNPUA;
                cnpd = &CNPDA;
                cncon = &CNCONA;
                cnen = &CNENA;
                cnne = &CNNEA;
            }
            break;
            #endif  

            #ifdef TRISB
            case('B'):         
            {                      /*0      1       2       3       4       5       6       7       8       9       10      11      12      13      14      15*/   
                const int dict[] = {0b0101  ,0b0101 ,0b0111 ,0b1000 ,-1     ,0b1000 ,0b0101 ,0b0111 ,0b0010 ,0b0101 ,0b0110 ,-1     ,-1     ,-1     ,0b0010 ,0b0011};
                tris_port = &TRISB;   
                ansel_port = &ANSELB;
                lat_port =  &LATB;
                
                if(GPIO_PIN(gpio)<sizeof(dict)) input_func = dict[GPIO_PIN(gpio)];
                rp_port = (&RPB0R +GPIO_PIN(gpio));
                
                cnpu = &CNPUB;
                cnpd = &CNPDB;
                cncon = &CNCONB;
                cnen = &CNENB;
                cnne = &CNNEB;
            }
            break;
            #endif
            
            #ifdef TRISC
            case('C'):
            {                      /*0      1       2       3       4       5       6       7       8       9       10      11      12      13      14      15*/
                const int dict[] = {-1      ,0b1010 ,-1     ,-1     ,0b1010 ,-1     ,-1     ,-1     ,-1     ,-1     ,-1     ,-1     ,-1     ,0b0111 ,0b0111 ,-1};
                tris_port = &TRISC;
                ansel_port = &ANSELC;
                lat_port =  &LATC;
                
                if(GPIO_PIN(gpio)<sizeof(dict)) input_func = dict[GPIO_PIN(gpio)];
                rp_port = (&RPC1R +GPIO_PIN(gpio)-1);
                
                cnpu = &CNPUC;
                cnpd = &CNPDC;
                cncon = &CNCONC;
                cnen = &CNENC;
                cnne = &CNNEC;
            }
            break;
            #endif

            #ifdef TRISD
            case('D'):
            {                      /*0      1       2       3       4       5       6       7       8       9       10      11      12      13      14      15*/
                const int dict[] = {0b0011  ,0b0000 ,0b0000 ,0b0000 ,0b0100 ,0b0110 ,0b1110 ,0b1110 ,-1     ,0b0000 ,0b0011 ,0b1011 ,0b1010 ,-1     ,0b1011 ,0b1011};
                tris_port = &TRISD;
                ansel_port = &ANSELD;
                lat_port =  &LATE;
                
                if(GPIO_PIN(gpio)<sizeof(dict)) input_func = dict[GPIO_PIN(gpio)];
                rp_port = (&RPD0R +GPIO_PIN(gpio));
                
                cnpu = &CNPUD;
                cnpd = &CNPDD;
                cncon = &CNCOND;
                cnen = &CNEND;
                cnne = &CNNED;
            }
            break;
            #endif      

            #ifdef TRISE
            case('E'):
             {                     /*0      1       2       3       4       5       6       7       8       9       10      11      12      13      14      15*/
                const int dict[] = {-1      ,-1     ,-1     ,0b0000 ,0b0100 ,0b0110 ,  -1   ,-1     ,0b1101 ,0b1101 ,0b0011 ,0b0011 ,-1     ,-1     ,-1     ,-1};
                tris_port = &TRISE;
                ansel_port = &ANSELE;
                lat_port =  &LATE;
                
                if(GPIO_PIN(gpio)<sizeof(dict)) input_func = dict[GPIO_PIN(gpio)];
                rp_port = (&RPE3R +GPIO_PIN(gpio)-3);
                
                cnpu = &CNPUE;
                cnpd = &CNPDE;
                cncon = &CNCONE;
                cnen = &CNENE;
                cnne = &CNNEE;
            }
            break;
            #endif

            #ifdef TRISF
            case('F'):
            {                         /*0       1       2       3       4       5       6       7       8       9       10      11      12      13      14      15*/
                const int8_t dict[] = {0b0100   ,0b0100 ,0b1011,0b1000 ,0b0010 ,0b0010, -1      ,-1     ,0b1011 ,-1     ,-1     ,-1     ,0b1001 ,0b1001 ,-1     ,-1};
                tris_port = &TRISF;
                ansel_port = &ANSELF;
                lat_port =  &LATF;
                
                if(GPIO_PIN(gpio)<sizeof(dict))  input_func = dict[GPIO_PIN(gpio)];
                rp_port = (&RPF0R +GPIO_PIN(gpio));
                
                cnpu = &CNPUF;
                cnpd = &CNPDF;
                cncon = &CNCONF;
                cnen = &CNENF;
                cnne = &CNNEF;
            }
            break;
            #endif

            #ifdef TRISG
            case('G'):
            {                      /*0      1       2       3       4       5       6       7      8      9       10    11      12      13      14      15*/
                const int dict[] = {0b1100  ,0b1100 ,-1     ,-1     ,-1     ,-1     ,0b0001 ,0b0001,0b0001,0b0001 ,-1   ,-1     ,-1     ,-1     ,-1     ,-1};
                tris_port = &TRISG;
                ansel_port = &ANSELG;
                lat_port =  &LATG;
                        
                if(GPIO_PIN(gpio)<sizeof(dict)) input_func = dict[GPIO_PIN(gpio)];
                rp_port = (&RPG0R +GPIO_PIN(gpio));
                
                cnpu = &CNPUG;
                cnpd = &CNPDG;
                cncon = &CNCONG;
                cnen = &CNENG;
                cnne = &CNNEG;
            }
            break;
            #endif  
        }   
        
        

        
    sys_unlock();
    
    if(gpio_options &GPIO_ANALOG)
    {                
        // if pin is analog we don;t care about digital circuit
        *ansel_port |= (1<<GPIO_PIN(gpio));        
    }
    else
    {        
        // turn off analog input and enable digital part
        *ansel_port &= ~(1<<GPIO_PIN(gpio));
        
        // it pin is peripheral output   (CUSTOM_OUTPUT)
        if(gpio_options & GPIO_IS_CUSTOM_OUTPUT){
            const uint32_t output_func = (gpio_options >>16)& (0xfff);
            *rp_port = output_func;
            *tris_port |= ((uint32_t)1 << GPIO_PIN(gpio));            
        }
        
        // if pin is peripheral input    (CUSTOM_INPUT)
        else if(gpio_options &GPIO_IS_CUSTOM_INPUT){
            const uint32_t offs = ((gpio_options >>16)& (0xfff));            
            if(input_func>=0){
                *( (volatile uint32_t*)((uint32_t)&INT1R  + offs*4)) = input_func;
            }                       
            *tris_port |= ((uint32_t)1 << GPIO_PIN(gpio));
        }
        
        // if port is some digital input output
        else {
            *rp_port =0;
            //turn on tris port
            if(gpio_options & GPIO_IN){
                 *tris_port |= ((uint32_t)1 << GPIO_PIN(gpio));
                 
                    // change notification options
                if(gpio_options & CN_ENABLE){
                    *cnen |= ((uint32_t)1 << GPIO_PIN(gpio));
                    *cncon |= (1<<15);
                }

                if(gpio_options & CN_PULLUP) {                    
                    *cnpu |= ((uint32_t)1 << GPIO_PIN(gpio));
                    *cnpd &= ~(((uint32_t)1 << GPIO_PIN(gpio)));                    
                }
                if(gpio_options & CN_PULLDOWN) {
                    *cnpu &= ~(((uint32_t)1 << GPIO_PIN(gpio)));
                    *cnpd |= ((uint32_t)1 << GPIO_PIN(gpio));
                }
                if(gpio_options & CN_INTERRUPT){
                    *cnne |= ((uint32_t)1 << GPIO_PIN(gpio));
                }
                 
            }
            else if(gpio_options & GPIO_OUT){
                // set 0 to TRIS port
                *tris_port &= ~((uint32_t)1 << GPIO_PIN(gpio));
                if(gpio_options & GPIO_OUT_HIGH)   *lat_port |= (uint32_t)1 << GPIO_PIN(gpio);
                else *lat_port &= ~((uint32_t)1 << GPIO_PIN(gpio));
            }     
        }
    }
    sys_lock();
}


/*!
* 	 void  gpio_set(uint32_t gpio, bool gpio_pin_value)
* 
* 	...tbd...
* 	\param uint32_t gpio -...
* 	\param bool gpio_pin_value -...
* 	\return void -...
*/
void  gpio_set(uint32_t gpio, bool gpio_pin_value) {
    volatile uint32_t *gpio_port = NULL;
    
        switch(GPIO_PORT(gpio)){

            #ifdef LATA
            case('A'):       
            if(gpio_pin_value == TRUE) gpio_port = &LATASET;
            else gpio_port = &LATACLR;
            break;
            #endif
            
            #ifdef LATB
            case('B'):
            if(gpio_pin_value == TRUE) gpio_port = &LATBSET;
            else gpio_port = &LATBCLR;
            break;
            #endif
            
            #ifdef LATC
            case('C'):
            if(gpio_pin_value == TRUE)  gpio_port = &LATCSET;
            else  gpio_port = &LATCCLR;
            break;
            #endif

            #ifdef LATD
            case('D'):
            if(gpio_pin_value == TRUE)  gpio_port = &LATDSET;
            else  gpio_port = &LATDCLR;
            break;            
            #endif

            #ifdef LATE
            case('E'):
            if(gpio_pin_value == TRUE) gpio_port = &LATESET;
            else gpio_port = &LATECLR;
            break;
            #endif
            
            #ifdef LATF
            case('F'):
            if(gpio_pin_value == TRUE) gpio_port = &LATFSET;
            else gpio_port = &LATFCLR;
            break;
            #endif
            
            #ifdef LATG
            case('G'):
            if(gpio_pin_value == TRUE) gpio_port = &LATGSET;
            else gpio_port = &LATGCLR;
            break;
            #endif
        }     
  *gpio_port |= ((uint32_t)1 << GPIO_PIN(gpio));
}


/*!
* 	 void  gpio_toggle(uint32_t gpio)
* 
* 	...tbd...
* 	\param uint32_t gpio -...
* 	\return void -...
*/
void  gpio_toggle(uint32_t gpio) {
    volatile uint32_t *gpio_port = NULL;
    
        switch(GPIO_PORT(gpio)){

            #ifdef LATA
            case('A'):       
            gpio_port = &LATAINV;            
            break;
            #endif
            
            #ifdef LATB
            case('B'):
            gpio_port = &LATBINV;            
            break;
            #endif
            
            #ifdef LATC
            case('C'):
            gpio_port = &LATCINV;            
            break;
            #endif

            #ifdef LATD
            case('D'):
            gpio_port = &LATDINV;            
            break;            
            #endif

            #ifdef LATE
            case('E'):
            gpio_port = &LATEINV;
            break;
            #endif
            
            #ifdef LATF
            case('F'):
            gpio_port = &LATFINV;            
            break;
            #endif
            
            #ifdef LATG
            case('G'):
            gpio_port = &LATGINV;
            break;
            #endif
        }     
  *gpio_port |= ((uint32_t)1 << GPIO_PIN(gpio));
}



/*!
* 	 bool gpio_get(uint32_t gpio)
* 
* 	...tbd...
* 	\param uint32_t gpio -...
* 	\return bool -...
*/
bool gpio_get(uint32_t gpio) {
    volatile uint32_t *gpio_port = NULL;
    uint32_t mask;
    switch(GPIO_PORT(gpio)){

        #ifdef PORTA
        case('A'):       
        gpio_port = &PORTA;
        break;
        #endif

        #ifdef PORTB
        case('B'):
        gpio_port = &PORTB;
        break;
        #endif

        #ifdef PORTC
        case('C'):
        gpio_port = &PORTC;
        break;
        #endif

        #ifdef PORTD
        case('D'):
        gpio_port = &PORTD;
        break;
        #endif

        #ifdef PORTE
        case('E'):
        gpio_port = &PORTE;
        break;
        #endif
        
        #ifdef PORTF
        case('F'):
        gpio_port = &PORTF;
        break;
        #endif

        #ifdef PORTG
        case('G'):
        gpio_port = &PORTG;
        break;  
        #endif

        default:
        break;
    }
    mask = ( 1 << GPIO_PIN(gpio));
    return ( (*gpio_port & mask) != 0 );
}



/*!
* 	  uint32_t *gpio_reg(RegType reg_type, uint32_t gpio, char set_type)
* 
* 	...tbd...
* 	\param RegType reg_type -...
* 	\param uint32_t gpio -...
* 	\param char set_type -...
* 	\return uint32_t -...
*/
volatile uint32_t *gpio_reg(RegType reg_type, uint32_t gpio, char set_type)
{           
    uint32_t offset =  0xbf860000;
    switch(GPIO_PORT(gpio))
        {
            #ifdef LATA
            case('A'):offset += 0x00;break;
            #endif            
            #ifdef LATB
            case('B'): offset += 0x100;break;
            #endif            
            #ifdef LATC
            case('C'):offset += 0x200;break;
            #endif
            #ifdef LATD
            case('D'):offset += 0x300;break;            
            #endif
            #ifdef LATE
            case('E'):offset += 0x400;break;
            #endif            
            #ifdef LATF
            case('F'):offset += 0x500;break;
            #endif            
            #ifdef LATG
            case('G'):offset += 0x600;break;
            #endif    
            default:
                return 0;
                break;
        }     
    
    
    switch(reg_type)
    {
        case     REG_ANSEL:
            offset += 0x00;
            break;
        case     REG_TRIS:
            offset += 0x10;
            break;
            
        case     REG_PORT:
            offset += 0x20;
            break;
        case     REG_LAT:
            offset += 0x30;
            break;
      
        case     REG_ODC:
            offset += 0x40;
            break;
        case     REG_CNPU:
            offset += 0x50;
            break;
        case     REG_CNPD:
            offset += 0x60;
            break;
        case     REG_CNCON:
            offset += 0x70;
            break;
        case     REG_EN:
            offset += 0x80;
            break;
        case     REG_CNSTAT:
            offset += 0x90;
            break;
        case     REG_CNEA:
            offset += 0xA0;
            break;
        case     REG_CNF:
            offset += 0xB0;
            break;
        case     REG_SRCON0A:
            offset += 0xC0;
            break;
        case     REG_SRCON1A:
            offset += 0xD0;
            break;
            
        default: return 0;
        break;
    }    
    
    if(set_type == 'c'){
        offset  +=  0x04;
    }else if(set_type == 's'){
        offset  +=  0x08;   
    }else if(set_type == 'i'){
        offset  +=  0x0C;
    }
    return (volatile uint32_t *)(offset);
}


void gpio_set_dir(uint32_t gpio, GpioDir gpio_dir){      
      if(gpio_dir == GPIO_DIR_INPUT){          
          volatile uint32_t *tris_port = gpio_reg(    REG_TRIS, gpio, 's');          
            *tris_port |= ((uint32_t)1 << GPIO_PIN(gpio));       
      }
      else {          
          volatile uint32_t *tris_port = gpio_reg(    REG_TRIS, gpio, 'c');
          *tris_port |= ((uint32_t)1 << GPIO_PIN(gpio));  
      }
}

GpioDir gpio_direction(uint32_t gpio){
    volatile uint32_t *tris_port = gpio_reg(    REG_TRIS,  gpio,'r');
    if(*tris_port  & ((uint32_t)1 << GPIO_PIN(gpio)) ) return GPIO_DIR_INPUT;
    else return GPIO_DIR_OUTPUT;
}