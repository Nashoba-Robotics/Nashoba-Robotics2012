#include "BottomLiftRejectContinuousCommand.h"
#include "../Subsystems/BottomLiftSubsystem.h"
#include "../Debug.h"

BottomLiftRejectContinuousCommand::BottomLiftRejectContinuousCommand() : CommandBase("BottomLiftRejectContinuousCommand")
{
	Requires( bottomliftsubsystem );
}

void BottomLiftRejectContinuousCommand::Initialize()
{
	ResetPrintCounter();
#ifndef _DEBUG
	printf ("BottomLiftRejectContinuousCommand Initialized \n");
#endif
}

void BottomLiftRejectContinuousCommand::Execute()
{
	bottomliftsubsystem->LiftBallDown();
}

bool BottomLiftRejectContinuousCommand::IsFinished()
{
	return false;
}

void BottomLiftRejectContinuousCommand::End()
{
	bottomliftsubsystem->LiftIdle();
}

void BottomLiftRejectContinuousCommand::Interrupted()
{
	bottomliftsubsystem->LiftIdle();
}
