#include "TensionDecreaseCommand.h"
#include "../Debug.h"

TensionDecreaseCommand::TensionDecreaseCommand() : CommandBase("TensionDecreaseCommand")
{
	Requires( shootersubsystem );
	SetReportPeriod( 200 );
}

void TensionDecreaseCommand::Initialize()
{
	printf ("TensionDecreaseCommand Initialized\n");
	ResetPrintCounter();
}

void TensionDecreaseCommand::Execute()
{
	if ( IsTimeToPrint() )
		 printf ("TensionDecreaseCommand is Executing!\n");
	shootersubsystem->Tensioner(-1.00);
	
}

bool TensionDecreaseCommand::IsFinished()
{
	return false;
	
}

void TensionDecreaseCommand::End()
{
	printf ("TensionDecreaseCommand Finished!\n");
	shootersubsystem->Tensioner(0.0);
}

void TensionDecreaseCommand::Interrupted()
{
	printf ("TensionDecreaseCommand Interrupted!\n");
	shootersubsystem->Tensioner(0.0);
}
