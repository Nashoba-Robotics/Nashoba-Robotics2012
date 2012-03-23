#include "ResetGyroCommand.h"


ResetGyroCommand::ResetGyroCommand() : CommandBase("ResetGyroCommand")
{
	Requires( shootersubsystem );
}

void ResetGyroCommand::Initialize()
{
	printf ("ResetGyroCommand Initialized");
	ResetPrintCounter();
}

void ResetGyroCommand::Execute()
{
	if ( IsTimeToPrint() )
		 printf ("ResetGyroCommand is Executing!\n");
	// reset Gyro 
	drivesubsystem->gyro.Reset();
}

bool ResetGyroCommand::IsFinished()
{
	return true;
}

void ResetGyroCommand::End()
{
	printf ("ResetGyroCommand Finished!");
}

void ResetGyroCommand::Interrupted()
{
	printf ("ResetGyroCommand Interrupted!");
}
