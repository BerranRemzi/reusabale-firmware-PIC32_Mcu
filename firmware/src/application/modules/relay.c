/*!
* @file modules\relay.c
* @author D.Chikov
* @date 10/15/2020, 10:24:38
* @brief ...tbd...
*/


#include "system.h"
#include "relay.h"


static uint8_t _out_buf[4];
static uint8_t _in_buf[4];

static uint32_t gpio_clk = GPIO('A',4);
static uint32_t gpio_mosi = GPIO('A',2);
static uint32_t gpio_miso = GPIO('A',3);
static uint32_t gpio_wr = GPIO('F',12);

static uint32_t _chip_type;
static uint32_t _chip_count; // one chip is always 8 bit



/*!
* 	 void _send_byte(uint8_t byte_out, uint8_t *pbyte_in)
* 
* 	...tbd...
* 	\param uint8_t byte_out -...
* 	\param uint8_t *pbyte_in -...
* 	\return void -...
*/
void _send_byte(uint8_t byte_out, uint8_t *pbyte_in);


/*!
* 	 bool relay_conf(ChipType chip_type, int32_t chip_count)
* 
* 	...tbd...
* 	\param ChipType chip_type -...
* 	\param int32_t chip_count -...
* 	\return bool -...
*/
bool relay_conf(ChipType chip_type, int32_t chip_count) {
    if (chip_count > 0 && chip_count < 4) {
        _chip_type = chip_type;
        _chip_count = chip_count;
        // configure pins
        gpio_enable(gpio_clk, GPIO_OUT | GPIO_OUT_HIGH);
        gpio_enable(gpio_mosi, GPIO_OUT| GPIO_OUT_HIGH);
        gpio_enable(gpio_miso, GPIO_IN);
        gpio_enable(gpio_wr, GPIO_OUT | GPIO_OUT_HIGH);
        return true;
    }
    return false;
}


/*!
* 	 bool relay_set(int32_t relay_out, bool value)
* 
* 	...tbd...
* 	\param int32_t relay_out -...
* 	\param bool value -...
* 	\return bool -...
*/
bool relay_set(int32_t relay_out, bool value) {
    int32_t i;
    uint8_t bit_mask;    
    gpio_enable(gpio_clk, GPIO_OUT | GPIO_OUT_HIGH);
    gpio_enable(gpio_mosi, GPIO_OUT);
    gpio_enable(gpio_miso, GPIO_IN);
    gpio_enable(gpio_wr, GPIO_OUT | GPIO_OUT_HIGH);
    if (relay_out > 0 && (relay_out <= (_chip_count * 8))) {
        //load to chip
        relay_out--;

        switch (_chip_type) {

            case CHIP_AMIS39100:
                bit_mask = 1 << ( relay_out%8);
                const int idx = _chip_count- (relay_out / 8) - 1;
                _out_buf[idx] &= ~bit_mask; //clear
                if (value == true) {
                    _out_buf[idx] |= bit_mask;
                }//set
                
                gpio_set(gpio_wr,0);
                for (i = 0; i < _chip_count; i++) {
                    _send_byte(0x00, NULL); //dummy
                    _send_byte(_out_buf[i], &_in_buf[i]);
                }
                gpio_set(gpio_wr,1);                
                break;

            case CHIP_74HC595:{
                bit_mask = 1 << ( 7-(relay_out%8));
                const int idx = _chip_count- relay_out / 8 - 1;
                _out_buf[idx] &= ~bit_mask; //clear
                if (value == true) {
                    _out_buf[idx] |= bit_mask;
                }//set
        
                for (i = 0; i < _chip_count; i++) {
                    _send_byte(_out_buf[i], &_in_buf[i]);
                }
                // actualy WR here is latch
                gpio_set(gpio_wr, 0);
                gpio_set(gpio_wr, 1);
                gpio_set(gpio_wr, 0);
            }
                break;

        }
        return true;
    }
    printf("(bad index)");
    return false;
}


/*!
* 	 bool relay_get(int32_t relay_out)
* 
* 	...tbd...
* 	\param int32_t relay_out -...
* 	\return bool -...
*/
bool relay_get(int32_t relay_out) {         
    if (relay_out > 0 && (relay_out <= (_chip_count * 8))) 
    {
        relay_out--;   
        switch(_chip_type){
            case CHIP_AMIS39100:{                                
                const int idx = _chip_count- (relay_out / 8) - 1;                
                return (_out_buf[idx] >> (relay_out % 8) ) & 1;     
            }
            break;
            case CHIP_74HC595:{                              
                const int idx = _chip_count- (relay_out / 8) - 1;                
                return (_out_buf[idx] >> (relay_out % 8) ) & 1;
            }
            break;
        }           
    }    
    printf("(bad index)");
    return 0;
}


/*!
* 	 void _send_byte(uint8_t byte_out, uint8_t *pbyte_in)
* 	Sending from LSB
* 	\param uint8_t byte_out -...
* 	\param uint8_t *pbyte_in -...
* 	\return void -...
*/
void _send_byte(uint8_t byte_out, uint8_t *pbyte_in) {
    int32_t bits = 8;
    int i=0;
    uint8_t byte_in = 0;
    while (bits--) {
        gpio_set(gpio_clk,0);
        for(i=0;i<50;i++) {Nop();Nop();Nop();Nop();Nop();Nop();}
        byte_in |= (gpio_get(gpio_miso) << 8) >> bits;
        if (byte_out & 1) {
            gpio_set(gpio_mosi,1);
        } else {
            gpio_set(gpio_mosi,0);
        }
        byte_out >>= 1;
        gpio_set(gpio_clk,1);
        for(i=0;i<50;i++) {Nop();Nop();Nop();Nop();Nop();Nop();}
    }
    if (pbyte_in) {
        *pbyte_in = byte_in;
    }
}
