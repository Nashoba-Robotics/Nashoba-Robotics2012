#include "TopLiftSubsystem.h"
#include "WPIlib.h"
#include "../OperatorInput.h"
#include "../CommandBasedRobot.h"
#include "../HardwareSettings.h"
#include "../Commands/TopLiftReceiveContinuousCommand.h"
#include "../Commands/TopLiftRejectContinuousCommand.h"
#include "../Commands/TopLiftIdleCommand.h"

#include "ShooterSubsystem.h"

char *tls_state_name[] =
{
		"UNKNOWN",
		"ERROR",
		"BALL_AT_REST",
		"EMPTY_READY",
		"INCOMING",
		"OUTGOING"
};

TopLiftSubsystem::TopLiftSubsystem(): Subsystem("TopLiftSubsystem"),
  topLiftJaguar( TOP_LIFT_JAGUAR_CANID ),
  topLiftBallSensor( BALL_SENSOR_MODULE, TOP_LIFT_BALL_SENSOR_CHANNEL )
{
	// we do not know what the initial ball state is.
	ResetBallState();
	ResetTime();	
	liftUpCommand = new TopLiftReceiveContinuousCommand();
}

void TopLiftSubsystem::ResetTime()
{
	time_ms = 0;	
}

void TopLiftSubsystem::InitDefaultCommand()
{
	SetDefaultCommand( new TopLiftIdleCommand() );
}

void TopLiftSubsystem::LiftBallUp()
{
	topLiftJaguar.Set(1.0);
}

void TopLiftSubsystem::LiftBallDown()
{
	topLiftJaguar.Set(-1.0);
}

void TopLiftSubsystem::LiftIdle()
{
	topLiftJaguar.Set(0.0);
}


TopLiftBallState TopLiftSubsystem::GetTopLiftBallState()
{
	return topLiftBallState;
}


void TopLiftSubsystem::ResetBallState()
{
	topLiftBallState = TLS_UNKNOWN;
}

void TopLiftSubsystem::UpdateBallStateMachine()
{
	time_ms += 20; // keep time for use by state machine
	
	// check shooter ball states first since the lower states
	// depend on its state
	switch( topLiftBallState )
	{
	case TLS_UNKNOWN:
		// figure out if a ball is at the sensor to set proper state
		if( topLiftBallSensor.IsBallThere( ))
			topLiftBallState = TLS_BALL_AT_REST;
		else
			topLiftBallState = TLS_EMPTY_READY;
		break;
		
	case TLS_ERROR:
		break;
		
	case TLS_BALL_AT_REST:
		if( SBS_EMPTY_READY == CommandBase::shootersubsystem->GetShooterBallState() )
		{
			topLiftBallState = TLS_OUTGOING;
			liftUpCommand->Start();
		}
		else
		{
			liftUpCommand->Cancel();
		}
		break;
		
	case TLS_EMPTY_READY:
		liftUpCommand->Cancel();
		// normally if the lower lift is sending us a ball...
		// turn on the lift and go to the incoming state.
		if( BLS_OUTGOING == CommandBase::bottomliftsubsystem->GetBottomLiftBallState() )
		{
			liftUpCommand->Start();
			topLiftBallState = TLS_BALL_AT_REST;
		}
		// sometimes when testing we want to just stick a ball directly in
		// so if it shows up change state.
		if( topLiftBallSensor.IsBallThere( ))
		{
			topLiftBallState = TLS_BALL_AT_REST;
		}
		break;
		
	case TLS_INCOMING:
		liftUpCommand->Start();
		if( topLiftBallSensor.IsBallThere( ))
		{
			topLiftBallState = TLS_BALL_AT_REST;
		}
		break;
		
	case TLS_OUTGOING:
		if( SBS_ARMED == CommandBase::shootersubsystem->GetShooterBallState() )
			topLiftBallState = TLS_EMPTY_READY;
		break;
	}
}

void TopLiftSubsystem::UpdateSmartDashboard()
{
	SmartDashboard::GetInstance()->PutBoolean( "TopLiftBallSensor", topLiftBallSensor.IsBallThere() );	
	SmartDashboard::GetInstance()->PutDouble ( "TopLiftBallSensorV", topLiftBallSensor.GetVoltage() );	
	SmartDashboard::GetInstance()->PutString ( "TopLiftBallState",  tls_state_name[topLiftBallState] );	
}

