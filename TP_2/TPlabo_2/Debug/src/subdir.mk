################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ArrayPassenger.c \
../src/Entidades.c \
../src/TPlabo_2.c 

C_DEPS += \
./src/ArrayPassenger.d \
./src/Entidades.d \
./src/TPlabo_2.d 

OBJS += \
./src/ArrayPassenger.o \
./src/Entidades.o \
./src/TPlabo_2.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/ArrayPassenger.d ./src/ArrayPassenger.o ./src/Entidades.d ./src/Entidades.o ./src/TPlabo_2.d ./src/TPlabo_2.o

.PHONY: clean-src

