#include "ShooterReadyShotCommand.h"
#include "../Debug.h"

ShooterReadyShotCommand::ShooterReadyShotCommand() : CommandBase("ShooterReadyShotCommand")
{
	Requires( shootersubsystem );
}

void ShooterReadyShotCommand::Initialize()
{
	SetTimeout(0.15);
	ResetPrintCounter();
	printf ("ShooterReadyShotCommand Initialized");
	
	shootersubsystem->shooterJaguar.ConfigEncoderCodesPerRev(360) ;
	shootersubsystem->shooterJaguar.SetPositionReference(CANJaguar::kPosRef_QuadEncoder);
}

void ShooterReadyShotCommand::Execute()
{
	shootersubsystem->Shoot( 0.5 );
	if ( IsTimeToPrint() )
		 printf ("ShooterReadyShotCommand is Executing!\n");
}

bool ShooterReadyShotCommand::IsFinished()
{
	return IsTimedOut();
}

void ShooterReadyShotCommand::End()
{
	printf ("ShooterReadyShotCommand Finished!");
}

void ShooterReadyShotCommand::Interrupted()
{
	printf ("ShooterReadyShotCommand Interrupted!");
}
