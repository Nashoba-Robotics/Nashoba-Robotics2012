#include "RotateAngleCommand.h"
#include "../Subsystems/DriveSubsystem.h"


RotateAngleCommand::RotateAngleCommand(float angle) : CommandBase("RotateAngleCommand"){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);

	Requires(drivesubsystem);
	m_angle = angle;

}

// Called just before this Command runs the first time
void RotateAngleCommand::Initialize()
{
	SetTimeout(2.0);			//Sets a timer (2 secs for testing)

	printf("%s Drive Stick Button Pressed : 6\n ", __FUNCTION__ );
	printf("%s Making a 90 Degree Right Turn", __FUNCTION__ );

	drivesubsystem->gyro.Reset();
	drivesubsystem->gyro.GetAngle();

}

// Called repeatedly when this Command is scheduled to run
void RotateAngleCommand::Execute()
{
	drivesubsystem->drive (0,
						   0,
						   .5
						   );
}

// Make this return true when this Command no longer needs to run execute()
bool RotateAngleCommand::IsFinished()
{
	return IsTimedOut();	//Checks to see if the Timer has finished
}

// Called once after isFinished returns true
void RotateAngleCommand::End()
{
	drivesubsystem->drive (0, //Stop motors
						   0,
						   0
						   );
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RotateAngleCommand::Interrupted()
{
	drivesubsystem->drive (0, //Stop motors
						   0,
						   0
						   );
}
