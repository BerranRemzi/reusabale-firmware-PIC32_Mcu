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
ifeq "$(wildcard nbproject/Makefile-local-LDM_TEST.mk)" "nbproject/Makefile-local-LDM_TEST.mk"
include nbproject/Makefile-local-LDM_TEST.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=LDM_TEST
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/BOOTLOADER.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/BOOTLOADER.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=../src/application/bootloader.c ../src/application/flash_mem.c ../src/board/board.c ../src/driver/gpio/gpio.c ../src/driver/nvmem/nvm.c ../src/driver/systmr/systmr.c ../src/driver/usart/usart.c ../src/driver/wdt/wdt.c ../src/modules/device_config/device_config.c ../src/system/debug/debug.c ../src/system/system.c ../src/system/system_exceptions.c ../src/system/system_init.c ../src/system/system_time.c ../src/main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/801483606/bootloader.o ${OBJECTDIR}/_ext/801483606/flash_mem.o ${OBJECTDIR}/_ext/1537666708/board.o ${OBJECTDIR}/_ext/455916380/gpio.o ${OBJECTDIR}/_ext/1255152928/nvm.o ${OBJECTDIR}/_ext/401144697/systmr.o ${OBJECTDIR}/_ext/1261517080/usart.o ${OBJECTDIR}/_ext/1509298662/wdt.o ${OBJECTDIR}/_ext/1727528777/device_config.o ${OBJECTDIR}/_ext/700139821/debug.o ${OBJECTDIR}/_ext/73441385/system.o ${OBJECTDIR}/_ext/73441385/system_exceptions.o ${OBJECTDIR}/_ext/73441385/system_init.o ${OBJECTDIR}/_ext/73441385/system_time.o ${OBJECTDIR}/_ext/1360937237/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/801483606/bootloader.o.d ${OBJECTDIR}/_ext/801483606/flash_mem.o.d ${OBJECTDIR}/_ext/1537666708/board.o.d ${OBJECTDIR}/_ext/455916380/gpio.o.d ${OBJECTDIR}/_ext/1255152928/nvm.o.d ${OBJECTDIR}/_ext/401144697/systmr.o.d ${OBJECTDIR}/_ext/1261517080/usart.o.d ${OBJECTDIR}/_ext/1509298662/wdt.o.d ${OBJECTDIR}/_ext/1727528777/device_config.o.d ${OBJECTDIR}/_ext/700139821/debug.o.d ${OBJECTDIR}/_ext/73441385/system.o.d ${OBJECTDIR}/_ext/73441385/system_exceptions.o.d ${OBJECTDIR}/_ext/73441385/system_init.o.d ${OBJECTDIR}/_ext/73441385/system_time.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/801483606/bootloader.o ${OBJECTDIR}/_ext/801483606/flash_mem.o ${OBJECTDIR}/_ext/1537666708/board.o ${OBJECTDIR}/_ext/455916380/gpio.o ${OBJECTDIR}/_ext/1255152928/nvm.o ${OBJECTDIR}/_ext/401144697/systmr.o ${OBJECTDIR}/_ext/1261517080/usart.o ${OBJECTDIR}/_ext/1509298662/wdt.o ${OBJECTDIR}/_ext/1727528777/device_config.o ${OBJECTDIR}/_ext/700139821/debug.o ${OBJECTDIR}/_ext/73441385/system.o ${OBJECTDIR}/_ext/73441385/system_exceptions.o ${OBJECTDIR}/_ext/73441385/system_init.o ${OBJECTDIR}/_ext/73441385/system_time.o ${OBJECTDIR}/_ext/1360937237/main.o

# Source Files
SOURCEFILES=../src/application/bootloader.c ../src/application/flash_mem.c ../src/board/board.c ../src/driver/gpio/gpio.c ../src/driver/nvmem/nvm.c ../src/driver/systmr/systmr.c ../src/driver/usart/usart.c ../src/driver/wdt/wdt.c ../src/modules/device_config/device_config.c ../src/system/debug/debug.c ../src/system/system.c ../src/system/system_exceptions.c ../src/system/system_init.c ../src/system/system_time.c ../src/main.c



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
	${MAKE}  -f nbproject/Makefile-LDM_TEST.mk dist/${CND_CONF}/${IMAGE_TYPE}/BOOTLOADER.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MZ1024EFH100
MP_LINKER_FILE_OPTION=,--script="..\btl_mz.ld"
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
${OBJECTDIR}/_ext/801483606/bootloader.o: ../src/application/bootloader.c  .generated_files/914e402cc7da9cf69c8bb0e8d5d03ca865959213.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/801483606" 
	@${RM} ${OBJECTDIR}/_ext/801483606/bootloader.o.d 
	@${RM} ${OBJECTDIR}/_ext/801483606/bootloader.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/801483606/bootloader.o.d" -o ${OBJECTDIR}/_ext/801483606/bootloader.o ../src/application/bootloader.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/801483606/flash_mem.o: ../src/application/flash_mem.c  .generated_files/9c721b817271399c5bd91ea6709ab17c38a5752a.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/801483606" 
	@${RM} ${OBJECTDIR}/_ext/801483606/flash_mem.o.d 
	@${RM} ${OBJECTDIR}/_ext/801483606/flash_mem.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/801483606/flash_mem.o.d" -o ${OBJECTDIR}/_ext/801483606/flash_mem.o ../src/application/flash_mem.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1537666708/board.o: ../src/board/board.c  .generated_files/9dab4e7bf32565b58a717acc264851bf1b8d47d3.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1537666708" 
	@${RM} ${OBJECTDIR}/_ext/1537666708/board.o.d 
	@${RM} ${OBJECTDIR}/_ext/1537666708/board.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1537666708/board.o.d" -o ${OBJECTDIR}/_ext/1537666708/board.o ../src/board/board.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/455916380/gpio.o: ../src/driver/gpio/gpio.c  .generated_files/d1ccf3dc44b0e6f117c032f0ad51d4962266ed8a.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/455916380" 
	@${RM} ${OBJECTDIR}/_ext/455916380/gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/455916380/gpio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/455916380/gpio.o.d" -o ${OBJECTDIR}/_ext/455916380/gpio.o ../src/driver/gpio/gpio.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1255152928/nvm.o: ../src/driver/nvmem/nvm.c  .generated_files/57c7d8fe210678d17a8c067e16e45cb194d9dab2.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1255152928" 
	@${RM} ${OBJECTDIR}/_ext/1255152928/nvm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1255152928/nvm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1255152928/nvm.o.d" -o ${OBJECTDIR}/_ext/1255152928/nvm.o ../src/driver/nvmem/nvm.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/401144697/systmr.o: ../src/driver/systmr/systmr.c  .generated_files/e4798ff9762bb3101db32242064d5d637af50792.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/401144697" 
	@${RM} ${OBJECTDIR}/_ext/401144697/systmr.o.d 
	@${RM} ${OBJECTDIR}/_ext/401144697/systmr.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/401144697/systmr.o.d" -o ${OBJECTDIR}/_ext/401144697/systmr.o ../src/driver/systmr/systmr.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1261517080/usart.o: ../src/driver/usart/usart.c  .generated_files/40f0f1affec9c3b7b42ef6eb87e8463e463da33c.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1261517080" 
	@${RM} ${OBJECTDIR}/_ext/1261517080/usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1261517080/usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1261517080/usart.o.d" -o ${OBJECTDIR}/_ext/1261517080/usart.o ../src/driver/usart/usart.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1509298662/wdt.o: ../src/driver/wdt/wdt.c  .generated_files/41abaf72e32c4505e8cc4130b2d9d1eaf3d9e17.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1509298662" 
	@${RM} ${OBJECTDIR}/_ext/1509298662/wdt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1509298662/wdt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1509298662/wdt.o.d" -o ${OBJECTDIR}/_ext/1509298662/wdt.o ../src/driver/wdt/wdt.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1727528777/device_config.o: ../src/modules/device_config/device_config.c  .generated_files/d00bfcf38a6d4f3ebfe2f76423af945a1e161425.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1727528777" 
	@${RM} ${OBJECTDIR}/_ext/1727528777/device_config.o.d 
	@${RM} ${OBJECTDIR}/_ext/1727528777/device_config.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1727528777/device_config.o.d" -o ${OBJECTDIR}/_ext/1727528777/device_config.o ../src/modules/device_config/device_config.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/700139821/debug.o: ../src/system/debug/debug.c  .generated_files/3191931fb3a9e7a68194daf61c7e9a64758dfa24.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/700139821" 
	@${RM} ${OBJECTDIR}/_ext/700139821/debug.o.d 
	@${RM} ${OBJECTDIR}/_ext/700139821/debug.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/700139821/debug.o.d" -o ${OBJECTDIR}/_ext/700139821/debug.o ../src/system/debug/debug.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/73441385/system.o: ../src/system/system.c  .generated_files/e6146f388f921d0b8d839bf27803a0d144411edd.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/system.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/system.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/73441385/system.o.d" -o ${OBJECTDIR}/_ext/73441385/system.o ../src/system/system.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/73441385/system_exceptions.o: ../src/system/system_exceptions.c  .generated_files/7d10747480cb6fd74037f091d6647a55166eb6b8.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/73441385/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/73441385/system_exceptions.o ../src/system/system_exceptions.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/73441385/system_init.o: ../src/system/system_init.c  .generated_files/dfe83d82174c3bb219a7bfb838be3a97b780a98.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_init.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/73441385/system_init.o.d" -o ${OBJECTDIR}/_ext/73441385/system_init.o ../src/system/system_init.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/73441385/system_time.o: ../src/system/system_time.c  .generated_files/a0baec16623bdcd286bf1a95ccec14033a715641.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_time.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_time.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/73441385/system_time.o.d" -o ${OBJECTDIR}/_ext/73441385/system_time.o ../src/system/system_time.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/bf8f90d619cbc219c5a21d59099550be8eb33177.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
else
${OBJECTDIR}/_ext/801483606/bootloader.o: ../src/application/bootloader.c  .generated_files/fd5c3d3a06d3c101b21931f326e6479c8cbe3996.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/801483606" 
	@${RM} ${OBJECTDIR}/_ext/801483606/bootloader.o.d 
	@${RM} ${OBJECTDIR}/_ext/801483606/bootloader.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/801483606/bootloader.o.d" -o ${OBJECTDIR}/_ext/801483606/bootloader.o ../src/application/bootloader.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/801483606/flash_mem.o: ../src/application/flash_mem.c  .generated_files/ece9ff7cb12d37b031f99646f882401475b4eaa8.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/801483606" 
	@${RM} ${OBJECTDIR}/_ext/801483606/flash_mem.o.d 
	@${RM} ${OBJECTDIR}/_ext/801483606/flash_mem.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/801483606/flash_mem.o.d" -o ${OBJECTDIR}/_ext/801483606/flash_mem.o ../src/application/flash_mem.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1537666708/board.o: ../src/board/board.c  .generated_files/899189208a4e8fa97ae5ac93d7797dd650dd0daa.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1537666708" 
	@${RM} ${OBJECTDIR}/_ext/1537666708/board.o.d 
	@${RM} ${OBJECTDIR}/_ext/1537666708/board.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1537666708/board.o.d" -o ${OBJECTDIR}/_ext/1537666708/board.o ../src/board/board.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/455916380/gpio.o: ../src/driver/gpio/gpio.c  .generated_files/d06ed28ecc6e8d54d330f2d717e478f732315dc5.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/455916380" 
	@${RM} ${OBJECTDIR}/_ext/455916380/gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/455916380/gpio.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/455916380/gpio.o.d" -o ${OBJECTDIR}/_ext/455916380/gpio.o ../src/driver/gpio/gpio.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1255152928/nvm.o: ../src/driver/nvmem/nvm.c  .generated_files/a59b13dfdb72ad25aadf814b5c4f4d0be300e128.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1255152928" 
	@${RM} ${OBJECTDIR}/_ext/1255152928/nvm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1255152928/nvm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1255152928/nvm.o.d" -o ${OBJECTDIR}/_ext/1255152928/nvm.o ../src/driver/nvmem/nvm.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/401144697/systmr.o: ../src/driver/systmr/systmr.c  .generated_files/de3c04e72e0fabf94c49990059b231a2b3f04ec2.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/401144697" 
	@${RM} ${OBJECTDIR}/_ext/401144697/systmr.o.d 
	@${RM} ${OBJECTDIR}/_ext/401144697/systmr.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/401144697/systmr.o.d" -o ${OBJECTDIR}/_ext/401144697/systmr.o ../src/driver/systmr/systmr.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1261517080/usart.o: ../src/driver/usart/usart.c  .generated_files/1eaeeb795cc9e5fa0a48ab23f5163bb1ee960107.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1261517080" 
	@${RM} ${OBJECTDIR}/_ext/1261517080/usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1261517080/usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1261517080/usart.o.d" -o ${OBJECTDIR}/_ext/1261517080/usart.o ../src/driver/usart/usart.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1509298662/wdt.o: ../src/driver/wdt/wdt.c  .generated_files/be344a44d075e699bd459429ff66115aec2c53e0.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1509298662" 
	@${RM} ${OBJECTDIR}/_ext/1509298662/wdt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1509298662/wdt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1509298662/wdt.o.d" -o ${OBJECTDIR}/_ext/1509298662/wdt.o ../src/driver/wdt/wdt.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1727528777/device_config.o: ../src/modules/device_config/device_config.c  .generated_files/1fad54db53384852a20bd89998444217417f1d4e.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1727528777" 
	@${RM} ${OBJECTDIR}/_ext/1727528777/device_config.o.d 
	@${RM} ${OBJECTDIR}/_ext/1727528777/device_config.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1727528777/device_config.o.d" -o ${OBJECTDIR}/_ext/1727528777/device_config.o ../src/modules/device_config/device_config.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/700139821/debug.o: ../src/system/debug/debug.c  .generated_files/e16042cbfa0f0d9992aa6fc1325ab8029cfe957.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/700139821" 
	@${RM} ${OBJECTDIR}/_ext/700139821/debug.o.d 
	@${RM} ${OBJECTDIR}/_ext/700139821/debug.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/700139821/debug.o.d" -o ${OBJECTDIR}/_ext/700139821/debug.o ../src/system/debug/debug.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/73441385/system.o: ../src/system/system.c  .generated_files/20aa8852fc5cf54a4cc1683ba727682b04abe003.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/system.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/system.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/73441385/system.o.d" -o ${OBJECTDIR}/_ext/73441385/system.o ../src/system/system.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/73441385/system_exceptions.o: ../src/system/system_exceptions.c  .generated_files/af2ccd26bb7570b6e1e7f779dfa7d730f31c399d.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/73441385/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/73441385/system_exceptions.o ../src/system/system_exceptions.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/73441385/system_init.o: ../src/system/system_init.c  .generated_files/dde3468a79d7cf5e42dd8c482a5195e74e0f4c84.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_init.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/73441385/system_init.o.d" -o ${OBJECTDIR}/_ext/73441385/system_init.o ../src/system/system_init.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/73441385/system_time.o: ../src/system/system_time.c  .generated_files/f9cb80f3a5e5ec0e0a6342711d68ea30125f4f5.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_time.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/system_time.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/73441385/system_time.o.d" -o ${OBJECTDIR}/_ext/73441385/system_time.o ../src/system/system_time.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/d494f14ca228ab4a43d08da27e7316f5ea803601.flag .generated_files/bd7dd0b3a044e969994f431b44562e0fbe889da2.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src/driver/gpio" -I"../src/driver/nvmem" -I"../src/driver/usart" -I"../src/system" -I"../src/system/common" -I"../src/system/debug" -I"../src/system/timers" -I"../src/application" -I"../src" -I"../src/system/common" -I"../src/modules/device_config" -I"../src/modules/rd_buffer" -I"../src/driver/systmr" -I"../src/driver/wdt" -I"../src/board" -I"../src/driver" -Wall -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/BOOTLOADER.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../btl_mz.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION) -O1 -o dist/${CND_CONF}/${IMAGE_TYPE}/BOOTLOADER.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x37F   -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=0,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/BOOTLOADER.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../btl_mz.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION) -O1 -o dist/${CND_CONF}/${IMAGE_TYPE}/BOOTLOADER.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_LDM_TEST=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=0,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml 
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/BOOTLOADER.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
	@echo Normalizing hex file
	@"C:/Program Files/Microchip/MPLABX/v5.45/mplab_platform/platform/../mplab_ide/modules/../../bin/hexmate" --edf="C:/Program Files/Microchip/MPLABX/v5.45/mplab_platform/platform/../mplab_ide/modules/../../dat/en_msgs.txt" dist/${CND_CONF}/${IMAGE_TYPE}/BOOTLOADER.X.${IMAGE_TYPE}.hex -odist/${CND_CONF}/${IMAGE_TYPE}/BOOTLOADER.X.${IMAGE_TYPE}.hex

endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/LDM_TEST
	${RM} -r dist/LDM_TEST

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
