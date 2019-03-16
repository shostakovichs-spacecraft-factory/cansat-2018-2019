################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Light_direction_determinant.c \
../src/main.c \
../src/matrix.c 

OBJS += \
./src/Light_direction_determinant.o \
./src/main.o \
./src/matrix.o 

C_DEPS += \
./src/Light_direction_determinant.d \
./src/main.d \
./src/matrix.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


