#include "DriveIntoFrontWallCommand.h"
#include "../Subsystems/DriveSubsystem.h"
#include "math.h"


DriveIntoFrontWallCommand::DriveIntoFrontWallCommand() : CommandBase("DriveIntoFrontWallCommand"){
	Requires(drivesubsystem);
}


void DriveIntoFrontWallCommand::Initialize() 
{
	
}

// Called repeatedly when this Command is scheduled to run
void DriveIntoFrontWallCommand::Execute() 
{	

	drivesubsystem->drive(0, 0.125, 0);
    
}

	
// Make this return true when this Command no longer needs to run execute()
bool DriveIntoFrontWallCommand::IsFinished() 
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
void DriveIntoFrontWallCommand::End()
{
	drivesubsystem->drive (0, //Stop motors
						   0,
						   0
						   );
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveIntoFrontWallCommand::Interrupted() 
{
	drivesubsystem->drive (0, //Stop motors
						   0,
						   0
						   );
}
