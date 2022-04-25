/*!
* @file adc.c
* @author D.Chikov
* @date 10/15/2020, 09:37:33
* @brief ADC control driver
*/


#include <xc.h>
#include <sys/attribs.h>
#include "adc.h"
#include "system.h"



#define ANALOG_INPUTS_COUNT             (45u)
uint32_t analog_inputs[ANALOG_INPUTS_COUNT];




/*!
* 	 ResultError_t adc_init(const int adc_channels[], uint32_t options, AdcTrgSource trg_sorce)
* 
* 	...tbd...
* 	\param const int adc_channels[] - zero ended list of channels to init
* 	\param uint32_t options - options for ADC channel (see header)
* 	\param AdcTrgSource trg_sorce - trigger sources for ADC channel ( see header)
* 	\return ResultError_t - RESULT_NO_ERROR - if success
*/
ResultError_t adc_init(const int adc_channels[], uint32_t options, AdcTrgSource trg_sorce){

  ResultError_t result =RES_ERROR;

    ADC0CFG = DEVADC0;
    ADC1CFG = DEVADC1;
    ADC2CFG = DEVADC2;
    ADC3CFG = DEVADC3;
    ADC4CFG = DEVADC4;
    ADC7CFG = DEVADC7;

    /* [ ADCCON1 ]*/
    ADCCON1 =0;
    ADCCON1bits.SELRES = 3; // ADC7 resolution is 12 bits
    ADCCON1bits.STRGSRC = (uint32_t)trg_sorce; // TMR1

    /*[ ADCCON2 ]*/
    ADCCON2 =0;
    ADCCON2bits.SAMC = 5; // ADC7 sampling time = 5 * TAD7
    ADCCON2bits.ADCDIV = 1; // ADC7 clock freq is half of control clock = TAD7

    /* [ADCANCON] */
    ADCANCON = 0;
    ADCANCONbits.WKUPCLKCNT = 5; // Wakeup exponent = 32 * TADx

    /* [ADCCON3] */
    ADCCON3 = 0;
    ADCCON3bits.ADCSEL = 0; // Select input clock source
    ADCCON3bits.CONCLKDIV = 1; // Control clock frequency is half of input clock
    ADCCON3bits.VREFSEL = 0; // Select AVDD and AVSS as reference source

    /* [ADCTRGMODE]  */
    ADCTRGMODE = 0;

    /* [ADCIMCON1] */
    ADCIMCON1=0;
    ADCIMCON2=0;
    ADCIMCON3=0;

    /* [ADCGIRQENx] */
    ADCGIRQEN1 = 0; // No interrupts are used
    ADCGIRQEN2 = 0;

    /* [ADCCSSx] */
    ADCCSS1 = 0; // No scanning is used
    ADCCSS2 = 0;

    /* [ADCCMPCONx] */
    ADCCMPCON1 = 0; // No digital comparators are used. Setting the ADCCMPCONx
    ADCCMPCON2 = 0; // register to '0' ensures that the comparator is disabled.
    ADCCMPCON3 = 0; // Other registers are ?don't care?.
    ADCCMPCON4 = 0;
    ADCCMPCON5 = 0;
    ADCCMPCON6 = 0;

    /* [ADCCMPENx] */
    ADCCMPEN2 = 0;
    ADCCMPEN3 = 0;
    ADCCMPEN1 = 0;
    ADCCMPEN4 = 0;
    ADCCMPEN5 = 0;
    ADCCMPEN6 = 0;

    /* [ADCCMPx]*/
    ADCCMP1=0;
    ADCCMP2=0;
    ADCCMP3=0;
    ADCCMP4=0;
    ADCCMP5=0;
    ADCCMP6=0;

    /* [ADCFLTRx] */
    ADCFLTR1 = 0; // No oversampling filters are used.
    ADCFLTR2 = 0;
    ADCFLTR3 = 0;
    ADCFLTR4 = 0;
    ADCFLTR5 = 0;
    ADCFLTR6 = 0;

    /* [ADCEIENx] */
    ADCEIEN1 = 0; // No early interrupt
    ADCEIEN2 = 0;

    /* [ADCTRGSNS] */
    ADCTRGSNS=0;

    /* [ADCSYSCFG0] */
    /* [ADCCSSx]    */
      int i=0;
      for(;i<ANALOG_INPUTS_COUNT;i++)
      {
          if(adc_channels[i]<0) break;
          else if( adc_channels[i]< 32)
          {
              ADCSYSCFG0 |= (1<<adc_channels[i]);
              ADCCSS1 |= (1<<adc_channels[i]);
          }else{
              ADCSYSCFG1 |= (1<<(adc_channels[i]/32) );
              ADCCSS2 |= (1<<(adc_channels[i]/32) );
          }
          analog_inputs[i] = adc_channels[i];
      }    

    /*[ Turn the ADC on ] */
    ADCCON1bits.ON = 1;

    /* [ Wait for voltage reference to be stable ]*/
    while(!ADCCON2bits.BGVRRDY); // Wait until the reference voltage is ready
    while(ADCCON2bits.REFFLT); // Wait if there is a fault with the reference voltage

    /* [ Enable clock to analog circuit ] */
    ADCANCONbits.ANEN7 = 1;


    /* Wait for ADC to be ready */
    while(!ADCANCONbits.WKRDY7); // Wait until ADC7 is ready

    /* Enable the ADC module */
    ADCCON3bits.DIGEN7 = 1; // Enable ADC7    
    result = RES_NO_ERROR;
    return result;
}


/*!
* 	 void adc_configure_interrupt(uint32_t channel, uint32_t opt)
* 
* 	configure ADC interrupt
* 	\param uint32_t channel -
* 	\param uint32_t opt -
*/
void adc_configure_interrupt(uint32_t channel, uint32_t opt){
    
    // TODO
    
}


/*!
* 	 ResultError_t adc_read(uint32_t channel, uint32_t *pvalue)
* 
* 	This function reads ADC channel value
* 	\param uint32_t channel - channel number (see header file)
* 	\param uint32_t *pvalue - pointer to variable 
* 	\return ResultError_t - RESULT_NO_ERROR - if success
*/
ResultError_t adc_read(uint32_t channel, uint32_t *pvalue){
    ResultError_t result = RES_ERROR;
   
  if(channel < ANALOG_INPUTS_COUNT && pvalue != 0 ){             
    *pvalue = *(&ADCDATA0 + analog_inputs[channel]);
    return RES_NO_ERROR;
  }
  return result;
}


/*!
* 	 void adc_trigger_measure()
* 
* 	This function makes software triugger to start ADC measure
*/
void adc_trigger_measure(){
    ADCCON3bits.GLSWTRG =0;
    ADCCON3bits.GLSWTRG =1;
}


/*!
* 	 bool adc_result_available(uint32_t channel)
* 
* 	This function is for checking if result is already available
* 	\param uint32_t channel - channel number
* 	\return bool - if ADC result available return true
*/
bool adc_result_available(uint32_t channel){
    const uint32_t an = analog_inputs[channel];    
    if(an <32u){
        return (ADCDSTAT1&(1<<an)) !=0;
    }else{
        return (ADCDSTAT2&(1<<(an/32u))) !=0;
    }
}
