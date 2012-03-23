#include "TensionIncreaseCommand.h"
#include "../Debug.h"

TensionIncreaseCommand::TensionIncreaseCommand() : CommandBase("TensionIncreaseCommand")
{
	Requires( shootersubsystem );
	SetReportPeriod ( 200 );
}

void TensionIncreaseCommand::Initialize()
{
	printf ("TensionIncreaseCommand Initialized\n");
	ResetPrintCounter();
}

void TensionIncreaseCommand::Execute()
{
	if ( IsTimeToPrint() )
		 printf ("TensionIncreaseCommand is Executing!\n");
	shootersubsystem->Tensioner(1.00);
}

bool TensionIncreaseCommand::IsFinished()
{
	return false;
}

void TensionIncreaseCommand::End()
{
	printf ("TensionIncreaseCommand Finished!\n");
	shootersubsystem->Tensioner(0.0);
}

void TensionIncreaseCommand::Interrupted()
{
	printf ("TensionIncreaseCommand Interrupted!\n");
	shootersubsystem->Tensioner(0.0);
}
