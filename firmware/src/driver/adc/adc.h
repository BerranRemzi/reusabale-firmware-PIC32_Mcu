/*!
* @file adc.h
* @author D.Chikov
* @date 10/15/2020, 09:37:33
*/



#ifndef ADC_H
#define ADC_H

#include "typedef_global.h"

typedef enum{
    ADC_SRC_COUT2=12,
    ADC_SRC_COUT1=11,
    ADC_SRC_OCMP5=10,
    ADC_SRC_OCMP3=9,
    ADC_SRC_OCMP1=8,
    ADC_SRC_INT0 =4,
    ADC_SRC_TIMER5 =7,
    ADC_SRC_TIMER3 = 6,
    ADC_SRC_TIMER1 =5,
    ADC_SRC_SOFTWARE_EDGE =1,
    ADC_SRC_SOFTWARE_LEVEL =2,
    ADC_SRC_NO_TRG =0            
}AdcTrgSource;

/*!
* ADC initialization
*/
ResultError_t adc_init(const int adc_channels[], uint32_t options, AdcTrgSource trg_sorce);

/*!
* ADC readout value
*/
ResultError_t adc_read(uint32_t chan, uint32_t *pvalue);

/*!
* ADC software trigger
*/
void adc_trigger_measure();

/*!
* ADC configure interrupt
*/
void adc_configure_interrupt(uint32_t channel, uint32_t opt);

/*!
* check ADC result available
*/
bool adc_result_available(uint32_t channel);

/*!
* dummy
*/
void adc_dummy();

#endif