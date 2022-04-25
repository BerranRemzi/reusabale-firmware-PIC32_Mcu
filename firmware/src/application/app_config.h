/*!
* @file app_config.h
* @author D.Chikov
* @date 10/15/2020, 09:37:33
* @brief ...tbd...
*/


// define application configuration
#ifndef _APP_CONFIG_H
#define _APP_CONFIG_H



#define USE_CONFIG      (0)

/*!
* MACRO:...tbd...
*/
#define COMM_BUFFER_SIZE    (1000u)



// config structure
/*!
* MACRO:...tbd...
*/
#define APP_CONFIG\
        uint32_t tmp1; \
        uint32_t tmp2;\
        uint32_t tmp3;\


//config values
/*!
* MACRO:...tbd...
*/
#define DEFAULT_CONFIG\
       .tmp1 = 0,\
        .tmp2 = 0,\
        .tmp3 = 0,\

#endif