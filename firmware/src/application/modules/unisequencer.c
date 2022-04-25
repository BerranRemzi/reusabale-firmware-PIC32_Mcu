/*!
* @file modules\unisequencer.c
* @author D.Chikov
* @date 10/19/2020, 11:51:15
* @brief ...tbd...
*/


// SEQUENCER
// format
// first symbol is number of signals max 4
// following 1..4 time xx - is DIO number
// the rest is stream for a format refer to documentation


#include "app.h"
#include "unisequencer.h"
#include "system.h"
#include "string_utils.h"
#include "chrono.h"
#include "dio.h"

typedef struct {
    uint8_t op;
    volatile uint32_t * addr;
    uint32_t arg;
} Operation;

typedef struct {
    uint8_t op;
    uint32_t res;
} Result;


static Operation *operations; // = (Operation *)&function_out[0];
static Operation *p_cur_op;
static uint32_t total_op = 0;

static Result *results=0; // = (Result*)&function_in[0];
static uint32_t total_res = 0;

static bool fail;
static bool stop_end;
static uint32_t last_read;

static uint32_t repeat_count = 0;
static Operation *repeat_goto;

static struct{
    uint32_t timing;
    uint32_t gpio_port_count;
    uint32_t gpio_port[5];
    bool configured;
}setup={0};

enum {
    SKIP
    , TURN_INPUT
    , TURN_OUTPUT    
    , CAPTURE_8Bit
    , CAPTURE_16bit
    , SET_HIGH
    , SET_LOW
    , TOGGLE
    , READ
    , BEGIN
    , END
    , REPEAT
    , WAIT_LL
    , WAIT_HL
    , WAIT_LE
    , WAIT_HE
    , LAST_READ
    , STOP
};


/*!
* 	  void addOperation(uint8_t op, volatile uint32_t* addr, uint32_t arg)
* 
* 	...tbd...
* 	\param uint8_t op -...
* 	\param volatile uint32_t* addr -...
* 	\param uint32_t arg -...
* 	\return void -...
*/
inline static void addOperation(uint8_t op, volatile uint32_t* addr, uint32_t arg) {
    operations[total_op].op = op;
    operations[total_op].addr = (volatile uint32_t*) addr;
    operations[total_op].arg = arg;
    total_op++;
}


/*!
* 	  void addResult(uint8_t op, uint32_t res)
* 
* 	...tbd...
* 	\param uint8_t op -...
* 	\param uint32_t res -...
*/
inline static void addResult(uint8_t op, uint32_t res) {
    results[total_res].op = op;
    results[total_res].res = res;
    total_res++;
}


bool unisequencer_conf(const char *ptext)
{
    char *item = 0;
    int n = 0;    
    setup.gpio_port_count =0;
    
    FOREACH_BEGIN(item, ptext,  ',')
    {
        switch (n)
        {
            case 0:
                setup.timing = StrToUInt(item);                
                if(setup.timing==0 || setup.timing>1000){
                    printf("(error configure timing)");
                    return false;
                }
                break;

            case 1:
            case 2:
            case 3:
            case 4:                            
            if(item[0] == 'D' && item[1] == 'I' && item[2] == 'O')
            {                
                    const int dio = StrToUInt( &item[3]);
                    if(DIO_Valid(dio)){
                        setup.gpio_port[setup.gpio_port_count++] =  dio_table[dio];            
                        setup.configured=1;
                    }
                    else {
                        printf("(error dio)");
                        setup.configured=0;
                        return 0;
                    }

            }            
            break;
            
            default:break;
        }
        n++;
    }
   FOREACH_END(item);	  
   
   return setup.gpio_port_count>0;
   
}

/*!
* 	  void signal1(uint32_t n, uint32_t *pi, const uint8_t *ppin)
* 
* 	...tbd...
* 	\param uint32_t n -...
* 	\param uint32_t *pi -...
* 	\param const uint8_t *ppin -...
*/
static void signal1(uint32_t n, uint32_t *pi, const uint8_t *ppin) {
    char c = ppin[*pi];
    if (c == '1') {
        volatile uint32_t *pport = gpio_reg(REG_LAT, setup.gpio_port[n], 's');
        uint32_t mask = (1 << (setup.gpio_port[n] % 32));
        addOperation(SET_HIGH, pport, mask);
        (*pi)++;
    } else if (c == '0') {
        volatile uint32_t *pport = gpio_reg(REG_LAT, setup.gpio_port[n], 'c');
        uint32_t mask = (1 << (setup.gpio_port[n] % 32));
        addOperation(SET_LOW, pport, mask);
        (*pi)++;
    } else if (c == '2') {
        volatile uint32_t *pport = gpio_reg(REG_LAT, setup.gpio_port[n], 'i');
        uint32_t mask = (1 << (setup.gpio_port[n] % 32));
        addOperation(TOGGLE, pport, mask);
        (*pi)++;
    } else if (c == 'r') {
        volatile uint32_t *pport = gpio_reg(REG_PORT, setup.gpio_port[n], 0);
        uint32_t mask = (1 << (setup.gpio_port[n] % 32));
        addOperation(READ, pport, mask);
        (*pi)++;
    } else if (c == 'h') {
        volatile uint32_t *pport = gpio_reg(REG_PORT, setup.gpio_port[n], 0);
        uint32_t mask = (1 << (setup.gpio_port[n] % 32));
        addOperation(WAIT_HL, pport, mask);
        (*pi)++;
    } else if (c == 'l') {
        volatile uint32_t *pport = gpio_reg(REG_PORT, setup.gpio_port[n], 0);
        uint32_t mask = (1 << (setup.gpio_port[n] % 32));
        addOperation(WAIT_LL, pport, mask);
        (*pi)++;
    } else if (c == 'H') {
        volatile uint32_t *pport = gpio_reg(REG_PORT, setup.gpio_port[n], 0);
        uint32_t mask = (1 << (setup.gpio_port[n] % 32));
        addOperation(WAIT_HE, pport, mask);
        (*pi)++;
    } else if (c == 'L') {
        volatile uint32_t *pport = gpio_reg(REG_PORT, setup.gpio_port[n], 0);
        uint32_t mask = (1 << (setup.gpio_port[n] % 32));
        addOperation(WAIT_LE, pport, mask);
        (*pi)++;
    }
    else if (c == 'm') {
        volatile uint32_t *pport = gpio_reg(REG_PORT, setup.gpio_port[n], 0);
        uint32_t mask = (1 << (setup.gpio_port[n] % 32));
        addOperation(LAST_READ, pport, mask);
        (*pi)++;
    }
    else if (c == 'i') {
        volatile uint32_t *pport = gpio_reg(REG_TRIS, setup.gpio_port[n], 's');
        uint32_t mask = (1 << (setup.gpio_port[n] % 32));
        addOperation(TURN_INPUT, pport, mask);
        (*pi)++;
    } else if (c == 'o') {
        volatile uint32_t *pport = gpio_reg(REG_TRIS, setup.gpio_port[n], 'c');
        uint32_t mask = (1 << (setup.gpio_port[n] % 32));
        addOperation(TURN_OUTPUT, pport, mask);
        (*pi)++;
    } else {
        (*pi)++;
    }

}


/*!
* 	  int32_t compile(const uint8_t* pin)
* 
* 	...tbd...
* 	\param const uint8_t* pin -...
* 	\return int32_t -...
*/
static int32_t compile(const uint8_t* pin) {
    uint32_t i = 0, j = 0;

    while (pin[i] != '\0') {
        // remove { } , symbols
        if (pin[i] == '{' || pin[i] == '}' || pin[i] == '.' || pin[i] == ',') {
            i++;
        } else if (pin[i] == 'w') {
            int nop_count=100;
            while(nop_count--)  {addOperation(SKIP, 0, 0);}
            i++;
        } else if (pin[i] == 'u') {
            int nop_count=10;
            while(nop_count--)  {addOperation(SKIP, 0, 0);}
            i++;
        } else if (pin[i] == 'p') {
            uint32_t time = (pin[i + 1] - '0')*100 + (pin[i + 2] - '0')*10 + (pin[i + 3] - '0');
            int nop_count = time;
            while(nop_count--)  {addOperation(SKIP, 0, 0);}            
            i += 4;
        } else if (pin[i] == 'c') {
            repeat_count = (pin[i + 1] - '0')*1000 + (pin[i + 2] - '0')*100 + (pin[i + 3] - '0')*10 + (pin[i + 4] - '0') - 1;
            i += 5;
            addOperation(REPEAT, 0, 0);
        } else if (pin[i] == 't') {
            //uint32_t time = CHRONO1_ELAPSED();  
            addOperation(CAPTURE_8Bit, 0, 0);
            i++;
        } else if (pin[i] == 'T') {
            //uint32_t time = CHRONO1_ELAPSED();
            addOperation(CAPTURE_16bit, 0, 0);
            i++;
        }
        else if (pin[i] == '[') {
            i++;
            addOperation(BEGIN, 0, 0);
        } else if (pin[i] == ']') {
            i++;
        }
            // set signal
        else {
            j = 0;
            switch (setup.gpio_port_count) {
                case 4:
                    signal1(j++, &i, pin);
                case 3:
                    signal1(j++, &i, pin);
                case 2:
                    signal1(j++, &i, pin);
                case 1:
                    signal1(j++, &i, pin);
                    break;
            }
        }
    }
    addOperation(STOP, 0, 0);
    return total_op;
}


/*!
* 	  void makeResult()
* 
* 	...tbd...
*/
static void makeResult() {
    uint32_t value;
    uint32_t i, j;
    uint32_t bit_n = 0;
    for (i = 0; i < total_res; i++) {
        switch (results[i].op) {
            case CAPTURE_8Bit:
                value = results[i].res;
                application_data[bit_n / 8] = 0;
                for (j = 0; j < 8; j++) {
                    application_data[bit_n / 8] |= (((value & (1 << j)) != 0) << (bit_n % 8));
                    bit_n++;
                }
                break;

            case CAPTURE_16bit:
                value = results[i].res;
                application_data[bit_n / 8] = 0;
                application_data[bit_n / 8 + 1] = 0;
                for (j = 0; j < 16; j++) {
                    application_data[bit_n / 8] |= (((value & (1 << j)) != 0) << (bit_n % 8));
                    bit_n++;
                }
                break;

            case READ:
                if ((bit_n % 8) == 0) application_data[bit_n / 8] = 0;
                application_data[bit_n / 8] |= (((results[i].res) != 0) << (bit_n % 8));
                bit_n++;
                break;
        }
    }
    app_result_count = bit_n / 8 + ((bit_n % 8) > 0);
}


/*!
* 	  void executeNextOperation()
* 
* 	...tbd...
*/
inline static void executeNextOperation() {
    //	int i;
    switch (p_cur_op->op) {
        case SKIP:
            break;
    

        case CAPTURE_8Bit:
        case CAPTURE_16bit:
            addResult(p_cur_op->op, CHRONO1_ELAPSED());
            break;

        case TURN_OUTPUT:
        case TURN_INPUT:
        case SET_HIGH:
        case SET_LOW:
        case TOGGLE:
            *(p_cur_op->addr) = p_cur_op->arg;
            break;

        case READ:
            //argument is pin mask
            addResult(p_cur_op->op, *(p_cur_op->addr) & p_cur_op->arg);
            break;

        case BEGIN:
            repeat_goto = p_cur_op;
            break;

        case REPEAT:
            if (repeat_count == 0) {
                break;
            } else {
                repeat_count--;
                if (repeat_goto != 0)
                    p_cur_op = repeat_goto;
            }
            break;

        case WAIT_LL:
            CHRONO2_SET_TIMEOUT(100000); //100 ms timeout
            CHRONO2_START();
            while ((*(p_cur_op->addr) & p_cur_op->arg) != 0) {
                if (CHRONO2_IS_TIMEOUT()) {
                    stop_end = 1;
                    fail = true;
                    break;
                }
            }
            CHRONO2_STOP();
            break;

        case WAIT_HL:
            CHRONO2_SET_TIMEOUT(100000); // 100 ms timeout
            CHRONO2_START();
            while ((*(p_cur_op->addr) & p_cur_op->arg) == 0) {
                if (CHRONO2_IS_TIMEOUT()) {
                    stop_end = 1;
                    fail = true;
                    break;
                }
            }
            CHRONO2_STOP();
            break;

        case WAIT_LE:
            CHRONO2_SET_TIMEOUT(100000); // 100 ms timeout
            CHRONO2_START();
            while ((*(p_cur_op->addr) & p_cur_op->arg) == 0) {
                if (CHRONO2_IS_TIMEOUT()) {
                    stop_end = 1;
                    fail = true;
                    break;
                }
            }
            while ((*(p_cur_op->addr) & p_cur_op->arg) != 0) {
                if (CHRONO2_IS_TIMEOUT()) {
                    stop_end = 1;
                    fail = true;
                    break;
                }
            }
            CHRONO2_STOP();
            break;

        case WAIT_HE:
            CHRONO2_SET_TIMEOUT(100000); //100 ms timeout
            CHRONO2_START();
            while ((*(p_cur_op->addr) & p_cur_op->arg) != 0) {
                if (CHRONO2_IS_TIMEOUT()) {
                    stop_end = 1;
                    fail = true;
                    break;
                }
            }
            while ((*(p_cur_op->addr) & p_cur_op->arg) == 0) {
                if (CHRONO2_IS_TIMEOUT()) {
                    stop_end = 1;
                    fail = true;
                    break;
                }
            }
            CHRONO2_STOP();
            break;

        case LAST_READ:
            *(p_cur_op->addr) |= ((last_read != 0) ? p_cur_op->arg : 0);
            break;


        case STOP:
            stop_end = 1;
            break;
    }
    p_cur_op++;
}


/*!
* 	 bool function_sequence(const char *ptext)
* 
* 	...tbd...
* 	\param const char *ptext -...
* 	\return bool -...
*/
bool unisequencer_execute(const char *ptext) {
    operations = (Operation *) & application_data[0];
    results = (Result*) & application_data[250000];

    fail = false;
    stop_end = 0;
    total_res = 0;
    total_op = 0;
    
    if(!setup.configured) {
        printf("(need to be configured first)");    
        return false;
    }
    
    compile((const uint8_t*) ptext);

    p_cur_op = &operations[0];
        
    
    //main process	
    CHRONO2_SET_TIMEOUT_TICKS(setup.timing);
    CHRONO2_START();
    
    while (!CHRONO2_IS_TIMEOUT());
        CHRONO2_RESTART();
        
    while (!stop_end) {        
        while (!CHRONO2_IS_TIMEOUT());
        CHRONO2_RESTART();
        executeNextOperation();
        
    }

    //prepare data
    makeResult();
    if (fail) return false;
    return true;
}


/*!
* 	 define ADD(arr,bit_n) arr[bit_n/8] = (1<<bit_n%8)
* 
* 	...tbd...
* 	\param arr -...
* 	\param bit_n) arr[bit_n/8] = (1<<bit_n%8 -...
* 	\return define -...
*/
//#define ADD(arr,bit_n) arr[bit_n/8] = (1<<bit_n%8)


/*!
* 	 bool function_sequence_result()
* 
* 	...tbd...
* 	\return bool -...
*/
bool unisequencer_result() {
    bool result = false;
    if (app_result_count > 0)
    {
        PRINTF("sequence=");
        int i=0;
        for(;i<application_data[i];i++){
            PRINTF("%02x",application_data[i]);
        }
        result = true;
        PRINTF(":%d",app_result_count);
    }
    return result;

}
