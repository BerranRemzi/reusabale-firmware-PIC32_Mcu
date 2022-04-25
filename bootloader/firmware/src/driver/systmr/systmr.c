/*!
* @file systmr\systmr.c
* @author D.Chikov
* @date 10/15/2020, 09:37:33
* @brief ...tbd...
*/


#include "systmr.h"
#include <xc.h>
#include "board.h"
#include "system_config.h"




/*!
* 	 void systmr1_interrupt_enable(bool enable, uint32_t priority, uint32_t sub_priority)
* 
* 	...tbd...
* 	\param bool enable -...
* 	\param uint32_t priority -...
* 	\param uint32_t sub_priority -...
* 	\return void -...
*/
void systmr1_interrupt_enable(bool enable, uint32_t priority, uint32_t sub_priority){
    IEC0bits.T1IE = enable;
    IPC1bits.T1IP = priority;
    IPC1bits.T1IS = sub_priority;
}


/*!
* 	 void systmr1_interrupt_disable()
* 
* 	...tbd...
* 	\return void -...
*/
void systmr1_interrupt_disable(){
    systmr1_interrupt_enable(1,0,0);
}


/*!
* 	 void systmr1_enable( SysTmrA_Prescaler prescaler, uint32_t period)
* 
* 	...tbd...
* 	\param SysTmrA_Prescaler prescaler -...
* 	\param uint32_t period -...
* 	\return void -...
*/
void systmr1_enable( SysTmrA_Prescaler prescaler, uint32_t period){
    T1CON=0;
    T1CONbits.TCKPS = (const uint32_t)prescaler; 
    TMR1=0;
    T1CONbits.ON = 1;
    PR1=period;
    IFS0bits.T1IF =0;   
}


/*!
* 	 void systmr1_disable()
* 
* 	...tbd...
* 	\return void -...
*/
void systmr1_disable(){
    T1CON = 0;    
}


/*!
* 	 void systmr1_clear_flag()
* 
* 	...tbd...
* 	\return void -...
*/
void systmr1_clear_flag(){
    IFS0bits.T1IF =0;
}


/*!
* 	 uint32_t systmrB_freq(TimerB num)
* 
* 	...tbd...
* 	\param TimerB num -...
* 	\return uint32_t -...
*/
uint32_t systmrB_freq(TimerB num){
    const uint32_t pbdiv = PB3DIVbits.PBDIV+1;
    const uint32_t div[]={1,8,64,256};
    switch(num)
    {
        case TIMER2_TIMER3:   return SYS_CLK_FREQ/pbdiv/(div[T3CONbits.TCKPS]) /((uint32_t)PR2|PR3<<16);
        case TIMER3:          return SYS_CLK_FREQ/pbdiv/(div[T3CONbits.TCKPS]) /((uint32_t)PR3);
        case TIMER2:          return SYS_CLK_FREQ/pbdiv/(div[T2CONbits.TCKPS]) /((uint32_t)PR2);                         
        case TIMER4_TIMER5:   return SYS_CLK_FREQ/pbdiv/(div[T5CONbits.TCKPS]) /((uint32_t)PR4|PR5<<16);
        case TIMER4:          return SYS_CLK_FREQ/pbdiv/(div[T4CONbits.TCKPS]) /((uint32_t)PR4);                                    
        case TIMER5:          return SYS_CLK_FREQ/pbdiv/(div[T5CONbits.TCKPS]) /((uint32_t)PR5);                      
        case TIMER6_TIMER7:   return SYS_CLK_FREQ/pbdiv/(div[T7CONbits.TCKPS]) /((uint32_t)PR6|PR7<<16);                     
        case TIMER6:          return SYS_CLK_FREQ/pbdiv/(div[T6CONbits.TCKPS]) /((uint32_t)PR6);                                   
        case TIMER7:          return SYS_CLK_FREQ/pbdiv/(div[T7CONbits.TCKPS]) /((uint32_t)PR7);                                     
        case TIMER8_TIMER9:   return SYS_CLK_FREQ/pbdiv/(div[T9CONbits.TCKPS]) /((uint32_t)PR8|PR9<<16);
        case TIMER8:          return SYS_CLK_FREQ/pbdiv/(div[T8CONbits.TCKPS]) /((uint32_t)PR8);
        case TIMER9:          return SYS_CLK_FREQ/pbdiv/(div[T9CONbits.TCKPS]) /((uint32_t)PR9);            
         default:
             break;
    }
     return 0;
}



/*!
* 	 void systmrB_enableInterrupt(TimerB num, uint32_t priority, uint32_t sub_priority)
* 
* 	...tbd...
* 	\param TimerB num -...
* 	\param uint32_t priority -...
* 	\param uint32_t sub_priority -...
* 	\return void -...
*/
void systmrB_enableInterrupt(TimerB num, uint32_t priority, uint32_t sub_priority){ 
    switch(num)
    {
        case TIMER3:                            
        case TIMER2_TIMER3:
            IFS0bits.T3IF =0;
            IEC0bits.T3IE =1;
            IPC2bits.IC2IP = priority;
            IPC2bits.IC2IS = priority;
            break;
            
        case TIMER2:      
            IFS0bits.T2IF =0;
            IEC0bits.T2IE = 1;
            IPC2bits.IC2IP = priority;
            IPC2bits.IC2IS = sub_priority;
            break;        
        
        
        case TIMER5:            
        case TIMER4_TIMER5:            
            IFS0bits.T5IF =0;
            IEC0bits.T5IE = 1;
            IPC6bits.IC5IP = priority;
            IPC6bits.IC5IS = sub_priority;
            break;
            
        case TIMER4:
            IFS0bits.T4IF =0;
            IEC0bits.T4IE = 1;
            IPC5bits.IC4IP = priority;
            IPC5bits.IC4IS = sub_priority;
            break;
            
        
            break;                    
        
        case TIMER7:   
        case TIMER6_TIMER7:            
            IFS1bits.T7IF =0;
            IEC1bits.T7IE = 1;
            IPC8bits.IC7IP = priority;
            IPC8bits.IC7IS = sub_priority;
            break;
            
        case TIMER6:   
            IFS0bits.T6IF =0;
            IEC0bits.T6IE = 1;
            IPC7bits.IC6IP = priority;
            IPC7bits.IC6IS = sub_priority;
            break;
                                  
        case TIMER9:
        case TIMER8_TIMER9:
            IFS1bits.T9IF =0;
            IEC1bits.T9IE = 1;
            IPC10bits.IC9IP = priority;
            IPC10bits.IC9IS = sub_priority;
            break;
            
        case TIMER8:
            IFS1bits.T8IF =0;
            IEC1bits.T8IE = 1;
            IPC9bits.IC8IP = priority;
            IPC9bits.IC8IS = sub_priority;
            break;
            
        default:break;
    }
}


/*!
* 	 void systmrB_disable(TimerB num)
* 
* 	...tbd...
* 	\param TimerB num -...
* 	\return void -...
*/
void systmrB_disable(TimerB num){    
    switch(num)
    {
        case TIMER2_TIMER3:            
            T2CONbits.ON =0;
            T3CONbits.ON =0;
            break;
            
        case TIMER2:
            T2CONbits.ON =0;
            break;        
        
        case TIMER3:
            T3CONbits.ON =0;
            break;
            
        case TIMER4_TIMER5:
            T4CONbits.ON =0;
            T5CONbits.ON =0;
            break;
            
        case TIMER4:
            T4CONbits.ON =0;
            break;
            
        case TIMER5:            
            T5CONbits.ON =0;
            break;                    
            
        case TIMER6_TIMER7:
            T7CONbits.ON = 0;
            T6CONbits.ON = 0;
            break;
            
        case TIMER6:
            T6CONbits.ON = 0;
            break;
            
        case TIMER7:
            T7CONbits.ON = 0;
            break;
                      
        case TIMER8_TIMER9:
            T8CONbits.ON = 0;
            T9CONbits.ON = 0;
            break;
            
        case TIMER8:
            T8CONbits.ON = 0;
            break;
            
        case TIMER9:
            T9CONbits.ON = 0;    
            break;
                    
    }    
}



/*!
* 	 void systmrB_enable(TimerB num, SysTmrB_Prescaler prescaler, uint32_t period)
* 
* 	...tbd...
* 	\param TimerB num -...
* 	\param SysTmrB_Prescaler prescaler -...
* 	\param uint32_t period -...
* 	\return void -...
*/
void systmrB_enable(TimerB num, SysTmrB_Prescaler prescaler, uint32_t period){    
    switch(num)
    {
        case TIMER2_TIMER3:
            T2CON = 0;
            T2CONbits.T32 = 1;                        
            T2CONbits.TCKPS = prescaler;
            TMR2 = 0;
            TMR3 = 0;
            PR2= period&0xffff;
            PR3 = (period>>16)&0xffff;
            T2CONbits.ON = 1;
            break;
            
        case TIMER2:
            T2CON = 0;            
            T2CONbits.TCKPS = prescaler;
            TMR2 = 0;
            PR2= period;
            T2CONbits.ON = 1;
            break;        
        
        case TIMER3:
            T3CON = 0;            
            T3CONbits.TCKPS = prescaler;
            TMR3 = 0;
            PR3= period;
            T3CONbits.ON = 1;
            break;
            
        case TIMER4_TIMER5:
            T4CON = 0;    
            T5CON=0;        
            T4CONbits.TCKPS = prescaler;
            T4CONbits.T32 = 1;
            TMR4 = 0;
            TMR5 = 0;
            PR4= period&0xffff;
            PR5 = (period>>16)&0xffff;            
            T4CONbits.ON = 1;
            break;
            
        case TIMER4:
            T4CON = 0;
            T4CONbits.ON = 1;
            T4CONbits.TCKPS = prescaler;
            TMR4 = 0;
            PR4= period;
            break;
            
        case TIMER5:
            T5CON = 0;            
            T5CONbits.TCKPS = prescaler;
            TMR5 = 0;
            PR5= period;
            T5CONbits.ON = 1;
            break;                    
            
        case TIMER6_TIMER7:
            T6CON = 0;            
            T7CON = 0;            
            T6CONbits.TCKPS = prescaler;            
            T6CONbits.T32 = 1;
            TMR6 = 0;
            TMR7 = 0;
            PR6= period&0xffff;
            PR7= (period>>16)&0xffff;
            T6CONbits.ON = 1;
            break;
            
        case TIMER6:
            T6CON = 0;            
            T6CONbits.TCKPS = prescaler;            
            TMR6 = 0;
            PR6= period;
            T6CONbits.ON = 1;
            break;
            
        case TIMER7:
            T7CON = 0;            
            T7CONbits.TCKPS = prescaler;            
            TMR7 = 0;
            PR7= period;
            T7CONbits.ON = 1;
            break;
                      
        case TIMER8_TIMER9:
            T8CON = 0;        
            T9CON = 0;        
            T8CONbits.TCKPS = prescaler;            
            T8CONbits.T32 = 1;
            TMR8 = 0;
            TMR9 = 0;
            PR8 =period&0xffff;
            PR9 =(period>>16)&0xffff;            
            T8CONbits.ON = 1;
            break;
            
        case TIMER8:
            T8CON = 0;                       
            T8CONbits.TCKPS = prescaler;            
            TMR8 = 0;
            PR8 = period;
            T8CONbits.ON = 1;
            break;
            
        case TIMER9:
            T9CON = 0;            
            T9CONbits.TCKPS = prescaler;            
            TMR9 = 0;
            PR9= period;
            T9CONbits.ON = 1;
            break;
                    
    }    
}




/*!
* 	 bool systmrB_timeout(TimerB num)
* 
* 	...tbd...
* 	\param TimerB num -...
* 	\return bool -...
*/
bool systmrB_timeout(TimerB num)
{
    switch(num)
    {
        case TIMER2: return IFS0bits.T2IF;
        case TIMER2_TIMER3: return IFS0bits.T3IF;
        case TIMER3: return IFS0bits.T3IF;
        case TIMER4: return IFS0bits.T4IF;
        case TIMER4_TIMER5: return IFS0bits.T5IF;
        case TIMER5: return IFS0bits.T5IF;
        case TIMER6: return IFS0bits.T6IF;
        case TIMER6_TIMER7: return IFS1bits.T7IF;
        case TIMER7: return IFS1bits.T7IF;
        case TIMER8: return IFS1bits.T8IF;
        case TIMER8_TIMER9: return IFS1bits.T9IF;
        case TIMER9: return IFS1bits.T9IF;                                 
       default:break;
    }    
    return false;
}



/*!
* 	 void systmrB_set_period(TimerB num, uint32_t tmr)
* 
* 	...tbd...
* 	\param TimerB num -...
* 	\param uint32_t tmr -...
* 	\return void -...
*/
void systmrB_set_period(TimerB num, uint32_t tmr)
{
        switch(num)
    {
        case TIMER2: PR2 = tmr; break;
        case TIMER2_TIMER3: PR2 = tmr&0xffff; PR3 = (tmr>>16)&0xffff; break;
        case TIMER3: PR3 = tmr; break;
        case TIMER4: PR4 = tmr; break;
        case TIMER4_TIMER5: PR4 = tmr&0xffff; PR5 = (tmr>>16)&0xffff; break;
        case TIMER5: PR5 = tmr; break;
        case TIMER6: PR6 = tmr; break;
        case TIMER6_TIMER7: PR6 = tmr&0xffff; PR7 = (tmr>>16)&0xffff;break;
        case TIMER7: PR7 = tmr; break;
        case TIMER8: PR8 = tmr; break;
        case TIMER8_TIMER9: PR8 = tmr&0xffff; PR9 = (tmr>>16)&0xffff;break;
        case TIMER9: PR9 = tmr; break;
       default:break;
    }    
}



/*!
* 	 void systmrB_restart(TimerB num)
* 
* 	...tbd...
* 	\param TimerB num -...
* 	\return void -...
*/
void systmrB_restart(TimerB num)
{   
     switch(num)
    {
        case TIMER2:  T2CONbits.ON = 0;TMR2=0;IFS0bits.T2IF =0; T2CONbits.ON = 1;break;
        case TIMER2_TIMER3:  T2CONbits.ON = 0;TMR2=0;TMR3=0;IFS0bits.T3IF =0; T2CONbits.ON = 1;break;
        case TIMER3: T3CONbits.ON = 0;TMR3=0; IFS0bits.T3IF =0; T3CONbits.ON = 1; break;
        case TIMER4: T4CONbits.ON = 0;TMR4=0; IFS0bits.T4IF =0; T4CONbits.ON = 1; break;
        case TIMER4_TIMER5:  T4CONbits.ON = 0;TMR4=0;TMR5=0;IFS0bits.T5IF =0; T4CONbits.ON = 1;break;
        case TIMER5: T5CONbits.ON = 0;TMR5=0; IFS0bits.T5IF =0; T5CONbits.ON = 1; break;
        case TIMER6: T6CONbits.ON = 0;TMR6=0; IFS0bits.T6IF =0; T6CONbits.ON = 1; break;
        case TIMER6_TIMER7:  T6CONbits.ON = 0;TMR6=0;TMR7=0;IFS1bits.T7IF =0; T6CONbits.ON = 1;break;
        case TIMER7: T7CONbits.ON = 0;TMR7=0; IFS1bits.T7IF =0; T7CONbits.ON = 1; break;
        case TIMER8: T8CONbits.ON = 0;TMR8=0; IFS1bits.T8IF =0; T8CONbits.ON = 1; break;
        case TIMER8_TIMER9:  T8CONbits.ON = 0;TMR8=0;TMR9=0;IFS1bits.T9IF =0; T8CONbits.ON = 1;break;
        case TIMER9: T9CONbits.ON = 0;TMR9=0; IFS1bits.T9IF =0; T9CONbits.ON = 1; break;                                 
       default:break;
    }    
}



/*!
* 	 uint32_t systmrB_elapsed(TimerB num)
* 
* 	...tbd...
* 	\param TimerB num -...
* 	\return uint32_t -...
*/
uint32_t systmrB_elapsed(TimerB num){
     switch(num)
    {
        case TIMER2:  return (uint32_t)TMR2;break;
        case TIMER2_TIMER3: return ((uint32_t)TMR2<<16) | (TMR3&0xffff);break;
        case TIMER3: return (uint32_t)TMR3; break;
        case TIMER4: return (uint32_t)TMR4; break;
        case TIMER4_TIMER5: return ((uint32_t)TMR4<<16) | (TMR5&0xffff);break;
        case TIMER5: return (uint32_t)TMR5; break;
        case TIMER6: return (uint32_t)TMR6; break;
        case TIMER6_TIMER7: return ((uint32_t)TMR6<<16) | (TMR7&0xffff);break;
        case TIMER7: return (uint32_t)TMR7; break;
        case TIMER8: return (uint32_t)TMR8; break;
        case TIMER8_TIMER9: return ((uint32_t)TMR8<<16) | (TMR9&0xffff); break;
        case TIMER9: return (uint32_t)TMR9; break;                                 
       default:break;
    }   
     return 0;
}
