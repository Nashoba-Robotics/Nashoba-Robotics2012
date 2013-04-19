#include "BallIntakeSubsystem.h"
#include "WPILib.h"
#include "../OperatorInput.h"
#include "../CommandBasedRobot.h"
#include "../HardwareSettings.h"
#include "../Commands/IntakeIdleCommand.h"
#include "../Commands/IntakeReceiveContinuousCommand.h"
#include "../Commands/IntakeRejectContinuousCommand.h"

const char *bis_state_name[] =
{
	"UNKNOWN",
	"ERROR",
	"GOT_BALL",
	"OUTGOING",
	"START_OUTGOING",
	"RECEIVING",
	"START_RECEIVING",
	"START_REJECTING",
	"REJECTING"
};

BallIntakeSubsystem::BallIntakeSubsystem(): Subsystem(const_cast<char*>("BallIntakeSubsyetm")),
  ballIntakeVictor( BALL_INTAKE_VICTOR_CHANNEL ),
  intakeBallSensor( BALL_SENSOR_MODULE, INTAKE_BALL_SENSOR_CHANNEL )
//  baseBallSensor  ( BALL_SENSOR_MODULE, BOT_LIFT_BASE_BALL_SENSOR_CHANNEL  )
{
	ResetBallState();
	ResetTime();	

}

BallIntakeBallState BallIntakeSubsystem::GetBallIntakeBallState()
{
	return ballIntakeBallState;
}

void BallIntakeSubsystem::ResetTime()
{
	time_ms = 0;	
}

void BallIntakeSubsystem::ResetBallState()
{
	ballIntakeBallState = BIS_UNKNOWN;
}

void BallIntakeSubsystem::DisableBallState()
{
	ballIntakeBallState = BIS_ERROR;
}

void BallIntakeSubsystem::InitDefaultCommand()
{
	SetDefaultCommand( new IntakeIdleCommand() );
	intakeIdleCommand = new IntakeIdleCommand();
    intakeReceiveCommand = new IntakeReceiveContinuousCommand();
    intakeRejectCommand = new IntakeRejectContinuousCommand();
}

void BallIntakeSubsystem::IntakeIdle()
{
	ballIntakeVictor.Set(0.0);
}

void BallIntakeSubsystem::IntakeIn()
{
	ballIntakeVictor.Set(-1.0);
}

void BallIntakeSubsystem::IntakeOut()
{
	ballIntakeVictor.Set(1.0);
}

void BallIntakeSubsystem::UpdateSmartDashboard()
{
#ifdef USE_SMART_DASHBOARD
//	SmartDashboard::PutNumber("BaseBallSensorV", baseBallSensor.GetVoltage() );	
//	SmartDashboard::PutNumber((double)"BaseBallSensorI", baseBallSensor.GetValue() );	

	SmartDashboard::PutBoolean("IntakeBallSensor", intakeBallSensor.IsBallThere() );	
	SmartDashboard::PutNumber("IntakeBallSensorV", intakeBallSensor.GetVoltage() );
//	SmartDashboard::PutNumber((double)"IntakeBallSensorI", intakeBallSensor.GetValue() );

	SmartDashboard::PutString ( "BallIntakeBallState",  bis_state_name[ballIntakeBallState] );	
#endif
	
}

void BallIntakeSubsystem::UpdateBallStateMachine()
{
	time_ms += 20; // keep time for use by state machine
	
	switch( ballIntakeBallState )
	{
	case BIS_UNKNOWN:
		if( intakeBallSensor.IsBallThere() )
		{
			ballIntakeBallState = BIS_GOT_BALL;
		}
		else
		{
			ballIntakeBallState = BIS_START_RECEIVING;
		}
		break;
		
	case BIS_ERROR:
		intakeIdleCommand->Start();
		break;
		
	case BIS_GOT_BALL:
		// if we got a ball and the bottom lift needs one, start sending it up by
		// signaling to the bottom lift by changing our state.  the bottom lift should
		// turn on its belt.
		// otherwise if the bottom lift does not need ball just stay in this state
		if( BLS_NEEDS_BALL == CommandBase::bottomliftsubsystem->GetBottomLiftBallState() )   
			ballIntakeBallState = BIS_START_OUTGOING;
		break;
		
	case BIS_START_OUTGOING:
		// may not need this state since we have no belt to start
		ballIntakeBallState = BIS_OUTGOING;
		break;
		
	case BIS_OUTGOING:
		// stay in this state until bottom lift gets ball completely
		if( BLS_GOT_BALL == CommandBase::bottomliftsubsystem->GetBottomLiftBallState() )
			ballIntakeBallState = BIS_START_REJECTING;
		break;
		
	case BIS_START_RECEIVING:
		intakeReceiveCommand->Start();
		ballIntakeBallState = BIS_RECEIVING;
		break;
		
    case BIS_RECEIVING:
		if( intakeBallSensor.IsBallThere() )
		{
			intakeReceiveCommand->Cancel();
			ballIntakeBallState = BIS_GOT_BALL;
		}
		break;
		
    case BIS_START_REJECTING:
    	ballIntakeBallState = BIS_REJECTING;
    	intakeRejectCommand->Start();
    	break;
    	
	case BIS_REJECTING:
		if( BLS_NEEDS_BALL == CommandBase::bottomliftsubsystem->GetBottomLiftBallState() )
			ballIntakeBallState = BIS_START_RECEIVING;		
		break;
	}
}
