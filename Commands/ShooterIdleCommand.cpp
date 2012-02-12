#include "ShooterIdleCommand.h"
#include "../Debug.h"

ShooterIdleCommand::ShooterIdleCommand() : CommandBase("ShooterIdleCommand")
{
	Requires( shootersubsystem );
}

void ShooterIdleCommand::Initialize()
{
	printf ("ShooterIdleCommand Initialized");
	ResetPrintCounter();
}

void ShooterIdleCommand::Execute()
{
	if ( IsTimeToPrint() )
		 printf ("ShooterIdleCommand is Executing!\n");
	shootersubsystem->Stop();
}

bool ShooterIdleCommand::IsFinished()
{
	return false;
}

void ShooterIdleCommand::End()
{
	printf ("ShooterIdleCommand Finished!");
}

void ShooterIdleCommand::Interrupted()
{
	printf ("ShooterIdleCommand Interrupted!");
}
