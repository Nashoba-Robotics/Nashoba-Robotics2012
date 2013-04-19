
#include "BallTracker.h"
#include "WPILib.h"
#include "Subsystems/BallIntakeSubsystem.h"
#include "Subsystems/BottomLiftSubsystem.h"
#include "Subsystems/TopLiftSubsystem.h"
#include "Subsystems/ShooterSubsystem.h"
#include "Commands/TopLiftReceiveContinuousCommand.h"
#include "Commands/TopLiftIdleCommand.h"
#include "Commands/BottomLiftReceiveContinuousCommand.h"
#include "Commands/BottomLiftIdleCommand.h"
#include "Commands/IntakeReceiveContinuousCommand.h"
#include "Commands/IntakeRejectContinuousCommand.h"

BallTracker *BallTracker::_instance = NULL;

BallTracker::BallTracker()
	{
	hasBeenCounted = false;
	ballCount = 0;
	}
/*
void BallTracker::HandleLift()
{
	
	if( !CommandBase::shootersubsystem->ShooterBallSensor.IsBallThere() && CommandBase::topliftsubsystem->TopLiftBallSensor.IsBallThere() )
	{
		new TopLiftReceiveContinuousCommand();
	}
	else
	{
		new TopLiftIdleCommand();
	}
	
	if( !CommandBase::topliftsubsystem->TopLiftBallSensor.IsBallThere() && CommandBase::bottomliftsubsystem->MiddleBallSensor.IsBallThere()  )
	{
		new BottomLiftReceiveContinuousCommand();
	}
	else
	{
		new BottomLiftIdleCommand();
	}
	
	if( !CommandBase::bottomliftsubsystem->MiddleBallSensor.IsBallThere())
	{
		//will be using manual control
		//new IntakeReceiveContinuousCommand();
	}
	else
	{
		
	}
	
	if( CommandBase::bottomliftsubsystem->BaseBallSensor.IsBallThere() && !CommandBase::bottomliftsubsystem->MiddleBallSensor.IsBallThere() )
	{
		new BottomLiftReceiveContinuousCommand();

	}
	else if( CommandBase::bottomliftsubsystem->BaseBallSensor.IsBallThere() && CommandBase::bottomliftsubsystem->MiddleBallSensor.IsBallThere() )
	{
	
	}
	else
	{

	}
	
	if( ( CommandBase::ballintakesubsystem->IntakeBallSensor.IsBallThere() ) && ( ballCount < 3 ) )
	{
		new IntakeReceiveContinuousCommand();

	}
	else if ( ( CommandBase::ballintakesubsystem->IntakeBallSensor.IsBallThere() ) && ( ballCount > 2 ) )
	{
		new IntakeRejectContinuousCommand();
		if( hasBeenCounted == false )
		{
			ballCount++;
			hasBeenCounted = true;
		}
	}
	else
	{
		//manual control to turn off if needed
		
		hasBeenCounted = false;
	}
}

void BallTracker::BallShot()
{
	ballCount--;
}

BallTracker *BallTracker::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new BallTracker();
	}
	return _instance;
}
*/
