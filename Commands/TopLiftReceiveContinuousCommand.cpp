#include "TopLiftReceiveContinuousCommand.h"
#include "../Subsystems/TopLiftSubsystem.h"
#include "../Debug.h"

TopLiftReceiveContinuousCommand::TopLiftReceiveContinuousCommand() : CommandBase("TopLiftReceiveContinuousCommand")
{
	Requires( topliftsubsystem );
}

void TopLiftReceiveContinuousCommand::Initialize()
{
	ResetPrintCounter();
	printf ("TopLiftReceiveContinuousCommand Initialized \n");
}

void TopLiftReceiveContinuousCommand::Execute()
{
	topliftsubsystem->LiftBallUp();
	if( IsTimeToPrint( ) )
		printf ("TopLiftReceiveContinuousCommand Executed \n");
}

bool TopLiftReceiveContinuousCommand::IsFinished()
{
	return false;
}

void TopLiftReceiveContinuousCommand::End()
{
	printf ("TopLiftReceiveContinuousCommand End \n");

	topliftsubsystem->LiftIdle();
}

void TopLiftReceiveContinuousCommand::Interrupted()
{
	printf ("TopLiftReceiveContinuousCommand End \n");
	topliftsubsystem->LiftIdle();
}
