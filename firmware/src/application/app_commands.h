/*!
* @file app_commands.h
* @author D.Chikov
* @date 10/15/2020, 10:20:56
* @brief ...tbd...
*/


#ifndef __COMMAND_LIST
#define __COMMAND_LIST



/*!
* MACRO:...tbd...
*/
#define ITEMS_LIST \
/* dio */       SYNTAX_ITEM("dio??"         ,Parameter_dio2          ),\
                SYNTAX_ITEM("dio?"          ,Parameter_dio1          ),\
                SYNTAX_ITEM("dio?out"           ,Parameter_dioout    ),\
                SYNTAX_ITEM("dio??out"          ,Parameter_dioout2   ),\
                SYNTAX_ITEM("dio?dir"           ,Parameter_diodir    ),\
                SYNTAX_ITEM("dio??dir"          ,Parameter_diodir2   ),\
/*---------------------------------------------------------------------------------------------*/\
                SYNTAX_ITEM("dioseq?"       ,Parameter_dioseq1       ),\
                SYNTAX_ITEM("dioseq??"      ,Parameter_dioseq2       ),\
                SYNTAX_ITEM("dio?conf"      ,Parameter_dioconf       ),\
                SYNTAX_ITEM("dio??conf"     ,Parameter_dioconf2      ),\
/*---------------------------------------------------------------------------------------------*/\
/* rel */       SYNTAX_ITEM("rel?"           ,Parameter_rel1        ),\
                SYNTAX_ITEM("rel??"          ,Parameter_rel2        ),\
                SYNTAX_ITEM("re??"           ,Parameter_re        ),\
                SYNTAX_ITEM("relconf"       ,Parameter_relconf      ),\
                SYNTAX_ITEM("relconf_HC595" ,Parameter_relconf_hc595),\
/*---------------------------------------------------------------------------------------------*/\
/* pwm */       SYNTAX_ITEM("pwm?freq"      ,Parameter_pwmfreq    ),\
                SYNTAX_ITEM("pwm?duty"      ,Parameter_pwmduty    ),\
                SYNTAX_ITEM("pwm?conf"      ,Parameter_pwmconf    ),\
                SYNTAX_ITEM("pwm?enable"        ,Parameter_pwmenable  ),\
                SYNTAX_ITEM("pwm?start"     ,Parameter_pwmstart   ),\
                SYNTAX_ITEM("pwm?stop"      ,Parameter_pwmstop     ),\
/*---------------------------------------------------------------------------------------------*/\
/* ain */       SYNTAX_ITEM("ain?"          ,Parameter_ain         ),\
                SYNTAX_ITEM("ainconf"      ,Parameter_ainconf       ),\
/*---------------------------------------------------------------------------------------------*/\
/* spi */       SYNTAX_ITEM("spi?cs?data"   ,Parameter_spidata      ),\
                SYNTAX_ITEM("spi?cs?speed"  ,Parameter_spispeed    ),\
                SYNTAX_ITEM("spi?cs?conf"     ,Parameter_spicsconf      ),\
/*---------------------------------------------------------------------------------------------*/\
/* ser */       SYNTAX_ITEM("ser?data"      ,Parameter_serdata      ),\
                SYNTAX_ITEM("ser?conf"      ,Parameter_serconf      ),\
                SYNTAX_ITEM("ser?baud"      ,Parameter_serbaud      ),\
                SYNTAX_ITEM("ser?mode"      ,Parameter_sermode      ),\
                SYNTAX_ITEM("ser?bits"      ,Parameter_serbits      ),\
                SYNTAX_ITEM("ser?parity"    ,Parameter_serparity    ),\
                SYNTAX_ITEM("ser?stopb"     ,Parameter_serstopb     ),\
/*---------------------------------------------------------------------------------------------*/\
/* can */       SYNTAX_ITEM("can?data"      ,Parameter_candata      ),\
                SYNTAX_ITEM("can?conf"      ,Parameter_canconf      ),\
/*---------------------------------------------------------------------------------------------*/\
/* aout */      SYNTAX_ITEM("aout?"         ,Parameter_aout        ),\
				SYNTAX_ITEM("aout?conf"     ,Parameter_aoutconf     ),\
/*---------------------------------------------------------------------------------------------*/\
/* i2c */       SYNTAX_ITEM("i2c?data"      ,Parameter_i2cdata      ),\
                SYNTAX_ITEM("i2c?conf"      ,Parameter_i2cconf      ),\
                SYNTAX_ITEM("i2c?speed"     ,Parameter_i2cspeed     ),\
                SYNTAX_ITEM("i2c?datawr"	,Parameter_i2cdatawr	),\
/*---------------------------------------------------------------------------------------------*/\
/* misc */      SYNTAX_ITEM("session"       ,Parameter_session      ),\
                SYNTAX_ITEM("key?"          ,Parameter_key           ),\
/*---------------------------------------------------------------------------------------------*/\
                SYNTAX_ITEM("baudrate"      ,Parameter_baudrate     ),\
                SYNTAX_ITEM("err"           ,Parameter_errors        ),\
                SYNTAX_ITEM("ver"           ,Parameter_version     ),\
                SYNTAX_ITEM( "reset"        , Command_reset        ),\
                SYNTAX_ITEM( "delay"         , Parameter_delay     ),\
                SYNTAX_ITEM( "wait"         , Command_wait        ),\
/*---------------------------------------------------------------------------------------------*/\
/*Commands*/    SYNTAX_ITEM("set"           , Command_set         ),\
                SYNTAX_ITEM("get"           , Command_get         ),\
                SYNTAX_ITEM("run"           , Command_run        ),\
                SYNTAX_ITEM("*idn?"         , Command_idn       ),\
/*---------------------------------------------------------------------------------------------*/\
                SYNTAX_ITEM("swspi"         ,Parameter_swspi       ),\
                SYNTAX_ITEM("swspiconfcs?"  ,Parameter_swspiconf    ),\
                SYNTAX_ITEM("swspics?"      ,Parameter_swspics   ),\
                SYNTAX_ITEM("sequence"      ,Parameter_sequence      ),\
                SYNTAX_ITEM("sequenceconf"      ,Parameter_sequenceconf      ),\
                SYNTAX_ITEM("scanchainconf" ,Parameter_scanchainconf   ),\
                SYNTAX_ITEM("scanchain1"    ,Parameter_scanchain1   ),\
                SYNTAX_ITEM("scanchain2"    ,Parameter_scanchain2    ),\
                SYNTAX_ITEM("scanchain3"    ,Parameter_scanchain3    ),\
                SYNTAX_ITEM("intadc"    ,Parameter_intadc    ),\
                SYNTAX_ITEM("jtag"    ,Parameter_jtag    ),\
                SYNTAX_ITEM("refclkconf"    ,Parameter_refclkconf    ),\
                SYNTAX_ITEM("refclkenable"    ,Parameter_refclkenable    ),\
                SYNTAX_ITEM("capconf"    ,Parameter_capconf    ),\
                SYNTAX_ITEM("captrig"    ,Parameter_captrig    ),\
                SYNTAX_ITEM("capres"    ,Parameter_capres    ),\
                SYNTAX_ITEM("genclk"        ,Parameter_genclk        )
                


#endif

