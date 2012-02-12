#include "BottomLiftIdleCommand.h"
#include "../Subsystems/BottomLiftSubsystem.h"
#include "../Debug.h"

BottomLiftIdleCommand::BottomLiftIdleCommand() : CommandBase ("BottomLiftIdleCommand")
{
//WILL NEED TO UNCOMMENT THIS OUT LATER!!!
	Requires( bottomliftsubsystem );
}

void BottomLiftIdleCommand::Initialize()
{
	ResetPrintCounter();
	printf ("BottomLiftIdleCommand Initialized \n");
}

void BottomLiftIdleCommand::Execute()
{
	bottomliftsubsystem->LiftIdle();
}

bool BottomLiftIdleCommand::IsFinished()
{
	return true;
}

void BottomLiftIdleCommand::End()
{
	bottomliftsubsystem->LiftIdle();
}

void BottomLiftIdleCommand::Interrupted()
{
	bottomliftsubsystem->LiftIdle();
}
