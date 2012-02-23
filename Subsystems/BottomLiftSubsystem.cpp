#include "BottomLiftSubsystem.h"
#include "WPIlib.h"
#include "../OperatorInput.h"
#include "../CommandBasedRobot.h"
#include "../HardwareSettings.h"
#include "../Commands/BottomLiftIdleCommand.h"
#include "../Commands/BottomLiftReceiveContinuousCommand.h"
#include "../Commands/BottomLiftRejectContinuousCommand.h"

char *bls_state_name[] =
{
		"UNKNOWN",
		"ERROR",
		"GOT_BALL",
		"NEEDS_BALL",
		"START_INCOMING"
		"INCOMING",
		"START_OUTGOING"
		"OUTGOING"
};

BottomLiftSubsystem::BottomLiftSubsystem(): Subsystem("BottomLiftSubsystem"),
  bottomLiftLeftRelay( BOTTOM_LIFT_LEFT_SPIKE_RELAY_CHANNEL ),
  bottomLiftRightRelay( BOTTOM_LIFT_RIGHT_SPIKE_RELAY_CHANNEL ),
  baseBallSensor  ( BALL_SENSOR_MODULE, BOT_LIFT_BASE_BALL_SENSOR_CHANNEL  ),
  middleBallSensor( BALL_SENSOR_MODULE, BOT_LIFT_MIDDLE_BALL_SENSOR_CHANNEL)
{
	ResetBallState();
	ResetTime();	

}


void BottomLiftSubsystem::ResetTime()
{
	time_ms = 0;	
}

void BottomLiftSubsystem::InitDefaultCommand()
{
	SetDefaultCommand( new BottomLiftIdleCommand() );
	liftUpCommand = new BottomLiftReceiveContinuousCommand();
}

void BottomLiftSubsystem::LiftBallUp()
{
	bottomLiftLeftRelay.Set( Relay::kForward );
	bottomLiftRightRelay.Set( Relay::kForward );
}

void BottomLiftSubsystem::LiftBallDown()
{
	bottomLiftLeftRelay.Set( Relay::kReverse );
	bottomLiftRightRelay.Set( Relay::kReverse );
}

void BottomLiftSubsystem::LiftIdle()
{
	bottomLiftLeftRelay.Set( Relay::kOff );
	bottomLiftRightRelay.Set( Relay::kOff );
}
void BottomLiftSubsystem::UpdateSmartDashboard()
{
	SmartDashboard::GetInstance()->PutBoolean("BaseBallSensor", baseBallSensor.IsBallThere() );	
	SmartDashboard::GetInstance()->PutDouble("BaseBallSensorV", baseBallSensor.GetVoltage() );	
//	SmartDashboard::GetInstance()->PutInt("BaseBallSensorI", baseBallSensor.GetValue() );	

	SmartDashboard::GetInstance()->PutBoolean("MiddleBallSensor", middleBallSensor.IsBallThere() );
	SmartDashboard::GetInstance()->PutDouble("MiddleBallSensorV", middleBallSensor.GetVoltage() );	
//	SmartDashboard::GetInstance()->PutInt("MiddleBallSensorI", middleBallSensor.GetValue() );

	SmartDashboard::GetInstance()->PutString ( "BottomLiftBallState",  bls_state_name[bottomLiftBallState] );	

}

BottomLiftBallState BottomLiftSubsystem::GetBottomLiftBallState()
{
	return bottomLiftBallState;
}


void BottomLiftSubsystem::ResetBallState()
{
	bottomLiftBallState = BLS_UNKNOWN;
}

void BottomLiftSubsystem::DisableBallState()
{
	bottomLiftBallState = BLS_ERROR;
}

void BottomLiftSubsystem::UpdateBallStateMachine()
{
	time_ms += 20; // keep time for use by state machine
	
	// check shooter ball states first since the lower states
	// depend on its state
	switch( bottomLiftBallState )
	{
	case BLS_UNKNOWN:
		// figure out if a ball is at either sensor to set proper state
		if( middleBallSensor.IsBallThere( ) ||
				baseBallSensor.IsBallThere( ) )
			bottomLiftBallState = BLS_GOT_BALL;
		else
			bottomLiftBallState = BLS_NEEDS_BALL;
		break;
		
	case BLS_ERROR:
		liftUpCommand->Cancel();
		break;
		
	case BLS_GOT_BALL:
		// stay in this state until we see the top lift needing a ball.
		if( TLS_NEEDS_BALL == CommandBase::topliftsubsystem->GetTopLiftBallState() )
		{
			bottomLiftBallState = BLS_START_OUTGOING;
		}
		else
		{
			liftUpCommand->Cancel();
		}
		break;
		
	case BLS_NEEDS_BALL:
		liftUpCommand->Cancel();
		// stay in this state until we detect a ball coming out from the ball intake.
		if( BIS_OUTGOING == CommandBase::ballintakesubsystem->GetBallIntakeBallState() )
		{
			bottomLiftBallState = BLS_START_INCOMING;
			break;
		}
		// sometimes when testing we want to just stick a ball directly in
		// so if it shows up change state.
		if( middleBallSensor.IsBallThere( ) || 
				baseBallSensor.IsBallThere( ) )
			bottomLiftBallState = BLS_GOT_BALL;
		break;
		
	case BLS_START_INCOMING:
		// start up the lift for incoming ball and go to the incoming state
		liftUpCommand->Start();
		bottomLiftBallState = BLS_INCOMING;
		break;
		
	case BLS_INCOMING:
		// stay in the incoming state until the  
		if( middleBallSensor.IsBallThere( ) ||
				baseBallSensor.IsBallThere() )
		{
			bottomLiftBallState = BLS_GOT_BALL;
			liftUpCommand->Cancel();
		}
		break;
		
	case BLS_START_OUTGOING:
		// start up lift to move ball upward
		liftUpCommand->Start();
		bottomLiftBallState = BLS_OUTGOING;
		break;
		
	case BLS_OUTGOING:
		// stay in this state until ball shows up in the top lift
		if( TLS_GOT_BALL == CommandBase::topliftsubsystem->GetTopLiftBallState() )
			bottomLiftBallState = BLS_NEEDS_BALL;
		break;
	}
}
