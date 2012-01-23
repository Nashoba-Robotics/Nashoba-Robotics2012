#include "DriveSubsystem.h"
#include "WPIlib.h"
#include "../OperatorInput.h"
#include "../Commands/JoyStickDriveCommand.h"
#include "../CommandBasedRobot.h"
#include "../Commands/DriveOneWheelCommand.h"
#include "../Commands/DriveForwardAutoCommand.h"

void DriveSubsystem::InitDefaultCommand()
{
	printf("%s entering", __FUNCTION__);
	SetDefaultCommand( new JoyStickDriveCommand() );
//	SetDefaultCommand (new DriveOneWheelCommand() );
//	SetDefaultCommand (new DriveForwardAutoCommand () );
	//	I believe this is what needs to be called when switching to non -default commands -Sam Kirschbaum 1/18/2012
//	SetCurrentCommand (new DriveForwardAutoCommand() );
}

void DriveSubsystem::drive (float x, float y, float z)
{
	static int runNumber = 0;
	
	// This will cut the speed in half for better precision
	if( OperatorInput::getInstance().getDriveStick().GetRawButton( 2 ))
		myWPIdrive.MecanumDrive_Cartesian(( -x ) / 2, ( -y ) / 2, ( -z ) / 2 );
	else
		myWPIdrive.MecanumDrive_Cartesian(-x, -y, -z );
	
	runNumber++;
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



DriveSubsystem::DriveSubsystem() : Subsystem("Drive"), 	
		frontLeftJaguar  ( FRONT_LEFT_JAGUAR_CANID  ),
		frontRightJaguar ( FRONT_RIGHT_JAGUAR_CANID ),
		backLeftJaguar   ( BACK_LEFT_JAGUAR_CANID   ),
		backRightJaguar  ( BACK_RIGHT_JAGUAR_CANID  ),

								   myWPIdrive(frontLeftJaguar,
										      backLeftJaguar,
										      frontRightJaguar,
										      backRightJaguar 
											 )
{
	myWPIdrive.SetSafetyEnabled	(false);
	
	//NOTE: Subtract 2 and 1 so that our numbers match those in WPILib
	myWPIdrive.SetInvertedMotor(( RobotDrive::MotorType )( FRONT_RIGHT_JAGUAR_CANID - 2 ), true );
	myWPIdrive.SetInvertedMotor(( RobotDrive::MotorType )( BACK_RIGHT_JAGUAR_CANID - 1 ), true );
}