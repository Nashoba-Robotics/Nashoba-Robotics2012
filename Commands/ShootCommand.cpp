#include "ShootCommand.h"
#include "../Debug.h"

ShootCommand::ShootCommand() : CommandBase("ShootCommand")
{
	
}

void ShootCommand::Initialize()
{
	printf ("ShootCommand Initialized");
}

void ShootCommand::Execute()
{
	static int runNum = 0;
	if (runNum % REPORT_PERIOD == 0)
		 printf ("ShootCommand is Executing!\n");
}

bool ShootCommand::IsFinished()
{
	return true;
}

void ShootCommand::End()
{
	printf ("ShootCommand Finished!");
}

void ShootCommand::Interrupted()
{
	printf ("ShootCommand Interrupted!");
}
