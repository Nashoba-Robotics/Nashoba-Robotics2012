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
	if( IsTimeToPrint( ) )
		printf ("TopReceiveDurationCommand Executed \n");
}

bool TopReceiveDurationCommand::IsFinished()
{
	return IsTimedOut();
}

void TopReceiveDurationCommand::End()
{
	printf ("TopReceiveDurationCommand End \n");

	topliftsubsystem->LiftIdle();
}

void TopReceiveDurationCommand::Interrupted()
{
	printf ("TopReceiveDurationCommand End \n");
	topliftsubsystem->LiftIdle();
}
