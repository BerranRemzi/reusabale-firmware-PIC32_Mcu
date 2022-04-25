/*!
* @file system_error_codes.h
* @author D.Chikov
* @date 10/15/2020, 09:37:34
* @brief ...tbd...
*/


#ifndef SYS_ERROR_CODES_H
#define SYS_ERROR_CODES_H


typedef enum{ 
    SYS_ERROR_MEMORY        =   (0xf005u),
    SYS_ERROR_CONFIG          =   (0xf004u),
    SYS_ERROR_COMMUNICATION =   (0xf001u),
    APP_ERRORS,   
}ErrorCodes;


#endif


