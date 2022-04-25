/*!
 * @file string_utils.h
 * @author D.Chikov
 * @date 10/15/2020, 10:20:51
 * @brief ...tbd...
 */


#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stdint.h>
#include <stdbool.h>
#include "string.h"
#include "stdio.h"


/*!
 * Maximum string length
 */
#define  STRING_UTILS_MAX_LEN   (1000)

/*!
 * Ascii chanractetr to binary
 */
#define ascii2bin(C)			((C)-'0')
#define LETTER_CASE_DIFF        ('a' - 'A')

/*!
 * Converts ASCII character to lower case
 */
#define fromUpperToLower(V)	((V)+LETTER_CASE_DIFF)
/*!
 * Converts ASCII character to higher case
 */
#define fromLowerToUpper(V)	((V)-LETTER_CASE_DIFF)

/*!
 * Converts ASCII character to lower case
 */
#define toLower(V) (( (V)>='A' && (V)<='Z' ) ? (fromUpperToLower(V)) : (V) )
/*!
 * Converts ASCII character to higher case
 */
#define toUpper(V) (( (V)>='a' && (V)<='z' ) ? (fromLowerToUpper(V)) : (V) )

typedef struct {
    int start;
    int end;
} StrCursor;



/*!
 * ...tbd...
 */
#define is_upper_case(C) ( ( (C) >= 'A') && ( (C) <= 'Z') )
#define is_lower_case(C)  ( ( (C) >= 'a') && ( (C) <= 'z') )
#define is_symbol(C)  ( ( (C) >= ' ') && ( (C) <= '~') )
#define is_letter(C) ( is_lower_case(C) || is_upper_case(C) )
#define is_digit(C) ( (C) >= '0' && (C) <= '9')


/*!
 * ...tbd...
 */
int32_t copy_text(char pdst[], const char psrc[], int32_t maxlen);

/*!
 * ...tbd...
 */
int32_t rm_symbol_from_text(char *pdst, const char *psrc, char symb);
/*!
 * ...tbd...
 */
int32_t split_text(char pbuf[], const char pstr[], char delimeter);
/*!
 * ...tbd...
 */
int32_t split_text2(StrCursor sc[], const char pstr[], char delimeter);
/*!
 * ...tbd...
 */
int32_t findpos(const char pbuf[], char delimeter);

/*!
 * ...tbd...
 */
int32_t bytes_from_hex(uint8_t *pdata, const char* phex_str);
/*!
 * ...tbd...
 */
void bytes_to_hex(char *phex_str, const uint8_t* pdata, int32_t data_len);
/*!
 * ...tbd...
 */
void to_lower_case(char pstr[]);
/*!
 * ...tbd...
 */
void to_upper_case(char pstr[]);
/*!
 * ...tbd...
 */
bool compare_string(const char pstr1[], const char pstr2[]);
/*!
 * ...tbd...
 */
bool compare_string_n(const char pstr1[], const char pstr2[], int32_t len);



/************************************************************************
    string_utils_ascii_to_byte - ---
    Parameter : 
    char symb									
    Return : uint8_t 
 ************************************************************************/
/*!
 * ...tbd...
 */
uint8_t ascii_to_byte(char symb);
/************************************************************************
    string_utils_byte_to_ascii - ---
    Parameter : 
    uint8_t byte									
    Return : char 
 ************************************************************************/
/*!
 * ...tbd...
 */
char byte_to_ascii(uint8_t byte);

/*!
 * ...tbd...
 */
int StrToUInt(const char *text);
/*!
 * MACRO:...tbd...
 */
#define StrToInt(STR) atoi(STR) 
#endif