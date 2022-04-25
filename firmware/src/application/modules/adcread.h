#ifndef FUNC_ADC_H
#define FUNC_ADC_H

#include "typedef_global.h"
#include "compiler.h"

#define FUNC_ADCREAD    (11)

bool function_adcread(const char *ptext);
bool function_adcread_result(char *ptext,int index);

#endif