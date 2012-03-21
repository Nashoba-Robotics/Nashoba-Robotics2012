#include "ShooterIdleCommand.h"
#include "../Debug.h"

ShooterIdleCommand::ShooterIdleCommand() : CommandBase("ShooterIdleCommand")
{
	Requires( shootersubsystem );
}

void ShooterIdleCommand::Initialize()
{
#ifndef _DEBUG
	printf ("ShooterIdleCommand Initialized");
#endif
	ResetPrintCounter();
}

void ShooterIdleCommand::Execute()
{
#ifndef _DEBUG
	if ( IsTimeToPrint() )
		 printf ("ShooterIdleCommand is Executing!\n");
#endif
	shootersubsystem->Stop();
}

bool ShooterIdleCommand::IsFinished()
{
	return false;
}

void ShooterIdleCommand::End()
{
#ifndef _DEBUG
	printf ("ShooterIdleCommand Finished!");
#endif
}

void ShooterIdleCommand::Interrupted()
{
#ifndef _DEBUG
	printf ("ShooterIdleCommand Interrupted!");
#endif
}
