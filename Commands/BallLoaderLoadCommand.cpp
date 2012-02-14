#include "BallLoaderLoadCommand.h"
#include "../Subsystems/BallLoaderSubsystem.h"
#include "../Debug.h"

BallLoaderLoadCommand::BallLoaderLoadCommand() : CommandBase ("BallLoaderLoadCommand")
{
	Requires( ballloadersubsystem );
}

void BallLoaderLoadCommand::Initialize()
{
	ResetPrintCounter();
	//Will run for 2 seconds
	SetTimeout(2.0);	
}

void BallLoaderLoadCommand::Execute()
{
	ballloadersubsystem->LoadBall();
}

bool BallLoaderLoadCommand::IsFinished()
{
	return IsTimedOut();
}

void BallLoaderLoadCommand::End()
{
	ballloadersubsystem->Idle();
}

void BallLoaderLoadCommand::Interrupted()
{
	ballloadersubsystem->Idle();
}
