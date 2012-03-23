#include "DisableBallStatesCommand.h"


DisableBallStatesCommand::DisableBallStatesCommand() : CommandBase("DisableBallStatesCommand")
{
}

void DisableBallStatesCommand::Initialize()
{
	printf ("DisableBallStatesCommand Initialized");
	ResetPrintCounter();
}

void DisableBallStatesCommand::Execute()
{
	if ( IsTimeToPrint() )
		 printf ("DisableBallStatesCommand is Executing!\n");
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
