################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../PPC603gnu/CommandBasedRobotTemplate/Debug/ctdt.o 

C_SRCS += \
../PPC603gnu/CommandBasedRobotTemplate/Debug/ctdt.c 

OBJS += \
./PPC603gnu/CommandBasedRobotTemplate/Debug/ctdt.o 

C_DEPS += \
./PPC603gnu/CommandBasedRobotTemplate/Debug/ctdt.d 


# Each subdirectory must supply rules for building sources it contributes
PPC603gnu/CommandBasedRobotTemplate/Debug/%.o: ../PPC603gnu/CommandBasedRobotTemplate/Debug/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


