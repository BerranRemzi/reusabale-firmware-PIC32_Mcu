#ifndef AIN_H
#define AIN_H
#include "typedef_global.h"




typedef enum{
    AIN1,
    AIN2,
    AIN3,
    AIN4
}AnalogInput;

bool ain_conf(AnalogInput input_number, char *ptext);
uint32_t ain_read(AnalogInput input_number);

#endif