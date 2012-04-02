#define _DRIVE_TO_TENSION
#ifdef _DRIVE_TO_TENSION
#include "DriveToTensionRangeCommand.h"
#include "../Debug.h"
#include "../Subsystems/DriveSubsystem.h"
#include "../CoprocessorVision.h"
#include <cmath>

//#define AUTONOMOUS
#define TELEOP

DriveToTensionRangeCommand::DriveToTensionRangeCommand() : CommandBase("DriveToTensionRangeCommand")
{
	Requires( drivesubsystem );
	SetReportPeriod(200);
}

void DriveToTensionRangeCommand::Initialize()
{	
	SetTimeout(10);
#ifndef _DEBUG
	printf ("DriveToTensionRangeCommand Initialized");
#endif
	ResetPrintCounter();
}

void DriveToTensionRangeCommand::Execute()
{
#ifdef TELEOP
	tensionValue = SmartDashboard::GetInstance()->GetDouble("Tension");
	if (tensionValue > 430)
		drivesubsystem->drive(0, .25, 0);
#endif
	
#ifdef AUTONOMOUS
	tensionValue = SmartDashboard::GetInstance()->GetDouble("Tension");
	if (tensionValue > 350)
		drivesubsystem->drive(0, .25, 0);
#endif
}

bool DriveToTensionRangeCommand::IsFinished()
{
	if (IsTimedOut())
		return true;
	return false;
}

void DriveToTensionRangeCommand::End()
{
	drivesubsystem->drive(0, 0, 0);
#ifndef _DEBUG
	printf ("DriveToTensionRangeCommand Finished!");
#endif
}

void DriveToTensionRangeCommand::Interrupted()
{
#ifndef _DEBUG
	printf ("DriveToTensionRangeCommand Interrupted!");
#endif
}
#endif
