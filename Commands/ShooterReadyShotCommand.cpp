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
#ifndef _DEBUG
	printf ("ShooterReadyShotCommand Initialized");
#endif
	
	shootersubsystem->shooterJaguar.ConfigEncoderCodesPerRev(360) ;
	shootersubsystem->shooterJaguar.SetPositionReference(CANJaguar::kPosRef_QuadEncoder);
}

void ShooterReadyShotCommand::Execute()
{
	shootersubsystem->Shoot( 0.5 );
#ifndef _DEBUG
	if ( IsTimeToPrint() )
		 printf ("ShooterReadyShotCommand is Executing!\n");
#endif
}

bool ShooterReadyShotCommand::IsFinished()
{
	return IsTimedOut();
}

void ShooterReadyShotCommand::End()
{
#ifndef _DEBUG
	printf ("ShooterReadyShotCommand Finished!");
#endif
}

void ShooterReadyShotCommand::Interrupted()
{
#ifndef _DEBUG
	printf ("ShooterReadyShotCommand Interrupted!");
#endif
}
