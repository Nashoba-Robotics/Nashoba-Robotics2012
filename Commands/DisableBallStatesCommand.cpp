#include "DisableBallStatesCommand.h"
#include "../Debug.h"


DisableBallStatesCommand::DisableBallStatesCommand() : CommandBase("DisableBallStatesCommand")
{
}

void DisableBallStatesCommand::Initialize()
{
#ifndef _DEBUG
	printf ("DisableBallStatesCommand Initialized");
#endif
	ResetPrintCounter();
}

void DisableBallStatesCommand::Execute()
{
#ifndef _DEBUG
	if ( IsTimeToPrint() )
		 printf ("DisableBallStatesCommand is Executing!\n");
#endif
	// Disable BallStates 
	bottomliftsubsystem->DisableBallState();
	topliftsubsystem->DisableBallState();
	ballintakesubsystem->DisableBallState();
	shootersubsystem->DisableBallState();
	
}

bool DisableBallStatesCommand::IsFinished()
{
	return true;
}

void DisableBallStatesCommand::End()
{
	printf ("DisableBallStatesCommand Finished!");
}

void DisableBallStatesCommand::Interrupted()
{
	printf ("DisableBallStatesCommand Interrupted!");
}
