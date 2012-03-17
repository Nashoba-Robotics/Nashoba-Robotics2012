#include "DriveToTensionRangeCommand.h"
#include "../Debug.h"
#include "../Subsystems/DriveSubsystem.h"
#include "../CoprocessorVision.h"

DriveToTensionRangeCommand::DriveToTensionRangeCommand() : CommandBase("DriveToTensionRangeCommand")
{
	Requires( drivesubsystem );
	SetReportPeriod(200);
}

void DriveToTensionRangeCommand::Initialize()
{
	SetTimeout(10);
	printf ("DriveToTensionRangeCommand Initialized");
	ResetPrintCounter();
}

void DriveToTensionRangeCommand::Execute()
{	
	currentTension = shootersubsystem->tensionerPot.GetValue();
	if (currentTension > 430)
		drivesubsystem->drive(.3, .5, .3);
	else
		drivesubsystem->drive(-.3, -.5, -.3);
}

bool DriveToTensionRangeCommand::IsFinished()
{
	if (IsTimedOut())
		return true;
//	float deltaTension = fabs(currentTension - tensionValue);
//	if(deltaTension < 2 && deltaTension > -2)
//		return true;
	return false;
}

void DriveToTensionRangeCommand::End()
{
	drivesubsystem->drive(0, 0, 0);
	printf ("DriveToTensionRangeCommand Finished!");
}

void DriveToTensionRangeCommand::Interrupted()
{
	printf ("DriveToTensionRangeCommand Interrupted!");
}
