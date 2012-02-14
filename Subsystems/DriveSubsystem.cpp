#include "DriveSubsystem.h"
#include "WPIlib.h"
#include "../OperatorInput.h"
#include "../Commands/JoyStickDriveCommand.h"
#include "../CommandBasedRobot.h"
#include "../Commands/DriveOneWheelCommand.h"
#include "../Commands/DriveDurationCommand.h"
#include "../HardwareSettings.h"


void DriveSubsystem::InitDefaultCommand()
{
	printf("%s entering", __FUNCTION__);
	SetDefaultCommand( new JoyStickDriveCommand() );
}

void DriveSubsystem::drive (float x, float y, float z )
{
	//float angle = gyro.GetAngle();
	myWPIdrive.MecanumDrive_Cartesian(x, y, (z/2), 0 /*gyro.GetAngle*/ );
}

void DriveSubsystem::polarDrive (float mag, float dir, float rot)
{
	myWPIdrive.MecanumDrive_Polar(mag, dir, rot);
}

void DriveSubsystem::frontLeftJaguarDrive (float speed)
{
	frontLeftJaguar.Set (speed);
}
void DriveSubsystem::frontRightJaguarDrive (float speed)
{
	frontRightJaguar.Set (speed);
}
void DriveSubsystem::backLeftJaguarDrive (float speed)
{
	backLeftJaguar.Set (speed);
}
void DriveSubsystem::backRightJaguarDrive (float speed)
{
	backRightJaguar.Set (speed);
}



DriveSubsystem::DriveSubsystem() : Subsystem("DriveSubsystem"), 	
		frontLeftJaguar  ( FRONT_LEFT_JAGUAR_CANID  ),
		frontRightJaguar ( FRONT_RIGHT_JAGUAR_CANID ),
		backLeftJaguar   ( BACK_LEFT_JAGUAR_CANID   ),
		backRightJaguar  ( BACK_RIGHT_JAGUAR_CANID  ),
		gyro ( GYRO_PORT ),
		myWPIdrive(frontLeftJaguar,  backLeftJaguar, frontRightJaguar,backRightJaguar),
		shooterIRSensor   (	SHOOTER_IR_SENSOR_PORT    ),
		leftFrontIRSensor (	LEFT_FRONT_IR_SENSOR_PORT ),
		leftBackIRSensor  (	LEFT_BACK_IR_SENSOR_PORT  ),
		rightFrontIRSensor(	RIGHT_FRONT_IR_SENSOR_PORT),
		rightBackIRSensor (	RIGHT_BACK_IR_SENSOR_PORT )
{
	myWPIdrive.SetSafetyEnabled	(false);
#define NR_CAST_CANID
#ifndef NR_CAST_CANID
	myWPIdrive.SetInvertedMotor( myWPIdrive.kFrontLeftMotor, true );
	myWPIdrive.SetInvertedMotor( myWPIdrive.kRearLeftMotor, true );
#else
	myWPIdrive.SetInvertedMotor(( RobotDrive::kFrontRightMotor ), true );
	myWPIdrive.SetInvertedMotor(( RobotDrive::kRearRightMotor ), true );
#endif
}


