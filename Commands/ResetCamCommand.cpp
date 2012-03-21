#include "ResetCamCommand.h"
#include "../Debug.h"


ResetCamCommand::ResetCamCommand() : CommandBase("ResetCamCommand")
{
	Requires( shootersubsystem );
}

void ResetCamCommand::Initialize()
{
#ifndef _DEBUG
	printf ("ResetCamCommand Initialized");
#endif
	ResetPrintCounter();
}

void ResetCamCommand::Execute()
{
#ifndef _DEBUG
	if ( IsTimeToPrint() )
		 printf ("ResetCamCommand is Executing!\n");
#endif
	// reset cam angle so that its current position is the starting spot
	shootersubsystem->ResetCamAngle();
}

bool ResetCamCommand::IsFinished()
{
	return true;
}

void ResetCamCommand::End()
{
#ifndef _DEBUG
	printf ("ResetCamCommand Finished!");
#endif
}

void ResetCamCommand::Interrupted()
{
#ifndef _DEBUG
	printf ("ResetCamCommand Interrupted!");
#endif
}
