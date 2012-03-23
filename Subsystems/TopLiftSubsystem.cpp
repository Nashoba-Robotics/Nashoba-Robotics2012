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
		"GOT_BALL",
		"NEEDS_BALL",
		"START_INCOMING"
		"INCOMING",
		"START_OUTGOING"
		"OUTGOING"
};

TopLiftSubsystem::TopLiftSubsystem(): Subsystem("TopLiftSubsystem"),
  topLiftJaguar( TOP_LIFT_JAGUAR_CANID ),
  topLiftBallSensor( BALL_SENSOR_MODULE, TOP_LIFT_BALL_SENSOR_CHANNEL )
{
	liftUpCommand = NULL;
	ResetBallState();
	ResetTime();	
}

void TopLiftSubsystem::ResetTime()
{
	time_ms = 0;	
}

void TopLiftSubsystem::InitDefaultCommand()
{
	SetDefaultCommand( new TopLiftIdleCommand() );
	liftUpCommand = new TopLiftReceiveContinuousCommand();
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
void TopLiftSubsystem::UpdateSmartDashboard()
{
	SmartDashboard::GetInstance()->PutBoolean("TopLiftBallSensor", topLiftBallSensor.IsBallThere() );	
	SmartDashboard::GetInstance()->PutDouble("TopLiftBallSensorV", topLiftBallSensor.GetVoltage() );	
 //	SmartDashboard::GetInstance()->PutInt("TopLiftBallSensorI", topLiftBallSensor.GetValue() );
    // send state name out to dashboard.
	SmartDashboard::GetInstance()->PutString ( "TopLiftBallState",  tls_state_name[topLiftBallState] );	
}


void TopLiftSubsystem::ResetBallState()
{
	topLiftBallState = TLS_UNKNOWN;
}

void TopLiftSubsystem::DisableBallState()
{
	topLiftBallState = TLS_ERROR;
	liftUpCommand->Cancel();
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
			topLiftBallState = TLS_GOT_BALL;
		else
			topLiftBallState = TLS_NEEDS_BALL;
		break;
		
	case TLS_ERROR:
		break;
		
	case TLS_GOT_BALL:
		// stay in this state until shooter needs a ball.
		if( SBS_NEEDS_BALL == CommandBase::shootersubsystem->GetShooterBallState() )
		{
			topLiftBallState = TLS_START_OUTGOING;
		}
		else
		{
			// the shooter is not ready for us, stop the lift and wait for shooter
			liftUpCommand->Cancel();
		}
		break;
		
	case TLS_NEEDS_BALL:
		liftUpCommand->Cancel();
		// if the lower lift is sending us a ball...
		// turn on the lift and go to the incoming state until it gets here
		if( BLS_OUTGOING == CommandBase::bottomliftsubsystem->GetBottomLiftBallState() )
		{
			topLiftBallState = TLS_START_INCOMING;
			break;
		}
		// sometimes when testing we want to just stick a ball directly in
		// so if it shows up change state.
		if( topLiftBallSensor.IsBallThere( ))
		{
			topLiftBallState = TLS_GOT_BALL;
		}
		break;
		
	case TLS_START_INCOMING:
		liftUpCommand->Start();
		topLiftBallState = TLS_INCOMING;
		break;
		
	case TLS_INCOMING:
		// stay in this state until we have a ball.
		if( topLiftBallSensor.IsBallThere( ))
		{
			topLiftBallState = TLS_GOT_BALL;
		}
		break;
		
	case TLS_START_OUTGOING:
		liftUpCommand->Start();
		// after starting the lift go into the outgoing state.
		topLiftBallState = TLS_OUTGOING;
		break;
		
	case TLS_OUTGOING:
		// stay in the outgoing state until shooter gets ball.
		if( SBS_ARMED == CommandBase::shootersubsystem->GetShooterBallState() )
			topLiftBallState = TLS_NEEDS_BALL;
		// if some one shoots prematurely go back to the GOT_BALL state
		if( SBS_EMPTY_NOT_READY == CommandBase::shootersubsystem->GetShooterBallState() )
			topLiftBallState = TLS_GOT_BALL;
		break;
	}
}
