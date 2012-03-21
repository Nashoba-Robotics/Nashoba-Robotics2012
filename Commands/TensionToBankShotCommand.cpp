#include "TensionToBankShotCommand.h"
#include "../Debug.h"
#include "../Subsystems/ShooterSubsystem.h"
#include "TensionDecreaseCommand.h"
#include "TensionIncreaseCommand.h"
#include "../CoprocessorVision.h"
#include <math.h>

TensionToBankShotCommand::TensionToBankShotCommand() : CommandBase("TensionToBankShotCommand")
{
	Requires( shootersubsystem );
	SetReportPeriod(200);
}

void TensionToBankShotCommand::Initialize()
{
	SetTimeout(6);
#ifndef _DEBUG
	printf ("TensionToBankShotCommand Initialized");
#endif
	tensionValue = SmartDashboard::GetInstance()->GetDouble("Tension") + 40;
	ResetPrintCounter();
}

void TensionToBankShotCommand::Execute()
{	
	currentTension = shootersubsystem->tensionerPot.GetValue();
	if (currentTension > tensionValue)
		shootersubsystem->Tensioner(-1.00);
	else
		shootersubsystem->Tensioner(1.00);
}

bool TensionToBankShotCommand::IsFinished()
{
	if (IsTimedOut())
		return true;
	float deltaTension = fabs(currentTension - tensionValue); 
	if(deltaTension < 2 && deltaTension > -2)
		return true;
	return false;
}

void TensionToBankShotCommand::End()
{
	shootersubsystem->Tensioner(0.00);
#ifndef _DEBUG
	printf ("TensionToBankShotCommand Finished!");
#endif
}

void TensionToBankShotCommand::Interrupted()
{
#ifndef _DEBUG
	printf ("TensionToBankShotCommand Interrupted!");
#endif
}
