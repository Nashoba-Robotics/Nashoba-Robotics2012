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
#ifndef _DEBUG
	printf ("TopLiftReceiveContinuousCommand Initialized \n");
#endif
}

void TopLiftReceiveContinuousCommand::Execute()
{
	topliftsubsystem->LiftBallUp();
#ifndef _DEBUG
	if( IsTimeToPrint( ) )
		printf ("TopLiftReceiveContinuousCommand Executed \n");
#endif
}

bool TopLiftReceiveContinuousCommand::IsFinished()
{
	return false;
}

void TopLiftReceiveContinuousCommand::End()
{
#ifndef _DEBUG
	printf ("TopLiftReceiveContinuousCommand End \n");
#endif

	topliftsubsystem->LiftIdle();
}

void TopLiftReceiveContinuousCommand::Interrupted()
{
#ifndef _DEBUG
	printf ("TopLiftReceiveContinuousCommand End \n");
#endif
	topliftsubsystem->LiftIdle();
}
