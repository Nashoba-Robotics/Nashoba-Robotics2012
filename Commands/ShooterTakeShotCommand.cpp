#include "ShooterTakeShotCommand.h"
#include "../Debug.h"

ShooterTakeShotCommand::ShooterTakeShotCommand() : CommandBase("ShooterTakeShotCommand")
{
	
}

void ShooterTakeShotCommand::Initialize()
{
	printf ("ShooterTakeShotCommand Initialized");
}

void ShooterTakeShotCommand::Execute()
{
	static int runNum = 0;
	if (runNum % REPORT_PERIOD == 0)
		 printf ("ShooterTakeShotCommand is Executing!\n");
}

bool ShooterTakeShotCommand::IsFinished()
{
	return true;
}

void ShooterTakeShotCommand::End()
{
	printf ("ShooterTakeShotCommand Finished!");
}

void ShooterTakeShotCommand::Interrupted()
{
	printf ("ShooterTakeShotCommand Interrupted!");
}
