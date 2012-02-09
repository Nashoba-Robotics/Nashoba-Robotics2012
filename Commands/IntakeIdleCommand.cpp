#include "IntakeIdleCommand.h"
#include "../Debug.h"

IntakeIdleCommand::IntakeIdleCommand() : CommandBase ("IntakeIdleCommand")
{
	//WILL NEED TO UNTAKE THIS LATER !!!
	//Requires( ballintakesubsystem );
}

void IntakeIdleCommand::Initialize()
{

}

void IntakeIdleCommand::Execute()
{

}

bool IntakeIdleCommand::IsFinished()
{
	return true;
}

void IntakeIdleCommand::End()
{

}

void IntakeIdleCommand::Interrupted()
{

}
