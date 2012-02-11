#include "IntakeReceiveContinuousCommand.h"
#include "../Subsystems/BallIntakeSubsystem.h"
#include "../Debug.h"

IntakeReceiveContinuousCommand::IntakeReceiveContinuousCommand() : CommandBase ("IntakeReceiveContinuousCommand")
{
	Requires( ballintakesubsystem );
}

void IntakeReceiveContinuousCommand::Initialize()
{
	ResetPrintCounter();
	printf ("IntakeReceiveContinuousCommand Initialized \n");
}

void IntakeReceiveContinuousCommand::Execute()
{
	ballintakesubsystem->IntakeIn();
}

bool IntakeReceiveContinuousCommand::IsFinished()
{
	return false;
}

void IntakeReceiveContinuousCommand::End()
{
	ballintakesubsystem->IntakeIdle();
}

void IntakeReceiveContinuousCommand::Interrupted()
{
	ballintakesubsystem->IntakeIdle();
}
