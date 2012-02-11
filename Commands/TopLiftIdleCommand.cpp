#include "TopLiftIdleCommand.h"
#include "../Subsystems/TopLiftSubsystem.h"
#include "../Debug.h"

TopLiftIdleCommand::TopLiftIdleCommand() : CommandBase ("TopLiftIdleCommand")
{

	Requires( topliftsubsystem );
}

void TopLiftIdleCommand::Initialize()
{

}

void TopLiftIdleCommand::Execute()
{
	topliftsubsystem->LiftIdle();
}

bool TopLiftIdleCommand::IsFinished()
{
	return false;
}

void TopLiftIdleCommand::End()
{
	topliftsubsystem->LiftIdle();
}

void TopLiftIdleCommand::Interrupted()
{
	topliftsubsystem->LiftIdle();
}
