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
	if( IsTimeToPrint() )
		printf ("BottomLiftIdleCommand Executed \n");
	bottomliftsubsystem->LiftIdle();
}

bool BottomLiftIdleCommand::IsFinished()
{
	return false;
}

void BottomLiftIdleCommand::End()
{
	printf ("BottomLiftIdleCommand End \n");

	bottomliftsubsystem->LiftIdle();
}

void BottomLiftIdleCommand::Interrupted()
{
	printf ("BottomLiftIdleCommand interrupted \n");
	bottomliftsubsystem->LiftIdle();
}
