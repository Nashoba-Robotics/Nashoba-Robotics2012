################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../AnalogIRSensor.cpp \
../BallSensor.cpp \
../BallTracker.cpp \
../CommandBase.cpp \
../CommandBasedRobot.cpp \
../CoprocessorVision.cpp \
../OperatorInput.cpp 

OBJS += \
./AnalogIRSensor.o \
./BallSensor.o \
./BallTracker.o \
./CommandBase.o \
./CommandBasedRobot.o \
./CoprocessorVision.o \
./OperatorInput.o 

CPP_DEPS += \
./AnalogIRSensor.d \
./BallSensor.d \
./BallTracker.d \
./CommandBase.d \
./CommandBasedRobot.d \
./CoprocessorVision.d \
./OperatorInput.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: FRC G++ Compiler'
	frc-g++ -O3 -g3 -Wall -c -fmessage-length=0 -pipe -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


