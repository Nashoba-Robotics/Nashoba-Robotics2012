#include "IntakeRejectContinuousCommand.h"
#include "../Debug.h"
#include "../Subsystems/BallIntakeSubsystem.h"

IntakeRejectContinuousCommand::IntakeRejectContinuousCommand() : CommandBase ("IntakeRejectContinuousCommand")
{
	Requires( ballintakesubsystem );
}

void IntakeRejectContinuousCommand::Initialize()
{
	ResetPrintCounter();
#ifndef _DEBUG
	printf ("IntakeRejectContinuousCommand Initialized \n");
#endif
}

void IntakeRejectContinuousCommand::Execute()
{
	ballintakesubsystem->IntakeOut();
}

bool IntakeRejectContinuousCommand::IsFinished()
{
	return false;
}

void IntakeRejectContinuousCommand::End()
{
	ballintakesubsystem->IntakeIdle();
}

void IntakeRejectContinuousCommand::Interrupted()
{
	ballintakesubsystem->IntakeIdle();
}
