#include "ResetCamCommand.h"


ResetCamCommand::ResetCamCommand() : CommandBase("ResetCamCommand")
{
	Requires( shootersubsystem );
}

void ResetCamCommand::Initialize()
{
	printf ("ResetCamCommand Initialized");
	ResetPrintCounter();
}

void ResetCamCommand::Execute()
{
	if ( IsTimeToPrint() )
		 printf ("ResetCamCommand is Executing!\n");
	// reset cam angle so that its current position is the starting spot
	shootersubsystem->ResetCamAngle();
}

bool ResetCamCommand::IsFinished()
{
	return true;
}

void ResetCamCommand::End()
{
	printf ("ResetCamCommand Finished!");
}

void ResetCamCommand::Interrupted()
{
	printf ("ResetCamCommand Interrupted!");
}
