#include "PrintfOneSecInterval.h"


PrintfOneSecInterval::PrintfOneSecInterval() : CommandBase("PrintfOneSecInterval")
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void PrintfOneSecInterval::Initialize() 
{
	SetTimeout(10.0);
	printf("Initializing PrintfOneSecInterval\n");
}

// Called repeatedly when this Command is scheduled to run
void PrintfOneSecInterval::Execute() 
{
	static int runNum = 0;
	if( runNum % 50 == 0)
		printf( "TestingParallel\n");
	
	runNum++;
}

// Make this return true when this Command no longer needs to run execute()
bool PrintfOneSecInterval::IsFinished() 
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void PrintfOneSecInterval::End() 
{
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PrintfOneSecInterval::Interrupted() {
}
