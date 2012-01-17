#include "DriveForwardAutoCommand.h"
#include "../Subsystems/DriveSubsystem.h"


DriveForwardAutoCommand::DriveForwardAutoCommand() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	
	Requires(drivesubsystem);
	
}

// Called just before this Command runs the first time
void DriveForwardAutoCommand::Initialize() 
{
	SetTimeout(5.0);			//Sets a timer
	printf("timer has been set\n");
}

// Called repeatedly when this Command is scheduled to run
void DriveForwardAutoCommand::Execute() 
{
	drivesubsystem->drive (1, //Go forward at max speed
						   0, //No turning
						   0  //No rotation
						   );
}

// Make this return true when this Command no longer needs to run execute()
bool DriveForwardAutoCommand::IsFinished() 
{
	return IsTimedOut();	//Checks to see if the Timer has finished
}

// Called once after isFinished returns true
void DriveForwardAutoCommand::End()
{
	drivesubsystem->drive (0, //Stop motors
						   0,
						   0
						   );
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForwardAutoCommand::Interrupted() 
{
}
