#include "IntakeRejectContinuousCommand.h"
#include "../Debug.h"

IntakeRejectContinuousCommand::IntakeRejectContinuousCommand() : CommandBase ("IntakeRejectContinuousCommand")
{
	Requires( ballintakesubsystem );
}

void IntakeRejectContinuousCommand::Initialize()
{

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
