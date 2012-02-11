#include "JoyStickDriveCommand.h"
#include "DriveForwardAutoCommand.h"
#include "../OperatorInput.h"
#include "../Subsystems/DriveSubsystem.h"
#include "../Debug.h"


JoyStickDriveCommand::JoyStickDriveCommand() : CommandBase("JoyStickDriveCommand")
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	
	Requires(drivesubsystem);
}

// Called just before this Command runs the first time
void JoyStickDriveCommand::Initialize() 
{
	ResetPrintCounter();
	printf ("DriveForwardAutoCommand Initialized \n");
}

// Called repeatedly when this Command is scheduled to run
void JoyStickDriveCommand::Execute() 
{
	Joystick& driveStick = OperatorInput::getInstance().getDriveStick();
	
	if( IsTimeToPrint() )
		printf( "JoyStickDriveCommand::Execute\n");
	// Default Command that will drive the robot with Mecanum Cartesian Drive
	drivesubsystem->drive (
					SNAP_TO_VALUE( 0, 0.05, driveStick.GetX() ), 
					SNAP_TO_VALUE( 0, 0.05, driveStick.GetY() ),
					SNAP_TO_VALUE( 0, 0.05, driveStick.GetZ() ) 
					// gyro (when uncommenting, add comma above)
						   );
	
}

// Make this return true when this Command no longer needs to run execute()
bool JoyStickDriveCommand::IsFinished() 
{
	return false;
}

// Called once after isFinished returns true
void JoyStickDriveCommand::End() 
{
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void JoyStickDriveCommand::Interrupted() 
{
	printf("JoyStickDriveCommand has been Interrupted");
}
