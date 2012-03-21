#include "ShooterTakeShotCommand.h"
#include "../BallTracker.h"
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
#ifndef _DEBUG
	printf ("ShooterTakeShotCommand Initialized \n");
#endif
	
	shotState = SHOT_STATE_SLOW_START;

	// Set point at after cam cliff where it is safe to speed up
	// based off of previous endingPoint
	speedUpPoint = 0.25;
	
	// Stop rotating after almost back to starting point.
    endingPoint = 0.90;
	
	speed = 0.5;
}

void ShooterTakeShotCommand::Execute()
{

	currentPoint = shootersubsystem->GetCamAngle();
	
	SmartDashboard::GetInstance()->PutDouble("Cam Value", currentPoint);
#ifndef _DEBUG
	printf("Cam Encoder %f \n", (float)currentPoint);
#endif
	
	switch ( shotState )
	{
	case SHOT_STATE_UNKNOWN:
	case SHOT_STATE_SLOW_START:
	    speed = 0.3;  // slow speed going over cliff
		if ( currentPoint >= speedUpPoint || currentPoint >=endingPoint )
			shotState = SHOT_STATE_FAST_MIDDLE;
		break;
		
	case SHOT_STATE_FAST_MIDDLE:
		// is it time to speed up yet?
		speed = 0.7;
		if( shootersubsystem->ShooterArmReady() )
		{
			shootersubsystem->ResetCamAngle();
			shotState = SHOT_STATE_READY;
			break;
		}
		if( currentPoint >= endingPoint)
			shotState = SHOT_STATE_SLOW_FINISH;
		
		break;
	case SHOT_STATE_SLOW_FINISH:
		speed = 0.5;
		if( shootersubsystem->ShooterArmReady() )
		{
			shootersubsystem->ResetCamAngle();
			shotState = SHOT_STATE_READY;
			break;
		}
		break;
		
	case SHOT_STATE_READY:
		speed = 0; // keep stopped
	}
	shootersubsystem->Shoot( speed );
		
}

bool ShooterTakeShotCommand::IsFinished()
{
	return ( shotState == SHOT_STATE_READY );
}
 
void ShooterTakeShotCommand::End()
{
#ifndef _DEBUG
	printf ("ShooterTakeShotCommand Finished! \n");
#endif
	shootersubsystem->Stop();
//	BallTracker::GetInstance()->BallShot();
}

void ShooterTakeShotCommand::Interrupted()
{
#ifndef _DEBUG
	printf ("ShooterTakeShotCommand Interrupted! \n");
#endif
	shootersubsystem->Stop();
}
