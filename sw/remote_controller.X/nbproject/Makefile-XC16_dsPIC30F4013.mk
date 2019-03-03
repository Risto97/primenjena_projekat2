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
ifeq "$(wildcard nbproject/Makefile-local-XC16_dsPIC30F4013.mk)" "nbproject/Makefile-local-XC16_dsPIC30F4013.mk"
include nbproject/Makefile-local-XC16_dsPIC30F4013.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=XC16_dsPIC30F4013
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/remote_controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/remote_controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=configuration_bits.c main.c system.c traps.c joystick.c misc.c motor_commands.c ../shared_lib/commands.c ../shared_lib/message.c ../shared_lib/uart_debug.c ../shared_lib/uart_rf.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/configuration_bits.o ${OBJECTDIR}/main.o ${OBJECTDIR}/system.o ${OBJECTDIR}/traps.o ${OBJECTDIR}/joystick.o ${OBJECTDIR}/misc.o ${OBJECTDIR}/motor_commands.o ${OBJECTDIR}/_ext/689862490/commands.o ${OBJECTDIR}/_ext/689862490/message.o ${OBJECTDIR}/_ext/689862490/uart_debug.o ${OBJECTDIR}/_ext/689862490/uart_rf.o
POSSIBLE_DEPFILES=${OBJECTDIR}/configuration_bits.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/system.o.d ${OBJECTDIR}/traps.o.d ${OBJECTDIR}/joystick.o.d ${OBJECTDIR}/misc.o.d ${OBJECTDIR}/motor_commands.o.d ${OBJECTDIR}/_ext/689862490/commands.o.d ${OBJECTDIR}/_ext/689862490/message.o.d ${OBJECTDIR}/_ext/689862490/uart_debug.o.d ${OBJECTDIR}/_ext/689862490/uart_rf.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/configuration_bits.o ${OBJECTDIR}/main.o ${OBJECTDIR}/system.o ${OBJECTDIR}/traps.o ${OBJECTDIR}/joystick.o ${OBJECTDIR}/misc.o ${OBJECTDIR}/motor_commands.o ${OBJECTDIR}/_ext/689862490/commands.o ${OBJECTDIR}/_ext/689862490/message.o ${OBJECTDIR}/_ext/689862490/uart_debug.o ${OBJECTDIR}/_ext/689862490/uart_rf.o

# Source Files
SOURCEFILES=configuration_bits.c main.c system.c traps.c joystick.c misc.c motor_commands.c ../shared_lib/commands.c ../shared_lib/message.c ../shared_lib/uart_debug.c ../shared_lib/uart_rf.c


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
	${MAKE}  -f nbproject/Makefile-XC16_dsPIC30F4013.mk dist/${CND_CONF}/${IMAGE_TYPE}/remote_controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=30F4013
MP_LINKER_FILE_OPTION=,--script=p30F4013.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/configuration_bits.o: configuration_bits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/configuration_bits.o.d 
	@${RM} ${OBJECTDIR}/configuration_bits.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  configuration_bits.c  -o ${OBJECTDIR}/configuration_bits.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/configuration_bits.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_XC16_dsPIC30F4013=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../shared_lib" -msmart-io=1 -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/configuration_bits.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_XC16_dsPIC30F4013=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../shared_lib" -msmart-io=1 -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/system.o: system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${RM} ${OBJECTDIR}/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system.c  -o ${OBJECTDIR}/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_XC16_dsPIC30F4013=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../shared_lib" -msmart-io=1 -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/system.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/traps.o: traps.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/traps.o.d 
	@${RM} ${OBJECTDIR}/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  traps.c  -o ${OBJECTDIR}/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/traps.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_XC16_dsPIC30F4013=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../shared_lib" -msmart-io=1 -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/traps.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/joystick.o: joystick.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/joystick.o.d 
	@${RM} ${OBJECTDIR}/joystick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  joystick.c  -o ${OBJECTDIR}/joystick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/joystick.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_XC16_dsPIC30F4013=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../shared_lib" -msmart-io=1 -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/joystick.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/misc.o: misc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/misc.o.d 
	@${RM} ${OBJECTDIR}/misc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  misc.c  -o ${OBJECTDIR}/misc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/misc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_XC16_dsPIC30F4013=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../shared_lib" -msmart-io=1 -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/misc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/motor_commands.o: motor_commands.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/motor_commands.o.d 
	@${RM} ${OBJECTDIR}/motor_commands.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  motor_commands.c  -o ${OBJECTDIR}/motor_commands.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/motor_commands.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_XC16_dsPIC30F4013=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../shared_lib" -msmart-io=1 -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/motor_commands.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/689862490/commands.o: ../shared_lib/commands.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/689862490" 
	@${RM} ${OBJECTDIR}/_ext/689862490/commands.o.d 
	@${RM} ${OBJECTDIR}/_ext/689862490/commands.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../shared_lib/commands.c  -o ${OBJECTDIR}/_ext/689862490/commands.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/689862490/commands.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_XC16_dsPIC30F4013=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../shared_lib" -msmart-io=1 -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/689862490/commands.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/689862490/message.o: ../shared_lib/message.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/689862490" 
	@${RM} ${OBJECTDIR}/_ext/689862490/message.o.d 
	@${RM} ${OBJECTDIR}/_ext/689862490/message.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../shared_lib/message.c  -o ${OBJECTDIR}/_ext/689862490/message.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/689862490/message.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_XC16_dsPIC30F4013=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../shared_lib" -msmart-io=1 -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/689862490/message.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/689862490/uart_debug.o: ../shared_lib/uart_debug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/689862490" 
	@${RM} ${OBJECTDIR}/_ext/689862490/uart_debug.o.d 
	@${RM} ${OBJECTDIR}/_ext/689862490/uart_debug.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../shared_lib/uart_debug.c  -o ${OBJECTDIR}/_ext/689862490/uart_debug.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/689862490/uart_debug.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_XC16_dsPIC30F4013=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../shared_lib" -msmart-io=1 -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/689862490/uart_debug.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/689862490/uart_rf.o: ../shared_lib/uart_rf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/689862490" 
	@${RM} ${OBJECTDIR}/_ext/689862490/uart_rf.o.d 
	@${RM} ${OBJECTDIR}/_ext/689862490/uart_rf.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../shared_lib/uart_rf.c  -o ${OBJECTDIR}/_ext/689862490/uart_rf.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/689862490/uart_rf.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1    -omf=elf -DXPRJ_XC16_dsPIC30F4013=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../shared_lib" -msmart-io=1 -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/689862490/uart_rf.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/configuration_bits.o: configuration_bits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/configuration_bits.o.d 
	@${RM} ${OBJECTDIR}/configuration_bits.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  configuration_bits.c  -o ${OBJECTDIR}/configuration_bits.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/configuration_bits.o.d"        -g -omf=elf -DXPRJ_XC16_dsPIC30F4013=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../shared_lib" -msmart-io=1 -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/configuration_bits.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d"        -g -omf=elf -DXPRJ_XC16_dsPIC30F4013=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../shared_lib" -msmart-io=1 -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/system.o: system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${RM} ${OBJECTDIR}/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system.c  -o ${OBJECTDIR}/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/system.o.d"        -g -omf=elf -DXPRJ_XC16_dsPIC30F4013=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../shared_lib" -msmart-io=1 -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/system.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/traps.o: traps.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/traps.o.d 
	@${RM} ${OBJECTDIR}/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  traps.c  -o ${OBJECTDIR}/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/traps.o.d"        -g -omf=elf -DXPRJ_XC16_dsPIC30F4013=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../shared_lib" -msmart-io=1 -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/traps.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/joystick.o: joystick.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/joystick.o.d 
	@${RM} ${OBJECTDIR}/joystick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  joystick.c  -o ${OBJECTDIR}/joystick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/joystick.o.d"        -g -omf=elf -DXPRJ_XC16_dsPIC30F4013=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../shared_lib" -msmart-io=1 -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/joystick.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/misc.o: misc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/misc.o.d 
	@${RM} ${OBJECTDIR}/misc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  misc.c  -o ${OBJECTDIR}/misc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/misc.o.d"        -g -omf=elf -DXPRJ_XC16_dsPIC30F4013=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../shared_lib" -msmart-io=1 -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/misc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/motor_commands.o: motor_commands.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/motor_commands.o.d 
	@${RM} ${OBJECTDIR}/motor_commands.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  motor_commands.c  -o ${OBJECTDIR}/motor_commands.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/motor_commands.o.d"        -g -omf=elf -DXPRJ_XC16_dsPIC30F4013=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../shared_lib" -msmart-io=1 -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/motor_commands.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/689862490/commands.o: ../shared_lib/commands.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/689862490" 
	@${RM} ${OBJECTDIR}/_ext/689862490/commands.o.d 
	@${RM} ${OBJECTDIR}/_ext/689862490/commands.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../shared_lib/commands.c  -o ${OBJECTDIR}/_ext/689862490/commands.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/689862490/commands.o.d"        -g -omf=elf -DXPRJ_XC16_dsPIC30F4013=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../shared_lib" -msmart-io=1 -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/689862490/commands.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/689862490/message.o: ../shared_lib/message.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/689862490" 
	@${RM} ${OBJECTDIR}/_ext/689862490/message.o.d 
	@${RM} ${OBJECTDIR}/_ext/689862490/message.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../shared_lib/message.c  -o ${OBJECTDIR}/_ext/689862490/message.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/689862490/message.o.d"        -g -omf=elf -DXPRJ_XC16_dsPIC30F4013=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../shared_lib" -msmart-io=1 -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/689862490/message.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/689862490/uart_debug.o: ../shared_lib/uart_debug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/689862490" 
	@${RM} ${OBJECTDIR}/_ext/689862490/uart_debug.o.d 
	@${RM} ${OBJECTDIR}/_ext/689862490/uart_debug.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../shared_lib/uart_debug.c  -o ${OBJECTDIR}/_ext/689862490/uart_debug.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/689862490/uart_debug.o.d"        -g -omf=elf -DXPRJ_XC16_dsPIC30F4013=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../shared_lib" -msmart-io=1 -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/689862490/uart_debug.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/689862490/uart_rf.o: ../shared_lib/uart_rf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/689862490" 
	@${RM} ${OBJECTDIR}/_ext/689862490/uart_rf.o.d 
	@${RM} ${OBJECTDIR}/_ext/689862490/uart_rf.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../shared_lib/uart_rf.c  -o ${OBJECTDIR}/_ext/689862490/uart_rf.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/689862490/uart_rf.o.d"        -g -omf=elf -DXPRJ_XC16_dsPIC30F4013=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"../shared_lib" -msmart-io=1 -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/689862490/uart_rf.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/remote_controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/remote_controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -omf=elf -DXPRJ_XC16_dsPIC30F4013=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)      -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,$(MP_LINKER_FILE_OPTION),--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/remote_controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/remote_controller.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_XC16_dsPIC30F4013=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}/xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/remote_controller.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/XC16_dsPIC30F4013
	${RM} -r dist/XC16_dsPIC30F4013

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
