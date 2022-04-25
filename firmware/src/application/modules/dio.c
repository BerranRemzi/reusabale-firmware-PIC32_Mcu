/*!
* @file modules\dio.c
* @author D.Chikov
* @date 10/15/2020, 18:16:01
* @brief ...tbd...
*/


#include "dio.h"
#include "xc.h"
#include "gpio.h"
#include "system.h"
#include "chrono.h"


const uint32_t dio_table[DIO_COUNT + 1] =
{
  0xffffffff, //dummy

  /*DIO1        DIO2          DIO3           DIO4           DIO5           DIO6           DIO7           DIO8           DIO9           DIO10  */
  GPIO('B',6),  GPIO('B',7),  GPIO('D',14),  GPIO('A',1),   GPIO('F',13),  GPIO('F',12),  GPIO('B',12),  GPIO('A',6),   GPIO('A',7),   GPIO('E',0)
  /*DIO11       DIO12         DIO13          DIO14          DIO15          DIO16          DIO17          DIO18          DIO19          DIO20 */
  ,GPIO('A',2), GPIO('A',3),  GPIO('A',4),   GPIO('F',3),   GPIO('D',10),  GPIO('D',11),  GPIO('D',0),   GPIO('C',13),  GPIO('C',14),  GPIO('F',2)       
  /*DIO21       DIO22         DIO23          DIO24          DIO25          DIO26          DIO27          DIO28          DIO29          DIO30 */
  ,GPIO('F',8), GPIO('F',4),  GPIO('F',5),   GPIO('A',15),  GPIO('A',14),  GPIO('D',9),   GPIO('D',12),  GPIO('D',4),   GPIO('D',5),   GPIO('F',0)          
  /*DIO31       DIO32         DIO33          DIO34          DIO35          DIO36          DIO37          DIO38          DIO39          DIO40 */
  ,GPIO('F',1), GPIO('E',3),  GPIO('G',14),  GPIO('A',5),   GPIO('E',5),   GPIO('E',6),   GPIO('C',4),   GPIO('G',7),   GPIO('G',6),   GPIO('G',12)          
  /*DIO41       DIO42         DIO43          DIO44          DIO45          DIO46          DIO47          DIO48          DIO49          DIO50 */
  ,GPIO('G',13),GPIO('E',2),  GPIO('G',15),  GPIO('D',3),   GPIO('D',2),   GPIO('E',7),   GPIO('C',1),   GPIO('C',2),   GPIO('E',9),   GPIO('E',8)               
  /*DIO51       DIO52         DIO53          DIO54*/
  ,GPIO('G',8), GPIO('C',3),  GPIO('B',3),   GPIO('B',5)
          
};


/* cache for dio direction*/
static DioDirection_t direction[DIO_COUNT + 1];



// init

/*!
* 	 void dio_init(void)
* 
* 	Initializes DIO channels
*/
void dio_init(void)
{
  int32_t i;
  for (i = 1; i <= DIO_COUNT; i++)
  {
    dio_conf(i, 0);
    direction[i] = DIODIR_UNDEF;    
  }
}




// set direction to port on start direction is undefined

/*!
* 	 bool dio_set_direction(uint32_t dio, DioDirection_t  dir)
* 
* 	...tbd...
* 	\param uint32_t dio -...
* 	\param DioDirection_t  dir -...
* 	\return bool -...
*/
bool dio_set_direction(uint32_t dio, DioDirection_t  dir)
{
  if ( DIO_Valid(dio) )
  {    
      // sets this port to direction
      if (dir == DIODIR_INPUT)
      {      
          gpio_set_dir(dio_table[dio], GPIO_DIR_INPUT );
      }
      else if (dir == DIODIR_OUTPUT )
      {
          gpio_set_dir(dio_table[dio], GPIO_DIR_OUTPUT );                
      }	
      direction[dio]   = dir;    
    return true;
  }
  return false;
}

// get direction

/*!
* 	 DioDirection_t dio_get_direction(uint32_t dio)
* 
* 	...tbd...
* 	\param uint32_t dio -...
* 	\return DioDirection_t -...
*/
DioDirection_t dio_get_direction(uint32_t dio)
{
	if (DIO_Valid(dio))
	{		
		return direction[dio];
	}
    return DIODIR_UNDEF;
}

// output

/*!
* 	 int dio_get_output(uint32_t dio)
* 
* 	...tbd...
* 	\param uint32_t dio -...
* 	\return int -...
*/
int dio_get_output(uint32_t dio)
{   
	if (DIO_Valid(dio))
	{		
		return (int)gpio_get( dio_table[dio]);
	}	
    return -1;
}


// TODO must reconfigure

/*!
* 	 int dio_get(uint32_t dio )
* 
* 	...tbd...
* 	\param uint32_t dio -...
* 	\return int -...
*/
int dio_get(uint32_t dio )
{    
    if (DIO_Valid(dio))
    {
        if (direction[dio] == DIODIR_UNDEF)         
           gpio_enable( dio_table[dio], GPIO_IN);           
        return (int) gpio_get( dio_table[dio]);      
    }
  return -1;
}



/*!
* 	 bool dio_set(int32_t dio, char *p)
* 
* 	...tbd...
* 	\param int32_t dio -...
* 	\param char *p -...
* 	\return bool -...
*/
bool dio_set(int32_t dio, char *p)
{    
    
  if (DIO_Valid(dio) )
  {   
      // if direction is undefined
	 if (direction[dio] == DIODIR_UNDEF)	 
		gpio_enable( dio_table[dio] ,GPIO_OUT);// set as OUTPUT	                  	 
     
	int i=0;
	while( p[i] != '\0')
	{
		if (p[i] == '0' )    gpio_set( dio_table[dio], 0);
		else if(p[i]=='1')   gpio_set( dio_table[dio], 1);
		else if (p[i] == 't')  gpio_toggle( dio_table[dio]);
		else if (p[i] == 'u')  CHRONO1_DELAY(1);
		else   return false;
		i++;
	}		
		return true;
  }
  return false;
}


//configures pin as DIO port 
// 1- pullup 
// 2- pulldown

/*!
* 	 bool dio_conf(uint32_t dio, uint32_t conf)
* 
* 	...tbd...
* 	\param uint32_t dio -...
* 	\param uint32_t conf -...
* 	\return bool -...
*/
bool dio_conf(uint32_t dio, uint32_t conf)
{        
	bool result = false;
    if(DIO_Valid(dio))
    {
        if(direction[dio] == DIODIR_INPUT)   {        
            uint32_t opt =GPIO_IN;
            if( conf == 1) {                
                    opt |= CN_PULLUP|CN_ENABLE;
            }
            else if(conf == 10 ){                
                opt |= CN_PULLDOWN|CN_ENABLE;
            }
            gpio_enable(dio_table[dio] ,opt);
        }
        else if(direction[dio] == DIODIR_OUTPUT)
            gpio_enable(dio_table[dio] ,GPIO_OUT);
        else{
            gpio_enable(dio_table[dio] ,GPIO_IN);
        }
        result = true;
    }
  return result;
}
