#include "AlignBackWithWallCommand.h"
#include "../Subsystems/DriveSubsystem.h"
#include "math.h"


AlignBackWithWallCommand::AlignBackWithWallCommand() : CommandBase("AlignBackWithWallCommand"){
	Requires(drivesubsystem);
}


void AlignBackWithWallCommand::Initialize() 
{
	
}

// Called repeatedly when this Command is scheduled to run
void AlignBackWithWallCommand::Execute() 
{	
	
	if (drivesubsystem->rightBackIRSensor.GetDistance() == 0 || drivesubsystem->leftBackIRSensor.GetDistance() == 0)  
  	{
  	drivesubsystem->drive (0, 0, 0.5);
  	}
  
  	else
  	{
 //	float length = 35.25;
	float nearFarSensorDistanceDelta =( drivesubsystem->rightBackIRSensor.GetDistance() - drivesubsystem->leftBackIRSensor.GetDistance() );
	float turnSpeed = 0.3;
	if (nearFarSensorDistanceDelta < 0)
	{
		turnSpeed= -1 * turnSpeed;
	}
		


	drivesubsystem->drive (0,
						   0,
						   turnSpeed);
	}
	
}

// Make this return true when this Command no longer needs to run execute()
bool AlignBackWithWallCommand::IsFinished() 
{
	if (fabsf (drivesubsystem->rightBackIRSensor.GetDistance() - drivesubsystem->leftBackIRSensor.GetDistance()) < 0.5 )
	{
		printf("Robot Is Aligned with Wall");
		return true;
	}
	else
	{
		return false;
	}

}

// Called once after isFinished returns true
void AlignBackWithWallCommand::End()
{
	drivesubsystem->drive (0, //Stop motors
						   0,
						   0
						   );
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AlignBackWithWallCommand::Interrupted() 
{
	drivesubsystem->drive (0, //Stop motors
						   0,
						   0
						   );
}
