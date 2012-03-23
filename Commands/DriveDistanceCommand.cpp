#include "DriveDistanceCommand.h"
#include "../Subsystems/DriveSubsystem.h"
#include "../Debug.h"


DriveDistanceCommand::DriveDistanceCommand(double distance, double bearingX, double bearingY) : CommandBase("DriveDistanceCommand"){

	Requires(drivesubsystem);
	m_distance = distance;
	m_bearingX = bearingX;
	m_bearingY = bearingY;
}

// Called just before this Command runs the first time
void DriveDistanceCommand::Initialize() 
{
	
	float startEncoderValueAvg;
	float endEncoderValue;
	
	float frontLeftEncoderValue = -drivesubsystem->frontLeftJaguar.GetPosition();
	float frontRightEncoderValue = drivesubsystem->frontRightJaguar.GetPosition();
	float backLeftEncoderValue = -drivesubsystem->backLeftJaguar.GetPosition();
	float backRightEncoderValue = drivesubsystem->backRightJaguar.GetPosition();
	
//	startEncoderValueAvg = (frontLeftEncoderValue + frontRightEncoderValu + backLeftEncoderValue + backRightEncoderValue)/4;
//	endEncoderValue = find function of encoder values
	
}	
// Called repeatedly when this Command is scheduled to run
void DriveDistanceCommand::Execute() 
{
	float currentFrontLeftEncoderValue = -drivesubsystem->frontLeftJaguar.GetPosition();
	float currentFrontRightEncoderValue = drivesubsystem->frontRightJaguar.GetPosition();
	float currentBackLeftEncoderValue = -drivesubsystem->backLeftJaguar.GetPosition();
	float currentBackRightEncoderValue = drivesubsystem->backRightJaguar.GetPosition();
	
	float currentEncoderValueAvg = (currentFrontLeftEncoderValue + currentFrontRightEncoderValue + currentBackLeftEncoderValue + currentBackRightEncoderValue)/4;
	
	
	drivesubsystem->drive (m_bearingY, 
						   m_bearingX, 
						   0
						   );
	
}

// Make this return true when this Command no longer needs to run execute()
bool DriveDistanceCommand::IsFinished() 
{
	//return (endEncoderValue =< currentEncoderValueAvg);
}

// Called once after isFinished returns true
void DriveDistanceCommand::End()
{
	drivesubsystem->drive (0, //Stop motors
						   0,
						   0
						   );
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveDistanceCommand::Interrupted() 
{
	printf( "DriveDistanceCommand Interrupt\n");
	drivesubsystem->drive (0, //Stop motors
						   0,
						   0
						   );
}
