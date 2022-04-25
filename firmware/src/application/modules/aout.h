#ifndef AOUT_H
#define AOUT_H
#include "typedef_global.h"


bool aout_conf(int channel, char *ptext);
bool aout_set(int channel, uint32_t value);
uint32_t aout_value(int channel);

#endif