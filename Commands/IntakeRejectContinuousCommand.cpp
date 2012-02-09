#include "IntakeRejectContinuousCommand.h"
#include "../Debug.h"

IntakeRejectContinuousCommand::IntakeRejectContinuousCommand() : CommandBase ("IntakeRejectContinuousCommand")
{
	//Requires( ballintakesubsystem );
}

void IntakeRejectContinuousCommand::Initialize()
{

}

void IntakeRejectContinuousCommand::Execute()
{

}

bool IntakeRejectContinuousCommand::IsFinished()
{
	return true;
}

void IntakeRejectContinuousCommand::End()
{

}

void IntakeRejectContinuousCommand::Interrupted()
{

}
