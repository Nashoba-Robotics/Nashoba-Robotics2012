#include "TopIdleDurationCommand.h"
#include "../Subsystems/TopLiftSubsystem.h"
#include "../Debug.h"

TopIdleDurationCommand::TopIdleDurationCommand() : CommandBase ("TopIdleDurationCommand")
{

	Requires( topliftsubsystem );
}

void TopIdleDurationCommand::Initialize()
{
SetTimeout(1.5);
}

void TopIdleDurationCommand::Execute()
{
	topliftsubsystem->LiftIdle();
}

bool TopIdleDurationCommand::IsFinished()
{
	return IsTimedOut();
}

void TopIdleDurationCommand::End()
{
	topliftsubsystem->LiftIdle();
}

void TopIdleDurationCommand::Interrupted()
{
	topliftsubsystem->LiftIdle();
}
