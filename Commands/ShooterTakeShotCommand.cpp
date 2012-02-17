#include "ShooterTakeShotCommand.h"
#include "../Subsystems/ShooterSubsystem.h"
#include "../Debug.h"

ShooterTakeShotCommand::ShooterTakeShotCommand() : CommandBase("ShooterTakeShotCommand")
{
	Requires(shootersubsystem);
	SetReportPeriod ( 500 );
	endingPoint = 0;
}

void ShooterTakeShotCommand::Initialize()
{
	ResetPrintCounter();
	printf ("ShooterTakeShotCommand Initialized \n");
	
	shootersubsystem->shooterJaguar.ConfigEncoderCodesPerRev(360);
	shootersubsystem->shooterJaguar.SetPositionReference(CANJaguar::kPosRef_QuadEncoder);
	
	// Get current position from encoder (make it positive)
	currentPoint = -shootersubsystem->shooterJaguar.GetPosition();
	
	// Set point at after cam cliff where it is safe to speed up
	// based off of previous endingPoint
	speedUpPoint = endingPoint + 0.15;
	
	// Stop rotating after one rotation.
	// The if checks to see if we need a new endingPoint, 
	// if it is not true then we have an interrupted turn
	// and should use the existing endingPoint
	if( (currentPoint + 1) > endingPoint  ) 
	    endingPoint  = endingPoint + 1.0;
	
	speed = 0.3;
}

void ShooterTakeShotCommand::Execute()
{

	currentPoint = -shootersubsystem->shooterJaguar.GetPosition();
	SmartDashboard::GetInstance()->PutDouble("Cam Encoder", currentPoint);	
	SmartDashboard::GetInstance()->PutDouble("Ending Point", endingPoint);	
	printf("Cam Encoder %f \n", (float)currentPoint);
	
	// is it time to speed up yet?
	if( currentPoint >= speedUpPoint )
	{
		speed = 1.0;  // full speed ahead
	}
	
	shootersubsystem->Shoot( speed );
		
}

bool ShooterTakeShotCommand::IsFinished()
{
	return (currentPoint >= endingPoint);
}

void ShooterTakeShotCommand::End()
{
	printf ("ShooterTakeShotCommand Finished! \n");
	shootersubsystem->Stop();
}

void ShooterTakeShotCommand::Interrupted()
{
	printf ("ShooterTakeShotCommand Interrupted! \n");
	shootersubsystem->Stop();
}
