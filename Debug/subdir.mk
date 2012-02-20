################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CommandBase.cpp \
../CommandBasedRobot.cpp \
../OperatorInput.cpp 

OBJS += \
./CommandBase.o \
./CommandBasedRobot.o \
./OperatorInput.o 

CPP_DEPS += \
./CommandBase.d \
./CommandBasedRobot.d \
./OperatorInput.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


