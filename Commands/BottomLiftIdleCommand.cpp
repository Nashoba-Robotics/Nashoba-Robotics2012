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
#ifndef _DEBUG
	printf ("BottomLiftIdleCommand Initialized \n");
#endif
}

void BottomLiftIdleCommand::Execute()
{
#ifndef _DEBUG
	if( IsTimeToPrint() )
		printf ("BottomLiftIdleCommand Executed \n");
#endif
	bottomliftsubsystem->LiftIdle();
}

bool BottomLiftIdleCommand::IsFinished()
{
	return false;
}

void BottomLiftIdleCommand::End()
{
#ifndef _DEBUG
	printf ("BottomLiftIdleCommand End \n");
#endif
	bottomliftsubsystem->LiftIdle();
}

void BottomLiftIdleCommand::Interrupted()
{
#ifndef _DEBUG
	printf ("BottomLiftIdleCommand interrupted \n");
#endif
	bottomliftsubsystem->LiftIdle();
}
