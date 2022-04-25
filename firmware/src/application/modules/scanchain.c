/*!
 * @file modules\scanchain1.c
 * @author D.Chikov
 * @date 10/15/2020, 10:24:38
 * @brief ...tbd...
 */


// scanchain communication
// 
//                             DIOxx,DIOxx,DIOxx,xxxx,data
// 1 - DIO number for CLK -----|      |    |     |    |
// 2 - DIO for read pin --------------|    |     |    |
// 3 - DIO for write pin ------------------|     |    |
// 4 - scanchain size in bits -------------------|    |
// 5 - scanchain data --------------------------------|
//     can have more bytes than size in bits the reset will be ignored
// for reading use get command



#include "app.h"
#include "scanchain.h"
#include "string_utils.h"
#include "chrono.h"
#include "dio.h"


static uint32_t ck_delay=0;

#define CK_CPOL 1
#define CK_CPHA 2
#define CK_PULSE 3
#define CK_HI 4
#define CK_LO 8
#define WR_HI 16
#define WR_LO 32

static uint32_t scanchain_mode=0;
static uint32_t gpio_ck;
static uint32_t gpio_w1, gpio_r1;
static uint32_t gpio_w2, gpio_r2;
static uint32_t gpio_w3, gpio_r3;

//in
static uint8_t *data1_in;
static uint8_t *data2_in;
static uint8_t *data3_in;

//out
static uint8_t *data1_out;
static uint8_t *data2_out;
static uint8_t *data3_out;

  // scanchain size in bits
static uint32_t  scanchain1_size=0;
static uint32_t  scanchain2_size=0;
static uint32_t  scanchain3_size=0;


#define INF_CK(_VAL_) do{ gpio_set(gpio_ck,(_VAL_));}while(0)
#define INF_CK_TOGGLE(_VAL_) do{ gpio_toggle(gpio_ck);}while(0)
#define INF_WRITE1(_VAL_)do{  gpio_set(gpio_w1, (_VAL_) );}while(0)
#define INF_WRITE2(_VAL_)do{  gpio_set(gpio_w2, (_VAL_) );}while(0)
#define INF_WRITE3(_VAL_)do{  gpio_set(gpio_w3, (_VAL_) );}while(0)

#define INF_READ1() (uint32_t)gpio_get(gpio_r1)
#define INF_READ2() (uint32_t)gpio_get(gpio_r2)
#define INF_READ3() (uint32_t)gpio_get(gpio_r3)

#define INF_WRITE(_VAL_)do{	gpio_set(gpio_w, (_VAL_) );}while(0)
#define INF_READ() (uint32_t)gpio_get(gpio_r)

int clockMode;

enum {FALLING_EDGE_CLOCK,RISING_EDGE_CLOCK,PULSE_CLOCK};


bool scanchain_conf(const char *ptext){
    char *item = 0;
    int n = 0;
    
    scanchain_mode =0;
    FOREACH_BEGIN(item, ptext, ',') 
    {
        switch (n) 
        {
            case 0:
            {
                if(compare_string("CPOL0",item) == true) scanchain_mode &=  ~CK_CPOL;
                else if(compare_string("CPOL1",item) == true) scanchain_mode |=  CK_CPOL;
                else if(compare_string("PULSE",item)){
                    scanchain_mode |= CK_PULSE;
                    n+=1;
                }
            }
            break;   
            
            case 1:
            {                
                if(compare_string("CPHA0",item) == true) scanchain_mode &=  ~CK_CPHA;
                else if(compare_string("CPHA1",item) == true) scanchain_mode |=  CK_CPHA;
            }
            break;   
            
            case 2:
                if(compare_string("HI",item) == true) scanchain_mode |=  CK_HI;                                
            break;
            
            case 3:
                if(compare_string("HI",item) == true) scanchain_mode |=  WR_HI;                
            break;
                        
            case 4:
            {
                ck_delay = StrToUInt( (char*)item);
            }
            break;
        }            
            
        n++;                    
    }
    FOREACH_END(item);
    
    return true;
}

/*!
 * 	 bool function_scanchain1(const char *ptext)
 * 
 * 	Sends single scanchain.
 *  !!! [1] when data == READ - means just read and write the same data back
 *  !!! [2] When writing first bit is already prepared on dio_r
 * 	\param const char *ptext - command text
 * 	\return bool - return True if Ok
 */
bool scanchan1_transfer(const char *ptext) {
 bool result = false;
 bool read_mode=false;

 int32_t   i;


// pins
  uint32_t  gpio_ck=0;
  uint32_t  gpio_w1=0;
  uint32_t  gpio_r1=0;
 bool parameters_ok = false;

    char *item = 0;

   int n = 0;
   data1_in = &application_data[0];
   data1_out = &application_data[10000];

   FOREACH_BEGIN(item, ptext,  ',')
   {
		uint32_t dio;
     switch (n)
     {
     case 0:
        dio = atoi(&item[3]);
        if (DIO_Valid(dio)) {
            gpio_ck = dio_table[ dio ];
            }
        else { printf("(dio_ck invalid)");
                return false;}
       break;

     case 1:
		dio = atoi(&item[3]);
        if (DIO_Valid(dio)) {
            gpio_w1 = dio_table[ dio ];
            }
        else { printf("(dio_w1 invalid)");
                return false;}
       break;

     case 2:
		dio = atoi(&item[3]);
        if (DIO_Valid(dio)) {
            gpio_r1 = dio_table[ dio ];
            }
        else { printf("(dio_r1 invalid)");
                return false;}	    
       break;

     case 3:	    
       scanchain1_size = StrToUInt(item);
       if(scanchain1_size<=0) {
           printf("(size1 should be >0)");
                return false;}		    
       break;

     case 4:
	    read_mode = compare_string(item, "READ") || compare_string(item, "read");
 		if(read_mode == false)
        {
 			const int hex_len = bytes_from_hex(data1_in, item);
            const int bytes_count = (scanchain1_size/8) + (scanchain1_size%8>0?1:0);
             if(hex_len < bytes_count)  {
                 printf("(insufficient hex1 data)"); 
                 break;
             } 
            parameters_ok = true;
        } else parameters_ok = true;  
       break;
     }
     n++;
   }
    FOREACH_END(item);
    
    if(parameters_ok == false) {               
        return false;
    }

    if(ck_delay>0)
        CHRONO1_SET_TIMEOUT(ck_delay);
    else CHRONO1_SET_TIMEOUT(1);

    if( (scanchain_mode & CK_CPOL) ==0)        INF_CK(0);
    else if( (scanchain_mode & CK_CPOL) ==1)        INF_CK(1);
    
    CHRONO1_START();        
    
    // READ
    if (read_mode) {
       int32_t idx_data_in1=0;
       int32_t idx_data_out1=0;

       for (i = 0; i < scanchain1_size; i++)
       {
         bool bit1 = 0;   
         
         //read [1]			
         BUF_ADD_BIT(data1_out, idx_data_out1, INF_READ1());
        
         // write [1]
         bit1 = BUF_BIT(data1_out, idx_data_in1);
		 idx_data_in1++;
		 INF_WRITE1(bit1);
         
        INF_CK_TOGGLE(); 
         while(!CHRONO1_IS_TIMEOUT());
         CHRONO1_RESTART();
         
        INF_CK_TOGGLE();         
         while(!CHRONO1_IS_TIMEOUT());
         CHRONO1_RESTART();        
       } 
        result = true;
    }
    // WRITE 
    else  {
       int32_t idx_data_in1=0;
       int32_t idx_data_out1=0;

       for (i = 0; i < scanchain1_size; i++)
       {
         bool bit1 = 0;	  	  
         //gpio_set(gpio_ck,1);   	
         //read [1]
     	 BUF_ADD_BIT(data1_out, idx_data_out1,INF_READ1());
    		
          // write [1]
           bit1 = BUF_BIT(data1_in, idx_data_in1);
			idx_data_in1++;
			INF_WRITE1(bit1);
         	            
         //delay_us(1);
         //gpio_set(gpio_ck,0);
         
         if( (i == (scanchain1_size-1)) && (scanchain_mode & CK_HI ) )
            {
                INF_CK_TOGGLE(); 
                while(!CHRONO1_IS_TIMEOUT());
                CHRONO1_RESTART();
            }
         else
            {    
                INF_CK_TOGGLE();         
                while(!CHRONO1_IS_TIMEOUT());
                CHRONO1_RESTART();
                
                INF_CK_TOGGLE();         
                while(!CHRONO1_IS_TIMEOUT());
                CHRONO1_RESTART();
            }	  
       }  
        result = true;       
    } 
    
    if ( scanchain_mode & CK_HI ) INF_CK(1);
    if (scanchain_mode & WR_HI ) INF_WRITE1(1);

    return result;
}


/*!
* 	 bool function_scanchain2(const char *ptext)
* 
* 	...tbd...
* 	\param const char *ptext -...
* 	\return bool -...
*/
bool scanchain2_transfer(const char *ptext)
{
  bool result = false;
 bool read_mode=false;

 int32_t   i;


// pins
  uint32_t  gpio_ck=0;
  uint32_t  gpio_w1=0;
  uint32_t  gpio_w2=0;
  uint32_t  gpio_r1=0;
  uint32_t  gpio_r2=0;
 bool parameters_ok = false;

    char *item = 0;

   int n = 0;
   data1_in = &application_data[1000];
   data2_in = &application_data[3000];
   data1_out = &application_data[5000];
   data2_out = &application_data[7000];

   FOREACH_BEGIN(item, ptext,  ',')
   {
		uint32_t dio;
     switch (n)
     {
     case 0:
        dio = atoi(&item[3]);
        if (DIO_Valid(dio)) {
            gpio_ck = dio_table[ dio ];
            }
        else { printf("(dio_ck invalid)");
                return false;}
       break;

     case 1:
		dio = atoi(&item[3]);
        if (DIO_Valid(dio)) {
            gpio_w1 = dio_table[ dio ];
            }
        else { printf("(dio_w1 invalid)");
                return false;}
       break;

     case 2:
		dio = atoi(&item[3]);
        if (DIO_Valid(dio)) {
            gpio_w2 = dio_table[ dio ];
            }
        else { printf("(dio_w2 invalid)");
                return false;}       
       break;

     case 3:
		dio = atoi(&item[3]);
        if (DIO_Valid(dio)) {
            gpio_r1 = dio_table[ dio ];
            }
        else { printf("(dio_r1 invalid)");
                return false;}	    
       break;

     case 4:
		dio = atoi(&item[3]);
        if (DIO_Valid(dio)) {
            gpio_r2 = dio_table[ dio ];
            }
        else { printf("(dio_r2 invalid)");
                return false;}		    
       break;

     case 5:	    
       scanchain1_size = StrToUInt(item);
       if(scanchain1_size<=0) {
           printf("(size1 should be >0)");
                return false;}		    
       break;

     case 6:
       scanchain2_size = StrToUInt(item);
       if(scanchain2_size <= 0) {
           printf("(size2 should be >0)");
                return false;}		    
       break;

     case 7:
	    read_mode = compare_string(item, "READ") || compare_string(item, "read");
 		if(read_mode == false)
        {
 			const int hex_len = bytes_from_hex(data1_in, item);
            const int bytes_count = (scanchain1_size/8) + (scanchain1_size%8>0?1:0);
             if(hex_len < bytes_count)  {
                 printf("(insufficient hex1 data)"); 
                 break;
             }
 		} else parameters_ok = true;        
       break;

     case 8:
         //both should be read mode		
 		if(read_mode == false)
        {
			const int hex_len =bytes_from_hex(data2_in, item);
            const int bytes_count = (scanchain2_size/8) + (scanchain2_size%8>0?1:0);
            if(hex_len < bytes_count)  {
                 printf("(insufficient hex2 data)"); 
                 break;
             }
            parameters_ok = true;
		  }          
       break;
     }
     n++;
   }
   FOREACH_END(item);	
		
	if(parameters_ok ==false)     { 
        return false;
    }
    
   
    if(ck_delay>0)    CHRONO1_SET_TIMEOUT(ck_delay);
    else CHRONO1_SET_TIMEOUT(1);
    
   if( (scanchain_mode & CK_CPOL) ==0)        INF_CK(0);
   else if( (scanchain_mode & CK_CPOL) ==1)        INF_CK(1);
   
    CHRONO1_START();     
   // READ MODE
	if ( read_mode)
   {     
       int32_t bits_total = (scanchain1_size > scanchain2_size) ? scanchain1_size : scanchain2_size;
       int32_t idx_data_in1=0, idx_data_in2=0;
       int32_t idx_data_out1=0, idx_data_out2=0;

       for (i = 0; i < bits_total; i++)
       {
         bool bit1 = 0, bit2 = 0;        
         

         
         //read [1]
         if(i<scanchain1_size)
         {            			
           BUF_ADD_BIT(data1_out, idx_data_out1, INF_READ1());
         }

         //read [2]
         if(i<scanchain2_size)
         { 			  
           BUF_ADD_BIT(data2_out, idx_data_out2, INF_READ2());
         }
         
         // write [1]
         if ((scanchain1_size - (bits_total - i)) >= 0)
         {
           bit1 = BUF_BIT(data1_out, idx_data_in1);
			idx_data_in1++;
			INF_WRITE1(bit1);
         }              
          
        //write [2]
         if ((scanchain2_size - (bits_total - i)) >= 0)
         {
           bit2 = BUF_BIT(data2_out, idx_data_in2);
			idx_data_in2++;
			INF_WRITE2(bit2);  
         }      
         
        INF_CK_TOGGLE(); 
         while(!CHRONO1_IS_TIMEOUT());
         CHRONO1_RESTART();
         
        INF_CK_TOGGLE();         
        while(!CHRONO1_IS_TIMEOUT());
        CHRONO1_RESTART();
        
       } 
		result=true;
   } 
   // WRITE MODE
   else 
   {        
       int32_t bits_total = (scanchain1_size > scanchain2_size) ? scanchain1_size : scanchain2_size;
   	  int32_t idx_data_in1=0, idx_data_in2=0;
       int32_t idx_data_out1=0, idx_data_out2=0;

       for (i = 0; i < bits_total; i++)
       {
         bool bit1 = 0, bit2 = 0;	  	  
            //gpio_set(gpio_ck,1);   	
     		//read [1]
     		if(i<scanchain1_size)
     		{
     			BUF_ADD_BIT(data1_out, idx_data_out1,INF_READ1());
     		}

     		//read [2]
     		if(i<scanchain2_size)
     		{
     			BUF_ADD_BIT(data2_out, idx_data_out2,INF_READ2());
     		}
     		
     	  // write [1]
         if ((scanchain1_size - (bits_total - i)) >= 0)
         {
           bit1 = BUF_BIT(data1_in, idx_data_in1);
			      idx_data_in1++;
			      INF_WRITE1(bit1);
     	  }      
     	  
     	  
     	 //write [2]
         if ((scanchain2_size - (bits_total - i)) >= 0)
         {
           bit2 = BUF_BIT(data2_in, idx_data_in2);
			       idx_data_in2++;
			       INF_WRITE2(bit2);	
     	  }      
     	            
            //delay_us(1);
         //gpio_set(gpio_ck,0);
         
         if( (i == (bits_total-1)) && (scanchain_mode & CK_HI ) )
            {
                INF_CK_TOGGLE(); 
                while(!CHRONO1_IS_TIMEOUT());
                CHRONO1_RESTART();
            }
         else
            {    
                INF_CK_TOGGLE();         
                while(!CHRONO1_IS_TIMEOUT());
                CHRONO1_RESTART();
                
                INF_CK_TOGGLE();         
                while(!CHRONO1_IS_TIMEOUT());
                CHRONO1_RESTART();
            }	  
       }	    
	result=true;
 }
    
    //if (scanchain_mode & CK_HI ) INF_CK(1);
    if (scanchain_mode & WR_HI ) INF_WRITE1(1);
    if (scanchain_mode & WR_HI ) INF_WRITE2(1);
  return result;
}





bool scanchain3_read(){
		int32_t bits_total=0;
		int i;
        
		if((scanchain1_size >= scanchain2_size) && (scanchain1_size >= scanchain3_size))
			{bits_total = scanchain1_size;}
		if((scanchain2_size >= scanchain1_size) && (scanchain2_size >= scanchain3_size))	
			{bits_total = scanchain2_size;}	
		if((scanchain3_size >= scanchain1_size) && (scanchain3_size >= scanchain2_size))
			{bits_total = scanchain3_size;}
        else {
            printf("(size error)");
            return false;
        }
					
		int32_t idx_data_in1=0, idx_data_in2=0, idx_data_in3=0;
		int32_t idx_data_out1=0, idx_data_out2=0, idx_data_out3=0;

		for (i = 0; i < bits_total; i++)
		{
			bool bit1 = 0, bit2 = 0, bit3 = 0;
			
			
			switch(clockMode)
			{
				case FALLING_EDGE_CLOCK:
				INF_CK(1);
				break;
				
				case  RISING_EDGE_CLOCK:
				INF_CK(0);
				break;
				
				case PULSE_CLOCK:
				break;
			}
			
			
			//read [1]
			if(i<scanchain1_size)
			{
				BUF_ADD_BIT(data1_out, idx_data_out1,INF_READ1());
			}

			//read [2]
			if(i<scanchain2_size)
			{
				BUF_ADD_BIT(data2_out, idx_data_out2,INF_READ2());
			}
			
			//read [3]
			if(i<scanchain3_size)
			{
				BUF_ADD_BIT(data3_out, idx_data_out3,INF_READ3());
			}
			
			// write [1]
			if ((scanchain1_size - (bits_total - i)) >= 0)
			{
				bit1 = BUF_BIT(data1_out, idx_data_in1);
				idx_data_in1++;
				INF_WRITE1(bit1);
			}
			
			
			//write [2]
			if ((scanchain2_size - (bits_total - i)) >= 0)
			{
				bit2 = BUF_BIT(data2_out, idx_data_in2);
				idx_data_in2++;
				INF_WRITE2(bit2);
			}
			
			//write [3]
			if ((scanchain3_size - (bits_total - i)) >= 0)
			{
				bit3 = BUF_BIT(data3_out, idx_data_in3);
				idx_data_in3++;
				INF_WRITE3(bit3);
			}
            while(!CHRONO1_IS_TIMEOUT());
            CHRONO1_RESTART();
			
			switch(clockMode)
			{
				case FALLING_EDGE_CLOCK:
				INF_CK(0);
				break;
				
				case  RISING_EDGE_CLOCK:
				INF_CK(1);
				break;
				
				case PULSE_CLOCK:
				INF_CK(0);
				INF_CK(1);
				INF_CK(0);
				break;
			}
			
			
            while(!CHRONO1_IS_TIMEOUT());
            CHRONO1_RESTART();
		}
    return true;
}

bool scanchain3_write(){
		int32_t bits_total=0;
		int i;
		if((scanchain1_size >= scanchain2_size) && (scanchain1_size >= scanchain3_size))
			{bits_total = scanchain1_size;}
		if((scanchain2_size >= scanchain1_size) && (scanchain2_size >= scanchain3_size))	
			{bits_total = scanchain2_size;}	
		if((scanchain3_size >= scanchain1_size) && (scanchain3_size >= scanchain2_size))
			{bits_total = scanchain3_size;}
        else {
            printf("(size error)");
            return false;
        }
		
		int32_t idx_data_in1=0, idx_data_in2=0, idx_data_in3=0;
		int32_t idx_data_out1=0, idx_data_out2=0, idx_data_out3=0;

		for (i = 0; i < bits_total; i++)
		{
			bool bit1 = 0, bit2 = 0, bit3 = 0;
			switch(clockMode)
			{
				case FALLING_EDGE_CLOCK:
				INF_CK(1);
				break;
				
				case  RISING_EDGE_CLOCK:
				INF_CK(0);
				break;
				
				case PULSE_CLOCK:
				
				break;
			}
			
			
			//read [1]
			if(i<scanchain1_size)
			{
				BUF_ADD_BIT(data1_out, idx_data_out1,INF_READ1());
			}

			//read [2]
			if(i<scanchain2_size)
			{
				BUF_ADD_BIT(data2_out, idx_data_out2,INF_READ2());
			}
			
			//read [3]
			if(i<scanchain3_size)
			{
				BUF_ADD_BIT(data3_out, idx_data_out3,INF_READ3());
			}
			
			// write [1]
			if ((scanchain1_size - (bits_total - i)) >= 0)
			{
				bit1 = BUF_BIT(data1_in, idx_data_in1);
				idx_data_in1++;
				INF_WRITE1(bit1);
			}
			
			
			//write [2]
			if ((scanchain2_size - (bits_total - i)) >= 0)
			{
				bit2 = BUF_BIT(data2_in, idx_data_in2);
				idx_data_in2++;
				INF_WRITE2(bit2);
			}
			
			//write [3]
			if ((scanchain3_size - (bits_total - i)) >= 0)
			{
				bit3 = BUF_BIT(data3_in, idx_data_in3);
				idx_data_in3++;
				INF_WRITE3(bit3);
			}
						
            while(!CHRONO1_IS_TIMEOUT());
            CHRONO1_RESTART();
			switch(clockMode)
			{
				case FALLING_EDGE_CLOCK:
				INF_CK(0);
				break;
				
				case  RISING_EDGE_CLOCK:
				INF_CK(1);
				break;
				
				case PULSE_CLOCK:
				INF_CK(0);
				INF_CK(1);
				INF_CK(0);
				break;
			}
            while(!CHRONO1_IS_TIMEOUT());
            CHRONO1_RESTART();
		}
      return true;
}

bool scanchain3_transfer(const char *ptext)
{
	bool result = false;
	bool read_mode=false;
    bool parameters_ok = false;
	
	char *item = 0;

	int n = 0;
	data1_in = &application_data[1000];
    data1_out = &application_data[2000];
    
	data2_in = &application_data[3000];
    data2_out = &application_data[4000];
    
	data3_in = &application_data[5000];
	data3_out = &application_data[6000];

	FOREACH_BEGIN(item, ptext,  ',')
	{
		int dio;
		switch (n)
		{
			case 0:
			sscanf(item,"DIO%d", &dio);
            if (DIO_Valid(dio)) {
                gpio_ck = dio_table[dio];
            }
			break;

			case 1:
            sscanf(item,"DIO%d", &dio);
            if (DIO_Valid(dio)) {
                gpio_w1 = dio_table[dio];
            }			
			break;

			case 2:
			sscanf(item,"DIO%d", &dio);
            if (DIO_Valid(dio)) {
                gpio_w2 = dio_table[dio];
            }
			break;
			
			case 3:
            sscanf(item,"DIO%d", &dio);
            if (DIO_Valid(dio)) {
                gpio_w3 = dio_table[dio];
            }			
			break;

			case 4:
            sscanf(item,"DIO%d", &dio);
            if (DIO_Valid(dio)) {
                gpio_r1 = dio_table[dio];
            }	
			break;

			case 5:
            sscanf(item,"DIO%d", &dio);
            if (DIO_Valid(dio)) {
                gpio_r2 = dio_table[dio];
            }
			break;
			
			case 6:
            sscanf(item,"DIO%d", &dio);
            if (DIO_Valid(dio)) {    			
                gpio_r3 = dio_table[dio];
            }
			break;			

			case 7:
			scanchain1_size = atoi(item);
			break;

			case 8:
			scanchain2_size = atoi(item);
			break;
			
			case 9:
			scanchain3_size = atoi(item);
			break;
			
			case 10:
			switch(item[0])
			{
				case 'F':
				clockMode = FALLING_EDGE_CLOCK;
				break;
				
				case 'R':
				clockMode = RISING_EDGE_CLOCK;
				break;
				
				case 'P':
				clockMode = PULSE_CLOCK;
				break;
				
			}
			break;
			
			case 11:
                 //both should be read mode
                read_mode = compare_string(item, "READ") || compare_string(item, "read");
                if(read_mode == false) 
                   {
                  const int hex_len =bytes_from_hex(data1_in, item);
                  const int bytes_count = (scanchain1_size/8) + (scanchain1_size%8>0?1:0);
                  if(hex_len < bytes_count)  {
                      printf("(insufficient hex1 data)");
                      break;
                  }                 
                }  
                 parameters_ok = true;
			break;
			

			case 12:
			     //both should be read mode                
                if(read_mode == false)
                {
                  const int hex_len =bytes_from_hex(data2_in, item);
                  const int bytes_count = (scanchain2_size/8) + (scanchain2_size%8>0?1:0);
                  if(hex_len < bytes_count)    {
                      printf("(insufficient hex2 data)");
                      break;
                  }
                  parameters_ok = true;
                }
                
			break;
			
			case 13:
                 //both should be read mode                
                if(read_mode==false)
                  {
                  const int hex_len =bytes_from_hex(data3_in, item);
                  const int bytes_count = (scanchain3_size/8) + (scanchain3_size%8>0?1:0);
                  if(hex_len < bytes_count)  {
                      printf("(insufficient hex3 data)");
                      break;
                  }
                  parameters_ok = true;
                }
                
			break;			
		}
		n++;
	}
	FOREACH_END(item);

	if(parameters_ok==true 
            && ( (read_mode==1 && n==12)  // if read mode - less parameters
            || (read_mode==0 && n==14) )) // if write mode parameters = 14
    {
          } else {
            printf("(wrong parameters number)");
            return false;
        }

    if(ck_delay>0)
        CHRONO1_SET_TIMEOUT(ck_delay);
    else CHRONO1_SET_TIMEOUT(1);
    
    CHRONO1_START();    
    
	// [READ MODE]	
	if ( read_mode)
	{
            result = scanchain3_read(); 
	}
	else
	{
            result = scanchain3_write();
	}
    
    if (scanchain_mode & CK_HI ) INF_CK(1);
    if (scanchain_mode & WR_HI ) INF_WRITE1(1);
    if (scanchain_mode & WR_HI ) INF_WRITE2(1);
    if (scanchain_mode & WR_HI ) INF_WRITE3(1);
    
	return result;
}




/*!
 * 	 bool function_scanchain1_result()
 * 
 * 	Returns result in hex format
 * 	\return bool - True if any data available
 */
bool scanchain1_result() {
  bool result = false;     
      printf("=");
      int bytes =  scanchain1_size/8 + ((scanchain1_size%8 !=0)?1:0);
      int i;
        for (i = 0; i < bytes; i++) {
            printf("%02x", data1_out[i]);
            result = true;
        }
      result = true;   
  return result;

}

/*!
* 	 bool function_scanchain2_result(int scanchain_number)
* 
* 	...tbd...
* 	\param int scanchain_number - scanchain number 0 - is first scanchain1 1- is scanchain 2
* 	\return bool True - data are available.
*/
bool scanchain2_result(int scanchain_number)
{
  bool result = false;  
  if(scanchain_number ==1)
  {          
      printf("=");
      int bytes =  scanchain1_size/8 + ((scanchain1_size%8 !=0)?1:0);
      int i;
        for (i = 0; i < bytes; i++) {
            printf("%02x", data1_out[i]);
            result = true;
        }
      result = true;   
  }
  else if(scanchain_number ==2)
  {
      printf("=");
   int bytes =  scanchain2_size/8 + ((scanchain2_size%8 !=0)?1:0);
      int i;
        for (i = 0; i < bytes; i++) {
            printf("%02x", data2_out[i]);
            result = true;
        }
    result = true;  
  }  
  return result;

}

bool scanchain3_result(int scanchain_number)
{
  bool result = false;  
  if(scanchain_number ==1)
  {           
        int bytes =  scanchain1_size/8 + ((scanchain1_size%8 !=0)?1:0);
        int i;
        for (i = 0; i < bytes; i++) {
            printf("%02x", data1_out[i]);
            result = true;
        }      
		result = true;   
  }
  else if(scanchain_number ==2)
  {
		int bytes =  scanchain2_size/8 + ((scanchain2_size%8 !=0)?1:0);
        int i;
        for (i = 0; i < bytes; i++) {
            printf("%02x", data2_out[i]);
            result = true;
        }
		result = true;  
  }  
  else if(scanchain_number ==3)
  {
	    int bytes =  scanchain3_size/8 + ((scanchain3_size%8 !=0)?1:0);
        int i;
        for (i = 0; i < bytes; i++) {
            printf("%02x", data3_out[i]);
            result = true;
        }
	    result = true;
  }
  return result;

}
