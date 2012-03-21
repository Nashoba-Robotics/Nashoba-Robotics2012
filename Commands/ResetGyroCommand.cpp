#include "ResetGyroCommand.h"
#include "../Debug.h"


ResetGyroCommand::ResetGyroCommand() : CommandBase("ResetGyroCommand")
{
	Requires( shootersubsystem );
}

void ResetGyroCommand::Initialize()
{
#ifndef _DEBUG
	printf ("ResetGyroCommand Initialized");
#endif
	ResetPrintCounter();
}

void ResetGyroCommand::Execute()
{
#ifndef _DEBUG
	if ( IsTimeToPrint() )
		 printf ("ResetGyroCommand is Executing!\n");
#endif
	// reset Gyro 
	drivesubsystem->gyro.Reset();
}

bool ResetGyroCommand::IsFinished()
{
	return true;
}

void ResetGyroCommand::End()
{
#ifndef _DEBUG
	printf ("ResetGyroCommand Finished!");
#endif
}

void ResetGyroCommand::Interrupted()
{
#ifndef _DEBUG
	printf ("ResetGyroCommand Interrupted!");
#endif
}
