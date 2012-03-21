#ifdef OUR_WAIT_COMMAND
#include "OurWaitCommand.h"
#include "../Debug.h"


OurWaitCommand::OurWaitCommand(double duration) : CommandBase("OurWaitCommand"){


	m_duration = duration;

}

// Called just before this Command runs the first time
void OurWaitCommand::Initialize() 
{
	
	SetTimeout(m_duration);			//Sets a timer 

}

// Called repeatedly when this Command is scheduled to run
void OurWaitCommand::Execute() 
{
	
}

// Make this return true when this Command no longer needs to run execute()
bool OurWaitCommand::IsFinished() 
{
	return IsTimedOut();	//Checks to see if the Timer has finished
}

// Called once after isFinished returns true
void OurWaitCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OurWaitCommand::Interrupted() 
{

}
#endif
