#include "ShooterReadyShotCommand.h"
#include "../Debug.h"

ShooterReadyShotCommand::ShooterReadyShotCommand() : CommandBase("ShooterReadyShotCommand")
{
	
}

void ShooterReadyShotCommand::Initialize()
{
	printf ("ShooterReadyShotCommand Initialized");
}

void ShooterReadyShotCommand::Execute()
{
	static int runNum = 0;
	if (runNum % REPORT_PERIOD == 0)
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
