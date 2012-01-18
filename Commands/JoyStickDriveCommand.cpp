#include "JoyStickDriveCommand.h"
#include "../Subsystems/DriveSubsystem.h"

JoyStickDriveCommand::JoyStickDriveCommand() 
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	
	Requires(drivesubsystem);
}

// Called just before this Command runs the first time
void JoyStickDriveCommand::Initialize() 
{
	
}

// Called repeatedly when this Command is scheduled to run
void JoyStickDriveCommand::Execute() 
{

	// Default Command that will drive the robot with Mecanum Cartesian Drive
	drivesubsystem->drive (
					OperatorInput::getInstance().getDriveStick().GetX(),
					OperatorInput::getInstance().getDriveStick().GetY(),
					OperatorInput::getInstance().getDriveStick().GetZ()// Switch to get twist if not working 
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
	
}
