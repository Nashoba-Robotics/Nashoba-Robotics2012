#include "DriveForwardAutoCommand.h"
#include "../Subsystems/DriveSubsystem.h"


DriveForwardAutoCommand::DriveForwardAutoCommand() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);

	Requires(drivesubsystem);

}

// Called just before this Command runs the first time
void DriveForwardAutoCommand::Initialize() 
{
<<<<<<< HEAD
	SetTimeout(2.5);			//Sets a timer (2.5 secs for testing)
	printf("timer has been set\n");
=======
	SetTimeout(5.0);			//Sets a timer (5 secs for testing)
	
	printf("%s Drive Stick Button Pressed: Trigger\n ", __FUNCTION__ );
	printf("%s Driving Forward at 1/5 speed for 5 seconds\n", __FUNCTION__ );
	
	
>>>>>>> sam
}

// Called repeatedly when this Command is scheduled to run
void DriveForwardAutoCommand::Execute() 
{			
	drivesubsystem->drive (0, 
<<<<<<< HEAD
						   -0.5f, //Go Forward at half speed
=======
						   -0.20, //Go Forward at 1/5 speed
>>>>>>> sam
						   0  
						   );
}

// Make this return true when this Command no longer needs to run execute()
bool DriveForwardAutoCommand::IsFinished() 
{
	return IsTimedOut();	//Checks to see if the Timer has finished
}

// Called once after isFinished returns true
void DriveForwardAutoCommand::End()
{
	drivesubsystem->drive (0, //Stop motors
						   0,
						   0
						   );
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForwardAutoCommand::Interrupted() 
{
	drivesubsystem->drive (0, //Stop motors
						   0,
						   0
						   );
}
