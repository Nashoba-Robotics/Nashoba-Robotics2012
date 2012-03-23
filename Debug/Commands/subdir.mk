################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Commands/AddParallelTestingCommand.cpp \
../Commands/BallIntakeCommand.cpp \
../Commands/DriveForwardAutoCommand.cpp \
../Commands/DriveOneWheelCommand.cpp \
../Commands/ExampleCommand.cpp \
../Commands/JoyStickDriveCommand.cpp \
../Commands/PrintfOneSecInterval.cpp \
../Commands/RightTurnCommand.cpp \
../Commands/ShootCommand.cpp \
../Commands/StraightThenRightTurnCommand.cpp 

OBJS += \
./Commands/AddParallelTestingCommand.o \
./Commands/BallIntakeCommand.o \
./Commands/DriveForwardAutoCommand.o \
./Commands/DriveOneWheelCommand.o \
./Commands/ExampleCommand.o \
./Commands/JoyStickDriveCommand.o \
./Commands/PrintfOneSecInterval.o \
./Commands/RightTurnCommand.o \
./Commands/ShootCommand.o \
./Commands/StraightThenRightTurnCommand.o 

CPP_DEPS += \
./Commands/AddParallelTestingCommand.d \
./Commands/BallIntakeCommand.d \
./Commands/DriveForwardAutoCommand.d \
./Commands/DriveOneWheelCommand.d \
./Commands/ExampleCommand.d \
./Commands/JoyStickDriveCommand.d \
./Commands/PrintfOneSecInterval.d \
./Commands/RightTurnCommand.d \
./Commands/ShootCommand.d \
./Commands/StraightThenRightTurnCommand.d 


# Each subdirectory must supply rules for building sources it contributes
Commands/%.o: ../Commands/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


