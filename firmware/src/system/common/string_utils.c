/*!
* @file string_utils.c
* @author D.Chikov
* @date 10/15/2020, 10:20:51
* @brief ...tbd...
*/


#include "string_utils.h"
#include "board.h"


/*!
* 	 int32_t string_utils_remove_symbol(char *pdst, const char *psrc, char symb)
*       Removes  all quotations in text.
*               Is allowed to have the same string pointer
* 	\param char *pdst -...
* 	\param const char *psrc -...
* 	\param char symb -...
* 	\return int32_t -...
*/
int32_t rm_symbol_from_text(char *pdst, const char *psrc, char symb)
{
    int32_t i, j = 0;
    if (pdst != NULL && psrc != NULL)
    {
        for (i = 0; i < STRING_UTILS_MAX_LEN; i++)
        {
            if (psrc[i] == '\0' ) { break; }
            if (psrc[i] != symb )
            {
                pdst[j++] = psrc[i];
            }
        }
        pdst[j] = '\0';
    }
    return j;
}

/*!
* 	 int32_t string_utils_copy(char pdst[], const char psrc[], int32_t maxlen)
* 
* 	Copies string
* 	\param char pdst[] -...
* 	\param const char psrc[] -...
* 	\param int32_t maxlen -...
* 	\return int32_t -...
*/
int32_t copy_text(char pdst[], const char psrc[], int32_t maxlen)
{
    int32_t result = -1;
    if (psrc != NULL)
    {
        while (*psrc != '\0' && maxlen--)
        {
            result++;
            *pdst++ = *psrc++;
        }
        result++;
    }
    return result;
}





int split_text2(StrCursor sc[],  const char pstr[] ,char delimeter)
{
    int chains = 0;
    char prev=0;
    int b0=0,b1=0;
    bool br=0;

    if(pstr==0 ) return -1;

    while(*pstr != '\0')
    {        
        if(*pstr == '[') br=1;
        else if(*pstr == ']') br=0;

        if(*pstr != delimeter || br) {
            b1++;
        }
        else{
            if(prev != delimeter ){
                sc[chains].end = b1;
                sc[chains].start = b0;
                chains++;
                b0 = b1;
            }
            b1=++b0;
        }
        prev = *pstr++;
    }
    if(b1>b0){
        sc[chains].end = b1;
        sc[chains].start = b0;
        chains++;
    }

    return chains;
}

/*!
* 	 int32_t string_utils_strchr(const char pbuf[], char delimeter)
* 
* 	 finds delimeter, first occurence
* 	\param const char pbuf[] - buffer of data bytes
* 	\param char delimeter -  delimeter data
* 	\return int32_t position number
*/
int32_t findpos(const char pbuf[], char delimeter)
{
    int32_t result = -1;
    if (pbuf != NULL)
    {
        int32_t pos;
        for (pos = 0; (pos < STRING_UTILS_MAX_LEN) && pbuf[pos]; pos++)
        {
            if (pbuf[pos] == delimeter)
            {
                result = pos;
                break;
            }
        }
    }
    return result;
}


/*!
* 	 void string_utils_to_lower_case(char pstr[])
* 
* 	changes all letters to low case
* 	\param char pstr[] -string pointer
* 	\return void -...
*/
void to_lower_case(char pstr[])
{
    uint32_t i = 0;
    int32_t maxlen = STRING_UTILS_MAX_LEN;
    while (pstr[i] && maxlen--)
    {
        if ( is_upper_case(pstr[i]) )
        {
            pstr[i] = fromUpperToLower(pstr[i]);
        }
        i++;

    }
}


/*!
* 	 void string_utils_to_upper_case(char pstr[])
* 	changes all letters to upper case
* 	\param char pstr[] - string pointer
* 	\return void -...
*/
void to_upper_case(char pstr[])
{
    uint32_t i = 0;
    int32_t maxlen = STRING_UTILS_MAX_LEN;
    while (pstr[i] && maxlen--)
    {
        if ( is_lower_case(pstr[i]) )
        {
            pstr[i] = fromLowerToUpper(pstr[i]);

        }
        i++;
    }
}


/*!
* 	 bool string_utils_strcmp(const char pstr1[], const char pstr2[])
* 
* 	compres two string  and its' length
* 	\param const char pstr1[] - string 1 
* 	\param const char pstr2[] - string 2
* 	\return bool - True if identical
*/
bool compare_string(const char pstr1[], const char pstr2[])
{
    bool result = false;
    if (pstr1 != NULL && pstr2 != NULL )
    {
        int32_t len1 = strlen(pstr1);
        int32_t len2 = strlen(pstr2);
        if (len1 == len2)
        {
            result = compare_string_n(pstr1, pstr2, len1);
        }
    }
    return result;
}


/*!
* 	 bool string_utils_strncmp(const char pstr1[], const char pstr2[], int32_t len)
* 
* 	compres two string  and its' length
* 	\param const char pstr1[] -...
* 	\param const char pstr2[] -...
* 	\param int32_t len -...
* 	\return bool -...
*/
bool compare_string_n(const char pstr1[], const char pstr2[], int32_t len)
{
    bool result = false;
    int32_t pos = 0;
    while ( len-- )
    {
        char symb1 = pstr1[pos];
        char symb2 = pstr2[pos];
        if (symb1 == '\0' || symb2 == '\0')
        {
            break;
        }
        //all compare as upper case
        
            if ( is_upper_case(symb1) )
            {
                symb1 = fromUpperToLower(symb1);
            }
            if ( is_upper_case(symb2) )
            {
                symb2 = fromUpperToLower(symb2);
            }
        
        
        if (symb1 == symb2 || symb1 == '?' || symb2 == '?')
        {
            result = true;
        }
        else
        {
            result = false;
            break;
        }
        pos++;
    }
    return result;
}






/*!
* 	 uint8_t string_utils_ascii_to_byte(char symb)
* 
* 	...tbd...
* 	\param char symb -...
* 	\return uint8_t -...
*/
uint8_t ascii_to_byte(char symb)
{
	uint8_t byte=0;
    switch (symb)
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        byte = (uint8_t)(symb - '0');
		break;
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
        byte = (uint8_t)(symb - 'a') + 10;
		break;
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
        byte =  (uint8_t)(symb - 'A') + 10;
		break;
    }
	return byte;
}


/*!
* 	 char string_utils_byte_to_ascii(uint8_t byte)
* 
* 	...tbd...
* 	\param uint8_t byte -...
* 	\return char -...
*/
char byte_to_ascii(uint8_t byte)
{
    char result;
    switch (byte)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        result = byte + '0';
        break;
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        result = byte - 10 + 'a';
        break;
    default:
        result = ' ';
        break;
    }
    return result;
}



/*!
* 	 int32_t string_utils_from_hex(uint8_t *pdata, const char* phex_str)
* 
* 	...tbd...
* 	\param uint8_t *pdata -...
* 	\param const char* phex_str -...
* 	\return int32_t -...
*/
int32_t bytes_from_hex(uint8_t *pdata, const char* phex_str)
{
    int32_t i = 0;
    int32_t j = 0;
    int32_t len = strlen(phex_str);
    while (i < (len - 1))
    {
        pdata[j] =  ascii_to_byte(phex_str[i]) * 16
                    + ascii_to_byte(phex_str[i + 1]);
        i += 2; j++;
    }
    return j;
}


/*!
* 	 void string_utils_to_hex(char *phex_str, const uint8_t* pdata, int32_t data_len)
* 
* 	...tbd...
* 	\param char *phex_str -...
* 	\param const uint8_t* pdata -...
* 	\param int32_t data_len -...
* 	\return void -...
*/
void bytes_to_hex(char *phex_str, const uint8_t* pdata, int32_t data_len)
{
    int32_t i;
    for (i = 0; i < data_len; i++)
    {
        sprintf(&phex_str[2 * i], "%02x ", (unsigned int)pdata[i]);
    }
}



/*!
* 	 int StrToUInt(const char *text)
* 
* 	...tbd...
* 	\param const char *text -...
* 	\return int -...
*/
int StrToUInt(const char *text)
{
    int i;
    int res=0;
    int w = 1;
    int base =10;
    const char*p=text;
    if(text[0]=='0' && text[1] == 'x' ){
        p = &text[2];
        base = 16;
    }


    int len= strlen(p);
    for(i=len-1; i>=0; i--){
        const char c = p[i];
        switch (c)
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            res += (c-'0')*w;
            break;

            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
            res += (c-'a'+10)*w;
            break;

            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            res += (c-'A'+10)*w;
            break;
        }
        w *= base;
    }
   return res;
}
