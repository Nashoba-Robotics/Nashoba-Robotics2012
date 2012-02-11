#include "BottomLiftReceiveContinuousCommand.h"
#include "../Subsystems/BottomLiftSubsystem.h"
#include "../Debug.h"

BottomLiftReceiveContinuousCommand::BottomLiftReceiveContinuousCommand() : CommandBase("BottomLiftReceiveContinuousCommand")
{
	Requires( bottomliftsubsystem );
}

void BottomLiftReceiveContinuousCommand::Initialize()
{

}

void BottomLiftReceiveContinuousCommand::Execute()
{
	bottomliftsubsystem->LiftBallUp();
}

bool BottomLiftReceiveContinuousCommand::IsFinished()
{
	return false;
}

void BottomLiftReceiveContinuousCommand::End()
{
	bottomliftsubsystem->LiftIdle();
}

void BottomLiftReceiveContinuousCommand::Interrupted()
{
	bottomliftsubsystem->LiftIdle();
}
