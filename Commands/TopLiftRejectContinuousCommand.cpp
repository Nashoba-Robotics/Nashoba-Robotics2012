#include "TopLiftRejectContinuousCommand.h"
#include "../Subsystems/TopLiftSubsystem.h"
#include "../Debug.h"

TopLiftRejectContinuousCommand::TopLiftRejectContinuousCommand() : CommandBase("TopLiftRejectContinuousCommand")
{
 Requires( topliftsubsystem );
}

void TopLiftRejectContinuousCommand::Initialize()
{
	ResetPrintCounter();
	printf ("TopLiftRejectCommand Initialized \n");
}

void TopLiftRejectContinuousCommand::Execute()
{
	topliftsubsystem->LiftBallDown();

}

bool TopLiftRejectContinuousCommand::IsFinished()
{
	return false;
}

void TopLiftRejectContinuousCommand::End()
{
	topliftsubsystem->LiftIdle();
}

void TopLiftRejectContinuousCommand::Interrupted()
{
	topliftsubsystem->LiftIdle();
}
