#include "ShooterReadyShotCommand.h"
#include "../Debug.h"

ShooterReadyShotCommand::ShooterReadyShotCommand() : CommandBase("ShooterReadyShotCommand")
{
	Requires( shootersubsystem );
}

void ShooterReadyShotCommand::Initialize()
{
	ResetPrintCounter();
	printf ("ShooterReadyShotCommand Initialized");
}

void ShooterReadyShotCommand::Execute()
{
	shootersubsystem->Shoot( 0.5 );
	if ( IsTimeToPrint() )
		 printf ("ShooterReadyShotCommand is Executing!\n");
}

bool ShooterReadyShotCommand::IsFinished()
{
	return false;
}

void ShooterReadyShotCommand::End()
{
	printf ("ShooterReadyShotCommand Finished!");
}

void ShooterReadyShotCommand::Interrupted()
{
	printf ("ShooterReadyShotCommand Interrupted!");
}
