#include "DriveToForwardWallCommand.h"
#include "../Subsystems/DriveSubsystem.h"
#include "math.h"


DriveToForwardWallCommand::DriveToForwardWallCommand() : CommandBase("DriveToForwardWallCommand"){
	Requires(drivesubsystem);
}


void DriveToForwardWallCommand::Initialize() 
{
	
}

// Called repeatedly when this Command is scheduled to run
void DriveToForwardWallCommand::Execute() 
{	

	drivesubsystem->drive(0, 0.25, 0);
    
}

	
// Make this return true when this Command no longer needs to run execute()
bool DriveToForwardWallCommand::IsFinished() 
{
	if (fabs (drivesubsystem->rightBackIRSensor.GetDistance() < 15) && fabs(drivesubsystem->leftBackIRSensor.GetDistance()) < 15 )
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Called once after isFinished returns true
void DriveToForwardWallCommand::End()
{
	drivesubsystem->drive (0, //Stop motors
						   0,
						   0
						   );
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveToForwardWallCommand::Interrupted() 
{
	drivesubsystem->drive (0, //Stop motors
						   0,
						   0
						   );
}
