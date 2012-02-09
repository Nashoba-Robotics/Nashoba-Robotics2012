#include "BottomLiftIdleCommand.h"
#include "../Debug.h"

BottomLiftIdleCommand::BottomLiftIdleCommand() : CommandBase ("BottomLiftIdleCommand")
{
//WILL NEED TO UNCOMMENT THIS OUT LATER!!!
//	Requires( ballintakesubsystem );
}

void BottomLiftIdleCommand::Initialize()
{

}

void BottomLiftIdleCommand::Execute()
{

}

bool BottomLiftIdleCommand::IsFinished()
{
	return true;
}

void BottomLiftIdleCommand::End()
{

}

void BottomLiftIdleCommand::Interrupted()
{

}
