#include "TopReceiveDurationCommand.h"
#include "../Subsystems/TopLiftSubsystem.h"
#include "../Debug.h"

TopReceiveDurationCommand::TopReceiveDurationCommand() : CommandBase("TopReceiveDurationCommand")
{
	Requires( topliftsubsystem );
}

void TopReceiveDurationCommand::Initialize()
{
	SetTimeout(1.0);
}

void TopReceiveDurationCommand::Execute()
{
	topliftsubsystem->LiftBallUp();
#ifndef _DEBUG
	if( IsTimeToPrint( ) )
		printf ("TopReceiveDurationCommand Executed \n");
#endif
}

bool TopReceiveDurationCommand::IsFinished()
{
	return IsTimedOut();
}

void TopReceiveDurationCommand::End()
{
#ifndef _DEBUG
	printf ("TopReceiveDurationCommand End \n");
#endif

	topliftsubsystem->LiftIdle();
}

void TopReceiveDurationCommand::Interrupted()
{
#ifndef _DEBUG
	printf ("TopReceiveDurationCommand End \n");
#endif
	topliftsubsystem->LiftIdle();
}
