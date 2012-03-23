#include "ResetBallStatesCommand.h"


ResetBallStatesCommand::ResetBallStatesCommand() : CommandBase("ResetBallStatesCommand")
{
}

void ResetBallStatesCommand::Initialize()
{
	printf ("ResetBallStatesCommand Initialized");
	ResetPrintCounter();
}

void ResetBallStatesCommand::Execute()
{
	if ( IsTimeToPrint() )
		 printf ("ResetBallStatesCommand is Executing!\n");
	// reset BallStates 
	bottomliftsubsystem->ResetBallState();
	topliftsubsystem->ResetBallState();
	ballintakesubsystem->ResetBallState();
	shootersubsystem->ResetBallState();
	
}

bool ResetBallStatesCommand::IsFinished()
{
	return true;
}

void ResetBallStatesCommand::End()
{
	printf ("ResetBallStatesCommand Finished!");
}

void ResetBallStatesCommand::Interrupted()
{
	printf ("ResetBallStatesCommand Interrupted!");
}
