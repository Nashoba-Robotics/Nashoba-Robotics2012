#include "ShooterTakeShotCommand.h"
#include "../Subsystems/ShooterSubsystem.h"
#include "../Debug.h"

ShooterTakeShotCommand::ShooterTakeShotCommand() : CommandBase("ShooterTakeShotCommand")
{
	Requires(shootersubsystem);
	SetReportPeriod ( 500 );
}

void ShooterTakeShotCommand::Initialize()
{
	ResetPrintCounter();
	printf ("ShooterTakeShotCommand Initialized \n");
}

void ShooterTakeShotCommand::Execute()
{
	float CamSpeed =  0 - OperatorInput::getInstance().getCamStick().GetY();
	
	CamSpeed = SNAP_TO_VALUE( 0, 0.05, CamSpeed );    // if it is close to zero, force it to be zero.
	
	if ( IsTimeToPrint() )
		 {
			printf ("ShooterTakeShotCommand is Executing! CamSpeed %6.4f \n", CamSpeed);
		 }
	shootersubsystem->Shoot( CamSpeed );
	
}

bool ShooterTakeShotCommand::IsFinished()
{
	return false;
}

void ShooterTakeShotCommand::End()
{
	printf ("ShooterTakeShotCommand Finished! \n");
}

void ShooterTakeShotCommand::Interrupted()
{
	printf ("ShooterTakeShotCommand Interrupted! \n");
	shootersubsystem->Stop();
}
