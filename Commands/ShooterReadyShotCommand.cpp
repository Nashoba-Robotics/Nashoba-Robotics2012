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
	
	if ( IsTimeToPrint() )
		 printf ("ShooterReadyShotCommand is Executing!\n");
}

bool ShooterReadyShotCommand::IsFinished()
{
	return true;
}

void ShooterReadyShotCommand::End()
{
	printf ("ShooterReadyShotCommand Finished!");
}

void ShooterReadyShotCommand::Interrupted()
{
	printf ("ShooterReadyShotCommand Interrupted!");
}
