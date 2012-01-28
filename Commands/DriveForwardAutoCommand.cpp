#include "DriveForwardAutoCommand.h"
#include "../Subsystems/DriveSubsystem.h"




DriveForwardAutoCommand::DriveForwardAutoCommand() : CommandBase("DriveForwardAutoCommand"){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);

	Requires(drivesubsystem);

}

// Called just before this Command runs the first time
void DriveForwardAutoCommand::Initialize() 
{
	SetTimeout(10.0);			//Sets a timer (10 secs for testing)
	
//	drivesubsystem->Enable();
	printf("%s Driving Forward at 1/5 speed for 10 seconds\n", __FUNCTION__ );
	
	
}

// Called repeatedly when this Command is scheduled to run
void DriveForwardAutoCommand::Execute() 
{
	static int runNum = 0;
	if( runNum % 10 == 0)
		printf( "DriveForwardAutoCommand::Execute\n");
	
	drivesubsystem->drive (0, 
						   -0.20, //Go Forward at 1/5 speed
						   0  
						   );
	runNum++;
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
//	drivesubsystem->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForwardAutoCommand::Interrupted() 
{
	printf( "DriveForwardAutoCommand Interrupt\n");
	drivesubsystem->drive (0, //Stop motors
						   0,
						   0
						   );
//	drivesubsystem->Disable();
}
