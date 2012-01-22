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
	SetTimeout(2.5);			//Sets a timer (2.5 secs for testing)
	printf("timer has been set\n");
}

// Called repeatedly when this Command is scheduled to run
void DriveForwardAutoCommand::Execute() 
{
	drivesubsystem->drive (0, 
						   -0.5f, //Go Forward at half speed
						   0  
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
	drivesubsystem->drive (0, //Stop motors
						   0,
						   0
						   );
}
