#include "BallLoaderIdleCommand.h"
#include "../Subsystems/BallLoaderSubsystem.h"
#include "../Debug.h"

BallLoaderIdleCommand::BallLoaderIdleCommand() : CommandBase ("BallLoaderIdleCommand")
{
//WILL NEED TO UNCOMMENT THIS OUT LATER!!!
	Requires( ballloadersubsystem );
}

void BallLoaderIdleCommand::Initialize()
{
	ResetPrintCounter();
	printf ("BallLoaderIdleCommand Initialized \n");
}

void BallLoaderIdleCommand::Execute()
{
	ballloadersubsystem->Idle();
}

bool BallLoaderIdleCommand::IsFinished()
{
	return true;
}

void BallLoaderIdleCommand::End()
{

}

void BallLoaderIdleCommand::Interrupted()
{
	ballloadersubsystem->Idle();
}
