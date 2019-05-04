################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c 

OBJS += \
./src/main.o 

C_DEPS += \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-raspbian-linux-gnueabihf-gcc -I"/home/kirs/rpi-dev/sysroot//usr/local/include" -I"/home/kirs/rpi-dev/sysroot//usr/include" -I"/home/kirs/rpi-dev/sysroot//usr/include/arm-linux-gnueabihf" -O3 -Wall -c -fmessage-length=0 --sysroot=/home/kirs/rpi-dev/sysroot/ -Wl,--sysroot=/home/kirs/rpi-dev/sysroot/ -march=armv6 -mfloat-abi=hard -mfpu=vfp -marm -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


