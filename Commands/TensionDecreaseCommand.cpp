#include "TensionDecreaseCommand.h"
#include "../Debug.h"

TensionDecreaseCommand::TensionDecreaseCommand() : CommandBase("TensionDecreaseCommand")
{
	Requires( shootersubsystem );
	SetReportPeriod( 200 );
}

void TensionDecreaseCommand::Initialize()
{
#ifndef _DEBUG
	printf ("TensionDecreaseCommand Initialized\n");
#endif
	ResetPrintCounter();
}

void TensionDecreaseCommand::Execute()
{
#ifndef _DEBUG
	if ( IsTimeToPrint() )
		 printf ("TensionDecreaseCommand is Executing!\n");
#endif
	shootersubsystem->Tensioner(-1.00);
	
}

bool TensionDecreaseCommand::IsFinished()
{
	return false;
	
}

void TensionDecreaseCommand::End()
{
#ifndef _DEBUG
	printf ("TensionDecreaseCommand Finished!\n");
#endif
	shootersubsystem->Tensioner(0.0);
}

void TensionDecreaseCommand::Interrupted()
{
#ifndef _DEBUG
	printf ("TensionDecreaseCommand Interrupted!\n");
#endif
	shootersubsystem->Tensioner(0.0);
}
