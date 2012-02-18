#include "DriveToCornerCommand.h"
#include "../Subsystems/DriveSubsystem.h"
#include "math.h"


DriveToCornerCommand::DriveToCornerCommand() : CommandBase("DriveToCornerCommand"){
	Requires(drivesubsystem);
}


void DriveToCornerCommand::Initialize() 
{
	
}

// Called repeatedly when this Command is scheduled to run
void DriveToCornerCommand::Execute() 
{	

	drivesubsystem->gyro.Reset();
	
	float direction;

    float RollerTowardsWallShotYValue = drivesubsystem->rightFrontIRSensor.GetDistance();
    float BackTowardsWallShotYValue = drivesubsystem->rightBackIRSensor.GetDistance();
	
	float ShooterXValue = drivesubsystem->shooterIRSensor.GetDistance();
	
	if (RollerTowardsWallShotYValue > BackTowardsWallShotYValue)
	{
	direction = 90 + ( 1 / ( tanf( (ShooterXValue - 4.5) / (RollerTowardsWallShotYValue - 3.5) ) ) );
	}
	else
	{
	direction = tanf( (ShooterXValue - 4.5) / (BackTowardsWallShotYValue - 3.5) );
	}
	
	drivesubsystem->polarDrive( 0.5, direction, 0 );

}

	
// Make this return true when this Command no longer needs to run execute()
bool DriveToCornerCommand::IsFinished() 
{
	if (fabsf (drivesubsystem->rightFrontIRSensor.GetDistance()<4.5) && fabsf(drivesubsystem->leftFrontIRSensor.GetDistance()) < 4.5 && fabsf(drivesubsystem->shooterIRSensor.GetDistance() ) < 5.5 )
	{
		printf("Robot Is Positioned to Shoot");
		return true;
	}
	else if ( fabsf(drivesubsystem->rightBackIRSensor.GetDistance()<4.5) && fabsf(drivesubsystem->leftBackIRSensor.GetDistance()) < 4.5 && fabsf(drivesubsystem->shooterIRSensor.GetDistance() ) < 5.5 )
	{
		printf("Robot Is Positioned to Shoot");
		return true;
	}
	else
	{
		return false;
	}
}

// Called once after isFinished returns true
void DriveToCornerCommand::End()
{
	drivesubsystem->drive (0, //Stop motors
						   0,
						   0
						   );
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveToCornerCommand::Interrupted() 
{
	drivesubsystem->drive (0, //Stop motors
						   0,
						   0
						   );
}
