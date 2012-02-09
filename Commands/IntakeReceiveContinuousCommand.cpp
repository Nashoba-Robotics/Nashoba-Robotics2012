#include "IntakeReceiveContinuousCommand.h"
#include "../Subsystems/BallIntakeSubsystem.h"
#include "../Debug.h"

IntakeReceiveContinuousCommand::IntakeReceiveContinuousCommand() : CommandBase ("IntakeReceiveContinuousCommand")
{
	//Requires( ballintakesubsystem );
}

void IntakeReceiveContinuousCommand::Initialize()
{

}

void IntakeReceiveContinuousCommand::Execute()
{

}

bool IntakeReceiveContinuousCommand::IsFinished()
{
	return true;
}

void IntakeReceiveContinuousCommand::End()
{

}

void IntakeReceiveContinuousCommand::Interrupted()
{

}
