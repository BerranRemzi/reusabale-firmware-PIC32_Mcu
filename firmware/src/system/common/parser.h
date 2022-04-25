/*!
* @file parser.h
* @author D.Chikov
* @date 10/15/2020, 10:20:45
* @brief ...tbd...
*/


#ifndef PARSER_H
#define PARSER_H

#include "board.h"

#define PARAMETER_NAME_LEN      (50)

#include "typedef_global.h"
#include "string_utils.h"


  

typedef enum {
	PARSER_PARAMETER ,
	PARSER_START,
	PARSER_STOP,
	PARSER_ERROR
}SyntaxOperation_t;
	

typedef struct {
    char name[PARAMETER_NAME_LEN]; //null ternminated command text
    int32_t name_len;
    int32_t id;    
} SyntaxItemData_t;


/*!
* Initialize syntax analyzer
*/
void syntax_init(bool case_sensitive);


/*!
* Parses string
*/
void parse_string( char *ptext, char *pline_end);

// returns pointer to data as string
/*!
* ...tbd...
*/
const char* syntax_parameter_name(void);

/*declare this function must be declared in the code*/
void on_parameter_found(SyntaxOperation_t operation ,int32_t cmd_id 
			, int32_t p_id  ,const void* p);



#include "app_commands.h"
/*!
* MACRO:...tbd...
*/
#define SYNTAX_ITEM(TXT,ID) ID
 typedef enum { 
     ITEMS_LIST,
     ITEMS_COUNT
    }SyntaxItemEnum_t;

#undef SYNTAX_ITEM
/*!
* MACRO:...tbd...
*/
#define SYNTAX_ITEM(TXT,ID) {TXT,sizeof(TXT)-1,ID}
static const SyntaxItemData_t syntax_data[ITEMS_COUNT] = {
        ITEMS_LIST,
};

int parse_parameters(const char *format, ...);


#endif
