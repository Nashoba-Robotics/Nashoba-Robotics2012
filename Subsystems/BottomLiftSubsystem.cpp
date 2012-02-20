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
		"BALL_AT_REST",
		"EMPTY_READY",
		"INCOMING",
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
	liftUpCommand = new BottomLiftReceiveContinuousCommand();
}


void BottomLiftSubsystem::ResetTime()
{
	time_ms = 0;	
}

void BottomLiftSubsystem::InitDefaultCommand()
{
	SetDefaultCommand( new BottomLiftIdleCommand() );
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
	SmartDashboard::GetInstance()->PutString ( "BottomLiftBallState",  bls_state_name[bottomLiftBallState] );	

	SmartDashboard::GetInstance()->PutBoolean("MiddleBallSensor", middleBallSensor.IsBallThere() );
	SmartDashboard::GetInstance()->PutDouble("MiddleBallSensorV", middleBallSensor.GetVoltage() );	
//	SmartDashboard::GetInstance()->PutInt("MiddleBallSensorI", middleBallSensor.GetValue() );

}

BottomLiftBallState BottomLiftSubsystem::GetBottomLiftBallState()
{
	return bottomLiftBallState;
}


void BottomLiftSubsystem::ResetBallState()
{
	bottomLiftBallState = BLS_UNKNOWN;
}

void BottomLiftSubsystem::UpdateBallStateMachine()
{
	time_ms += 20; // keep time for use by state machine
	
	// check shooter ball states first since the lower states
	// depend on its state
	switch( bottomLiftBallState )
	{
	case BLS_UNKNOWN:
		// figure out if a ball is at the sensor to set proper state
		if( middleBallSensor.IsBallThere( ))
			bottomLiftBallState = BLS_BALL_AT_REST;
		else
			bottomLiftBallState = BLS_EMPTY_READY;
		break;
		
	case BLS_ERROR:
		break;
		
	case BLS_BALL_AT_REST:
		if( TLS_EMPTY_READY == CommandBase::topliftsubsystem->GetTopLiftBallState() )
		{
			bottomLiftBallState = BLS_OUTGOING;
			liftUpCommand->Start();
		}
		else
		{
			liftUpCommand->Cancel();
		}
		break;
		
	case BLS_EMPTY_READY:
		liftUpCommand->Cancel();
		// sometimes when testing we want to just stick a ball directly in
		// so if it shows up change state.
		if( middleBallSensor.IsBallThere( ))
		{
			bottomLiftBallState = BLS_BALL_AT_REST;
		}
		break;
		
	case BLS_INCOMING:
		liftUpCommand->Start();
		if( middleBallSensor.IsBallThere( ))
			bottomLiftBallState = BLS_BALL_AT_REST;
		break;
		
	case BLS_OUTGOING:
		if( TLS_BALL_AT_REST == CommandBase::topliftsubsystem->GetTopLiftBallState() )
			bottomLiftBallState = BLS_EMPTY_READY;
		break;
	}
}
