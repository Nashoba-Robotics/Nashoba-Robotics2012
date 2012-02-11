#include "TopLiftReceiveContinuousCommand.h"
#include "../Subsystems/TopLiftSubsystem.h"
#include "../Debug.h"

TopLiftReceiveContinuousCommand::TopLiftReceiveContinuousCommand() : CommandBase("TopLiftReceiveContinuousCommand")
{
	Requires( topliftsubsystem );
}

void TopLiftReceiveContinuousCommand::Initialize()
{

}

void TopLiftReceiveContinuousCommand::Execute()
{
	topliftsubsystem->LiftBallUp();

}

bool TopLiftReceiveContinuousCommand::IsFinished()
{
	return false;
}

void TopLiftReceiveContinuousCommand::End()
{
	topliftsubsystem->LiftIdle();
}

void TopLiftReceiveContinuousCommand::Interrupted()
{
	topliftsubsystem->LiftIdle();
}
