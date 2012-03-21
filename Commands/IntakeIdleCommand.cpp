#include "IntakeIdleCommand.h"
#include "../Debug.h"
#include "../Subsystems/BallIntakeSubsystem.h"

IntakeIdleCommand::IntakeIdleCommand() : CommandBase ("IntakeIdleCommand")
{
	Requires( ballintakesubsystem );
}

void IntakeIdleCommand::Initialize()
{
	ResetPrintCounter();
#ifndef _DEBUG
	printf ("IntakeIdleCommand Initialized \n");
#endif
}

void IntakeIdleCommand::Execute()
{
	ballintakesubsystem->IntakeIdle();
}

bool IntakeIdleCommand::IsFinished()
{
	return false;
}

void IntakeIdleCommand::End()
{
	ballintakesubsystem->IntakeIdle();
}

void IntakeIdleCommand::Interrupted()
{
	ballintakesubsystem->IntakeIdle();
}
