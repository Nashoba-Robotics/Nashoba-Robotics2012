#include "DriveDurationCommand.h"
#include "../Subsystems/DriveSubsystem.h"
#include "../Debug.h"


DriveDurationCommand::DriveDurationCommand(double duration, double bearingX, double bearingY) : CommandBase("DriveDurationCommand"){

	Requires(drivesubsystem);
	m_duration = duration;
	m_bearingX = bearingX;
	m_bearingY = bearingY;
}

// Called just before this Command runs the first time
void DriveDurationCommand::Initialize() 
{
	
	SetTimeout(m_duration);			//Sets a timer 
	
//	drivesubsystem->Enable();
	printf("%s Driving Forward at 1/5 speed for %f seconds\n", __FUNCTION__, m_duration );
	
	ResetPrintCounter();
	
}

// Called repeatedly when this Command is scheduled to run
void DriveDurationCommand::Execute() 
{
	if( IsTimeToPrint() )
		printf( "DriveDurationCommand::Execute\n");
	
	drivesubsystem->drive (m_bearingY, 
						   m_bearingX, 
						   0
						   );
	
}

// Make this return true when this Command no longer needs to run execute()
bool DriveDurationCommand::IsFinished() 
{
	return IsTimedOut();	//Checks to see if the Timer has finished
}

// Called once after isFinished returns true
void DriveDurationCommand::End()
{
	drivesubsystem->drive (0, //Stop motors
						   0,
						   0
						   );
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveDurationCommand::Interrupted() 
{
	printf( "DriveDurationCommand Interrupt\n");
	drivesubsystem->drive (0, //Stop motors
						   0,
						   0
						   );
}
