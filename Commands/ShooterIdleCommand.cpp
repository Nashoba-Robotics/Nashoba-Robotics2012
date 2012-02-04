#include "ShooterIdleCommand.h"
#include "../Debug.h"

ShooterIdleCommand::ShooterIdleCommand() : CommandBase("ShooterIdleCommand")
{
	
}

void ShooterIdleCommand::Initialize()
{
	printf ("ShooterIdleCommand Initialized");
}

void ShooterIdleCommand::Execute()
{
	static int runNum = 0;
	if (runNum % REPORT_PERIOD == 0)
		 printf ("ShooterIdleCommand is Executing!\n");
}

bool ShooterIdleCommand::IsFinished()
{
	return true;
}

void ShooterIdleCommand::End()
{
	printf ("ShooterIdleCommand Finished!");
}

void ShooterIdleCommand::Interrupted()
{
	printf ("ShooterIdleCommand Interrupted!");
}
