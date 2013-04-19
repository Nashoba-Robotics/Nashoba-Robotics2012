################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Subsystems/BallIntakeSubsystem.cpp \
../Subsystems/BottomLiftSubsystem.cpp \
../Subsystems/DriveSubsystem.cpp \
../Subsystems/ShooterSubsystem.cpp \
../Subsystems/TopLiftSubsystem.cpp 

OBJS += \
./Subsystems/BallIntakeSubsystem.o \
./Subsystems/BottomLiftSubsystem.o \
./Subsystems/DriveSubsystem.o \
./Subsystems/ShooterSubsystem.o \
./Subsystems/TopLiftSubsystem.o 

CPP_DEPS += \
./Subsystems/BallIntakeSubsystem.d \
./Subsystems/BottomLiftSubsystem.d \
./Subsystems/DriveSubsystem.d \
./Subsystems/ShooterSubsystem.d \
./Subsystems/TopLiftSubsystem.d 


# Each subdirectory must supply rules for building sources it contributes
Subsystems/%.o: ../Subsystems/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: FRC G++ Compiler'
	frc-g++ -O3 -g3 -Wall -c -fmessage-length=0 -pipe -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


