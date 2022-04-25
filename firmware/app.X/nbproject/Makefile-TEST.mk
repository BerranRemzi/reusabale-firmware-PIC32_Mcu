#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-TEST.mk)" "nbproject/Makefile-local-TEST.mk"
include nbproject/Makefile-local-TEST.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=TEST
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/app.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/app.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/application/chrono/chrono.c ../src/application/extdev/ad5641.c ../src/application/modules/dio.c ../src/application/modules/genclk.c ../src/application/modules/relay.c ../src/application/modules/unisequencer.c ../src/application/modules/mod_pwm.c ../src/application/modules/mod_spi.c ../src/application/modules/mod_swspi.c ../src/application/modules/mod_i2c.c ../src/application/modules/aout.c ../src/application/modules/ain.c ../src/application/modules/scanchain.c ../src/application/modules/intadc.c ../src/application/modules/mod_refclk.c ../src/application/modules/cap.c ../src/application/app.c ../src/application/on_parameter_found.c ../src/board/board.c ../src/driver/adc/adc.c ../src/driver/can/can.c ../src/driver/gpio/gpio.c ../src/driver/int/int.c ../src/driver/nvmem/nvm.c ../src/driver/pwm/pwm.c ../src/driver/refclk/refclk.c ../src/driver/spi/spi.c ../src/driver/spi/swspi.c ../src/driver/systmr/systmr.c ../src/driver/usart/usart.c ../src/driver/wdt/wdt.c ../src/system/common/rd_buffer.c ../src/system/common/parser.c ../src/system/common/string_utils.c ../src/system/planner/planner.c ../src/system/system_exceptions.c ../src/system/system_init.c ../src/system/system_dbg.c ../src/system/system_time.c ../src/system/system_config.c ../src/system/system_comm.c ../src/system/system_error.c ../src/system/crc.c ../src/main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/744274812/chrono.o ${OBJECTDIR}/_ext/816358189/ad5641.o ${OBJECTDIR}/_ext/2070436302/dio.o ${OBJECTDIR}/_ext/2070436302/genclk.o ${OBJECTDIR}/_ext/2070436302/relay.o ${OBJECTDIR}/_ext/2070436302/unisequencer.o ${OBJECTDIR}/_ext/2070436302/mod_pwm.o ${OBJECTDIR}/_ext/2070436302/mod_spi.o ${OBJECTDIR}/_ext/2070436302/mod_swspi.o ${OBJECTDIR}/_ext/2070436302/mod_i2c.o ${OBJECTDIR}/_ext/2070436302/aout.o ${OBJECTDIR}/_ext/2070436302/ain.o ${OBJECTDIR}/_ext/2070436302/scanchain.o ${OBJECTDIR}/_ext/2070436302/intadc.o ${OBJECTDIR}/_ext/2070436302/mod_refclk.o ${OBJECTDIR}/_ext/2070436302/cap.o ${OBJECTDIR}/_ext/801483606/app.o ${OBJECTDIR}/_ext/801483606/on_parameter_found.o ${OBJECTDIR}/_ext/1537666708/board.o ${OBJECTDIR}/_ext/1509319821/adc.o ${OBJECTDIR}/_ext/1509317981/can.o ${OBJECTDIR}/_ext/455916380/gpio.o ${OBJECTDIR}/_ext/1509311806/int.o ${OBJECTDIR}/_ext/1255152928/nvm.o ${OBJECTDIR}/_ext/1509304807/pwm.o ${OBJECTDIR}/_ext/353641468/refclk.o ${OBJECTDIR}/_ext/1509302145/spi.o ${OBJECTDIR}/_ext/1509302145/swspi.o ${OBJECTDIR}/_ext/401144697/systmr.o ${OBJECTDIR}/_ext/1261517080/usart.o ${OBJECTDIR}/_ext/1509298662/wdt.o ${OBJECTDIR}/_ext/210424401/rd_buffer.o ${OBJECTDIR}/_ext/210424401/parser.o ${OBJECTDIR}/_ext/210424401/string_utils.o ${OBJECTDIR}/_ext/783894060/planner.o ${OBJECTDIR}/_ext/73441385/system_exceptions.o ${OBJECTDIR}/_ext/73441385/system_init.o ${OBJECTDIR}/_ext/73441385/system_dbg.o ${OBJECTDIR}/_ext/73441385/system_time.o ${OBJECTDIR}/_ext/73441385/system_config.o ${OBJECTDIR}/_ext/73441385/system_comm.o ${OBJECTDIR}/_ext/73441385/system_error.o ${OBJECTDIR}/_ext/73441385/crc.o ${OBJECTDIR}/_ext/1360937237/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/744274812/chrono.o.d ${OBJECTDIR}/_ext/816358189/ad5641.o.d ${OBJECTDIR}/_ext/2070436302/dio.o.d ${OBJECTDIR}/_ext/2070436302/genclk.o.d ${OBJECTDIR}/_ext/2070436302/relay.o.d ${OBJECTDIR}/_ext/2070436302/unisequencer.o.d ${OBJECTDIR}/_ext/2070436302/mod_pwm.o.d ${OBJECTDIR}/_ext/2070436302/mod_spi.o.d ${OBJECTDIR}/_ext/2070436302/mod_swspi.o.d ${OBJECTDIR}/_ext/2070436302/mod_i2c.o.d ${OBJECTDIR}/_ext/2070436302/aout.o.d ${OBJECTDIR}/_ext/2070436302/ain.o.d ${OBJECTDIR}/_ext/2070436302/scanchain.o.d ${OBJECTDIR}/_ext/2070436302/intadc.o.d ${OBJECTDIR}/_ext/2070436302/mod_refclk.o.d ${OBJECTDIR}/_ext/2070436302/cap.o.d ${OBJECTDIR}/_ext/801483606/app.o.d ${OBJECTDIR}/_ext/801483606/on_parameter_found.o.d ${OBJECTDIR}/_ext/1537666708/board.o.d ${OBJECTDIR}/_ext/1509319821/adc.o.d ${OBJECTDIR}/_ext/1509317981/can.o.d ${OBJECTDIR}/_ext/455916380/gpio.o.d ${OBJECTDIR}/_ext/1509311806/int.o.d ${OBJECTDIR}/_ext/1255152928/nvm.o.d ${OBJECTDIR}/_ext/1509304807/pwm.o.d ${OBJECTDIR}/_ext/353641468/refclk.o.d ${OBJECTDIR}/_ext/1509302145/spi.o.d ${OBJECTDIR}/_ext/1509302145/swspi.o.d ${OBJECTDIR}/_ext/401144697/systmr.o.d ${OBJECTDIR}/_ext/1261517080/usart.o.d ${OBJECTDIR}/_ext/1509298662/wdt.o.d ${OBJECTDIR}/_ext/210424401/rd_buffer.o.d ${OBJECTDIR}/_ext/210424401/parser.o.d ${OBJECTDIR}/_ext/210424401/string_utils.o.d ${OBJECTDIR}/_ext/783894060/planner.o.d ${OBJECTDIR}/_ext/73441385/system_exceptions.o.d ${OBJECTDIR}/_ext/73441385/system_init.o.d ${OBJECTDIR}/_ext/73441385/system_dbg.o.d ${OBJECTDIR}/_ext/73441385/system_time.o.d ${OBJECTDIR}/_ext/73441385/system_config.o.d ${OBJECTDIR}/_ext/73441385/system_comm.o.d ${OBJECTDIR}/_ext/73441385/system_error.o.d ${OBJECTDIR}/_ext/73441385/crc.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/744274812/chrono.o ${OBJECTDIR}/_ext/816358189/ad5641.o ${OBJECTDIR}/_ext/2070436302/dio.o ${OBJECTDIR}/_ext/2070436302/genclk.o ${OBJECTDIR}/_ext/2070436302/relay.o ${OBJECTDIR}/_ext/2070436302/unisequencer.o ${OBJECTDIR}/_ext/2070436302/mod_pwm.o ${OBJECTDIR}/_ext/2070436302/mod_spi.o ${OBJECTDIR}/_ext/2070436302/mod_swspi.o ${OBJECTDIR}/_ext/2070436302/mod_i2c.o ${OBJECTDIR}/_ext/2070436302/aout.o ${OBJECTDIR}/_ext/2070436302/ain.o ${OBJECTDIR}/_ext/2070436302/scanchain.o ${OBJECTDIR}/_ext/2070436302/intadc.o ${OBJECTDIR}/_ext/2070436302/mod_refclk.o ${OBJECTDIR}/_ext/2070436302/cap.o ${OBJECTDIR}/_ext/801483606/app.o ${OBJECTDIR}/_ext/801483606/on_parameter_found.o ${OBJECTDIR}/_ext/1537666708/board.o ${OBJECTDIR}/_ext/1509319821/adc.o ${OBJECTDIR}/_ext/1509317981/can.o ${OBJECTDIR}/_ext/455916380/gpio.o ${OBJECTDIR}/_ext/1509311806/int.o ${OBJECTDIR}/_ext/1255152928/nvm.o ${OBJECTDIR}/_ext/1509304807/pwm.o ${OBJECTDIR}/_ext/353641468/refclk.o ${OBJECTDIR}/_ext/1509302145/spi.o ${OBJECTDIR}/_ext/1509302145/swspi.o ${OBJECTDIR}/_ext/401144697/systmr.o ${OBJECTDIR}/_ext/1261517080/usart.o ${OBJECTDIR}/_ext/1509298662/wdt.o ${OBJECTDIR}/_ext/210424401/rd_buffer.o ${OBJECTDIR}/_ext/210424401/parser.o ${OBJECTDIR}/_ext/210424401/string_utils.o ${OBJECTDIR}/_ext/783894060/planner.o ${OBJECTDIR}/_ext/73441385/system_exceptions.o ${OBJECTDIR}/_ext/73441385/system_init.o ${OBJECTDIR}/_ext/73441385/system_dbg.o ${OBJECTDIR}/_ext/73441385/system_time.o ${OBJECTDIR}/_ext/73441385/system_config.o ${OBJECTDIR}/_ext/73441385/system_comm.o ${OBJECTDIR}/_ext/73441385/system_error.o ${OBJECTDIR}/_ext/73441385/crc.o ${OBJECTDIR}/_ext/1360937237/main.o

# Source Files
SOURCEFILES=../src/application/chrono/chrono.c ../src/application/extdev/ad5641.c ../src/application/modules/dio.c ../src/application/modules/genclk.c ../src/application/modules/relay.c ../src/application/modules/unisequencer.c ../src/application/modules/mod_pwm.c ../src/application/modules/mod_spi.c ../src/application/modules/mod_swspi.c ../src/application/modules/mod_i2c.c ../src/application/modules/aout.c ../src/application/modules/ain.c ../src/application/modules/scanchain.c ../src/application/modules/intadc.c ../src/application/modules/mod_refclk.c ../src/application/modules/cap.c ../src/application/app.c ../src/application/on_parameter_found.c ../src/board/board.c ../src/driver/adc/adc.c ../src/driver/can/can.c ../src/driver/gpio/gpio.c ../src/driver/int/int.c ../src/driver/nvmem/nvm.c ../src/driver/pwm/pwm.c ../src/driver/refclk/refclk.c ../src/driver/spi/spi.c ../src/driver/spi/swspi.c ../src/driver/systmr/systmr.c ../src/driver/usart/usart.c ../src/driver/wdt/wdt.c ../src/system/common/rd_buffer.c ../src/system/common/parser.c ../src/system/common/string_utils.c ../src/system/planner/planner.c ../src/system/system_exceptions.c ../src/system/system_init.c ../src/system/system_dbg.c ../src/system/system_time.c ../src/system/system_config.c ../src/system/system_comm.c ../src/system/system_error.c ../src/system/crc.c ../src/main.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-TEST.mk dist/${CND_CONF}/${IMAGE_TYPE}/app.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MZ1024EFH100
MP_LINKER_FILE_OPTION=,--script="..\app_mz.ld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/744274812/chrono.o: ../src/application/chrono/chrono.c  .generated_files/fa941f7efca8f48e2ea7ef23695996bf297a9531.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/744274812" 
	@${RM} ${OBJECTDIR}/_ext/744274812/chrono.o.d 
	@${RM} ${OBJECTDIR}/_ext/744274812/chrono.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/744274812/chrono.o.d" -o ${OBJECTDIR}/_ext/744274812/chrono.o ../src/application/chrono/chrono.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/816358189/ad5641.o: ../src/application/extdev/ad5641.c  .generated_files/1d7af58c257b93df8fa032e3563756c2943324c4.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/816358189" 
	@${RM} ${OBJECTDIR}/_ext/816358189/ad5641.o.d 
	@${RM} ${OBJECTDIR}/_ext/816358189/ad5641.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/816358189/ad5641.o.d" -o ${OBJECTDIR}/_ext/816358189/ad5641.o ../src/application/extdev/ad5641.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2070436302/dio.o: ../src/application/modules/dio.c  .generated_files/bee59bd975ce2c86966e7bef273a9c8a8a3845ae.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2070436302" 
	@${RM} ${OBJECTDIR}/_ext/2070436302/dio.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070436302/dio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2070436302/dio.o.d" -o ${OBJECTDIR}/_ext/2070436302/dio.o ../src/application/modules/dio.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2070436302/genclk.o: ../src/application/modules/genclk.c  .generated_files/6eb0129890580d93d8f9545f6112df3be5375ba0.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2070436302" 
	@${RM} ${OBJECTDIR}/_ext/2070436302/genclk.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070436302/genclk.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2070436302/genclk.o.d" -o ${OBJECTDIR}/_ext/2070436302/genclk.o ../src/application/modules/genclk.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2070436302/relay.o: ../src/application/modules/relay.c  .generated_files/55f7dc0c4d073e847f162b1d28aa7ce3bb64636d.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2070436302" 
	@${RM} ${OBJECTDIR}/_ext/2070436302/relay.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070436302/relay.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2070436302/relay.o.d" -o ${OBJECTDIR}/_ext/2070436302/relay.o ../src/application/modules/relay.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2070436302/unisequencer.o: ../src/application/modules/unisequencer.c  .generated_files/fddbea2b9d1c50c92b108a34461983911755289b.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2070436302" 
	@${RM} ${OBJECTDIR}/_ext/2070436302/unisequencer.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070436302/unisequencer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2070436302/unisequencer.o.d" -o ${OBJECTDIR}/_ext/2070436302/unisequencer.o ../src/application/modules/unisequencer.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2070436302/mod_pwm.o: ../src/application/modules/mod_pwm.c  .generated_files/8e9ec12724938daf9c3d2ec41022aaf3c3a92c30.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2070436302" 
	@${RM} ${OBJECTDIR}/_ext/2070436302/mod_pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070436302/mod_pwm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2070436302/mod_pwm.o.d" -o ${OBJECTDIR}/_ext/2070436302/mod_pwm.o ../src/application/modules/mod_pwm.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2070436302/mod_spi.o: ../src/application/modules/mod_spi.c  .generated_files/882d9e68dad9ba3b2a3fac0977df9c4fd65f3885.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2070436302" 
	@${RM} ${OBJECTDIR}/_ext/2070436302/mod_spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070436302/mod_spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2070436302/mod_spi.o.d" -o ${OBJECTDIR}/_ext/2070436302/mod_spi.o ../src/application/modules/mod_spi.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2070436302/mod_swspi.o: ../src/application/modules/mod_swspi.c  .generated_files/35f7662f11af55d7697d698b2918391833d6c52e.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2070436302" 
	@${RM} ${OBJECTDIR}/_ext/2070436302/mod_swspi.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070436302/mod_swspi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2070436302/mod_swspi.o.d" -o ${OBJECTDIR}/_ext/2070436302/mod_swspi.o ../src/application/modules/mod_swspi.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2070436302/mod_i2c.o: ../src/application/modules/mod_i2c.c  .generated_files/251f79b0fbe753850cc55816fcfabed1488b9779.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2070436302" 
	@${RM} ${OBJECTDIR}/_ext/2070436302/mod_i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070436302/mod_i2c.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2070436302/mod_i2c.o.d" -o ${OBJECTDIR}/_ext/2070436302/mod_i2c.o ../src/application/modules/mod_i2c.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2070436302/aout.o: ../src/application/modules/aout.c  .generated_files/870cfb0fe59550525efd0ed7e4f37a08d4a93f9d.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2070436302" 
	@${RM} ${OBJECTDIR}/_ext/2070436302/aout.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070436302/aout.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2070436302/aout.o.d" -o ${OBJECTDIR}/_ext/2070436302/aout.o ../src/application/modules/aout.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2070436302/ain.o: ../src/application/modules/ain.c  .generated_files/3d70f23b1325d4387b23a0a1c4a32ab16074e5b6.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2070436302" 
	@${RM} ${OBJECTDIR}/_ext/2070436302/ain.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070436302/ain.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2070436302/ain.o.d" -o ${OBJECTDIR}/_ext/2070436302/ain.o ../src/application/modules/ain.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2070436302/scanchain.o: ../src/application/modules/scanchain.c  .generated_files/578c5312d4765bd10e980fad0e0713340a9d1108.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2070436302" 
	@${RM} ${OBJECTDIR}/_ext/2070436302/scanchain.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070436302/scanchain.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2070436302/scanchain.o.d" -o ${OBJECTDIR}/_ext/2070436302/scanchain.o ../src/application/modules/scanchain.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2070436302/intadc.o: ../src/application/modules/intadc.c  .generated_files/bcf30a7e6eff7f6a3d3d3c90cc0a325566b101e2.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2070436302" 
	@${RM} ${OBJECTDIR}/_ext/2070436302/intadc.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070436302/intadc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2070436302/intadc.o.d" -o ${OBJECTDIR}/_ext/2070436302/intadc.o ../src/application/modules/intadc.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2070436302/mod_refclk.o: ../src/application/modules/mod_refclk.c  .generated_files/84fecb1d2ebf9a9c6056a4bfdd951e3f60a89797.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2070436302" 
	@${RM} ${OBJECTDIR}/_ext/2070436302/mod_refclk.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070436302/mod_refclk.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2070436302/mod_refclk.o.d" -o ${OBJECTDIR}/_ext/2070436302/mod_refclk.o ../src/application/modules/mod_refclk.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2070436302/cap.o: ../src/application/modules/cap.c  .generated_files/efa81719f9700a51f5e3077adad69a726e970714.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2070436302" 
	@${RM} ${OBJECTDIR}/_ext/2070436302/cap.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070436302/cap.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2070436302/cap.o.d" -o ${OBJECTDIR}/_ext/2070436302/cap.o ../src/application/modules/cap.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/801483606/app.o: ../src/application/app.c  .generated_files/8e30f202111b9034727a64483c42195a0560978e.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/801483606" 
	@${RM} ${OBJECTDIR}/_ext/801483606/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/801483606/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/801483606/app.o.d" -o ${OBJECTDIR}/_ext/801483606/app.o ../src/application/app.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/801483606/on_parameter_found.o: ../src/application/on_parameter_found.c  .generated_files/9889d2b73a6370fdd9cd73ddd397975ebb801ca7.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/801483606" 
	@${RM} ${OBJECTDIR}/_ext/801483606/on_parameter_found.o.d 
	@${RM} ${OBJECTDIR}/_ext/801483606/on_parameter_found.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/801483606/on_parameter_found.o.d" -o ${OBJECTDIR}/_ext/801483606/on_parameter_found.o ../src/application/on_parameter_found.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1537666708/board.o: ../src/board/board.c  .generated_files/873b1864ea7c54630a349574fb41783e720c632c.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1537666708" 
	@${RM} ${OBJECTDIR}/_ext/1537666708/board.o.d 
	@${RM} ${OBJECTDIR}/_ext/1537666708/board.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1537666708/board.o.d" -o ${OBJECTDIR}/_ext/1537666708/board.o ../src/board/board.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1509319821/adc.o: ../src/driver/adc/adc.c  .generated_files/9c8442cb33ef7d1d14107a4cc3a00f206c2d2694.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1509319821" 
	@${RM} ${OBJECTDIR}/_ext/1509319821/adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1509319821/adc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1509319821/adc.o.d" -o ${OBJECTDIR}/_ext/1509319821/adc.o ../src/driver/adc/adc.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1509317981/can.o: ../src/driver/can/can.c  .generated_files/4b56c36ba84479550f129a00e3370303951c00b0.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1509317981" 
	@${RM} ${OBJECTDIR}/_ext/1509317981/can.o.d 
	@${RM} ${OBJECTDIR}/_ext/1509317981/can.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1509317981/can.o.d" -o ${OBJECTDIR}/_ext/1509317981/can.o ../src/driver/can/can.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/455916380/gpio.o: ../src/driver/gpio/gpio.c  .generated_files/704e6421c4b63b9afe8348c5056c382caa4e50bc.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/455916380" 
	@${RM} ${OBJECTDIR}/_ext/455916380/gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/455916380/gpio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/455916380/gpio.o.d" -o ${OBJECTDIR}/_ext/455916380/gpio.o ../src/driver/gpio/gpio.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1509311806/int.o: ../src/driver/int/int.c  .generated_files/6cae2a1760a2b5eabf49586febfea76643608619.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1509311806" 
	@${RM} ${OBJECTDIR}/_ext/1509311806/int.o.d 
	@${RM} ${OBJECTDIR}/_ext/1509311806/int.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1509311806/int.o.d" -o ${OBJECTDIR}/_ext/1509311806/int.o ../src/driver/int/int.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1255152928/nvm.o: ../src/driver/nvmem/nvm.c  .generated_files/56629d895a90281f55c3650942fee420ca0cce19.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1255152928" 
	@${RM} ${OBJECTDIR}/_ext/1255152928/nvm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1255152928/nvm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1255152928/nvm.o.d" -o ${OBJECTDIR}/_ext/1255152928/nvm.o ../src/driver/nvmem/nvm.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1509304807/pwm.o: ../src/driver/pwm/pwm.c  .generated_files/4866c6ec1c0e235f79dd1f82b1f2891851a73e.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1509304807" 
	@${RM} ${OBJECTDIR}/_ext/1509304807/pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1509304807/pwm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1509304807/pwm.o.d" -o ${OBJECTDIR}/_ext/1509304807/pwm.o ../src/driver/pwm/pwm.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/353641468/refclk.o: ../src/driver/refclk/refclk.c  .generated_files/5632b9a07590f4312478c358f1440fccc539f554.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/353641468" 
	@${RM} ${OBJECTDIR}/_ext/353641468/refclk.o.d 
	@${RM} ${OBJECTDIR}/_ext/353641468/refclk.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/353641468/refclk.o.d" -o ${OBJECTDIR}/_ext/353641468/refclk.o ../src/driver/refclk/refclk.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1509302145/spi.o: ../src/driver/spi/spi.c  .generated_files/3725ae84d8b314ae9db060413de2359ab415ca18.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1509302145" 
	@${RM} ${OBJECTDIR}/_ext/1509302145/spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1509302145/spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1509302145/spi.o.d" -o ${OBJECTDIR}/_ext/1509302145/spi.o ../src/driver/spi/spi.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1509302145/swspi.o: ../src/driver/spi/swspi.c  .generated_files/aa2acb12dcf2d05704a3abe7a648345c46b90262.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1509302145" 
	@${RM} ${OBJECTDIR}/_ext/1509302145/swspi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1509302145/swspi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1509302145/swspi.o.d" -o ${OBJECTDIR}/_ext/1509302145/swspi.o ../src/driver/spi/swspi.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/401144697/systmr.o: ../src/driver/systmr/systmr.c  .generated_files/b2bd827c76d99f36e2ac612947c2075bdf928c5c.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/401144697" 
	@${RM} ${OBJECTDIR}/_ext/401144697/systmr.o.d 
	@${RM} ${OBJECTDIR}/_ext/401144697/systmr.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/401144697/systmr.o.d" -o ${OBJECTDIR}/_ext/401144697/systmr.o ../src/driver/systmr/systmr.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1261517080/usart.o: ../src/driver/usart/usart.c  .generated_files/e6397eb1e8a818dea2a92c86a07e998e20b78157.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1261517080" 
	@${RM} ${OBJECTDIR}/_ext/1261517080/usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1261517080/usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1261517080/usart.o.d" -o ${OBJECTDIR}/_ext/1261517080/usart.o ../src/driver/usart/usart.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1509298662/wdt.o: ../src/driver/wdt/wdt.c  .generated_files/220785b216507bd2c524a3f39b6a7e305f732051.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1509298662" 
	@${RM} ${OBJECTDIR}/_ext/1509298662/wdt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1509298662/wdt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1509298662/wdt.o.d" -o ${OBJECTDIR}/_ext/1509298662/wdt.o ../src/driver/wdt/wdt.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/210424401/rd_buffer.o: ../src/system/common/rd_buffer.c  .generated_files/85b936923d5f9301d32f317c6f774761c048c62.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/210424401" 
	@${RM} ${OBJECTDIR}/_ext/210424401/rd_buffer.o.d 
	@${RM} ${OBJECTDIR}/_ext/210424401/rd_buffer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/210424401/rd_buffer.o.d" -o ${OBJECTDIR}/_ext/210424401/rd_buffer.o ../src/system/common/rd_buffer.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/210424401/parser.o: ../src/system/common/parser.c  .generated_files/b5d57c548a19a46a5bbd76027347e91859f69f01.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/210424401" 
	@${RM} ${OBJECTDIR}/_ext/210424401/parser.o.d 
	@${RM} ${OBJECTDIR}/_ext/210424401/parser.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/210424401/parser.o.d" -o ${OBJECTDIR}/_ext/210424401/parser.o ../src/system/common/parser.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/210424401/string_utils.o: ../src/system/common/string_utils.c  .generated_files/2cac8736c5e8a02cfdec97ddc7fc6850a70a07e3.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/210424401" 
	@${RM} ${OBJECTDIR}/_ext/210424401/string_utils.o.d 
	@${RM} ${OBJECTDIR}/_ext/210424401/string_utils.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/210424401/string_utils.o.d" -o ${OBJECTDIR}/_ext/210424401/string_utils.o ../src/system/common/string_utils.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/783894060/planner.o: ../src/system/planner/planner.c  .generated_files/c9d65b86d6420d120ac6d6f9879fd5157afcf3de.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/783894060" 
	@${RM} ${OBJECTDIR}/_ext/783894060/planner.o.d 
	@${RM} ${OBJECTDIR}/_ext/783894060/planner.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/783894060/planner.o.d" -o ${OBJECTDIR}/_ext/783894060/planner.o ../src/system/planner/planner.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/73441385/system_exceptions.o: ../src/system/system_exceptions.c  .generated_files/92aee5d04f7f4c3447e43751ff9245366d5cec74.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/73441385/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/73441385/system_exceptions.o ../src/system/system_exceptions.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/73441385/system_init.o: ../src/system/system_init.c  .generated_files/f37ae3027adefe9fbe6924ddeca2cf7a558128cb.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_init.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/73441385/system_init.o.d" -o ${OBJECTDIR}/_ext/73441385/system_init.o ../src/system/system_init.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/73441385/system_dbg.o: ../src/system/system_dbg.c  .generated_files/ef53689433459c013c2d0a819dd64cad0107b2dd.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_dbg.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_dbg.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/73441385/system_dbg.o.d" -o ${OBJECTDIR}/_ext/73441385/system_dbg.o ../src/system/system_dbg.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/73441385/system_time.o: ../src/system/system_time.c  .generated_files/8b9fc26f7332c749f8e3366d7b561bd4399ab507.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_time.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_time.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/73441385/system_time.o.d" -o ${OBJECTDIR}/_ext/73441385/system_time.o ../src/system/system_time.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/73441385/system_config.o: ../src/system/system_config.c  .generated_files/a6ab4e8c6bec01d12af3b50987b1b6a0a32fa0a1.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_config.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_config.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/73441385/system_config.o.d" -o ${OBJECTDIR}/_ext/73441385/system_config.o ../src/system/system_config.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/73441385/system_comm.o: ../src/system/system_comm.c  .generated_files/fa556b3da93c1ac9e7ffd51e45a58a11aab4b9b0.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_comm.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_comm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/73441385/system_comm.o.d" -o ${OBJECTDIR}/_ext/73441385/system_comm.o ../src/system/system_comm.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/73441385/system_error.o: ../src/system/system_error.c  .generated_files/fd7ba694f28b4e9065e32c4ae7526b9603381af9.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_error.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_error.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/73441385/system_error.o.d" -o ${OBJECTDIR}/_ext/73441385/system_error.o ../src/system/system_error.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/73441385/crc.o: ../src/system/crc.c  .generated_files/3c5ba350e8844a22bb42001ab2e4fe9f36b4fa33.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/crc.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/crc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/73441385/crc.o.d" -o ${OBJECTDIR}/_ext/73441385/crc.o ../src/system/crc.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/ade0e8fbd5e461f504d698f1b0c0d305e54ab1b1.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/_ext/744274812/chrono.o: ../src/application/chrono/chrono.c  .generated_files/236490cab96d9147bbe525c48a3108e3750e73ac.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/744274812" 
	@${RM} ${OBJECTDIR}/_ext/744274812/chrono.o.d 
	@${RM} ${OBJECTDIR}/_ext/744274812/chrono.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/744274812/chrono.o.d" -o ${OBJECTDIR}/_ext/744274812/chrono.o ../src/application/chrono/chrono.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/816358189/ad5641.o: ../src/application/extdev/ad5641.c  .generated_files/c2cf0f6a6d63771151c3df83b331b498730f1a0f.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/816358189" 
	@${RM} ${OBJECTDIR}/_ext/816358189/ad5641.o.d 
	@${RM} ${OBJECTDIR}/_ext/816358189/ad5641.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/816358189/ad5641.o.d" -o ${OBJECTDIR}/_ext/816358189/ad5641.o ../src/application/extdev/ad5641.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2070436302/dio.o: ../src/application/modules/dio.c  .generated_files/1c78dda02432cf1faab9e81177f92d19aa5c4bed.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2070436302" 
	@${RM} ${OBJECTDIR}/_ext/2070436302/dio.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070436302/dio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2070436302/dio.o.d" -o ${OBJECTDIR}/_ext/2070436302/dio.o ../src/application/modules/dio.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2070436302/genclk.o: ../src/application/modules/genclk.c  .generated_files/e02d7a074335c7c2335dd59b85dce35a74a44ecf.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2070436302" 
	@${RM} ${OBJECTDIR}/_ext/2070436302/genclk.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070436302/genclk.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2070436302/genclk.o.d" -o ${OBJECTDIR}/_ext/2070436302/genclk.o ../src/application/modules/genclk.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2070436302/relay.o: ../src/application/modules/relay.c  .generated_files/f848292cb02740b2e8c81e994d2f02d2825abf8d.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2070436302" 
	@${RM} ${OBJECTDIR}/_ext/2070436302/relay.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070436302/relay.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2070436302/relay.o.d" -o ${OBJECTDIR}/_ext/2070436302/relay.o ../src/application/modules/relay.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2070436302/unisequencer.o: ../src/application/modules/unisequencer.c  .generated_files/aa7164c1c3a2fa1a09fd638848a4f5d3a4b3c124.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2070436302" 
	@${RM} ${OBJECTDIR}/_ext/2070436302/unisequencer.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070436302/unisequencer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2070436302/unisequencer.o.d" -o ${OBJECTDIR}/_ext/2070436302/unisequencer.o ../src/application/modules/unisequencer.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2070436302/mod_pwm.o: ../src/application/modules/mod_pwm.c  .generated_files/c12e9afbaf975260a1447988ebac7b8f42bdad18.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2070436302" 
	@${RM} ${OBJECTDIR}/_ext/2070436302/mod_pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070436302/mod_pwm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2070436302/mod_pwm.o.d" -o ${OBJECTDIR}/_ext/2070436302/mod_pwm.o ../src/application/modules/mod_pwm.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2070436302/mod_spi.o: ../src/application/modules/mod_spi.c  .generated_files/8a75857c518c50055dd8fd35de0ef4c009d2995c.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2070436302" 
	@${RM} ${OBJECTDIR}/_ext/2070436302/mod_spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070436302/mod_spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2070436302/mod_spi.o.d" -o ${OBJECTDIR}/_ext/2070436302/mod_spi.o ../src/application/modules/mod_spi.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2070436302/mod_swspi.o: ../src/application/modules/mod_swspi.c  .generated_files/c62137f39621786bb72a0a73d0cc1580da30f96d.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2070436302" 
	@${RM} ${OBJECTDIR}/_ext/2070436302/mod_swspi.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070436302/mod_swspi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2070436302/mod_swspi.o.d" -o ${OBJECTDIR}/_ext/2070436302/mod_swspi.o ../src/application/modules/mod_swspi.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2070436302/mod_i2c.o: ../src/application/modules/mod_i2c.c  .generated_files/5ecf6cc2ea6158e52caa623f0aa7001fc4b06477.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2070436302" 
	@${RM} ${OBJECTDIR}/_ext/2070436302/mod_i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070436302/mod_i2c.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2070436302/mod_i2c.o.d" -o ${OBJECTDIR}/_ext/2070436302/mod_i2c.o ../src/application/modules/mod_i2c.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2070436302/aout.o: ../src/application/modules/aout.c  .generated_files/ba54656e76803a631d4f3239d26260631eb55d97.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2070436302" 
	@${RM} ${OBJECTDIR}/_ext/2070436302/aout.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070436302/aout.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2070436302/aout.o.d" -o ${OBJECTDIR}/_ext/2070436302/aout.o ../src/application/modules/aout.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2070436302/ain.o: ../src/application/modules/ain.c  .generated_files/f1c5be0ac3f7fad05b572dd42f407a990c79bbbe.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2070436302" 
	@${RM} ${OBJECTDIR}/_ext/2070436302/ain.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070436302/ain.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2070436302/ain.o.d" -o ${OBJECTDIR}/_ext/2070436302/ain.o ../src/application/modules/ain.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2070436302/scanchain.o: ../src/application/modules/scanchain.c  .generated_files/fcd290a0e260d33c40af368e0f4f5da044d471b2.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2070436302" 
	@${RM} ${OBJECTDIR}/_ext/2070436302/scanchain.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070436302/scanchain.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2070436302/scanchain.o.d" -o ${OBJECTDIR}/_ext/2070436302/scanchain.o ../src/application/modules/scanchain.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2070436302/intadc.o: ../src/application/modules/intadc.c  .generated_files/a7bab8147c6dad023a99e6421fa2581417bbd2e7.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2070436302" 
	@${RM} ${OBJECTDIR}/_ext/2070436302/intadc.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070436302/intadc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2070436302/intadc.o.d" -o ${OBJECTDIR}/_ext/2070436302/intadc.o ../src/application/modules/intadc.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2070436302/mod_refclk.o: ../src/application/modules/mod_refclk.c  .generated_files/31ca15d0955258565042f5342650692e2b33c5c7.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2070436302" 
	@${RM} ${OBJECTDIR}/_ext/2070436302/mod_refclk.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070436302/mod_refclk.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2070436302/mod_refclk.o.d" -o ${OBJECTDIR}/_ext/2070436302/mod_refclk.o ../src/application/modules/mod_refclk.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/2070436302/cap.o: ../src/application/modules/cap.c  .generated_files/e0dd2743cd5ceec2f866641a10d420796f335e4d.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2070436302" 
	@${RM} ${OBJECTDIR}/_ext/2070436302/cap.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070436302/cap.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/2070436302/cap.o.d" -o ${OBJECTDIR}/_ext/2070436302/cap.o ../src/application/modules/cap.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/801483606/app.o: ../src/application/app.c  .generated_files/8310f1fc5875dcbfcbb6b8c2dab98bd05c3913a.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/801483606" 
	@${RM} ${OBJECTDIR}/_ext/801483606/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/801483606/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/801483606/app.o.d" -o ${OBJECTDIR}/_ext/801483606/app.o ../src/application/app.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/801483606/on_parameter_found.o: ../src/application/on_parameter_found.c  .generated_files/39e01ce2059723fcbb6a5094c7e0657d3c377ea9.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/801483606" 
	@${RM} ${OBJECTDIR}/_ext/801483606/on_parameter_found.o.d 
	@${RM} ${OBJECTDIR}/_ext/801483606/on_parameter_found.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/801483606/on_parameter_found.o.d" -o ${OBJECTDIR}/_ext/801483606/on_parameter_found.o ../src/application/on_parameter_found.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1537666708/board.o: ../src/board/board.c  .generated_files/c9c6ae21797009160688d6036909cc98fb4cffb7.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1537666708" 
	@${RM} ${OBJECTDIR}/_ext/1537666708/board.o.d 
	@${RM} ${OBJECTDIR}/_ext/1537666708/board.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1537666708/board.o.d" -o ${OBJECTDIR}/_ext/1537666708/board.o ../src/board/board.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1509319821/adc.o: ../src/driver/adc/adc.c  .generated_files/8924a57ad9cb0fd1bcdef694d409aaa1fa7bf11c.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1509319821" 
	@${RM} ${OBJECTDIR}/_ext/1509319821/adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1509319821/adc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1509319821/adc.o.d" -o ${OBJECTDIR}/_ext/1509319821/adc.o ../src/driver/adc/adc.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1509317981/can.o: ../src/driver/can/can.c  .generated_files/d0b2077de1188e2b264000caf460aad9e1b8407c.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1509317981" 
	@${RM} ${OBJECTDIR}/_ext/1509317981/can.o.d 
	@${RM} ${OBJECTDIR}/_ext/1509317981/can.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1509317981/can.o.d" -o ${OBJECTDIR}/_ext/1509317981/can.o ../src/driver/can/can.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/455916380/gpio.o: ../src/driver/gpio/gpio.c  .generated_files/9781f418837de188cdcb3f1457a7aefb546f842b.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/455916380" 
	@${RM} ${OBJECTDIR}/_ext/455916380/gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/455916380/gpio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/455916380/gpio.o.d" -o ${OBJECTDIR}/_ext/455916380/gpio.o ../src/driver/gpio/gpio.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1509311806/int.o: ../src/driver/int/int.c  .generated_files/ffa9a961ce812860e17c2bb1e944c432c792316c.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1509311806" 
	@${RM} ${OBJECTDIR}/_ext/1509311806/int.o.d 
	@${RM} ${OBJECTDIR}/_ext/1509311806/int.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1509311806/int.o.d" -o ${OBJECTDIR}/_ext/1509311806/int.o ../src/driver/int/int.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1255152928/nvm.o: ../src/driver/nvmem/nvm.c  .generated_files/40da72dd0e71c37cc6330de74ae7f6ce85785d11.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1255152928" 
	@${RM} ${OBJECTDIR}/_ext/1255152928/nvm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1255152928/nvm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1255152928/nvm.o.d" -o ${OBJECTDIR}/_ext/1255152928/nvm.o ../src/driver/nvmem/nvm.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1509304807/pwm.o: ../src/driver/pwm/pwm.c  .generated_files/34e3d91952d9957ce3c684663f00facdc2c9eefc.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1509304807" 
	@${RM} ${OBJECTDIR}/_ext/1509304807/pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1509304807/pwm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1509304807/pwm.o.d" -o ${OBJECTDIR}/_ext/1509304807/pwm.o ../src/driver/pwm/pwm.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/353641468/refclk.o: ../src/driver/refclk/refclk.c  .generated_files/52ef8eff11aadb0578d4e4f89c5d4922ed5715c4.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/353641468" 
	@${RM} ${OBJECTDIR}/_ext/353641468/refclk.o.d 
	@${RM} ${OBJECTDIR}/_ext/353641468/refclk.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/353641468/refclk.o.d" -o ${OBJECTDIR}/_ext/353641468/refclk.o ../src/driver/refclk/refclk.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1509302145/spi.o: ../src/driver/spi/spi.c  .generated_files/c809a17171ce0e89e19c3fdc17decad6926c37ef.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1509302145" 
	@${RM} ${OBJECTDIR}/_ext/1509302145/spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1509302145/spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1509302145/spi.o.d" -o ${OBJECTDIR}/_ext/1509302145/spi.o ../src/driver/spi/spi.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1509302145/swspi.o: ../src/driver/spi/swspi.c  .generated_files/85b4b897cdccb4ce7464f8b6d687e003f5b92ef2.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1509302145" 
	@${RM} ${OBJECTDIR}/_ext/1509302145/swspi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1509302145/swspi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1509302145/swspi.o.d" -o ${OBJECTDIR}/_ext/1509302145/swspi.o ../src/driver/spi/swspi.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/401144697/systmr.o: ../src/driver/systmr/systmr.c  .generated_files/50458b692d1ca1b59f26af8f451b98c7083969e4.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/401144697" 
	@${RM} ${OBJECTDIR}/_ext/401144697/systmr.o.d 
	@${RM} ${OBJECTDIR}/_ext/401144697/systmr.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/401144697/systmr.o.d" -o ${OBJECTDIR}/_ext/401144697/systmr.o ../src/driver/systmr/systmr.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1261517080/usart.o: ../src/driver/usart/usart.c  .generated_files/7e6033edf63d676d5729184514f11d7eb61af126.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1261517080" 
	@${RM} ${OBJECTDIR}/_ext/1261517080/usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1261517080/usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1261517080/usart.o.d" -o ${OBJECTDIR}/_ext/1261517080/usart.o ../src/driver/usart/usart.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1509298662/wdt.o: ../src/driver/wdt/wdt.c  .generated_files/27c99e27d8afc8988fb9e7c65c87d9dba4893e10.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1509298662" 
	@${RM} ${OBJECTDIR}/_ext/1509298662/wdt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1509298662/wdt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1509298662/wdt.o.d" -o ${OBJECTDIR}/_ext/1509298662/wdt.o ../src/driver/wdt/wdt.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/210424401/rd_buffer.o: ../src/system/common/rd_buffer.c  .generated_files/c3132bd23ba2c761c0caae9fac13e1225d6c0344.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/210424401" 
	@${RM} ${OBJECTDIR}/_ext/210424401/rd_buffer.o.d 
	@${RM} ${OBJECTDIR}/_ext/210424401/rd_buffer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/210424401/rd_buffer.o.d" -o ${OBJECTDIR}/_ext/210424401/rd_buffer.o ../src/system/common/rd_buffer.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/210424401/parser.o: ../src/system/common/parser.c  .generated_files/86ab5745bd843eeb0c2a9077336ef2fae19fe365.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/210424401" 
	@${RM} ${OBJECTDIR}/_ext/210424401/parser.o.d 
	@${RM} ${OBJECTDIR}/_ext/210424401/parser.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/210424401/parser.o.d" -o ${OBJECTDIR}/_ext/210424401/parser.o ../src/system/common/parser.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/210424401/string_utils.o: ../src/system/common/string_utils.c  .generated_files/6b4c0fe5478b74bcf3b6e66598c0ae511ff79ffe.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/210424401" 
	@${RM} ${OBJECTDIR}/_ext/210424401/string_utils.o.d 
	@${RM} ${OBJECTDIR}/_ext/210424401/string_utils.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/210424401/string_utils.o.d" -o ${OBJECTDIR}/_ext/210424401/string_utils.o ../src/system/common/string_utils.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/783894060/planner.o: ../src/system/planner/planner.c  .generated_files/241a69a88ff52c1bcc71905a8470131e51be3aea.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/783894060" 
	@${RM} ${OBJECTDIR}/_ext/783894060/planner.o.d 
	@${RM} ${OBJECTDIR}/_ext/783894060/planner.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/783894060/planner.o.d" -o ${OBJECTDIR}/_ext/783894060/planner.o ../src/system/planner/planner.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/73441385/system_exceptions.o: ../src/system/system_exceptions.c  .generated_files/7ee4dce52182fe73ed83aaa32cae565a62cb0876.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/73441385/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/73441385/system_exceptions.o ../src/system/system_exceptions.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/73441385/system_init.o: ../src/system/system_init.c  .generated_files/c978a543f837a8aa174dad30463bf0bc7fde7528.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_init.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/73441385/system_init.o.d" -o ${OBJECTDIR}/_ext/73441385/system_init.o ../src/system/system_init.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/73441385/system_dbg.o: ../src/system/system_dbg.c  .generated_files/c88ad53c81464e7b4b1689d53436d6acdebd16c2.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_dbg.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_dbg.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/73441385/system_dbg.o.d" -o ${OBJECTDIR}/_ext/73441385/system_dbg.o ../src/system/system_dbg.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/73441385/system_time.o: ../src/system/system_time.c  .generated_files/7278ec109db111d95ce159a6cb9b118fd2489746.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_time.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_time.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/73441385/system_time.o.d" -o ${OBJECTDIR}/_ext/73441385/system_time.o ../src/system/system_time.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/73441385/system_config.o: ../src/system/system_config.c  .generated_files/806b4cbcad526dcde730b86082f99ce6dffa9771.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_config.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_config.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/73441385/system_config.o.d" -o ${OBJECTDIR}/_ext/73441385/system_config.o ../src/system/system_config.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/73441385/system_comm.o: ../src/system/system_comm.c  .generated_files/86216e8874a5024fd048269c883537f9a3db4281.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_comm.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_comm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/73441385/system_comm.o.d" -o ${OBJECTDIR}/_ext/73441385/system_comm.o ../src/system/system_comm.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/73441385/system_error.o: ../src/system/system_error.c  .generated_files/a86a51276490a254f3337fd8ae4e26d5042d3321.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_error.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_error.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/73441385/system_error.o.d" -o ${OBJECTDIR}/_ext/73441385/system_error.o ../src/system/system_error.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/73441385/crc.o: ../src/system/crc.c  .generated_files/f3a180de82aa96c61ded50bbe9b6e25ea2be9737.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/crc.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/crc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/73441385/crc.o.d" -o ${OBJECTDIR}/_ext/73441385/crc.o ../src/system/crc.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/e9e91dd7a7674ace23ca277a557f4a0369198143.flag .generated_files/3eda10ae19fa762b9b018eebb81f511d750eb34.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/delay" -I"../src/driver/nvmem" -I"../src/driver/i2c" -I"../src/driver" -I"../src/system/common" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver/refclk" -I"../src/driver/spi" -I"../src/driver/int" -I"../src/driver/adc" -I"../src/driver/systmr" -I"../src/system/planner" -I"../src/driver/pwm" -I"../src/serial_comm" -I"../src/application/modules" -I"../src/application/chrono" -I"../src/driver/spi" -I"../src/driver/gpio" -I"../src/driver/usart" -I"../src/system" -I"../src/application/extdev" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -ftrack-macro-expansion=0 -ftrack-macro-expansion=0 -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/app.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../app_mz.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION) -O1 -o dist/${CND_CONF}/${IMAGE_TYPE}/app.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  -ftrack-macro-expansion=0 $(COMPARISON_BUILD)      -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=0,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/app.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../app_mz.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION) -O1 -o dist/${CND_CONF}/${IMAGE_TYPE}/app.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_TEST=$(CND_CONF)  -legacy-libc  -ftrack-macro-expansion=0 $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=0,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/app.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
	@echo Normalizing hex file
	@"C:/Program Files/Microchip/MPLABX/v5.45/mplab_platform/platform/../mplab_ide/modules/../../bin/hexmate" --edf="C:/Program Files/Microchip/MPLABX/v5.45/mplab_platform/platform/../mplab_ide/modules/../../dat/en_msgs.txt" dist/${CND_CONF}/${IMAGE_TYPE}/app.X.${IMAGE_TYPE}.hex -odist/${CND_CONF}/${IMAGE_TYPE}/app.X.${IMAGE_TYPE}.hex

endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/TEST
	${RM} -r dist/TEST

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
