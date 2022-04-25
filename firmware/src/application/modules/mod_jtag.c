/*!
* @file modules\jtag.c
* @author D.Chikov
* @date 10/15/2020, 10:24:38
* @brief ...tbd...
*/



#include "jtag.h"

#include "application.h"
#include "dio.h"
#include "string_utils.h"


bool m_configured;
unsigned int gpio_tms = 0;
unsigned int gpio_tck = 0;
unsigned int gpio_tdi = 0;
unsigned int gpio_tdo = 0;

static volatile uint32_t *m_gpio_tck;
static volatile uint32_t m_gpio_tck_mask;

/*!
* 	 define TCLK() do{*m_gpio_tck=m_gpio_tck_mask;*m_gpio_tck=m_gpio_tck_mask;}while(0)
* 
* 	...tbd...
* 	\param ) do{*m_gpio_tck=m_gpio_tck_mask;*m_gpio_tck=m_gpio_tck_mask;}while(0 -...
* 	\return define -...
*/
#define TCLK() do{*m_gpio_tck=m_gpio_tck_mask;*m_gpio_tck=m_gpio_tck_mask;}while(0)

static volatile uint32_t *m_gpio_tms;
static volatile uint32_t m_gpio_tms_mask;

/*!
* 	 define TMS_HI()
* 
* 	...tbd...
* 	\return define -...
*/
#define TMS_HI() *m_gpio_tms &= ~m_gpio_tms_mask;

/*!
* 	 define TMS_LO()
* 
* 	...tbd...
* 	\return define -...
*/
#define TMS_LO() *m_gpio_tms |= m_gpio_tms_mask;

static volatile uint32_t *m_gpio_tdi;
static volatile uint32_t m_gpio_tdi_mask;

/*!
* 	 define TDI_HI() do{*m_gpio_tdi &= ~m_gpio_tdi_mask;}while(0)
* 
* 	...tbd...
* 	\param ) do{*m_gpio_tdi &= ~m_gpio_tdi_mask;}while(0 -...
* 	\return define -...
*/
#define TDI_HI() do{*m_gpio_tdi &= ~m_gpio_tdi_mask;}while(0)

/*!
* 	 define TDI_LO() do{*m_gpio_tdi |= m_gpio_tdi_mask;}while(0)
* 
* 	...tbd...
* 	\param ) do{*m_gpio_tdi |= m_gpio_tdi_mask;}while(0 -...
* 	\return define -...
*/
#define TDI_LO() do{*m_gpio_tdi |= m_gpio_tdi_mask;}while(0)

static volatile uint32_t *m_gpio_tdo;
static volatile uint32_t m_gpio_tdo_mask;

/*!
* 	 define TDO() (*m_gpio_tdo &m_gpio_tdo_mask)
* 
* 	...tbd...
* 	\param ) (*m_gpio_tdo &m_gpio_tdo_mask -...
* 	\return define -...
*/
#define TDO() (*m_gpio_tdo &m_gpio_tdo_mask)

static unsigned char *m_buffer;
static uint32_t m_buffer_idx;





/*!
* 	 bool jtag_conf(const char *ptext)
* 
* 	...tbd...
* 	\param const char *ptext -...
* 	\return bool -...
*/
bool jtag_conf(const char *ptext)
{
	bool result = false;
	char *item = 0;
	uint32_t gpio;
	int n = 0;
    m_buffer_idx = 0;
    
	FOREACH_BEGIN(item, ptext,  ',')
	{
        switch (n)
		{
			//TMS
			case 0:
			gpio = dio_gpio( atoi(&item[3]) ); 
			m_gpio_tms = ((gpio>>5)*0x100 + &LATB);
            m_gpio_tms_mask = 1<<(gpio&0x1f) ;
			break;
			
            //TCK
			case 1:
            gpio = dio_gpio( atoi(&item[3]) ); 
			m_gpio_tck = ((gpio>>5)*0x100 + &LATB);
            m_gpio_tck_mask = 1<<(gpio&0x1f) ;
			break;
			
            //TDI
			case 2:
            gpio = dio_gpio( atoi(&item[3]) ); 
			m_gpio_tdi = ((gpio>>5)*0x100 + &LATB);
			m_gpio_tdi_mask = 1<<(gpio&0x1f);
			break;
            
			//TDO
			case 3:
            gpio = dio_gpio( atoi(&item[3]) ); 
			m_gpio_tdo = ((gpio>>5)*0x100 + &PORTB) ;
			m_gpio_tdo_mask = 1<<(gpio&0x1f);
			break;


			default:
			break;
		}
		n++;
	}
	FOREACH_END(item);

	if (n == 4) {m_configured = 1; result = 1;}
	else m_configured = 0;
	
	return result;
}




/*!
* 	 bool jtag_set(const char *ptext)
* 
* 	...tbd...
* 	\param const char *ptext -...
* 	\return bool -...
*/
bool jtag_set(const char *ptext)
{
	bool result = false;
	char *item = 0;

	int bits = -1;
	unsigned int data = 0;

	
	int n = 0;
    int i;
	enum {NONE = -1, RST = 0, DR = 1, IR = 2};
	int op  = NONE;


    m_buffer = &application_out[0];
	FOREACH_BEGIN(item, ptext,  ',')
	{

		switch (n)
		{
			//TMS
			case 0:
			if ( (item[0] == 'D' || item[0] == 'd') && (item[1] == 'R' || item[1] == 'r') )
			op = DR;
			else if ( (item[0] == 'I' || item[0] == 'i') && (item[1] == 'R' || item[1] == 'r') )
        		op = IR;
			else if ( (item[0] == 'R' || item[0] == 'r') && (item[1] == 'S' || item[1] == 's') && (item[2] == 'T' || item[2] == 't') )
			op = RST;

			break;

			case 1:
			bits = atoi(item);
			break;

			case 2:
			string_utils_from_hex(m_buffer, item);
			break;

			default:
			break;

		}
		n++;
	}
	FOREACH_END(item);
	
	
	m_buffer_idx =0;
	
	if ( op != NONE )
	{

		if (op == RST)
		{
			TMS_LO();
			TCLK();
			// switch to IR
			TMS_HI();
			TCLK();
			TCLK();
			TCLK();
			
			// capture IR
            TMS_LO();
			
			TCLK();
			
			result=true;
		}

		else if ( op == IR && bits>0 )
		{

			TMS_LO();
			TCLK();
			TCLK();
			
			// switch to IR
			TMS_HI();
			TCLK();
			TCLK();

			// capture IR
			TMS_LO();
			TCLK();
			TCLK();

			for (i = 0; i < bits; i++)
			{
				
				if ( BUF_BIT(m_buffer,i) !=0)                     TDI_HI();
				else                     TDI_LO();
				
                if (TDO())
					{
						BUFF_ADD_BIT(m_buffer, m_buffer_idx, 1);
					}
				else {
                        BUFF_ADD_BIT(m_buffer, m_buffer_idx, 0);									
				}
								
				if(i==bits-1){
					//Exit DR
					TMS_HI();
				}
				TCLK();


			}
			

			// Update IR
			TMS_HI();
			TCLK();

			// IDLE
			TMS_LO();
			TCLK();
			TCLK();
			TCLK();
			result=true;
		}

		else if (op == DR && bits>0)
		{
			TMS_LO();
			TCLK();
			TCLK();
						
			// Select DR
			TMS_HI();
			TCLK();

			// capture DR			
			TMS_LO();
			TCLK();
			TCLK();

			for ( i = 0; i < bits; i++)
			{
				if ( BUF_BIT(m_buffer,i) !=0)                     TDI_HI();
				else                     TDI_LO();
			
                if (TDO())
				{
					BUF_ADD_BIT(m_buffer,m_buffer_idx,1);
				}
				else {
					BUF_ADD_BIT(m_buffer,m_buffer_idx,0);
				}
								
				if( i == bits-1 ){
					//Exit DR
					TMS_HI();
				}
				
				TCLK();
			
			
			}

			

			//Update DR
			TMS_HI();
			TCLK();

			// IDLE
			TMS_LO();
			TCLK();
			TCLK();
			TCLK();
			result=true;
		}
	}
	return result;
}





/*!
* 	 bool jtag_data(char *ptext)
* 
* 	...tbd...
* 	\param char *ptext -...
* 	\return bool -...
*/
bool jtag_data(char *ptext)
{
 bool result = false;
 if (application_in_index > 0)
 {
	 make_hex_from_result(ptext, application_in, application_in_index);
	 result = true;
 }
 return result;

}

