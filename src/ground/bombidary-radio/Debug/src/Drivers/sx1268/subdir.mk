################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Drivers/sx1268/sx1268.c 

OBJS += \
./src/Drivers/sx1268/sx1268.o 

C_DEPS += \
./src/Drivers/sx1268/sx1268.d 


# Each subdirectory must supply rules for building sources it contributes
src/Drivers/sx1268/%.o: ../src/Drivers/sx1268/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-raspbian-linux-gnueabihf-gcc -DSX1268_RPI=1 -I"/home/kirs/development/rpi-dev/sysroot//usr/local/include" -I"/home/kirs/development/rpi-dev/sysroot//usr/include" -I"/home/kirs/development/rpi-dev/sysroot//usr/include/arm-linux-gnueabihf" -I"/home/kirs/development/cansat-2018-2019/src/ground/bombidary-radio/Debug/../src/Drivers/sx1268" -O3 -Wall -c -fmessage-length=0 -pthread --sysroot=/home/kirs/development/rpi-dev/sysroot/ -Wl,--sysroot=/home/kirs/development/rpi-dev/sysroot/ -march=armv6 -mfloat-abi=hard -mfpu=vfp -marm -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


