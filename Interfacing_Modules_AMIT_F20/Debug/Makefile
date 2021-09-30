################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../ADC.c \
../DIO.c \
../EXT_INT.c \
../KEYPAD.c \
../LCD.c \
../main.c \
../Motor.c \
../OUTPUT_Module.c \
../S7SEG.c \
../Servo.c \
../Timer0.c \
../TWI.c \
../UART.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
ADC.o \
DIO.o \
EXT_INT.o \
KEYPAD.o \
LCD.o \
main.o \
Motor.o \
OUTPUT_Module.o \
S7SEG.o \
Servo.o \
Timer0.o \
TWI.o \
UART.o

OBJS_AS_ARGS +=  \
ADC.o \
DIO.o \
EXT_INT.o \
KEYPAD.o \
LCD.o \
main.o \
Motor.o \
OUTPUT_Module.o \
S7SEG.o \
Servo.o \
Timer0.o \
TWI.o \
UART.o

C_DEPS +=  \
ADC.d \
DIO.d \
EXT_INT.d \
KEYPAD.d \
LCD.d \
main.d \
Motor.d \
OUTPUT_Module.d \
S7SEG.d \
Servo.d \
Timer0.d \
TWI.d \
UART.d

C_DEPS_AS_ARGS +=  \
ADC.d \
DIO.d \
EXT_INT.d \
KEYPAD.d \
LCD.d \
main.d \
Motor.d \
OUTPUT_Module.d \
S7SEG.d \
Servo.d \
Timer0.d \
TWI.d \
UART.d

OUTPUT_FILE_PATH +=Interfacing_Modules_AMIT_F20.elf

OUTPUT_FILE_PATH_AS_ARGS +=Interfacing_Modules_AMIT_F20.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler



























./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 4.9.2
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\Atmel\ATmega_DFP\1.3.300\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\Atmel\ATmega_DFP\1.3.300\gcc\dev\atmega32" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 4.9.2
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="Interfacing_Modules_AMIT_F20.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega32 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\Atmel\ATmega_DFP\1.3.300\gcc\dev\atmega32"  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "Interfacing_Modules_AMIT_F20.elf" "Interfacing_Modules_AMIT_F20.hex"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "Interfacing_Modules_AMIT_F20.elf" "Interfacing_Modules_AMIT_F20.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "Interfacing_Modules_AMIT_F20.elf" > "Interfacing_Modules_AMIT_F20.lss"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "Interfacing_Modules_AMIT_F20.elf" "Interfacing_Modules_AMIT_F20.srec"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "Interfacing_Modules_AMIT_F20.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "Interfacing_Modules_AMIT_F20.elf" "Interfacing_Modules_AMIT_F20.a" "Interfacing_Modules_AMIT_F20.hex" "Interfacing_Modules_AMIT_F20.lss" "Interfacing_Modules_AMIT_F20.eep" "Interfacing_Modules_AMIT_F20.map" "Interfacing_Modules_AMIT_F20.srec" "Interfacing_Modules_AMIT_F20.usersignatures"
	