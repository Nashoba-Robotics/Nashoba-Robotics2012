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

//	drivesubsystem->gyro.Reset();
	
	float direction;

    float RollerTowardsWallShotYValueRight = drivesubsystem->rightFrontIRSensor.GetDistance();
    float RollerTowardsWallShotYValueLeft  = drivesubsystem->leftFrontIRSensor.GetDistance();
    
    float BackTowardsWallShotYValueLeft  =   drivesubsystem->leftBackIRSensor.GetDistance();
    float BackTowardsWallShotYValueRight =   drivesubsystem->rightBackIRSensor.GetDistance();
	
	float ShooterXValue = drivesubsystem->shooterIRSensor.GetDistance();
	
	printf("%f ShooterValue", ShooterXValue);
	//drivesubsystem->driveField(these values will be to go 40 inches to the right);
	
/*	
	direction = 90 + (180/3.14)*(atan( (BackTowardsWallShotYValue -3.5) / (ShooterXValue -4.5) ) );
	
	drivesubsystem->polarDrive( 0.30, direction, 0 );
	
	printf("%f Angle", direction);
	
*/
}

	
// Make this return true when this Command no longer needs to run execute()
bool DriveToCornerCommand::IsFinished() 
{
	if (fabs (drivesubsystem->rightFrontIRSensor.GetDistance()<4.5) && fabs(drivesubsystem->leftFrontIRSensor.GetDistance()) < 4.5 && fabs(drivesubsystem->shooterIRSensor.GetDistance() ) < 5.5 )
	{
		printf("Robot Is Positioned to Shoot");
		return true;
	}
	else if ( fabs(drivesubsystem->rightBackIRSensor.GetDistance()<4.5) && fabs(drivesubsystem->leftBackIRSensor.GetDistance()) < 4.5 && fabs(drivesubsystem->shooterIRSensor.GetDistance() ) < 5.5 )
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
