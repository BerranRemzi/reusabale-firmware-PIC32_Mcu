/*!
* @file parser.c
* @author D.Chikov
* @date 10/15/2020, 10:20:45
* @brief ...tbd...
*/



#include "string_utils.h"
#include "parser.h"
#include <stdlib.h>
#include "system.h"
#include <stdarg.h>




//last parsed parameter value
static char *parameter_value;
static char parameter_name[50];
static char *parameter_all_text;



/*!
* 	 void syntax_init(bool case_sensitive)
* 
* 	...tbd...
* 	\param bool case_sensitive -...
* 	\return void -...
*/
void syntax_init(bool case_sensitive)
{

}
/* *********************************************************************
@Function name: this_parse_parameter
@Return: (bool) - 0 - not ok
@Parameters:
    const char par_str[] - parameter string
@Description: This function parses parameter string
in format "parameter=value"
 ********************************************************************* */

/*!
* 	  int32_t this_parse_item(char pstr[])
* 
* 	...tbd...
* 	\param char pstr[] -...
* 	\return int32_t -...
*/
static inline int32_t this_parse_item(char pstr[]) {

    if ( pstr == NULL) return false;    
     
    parameter_all_text = pstr; //pointer to variable name
    parameter_value =0; //pointer to variable value
    int32_t var_len;
    int32_t i = 0;
    int32_t str_len = strlen(pstr);
    /* parameter has = so will be evaluated as set type*/
    var_len = findpos(pstr, '=');    
    if (var_len > 0) {
        parameter_value = &pstr[ var_len + 1 ];
    } else {
        /* if no value for variable value pointer points to variable*/
        var_len = str_len;
    }    
    // save parameter name
    copy_text(parameter_name, parameter_all_text, var_len);
    parameter_name[var_len] = '\0';

    /* find parameter in list */
    for (i = 0; i < ITEMS_COUNT; i++) {
        if (syntax_data[i].name_len == var_len
                && compare_string_n(syntax_data[i].name, parameter_all_text, var_len)) {
            return syntax_data[i].id;
        }
    }

    return -1;
}

/* *********************************************************************
@Function name: syntax_string - parsing a string
@Return: (uint32_t)
@Parameters:
    const char pstr[] - string to syntax
@Description:
 This function parses string on parameters and commands
********************************************************************* */


/*!
* 	 void parse_string( char *ptext, char *pline_end)
* 
* 	...tbd...
* 	\param char *ptext -...
* 	\param char *pline_end -...
* 	\return void -...
*/
void parse_string( char *ptext, char *pline_end)
{ 

  int32_t command_id = -1;
  int32_t parameter_id = -1;
  int32_t chains ;
  
      
  //split string and put data to this string back
  chains = split_text(ptext, ptext,  ' ');    
  int32_t pos = 0;
  int i;
  for(i=0;i<chains;i++ )
    {      
      //[COMMAND] - first item is always command
      if (i == 0 )
      {          
        /* parse command*/
        command_id = this_parse_item( &ptext[pos] );

        if(command_id != -1)
            on_parameter_found(PARSER_START, command_id, -1, (void*)parameter_value);
        else {
            printf("%s:err",&ptext[pos]);
            break;
        }
      }
      // [PARAMETER]
      else
      {
        /* parse parameter*/
        parameter_id = this_parse_item( &ptext[pos] );
        if ( parameter_id != -1)
        {
             on_parameter_found(PARSER_PARAMETER, command_id, parameter_id, (void*)parameter_value);
        }
        /* parameter not found in list*/
        else
        {
          on_parameter_found(PARSER_PARAMETER, command_id, -1 , (void*)parameter_all_text);
        }
      }
      /* switch to next parameter */
      pos += strlen(&ptext[pos]) + 1;
    }

    on_parameter_found(PARSER_STOP, command_id, -1, (void*)parameter_value);
    printf(pline_end);

}

/*!
* 	 int32_t string_utils_split(char pbuf[], const char pstr[],  char delimeter)
*        This function cuts the sring on a words with one \0 behind every word
* 	...tbd...
* 	\param char pbuf[] - buffer to get data to
* 	\param const char pstr[] - string from
* 	\param char delimeter - delimeter
* 	\return int32_t - chains number.
*/
int32_t split_text(char pbuf[], const char pstr[],  char delimeter)
{
    int chains = 0;
    char prev=0;
    int b0=0,b1=0;
    bool br=0;

    if(pstr==0 || pbuf ==0) return -1;

    while(*pstr != '\0')
    {
        if(*pstr=='[') { br=1; }
        else if(*pstr==']') { br=0;}

        if(*pstr != delimeter ||br) {
            pbuf[b1++] = *pstr;
        }
        else{
                if( prev != delimeter && b1>b0){
                    chains++;
                    pbuf[b1]=0;
                    b0=++b1;
                }
        }
        prev = *pstr++;
    }
    if(b1>b0){
        pbuf[b1]=0;
        chains++;
    }

    return chains;
}


/* *********************************************************************
@Function name: syntax_parameter_name()
@Return: (const char*)
@Parameters:
    void
@Description:
   This function gets id and returns pointer to name
********************************************************************* */

/*!
* 	  char* syntax_parameter_name(void)
* 
* 	...tbd...
* 	\return char* -...
*/
const char* syntax_parameter_name(void)
{
  return parameter_name;
}


//int parse_parameters(const char *format, ...){
//   va_list ap;
//   int i;
//
//   va_start(ap, num_args);
//   for(i = 0; i < num_args; i++) {
//      val += va_arg(ap, int);
//   }
//   va_end(ap);
// 
//   return val;
//   
//    return 0;
//}