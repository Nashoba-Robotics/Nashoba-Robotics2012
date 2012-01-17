#include "DriveSubsystem.h"
#include "WPIlib.h"
#include "../OperatorInput.h"
#include "../Commands/JoyStickDriveCommand.h"
#include "../CommandBasedRobot.h"

void DriveSubsystem::InitDefaultCommand()
{
	printf("%s entering", __FUNCTION__);
	SetDefaultCommand( new JoyStickDriveCommand() );
}

void DriveSubsystem::drive (float x, float y, float rotation)
{
	myWPIdrive.MecanumDrive_Cartesian(x,y,rotation);
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
}
