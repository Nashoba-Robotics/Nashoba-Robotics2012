#include "ResetBallStatesCommand.h"
#include "../Debug.h"


ResetBallStatesCommand::ResetBallStatesCommand() : CommandBase("ResetBallStatesCommand")
{
}

void ResetBallStatesCommand::Initialize()
{
#ifndef _DEBUG
	printf ("ResetBallStatesCommand Initialized");
#endif
	ResetPrintCounter();
}

void ResetBallStatesCommand::Execute()
{
#ifndef _DEBUG
	if ( IsTimeToPrint() )
		 printf ("ResetBallStatesCommand is Executing!\n");
#endif
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
#ifndef _DEBUG
	printf ("ResetBallStatesCommand Finished!");
#endif
}

void ResetBallStatesCommand::Interrupted()
{
#ifndef _DEBUG
	printf ("ResetBallStatesCommand Interrupted!");
#endif
}
