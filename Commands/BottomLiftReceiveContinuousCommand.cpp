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
#ifndef _DEBUG
	printf ("BottomLiftReceiveContinuousCommand Initialized \n");
#endif
}

void BottomLiftReceiveContinuousCommand::Execute()
{
	bottomliftsubsystem->LiftBallUp();
#ifndef _DEBUG
	printf ("BottomLiftReceiveContinuousCommand Executing \n");
#endif
}

bool BottomLiftReceiveContinuousCommand::IsFinished()
{
#ifndef _DEBUG
	printf ("BottomLiftReceiveContinuousCommand IsFinished \n");
#endif
	return false;
}

void BottomLiftReceiveContinuousCommand::End()
{
#ifndef _DEBUG
	printf ("BottomLiftReceiveContinuousCommand End \n");
#endif
	bottomliftsubsystem->LiftIdle();
}

void BottomLiftReceiveContinuousCommand::Interrupted()
{
#ifndef _DEBUG
	printf ("BottomLiftReceiveContinuousCommand Interrupted \n");
#endif
	bottomliftsubsystem->LiftIdle();
}
