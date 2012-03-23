#include "DriveIntoCornerContinuousCommand.h"
#include "../Subsystems/DriveSubsystem.h"
#include "../Debug.h"
#include "math.h"


DriveIntoCornerContinuousCommand::DriveIntoCornerContinuousCommand() : CommandBase("DriveIntoCornerContinuousCommand"){
	Requires(drivesubsystem);
}


void DriveIntoCornerContinuousCommand::Initialize() 
{
	SetTimeout(1.0);
}

// Called repeatedly when this Command is scheduled to run
void DriveIntoCornerContinuousCommand::Execute() 
{	

	drivesubsystem->drive(0.50, 0.25, 0);
    
}

	
// Make this return true when this Command no longer needs to run execute()
bool DriveIntoCornerContinuousCommand::IsFinished() 
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void DriveIntoCornerContinuousCommand::End()
{
	drivesubsystem->drive (0, //Stop motors
						   0,
						   0
						   );
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveIntoCornerContinuousCommand::Interrupted() 
{
	drivesubsystem->drive (0, //Stop motors
						   0,
						   0
						   );
}
