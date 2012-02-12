#include "RightTurnCommand.h"
#include "../Subsystems/DriveSubsystem.h"


RightTurnCommand::RightTurnCommand() : CommandBase("RightTurnCommand"){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);

	Requires(drivesubsystem);

}

// Called just before this Command runs the first time
void RightTurnCommand::Initialize() 
{
	SetTimeout(2.0);			//Sets a timer (2 secs for testing)
	
	printf("%s Drive Stick Button Pressed : 6\n ", __FUNCTION__ );
	printf("%s Making a 90 Degree Right Turn", __FUNCTION__ );
	
	
}

// Called repeatedly when this Command is scheduled to run
void RightTurnCommand::Execute() 
{			
	drivesubsystem->drive (0, 
						   0, 
						   .5  
						   );
}

// Make this return true when this Command no longer needs to run execute()
bool RightTurnCommand::IsFinished() 
{
	return IsTimedOut();	//Checks to see if the Timer has finished
}

// Called once after isFinished returns true
void RightTurnCommand::End()
{
	drivesubsystem->drive (0, //Stop motors
						   0,
						   0
						   );
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RightTurnCommand::Interrupted() 
{
	drivesubsystem->drive (0, //Stop motors
						   0,
						   0.4
						   );
}
