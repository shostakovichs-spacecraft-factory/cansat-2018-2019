################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/Drivers/sx1268/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: bombidary-radio

# Tool invocations
bombidary-radio: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross GCC Linker'
	arm-raspbian-linux-gnueabihf-gcc -L"/home/kirs/rpi-dev/sysroot//lib/arm-linux-gnueabihf" -L"/home/kirs/rpi-dev/sysroot//usr/local/lib" --sysroot=/home/kirs/rpi-dev/sysroot/ -Wl,--sysroot=/home/kirs/rpi-dev/sysroot/ -march=armv6 -mfloat-abi=hard -mfpu=vfp -marm -Xlinker -pthread -o "bombidary-radio" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) bombidary-radio
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
