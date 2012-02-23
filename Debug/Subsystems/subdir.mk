################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Subsystems/BallIntakeSubsystem.cpp \
../Subsystems/BottomLiftSubsystem.cpp \
../Subsystems/DriveSubsystem.cpp \
../Subsystems/ExampleSubsystem.cpp \
../Subsystems/RampTipperSubsystem.cpp \
../Subsystems/ShooterSubsystem.cpp \
../Subsystems/TopLiftSubsystem.cpp 

OBJS += \
./Subsystems/BallIntakeSubsystem.o \
./Subsystems/BottomLiftSubsystem.o \
./Subsystems/DriveSubsystem.o \
./Subsystems/ExampleSubsystem.o \
./Subsystems/RampTipperSubsystem.o \
./Subsystems/ShooterSubsystem.o \
./Subsystems/TopLiftSubsystem.o 

CPP_DEPS += \
./Subsystems/BallIntakeSubsystem.d \
./Subsystems/BottomLiftSubsystem.d \
./Subsystems/DriveSubsystem.d \
./Subsystems/ExampleSubsystem.d \
./Subsystems/RampTipperSubsystem.d \
./Subsystems/ShooterSubsystem.d \
./Subsystems/TopLiftSubsystem.d 


# Each subdirectory must supply rules for building sources it contributes
Subsystems/%.o: ../Subsystems/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


