
#include "typedef_global.h"
#include "app.h"
#include "system.h"
#include "chrono.h"
#include "intadc.h"
#include "wdt.h"
#include "dio.h"
#include "string_utils.h"





#define ENABLE(V) do{  gpio_set(gpio_enable,V);}while(0)

#define DATA() gpio_get(gpio_data)

#define SCK(V)do{ gpio_set(gpio_sck,V);}while(0)

#define SCK_TGL() gpio_toggle(gpio_sck);

static uint16_t *pdata;

bool intadc_read(const char *ptext) {
    bool result = 0;
    int i, n = 0;
    char *item = 0;
    uint32_t gpio_enable = 0;
    uint32_t gpio_data = 0;
    uint32_t gpio_sck = 0;
    uint32_t delay = 0;
    uint32_t count = 0;
    uint32_t word_size=16;
    bool ok = 0;


    app_result_count = 0;

    // parameters parse

    FOREACH_BEGIN(item, ptext, ',') {
        switch (n) {
            case 0:
            {
                const int dio = StrToUInt(&item[3]);                 
                if (DIO_Valid(dio)) {
                    gpio_enable = dio_table[ dio ];
                }
            }
                break;

            case 1:
            {
                const int dio = StrToUInt(&item[3]);
                if (DIO_Valid(dio)) {
                    gpio_sck = dio_table[ dio ];
                }
            }
                break;

            case 2:
            {
                const int dio = StrToUInt(&item[3]);
                if (DIO_Valid(dio)) {
                    gpio_data = dio_table[ dio ];
                }
            }
                break;

            case 3:
                delay = StrToUInt(item);
                if (delay <0 || delay > CHRONO1_MAX) {
                    printf("(error delay)");
                    return 0;
                }
                break;

            case 4:
                count = StrToUInt(item);
                // some limitation 
                // 25000 = 50000bytes
                if (count<=0 && count > 25000) {
                    printf("(error data count 1..25000)");
                    return 0;
                }
                break;
                
            case 5:
                word_size = StrToUInt(item);                
                if (word_size<7 && word_size > 50) {
                    printf("(error word size 7..50)");
                    return 0;
                }
                ok = true;
                break;
            default:
                break;
        }
        n++;
    }
    FOREACH_END(item);

    // set pointer to data
    pdata = (uint16_t*) & application_data[0];
    
   
    if(ok == 1)
    {
        SCK(0);
        int j;
        for (i = 0; i < count; i++) {
            ENABLE(1);
            CHRONO1_DELAY(1);
            CHRONO1_SET_TIMEOUT(1);
            pdata[i] = 0;
            for (j = 0; j < word_size; j++) {
                pdata[i] |= (DATA() << (word_size-1- j));
                SCK(1);
                CHRONO1_START();
                while (!CHRONO1_IS_TIMEOUT());

                SCK(0);
                CHRONO1_START();
                while (!CHRONO1_IS_TIMEOUT());
            }
            ENABLE(0);

            // clear watch dog timer
            // may take longer time
            clearWdt();

            result = 1;

            // delay between packets
            if (delay > 0) {
                CHRONO1_DELAY(delay);
            }
        }

        app_result_count = i;
    }

    return result;
}

bool intadc_result(int index) {
    bool result = false;
    printf("=");
    if (app_result_count > 0 && (index * 100) < app_result_count) {
        int i = 0;
        int remains = app_result_count - (index * 100);
        remains = remains > 100 ? 100 : remains;
        for (; i < remains; i++) {
            printf("%04x", pdata[index * 100 + i]);
        }
        result = true;
    }
    return result;

}
