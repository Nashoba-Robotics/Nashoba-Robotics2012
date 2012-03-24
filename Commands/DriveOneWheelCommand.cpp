#include "DriveOneWheelCommand.h"
#include "../Subsystems/DriveSubsystem.h"

DriveOneWheelCommand::DriveOneWheelCommand() : CommandBase("DriveOneWheelCommand")
{
	// Use Requires() here to declare subsystem dependencies
	
	Requires(drivesubsystem);
}

// Called just before this Command runs the first time
void DriveOneWheelCommand::Initialize() 
{
	ResetPrintCounter();
	printf ("IntakeIdleCommand Initialized \n");
}

// Called repeatedly when this Command is scheduled to run
void DriveOneWheelCommand::Execute() 
{

	drivesubsystem->frontLeftJaguarDrive (-1.0);
	
}

// Make this return true when this Command no longer needs to run execute()
bool DriveOneWheelCommand::IsFinished() 
{
	return false;
}

// Called once after isFinished returns true
void DriveOneWheelCommand::End() 
{
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveOneWheelCommand::Interrupted() {
}
