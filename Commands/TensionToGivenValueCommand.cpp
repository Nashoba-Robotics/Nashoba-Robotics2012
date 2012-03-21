#include "TensionToGivenValueCommand.h"
#include "../Debug.h"
#include "../Subsystems/ShooterSubsystem.h"
#include "TensionDecreaseCommand.h"
#include "TensionIncreaseCommand.h"
#include "../CoprocessorVision.h"
#include <math.h>

TensionToGivenValueCommand::TensionToGivenValueCommand() : CommandBase("TensionToGivenValueCommand")
{
	Requires( shootersubsystem );
	SetReportPeriod(200);
}

void TensionToGivenValueCommand::Initialize()
{
	SetTimeout(6);
#ifndef _DEBUG
	printf ("TensionToGivenValueCommand Initialized");
#endif
	tensionValue = SmartDashboard::GetInstance()->GetDouble("Tension");
	ResetPrintCounter();
}

void TensionToGivenValueCommand::Execute()
{	
	currentTension = shootersubsystem->tensionerPot.GetValue();
	if (currentTension > tensionValue)
		shootersubsystem->Tensioner(-1.00);
	else
		shootersubsystem->Tensioner(1.00);
}

bool TensionToGivenValueCommand::IsFinished()
{
	if (IsTimedOut())
		return true;
	float deltaTension = fabs(currentTension - tensionValue); 
	if(deltaTension < 2 && deltaTension > -2)
		return true;
	return false;
}

void TensionToGivenValueCommand::End()
{
	shootersubsystem->Tensioner(0.00);
#ifndef _DEBUG
	printf ("TensionToGivenValueCommand Finished!");
#endif
}

void TensionToGivenValueCommand::Interrupted()
{
#ifndef _DEBUG
	printf ("TensionToGivenValueCommand Interrupted!");
#endif
}
