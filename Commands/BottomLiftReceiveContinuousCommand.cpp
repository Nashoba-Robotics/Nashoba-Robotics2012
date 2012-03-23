#include "BottomLiftReceiveContinuousCommand.h"
#include "../Subsystems/BottomLiftSubsystem.h"
#include "../Debug.h"

BottomLiftReceiveContinuousCommand::BottomLiftReceiveContinuousCommand() : CommandBase("BottomLiftReceiveContinuousCommand")
{
	Requires( bottomliftsubsystem );
}

void BottomLiftReceiveContinuousCommand::Initialize()
{
	ResetPrintCounter();
	printf ("BottomLiftReceiveContinuousCommand Initialized \n");
}

void BottomLiftReceiveContinuousCommand::Execute()
{
	bottomliftsubsystem->LiftBallUp();
	printf ("BottomLiftReceiveContinuousCommand Executing \n");
}

bool BottomLiftReceiveContinuousCommand::IsFinished()
{
	printf ("BottomLiftReceiveContinuousCommand IsFinished \n");
	return false;
}

void BottomLiftReceiveContinuousCommand::End()
{
	printf ("BottomLiftReceiveContinuousCommand End \n");
	bottomliftsubsystem->LiftIdle();
}

void BottomLiftReceiveContinuousCommand::Interrupted()
{
	printf ("BottomLiftReceiveContinuousCommand Interrupted \n");
	bottomliftsubsystem->LiftIdle();
}
