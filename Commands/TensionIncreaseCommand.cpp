#include "TensionIncreaseCommand.h"
#include "../Debug.h"

TensionIncreaseCommand::TensionIncreaseCommand() : CommandBase("TensionIncreaseCommand")
{
	Requires( shootersubsystem );
	SetReportPeriod ( 200 );
}

void TensionIncreaseCommand::Initialize()
{
#ifndef _DEBUG
	printf ("TensionIncreaseCommand Initialized\n");
#endif
	ResetPrintCounter();
}

void TensionIncreaseCommand::Execute()
{
#ifndef _DEBUG
	if ( IsTimeToPrint() )
		 printf ("TensionIncreaseCommand is Executing!\n");
#endif
	shootersubsystem->Tensioner(1.00);
}

bool TensionIncreaseCommand::IsFinished()
{
	return false;
}

void TensionIncreaseCommand::End()
{
#ifndef _DEBUG
	printf ("TensionIncreaseCommand Finished!\n");
#endif
	shootersubsystem->Tensioner(0.0);
}

void TensionIncreaseCommand::Interrupted()
{
#ifndef _DEBUG
	printf ("TensionIncreaseCommand Interrupted!\n");
#endif
	shootersubsystem->Tensioner(0.0);
}
