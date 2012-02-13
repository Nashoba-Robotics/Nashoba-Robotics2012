#include "AlignWithWallCommand.h"
#include "../Subsystems/DriveSubsystem.h"
#include "math.h"


AlignWithWallCommand::AlignWithWallCommand() : CommandBase("AlignWithWallCommand"){
	Requires(drivesubsystem);
}


void AlignWithWallCommand::Initialize() 
{
	
}

// Called repeatedly when this Command is scheduled to run
void AlignWithWallCommand::Execute() 
{	
/*	float length = 35.25;
	float nearFarSensorDistanceDelta =( drivesubsystem->rightFrontIRSensor.GetDistance() - drivesubsystem->leftFrontIRSensor.GetDistance() );
	float turnSpeed = 0.3;
	if (nearFarSensorDistanceDelta < 0)
	{
		turnSpeed= -1 * turnSpeed;
	}
		


	drivesubsystem->drive (0,
						   0,
						   turnSpeed);*/
	
}

// Make this return true when this Command no longer needs to run execute()
bool AlignWithWallCommand::IsFinished() 
{
/*	if (fabsf (drivesubsystem->rightFrontIRSensor.GetDistance() - drivesubsystem->leftFrontIRSensor.GetDistance()) < 0.5 )
	{
		printf("Robot Is Aligned with Wall");
		return true;
	}
	else
	{
		return false;
	}*/
	return true;
}

// Called once after isFinished returns true
void AlignWithWallCommand::End()
{
	drivesubsystem->drive (0, //Stop motors
						   0,
						   0
						   );
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AlignWithWallCommand::Interrupted() 
{
	drivesubsystem->drive (0, //Stop motors
						   0,
						   0
						   );
}
