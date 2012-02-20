#include "ShooterTakeShotCommand.h"
#include "../BallTracker.h"
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
	
	shootersubsystem->shooterJaguar.ConfigEncoderCodesPerRev(360) ;
	shootersubsystem->shooterJaguar.SetPositionReference(CANJaguar::kPosRef_QuadEncoder);
	
	ResetPrintCounter();
	printf ("ShooterTakeShotCommand Initialized \n");
	
	shotState = SHOT_STATE_SLOW_START;
	
	// Get current position from encoder (make it positive)
	currentPoint = shootersubsystem->GetCamAngle();
	
	// Set point at after cam cliff where it is safe to speed up
	// based off of previous endingPoint
	speedUpPoint = 0.15;
	
	// Stop rotating after almost back to starting point.
    endingPoint = .95;
	
	speed = 0.5;
}

void ShooterTakeShotCommand::Execute()
{

	currentPoint = shootersubsystem->GetCamAngle();
	
	SmartDashboard::GetInstance()->PutDouble("Cam Value", currentPoint);	
	printf("Cam Encoder %f \n", (float)currentPoint);
	
	switch ( shotState )
	{
	case SHOT_STATE_UNKNOWN:
	case SHOT_STATE_SLOW_START:
		if( currentPoint >= endingPoint )
			speed = 0.2;  // slow speed going over cliff
		else if ( speed >= speedUpPoint )
			shotState = SHOT_STATE_FAST_MIDDLE;
		else 
			speed = 0.2;
		break;
		
	case SHOT_STATE_FAST_MIDDLE:
		// is it time to speed up yet?
		speed = 0.8;
		if( currentPoint >= endingPoint )
		{
			shotState = SHOT_STATE_READY;
		}
		break;
	case SHOT_STATE_READY:
		speed = 0; // keep stopped
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
//	BallTracker::GetInstance()->BallShot();
}

void ShooterTakeShotCommand::Interrupted()
{
	printf ("ShooterTakeShotCommand Interrupted! \n");
	shootersubsystem->Stop();
}
