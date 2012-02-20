#include "DriveIntoSideWallCommand.h"
#include "../Subsystems/DriveSubsystem.h"
#include "math.h"


DriveIntoSideWallCommand::DriveIntoSideWallCommand() : CommandBase("DriveIntoSideWallCommand"){
	Requires(drivesubsystem);
}


void DriveIntoSideWallCommand::Initialize() 
{
	
}

// Called repeatedly when this Command is scheduled to run
void DriveIntoSideWallCommand::Execute() 
{	

	drivesubsystem->drive(0, 0.175, 0);
    
}

	
// Make this return true when this Command no longer needs to run execute()
bool DriveIntoSideWallCommand::IsFinished() 
{
	if (fabs (drivesubsystem->rightBackIRSensor.GetDistance() < 11.5) && fabs(drivesubsystem->leftBackIRSensor.GetDistance()) < 11.5 )
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Called once after isFinished returns true
void DriveIntoSideWallCommand::End()
{
	drivesubsystem->drive (0, //Stop motors
						   0,
						   0
						   );
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveIntoSideWallCommand::Interrupted() 
{
	drivesubsystem->drive (0, //Stop motors
						   0,
						   0
						   );
}
