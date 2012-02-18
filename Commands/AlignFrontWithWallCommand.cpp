#include "AlignFrontWithWallCommand.h"
#include "../Subsystems/DriveSubsystem.h"
#include "math.h"


AlignFrontWithWallCommand::AlignFrontWithWallCommand() : CommandBase("AlignFrontWithWallCommand"){
	Requires(drivesubsystem);
}


void AlignFrontWithWallCommand::Initialize() 
{
	
}

// Called repeatedly when this Command is scheduled to run
void AlignFrontWithWallCommand::Execute() 
{	
	
	if (drivesubsystem->rightFrontIRSensor.GetDistance() == 0 || drivesubsystem->leftFrontIRSensor.GetDistance() == 0)  
  	{
  	drivesubsystem->drive (0, 0, 0.5);
  	}
	else
	{
//	float length = 35.25;
	float nearFarSensorDistanceDelta =( drivesubsystem->rightFrontIRSensor.GetDistance() - drivesubsystem->leftFrontIRSensor.GetDistance() );
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
bool AlignFrontWithWallCommand::IsFinished() 
{
	if (fabsf (drivesubsystem->rightFrontIRSensor.GetDistance() - drivesubsystem->leftFrontIRSensor.GetDistance()) < 0.5 )
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
void AlignFrontWithWallCommand::End()
{
	drivesubsystem->drive (0, //Stop motors
						   0,
						   0
						   );
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AlignFrontWithWallCommand::Interrupted() 
{
	drivesubsystem->drive (0, //Stop motors
						   0,
						   0
						   );
}
