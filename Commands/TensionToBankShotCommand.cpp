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
	printf ("TensionToBankShotCommand Initialized");
	tensionValue = SmartDashboard::GetNumber("Tension") + 30;
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
	printf ("TensionToBankShotCommand Finished!");
}

void TensionToBankShotCommand::Interrupted()
{
	printf ("TensionToBankShotCommand Interrupted!");
}
