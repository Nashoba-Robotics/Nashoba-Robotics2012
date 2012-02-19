#include "BottomLiftSubsystem.h"
#include "WPIlib.h"
#include "../OperatorInput.h"
#include "../CommandBasedRobot.h"
#include "../HardwareSettings.h"
#include "../Commands/BottomLiftIdleCommand.h"
#include "../Commands/BottomLiftReceiveContinuousCommand.h"
#include "../Commands/BottomLiftRejectContinuousCommand.h"

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

	SmartDashboard::GetInstance()->PutBoolean("MiddleBallSensor", middleBallSensor.IsBallThere() );
	SmartDashboard::GetInstance()->PutDouble("MiddleBallSensorV", middleBallSensor.GetVoltage() );	
//	SmartDashboard::GetInstance()->PutInt("MiddleBallSensorI", middleBallSensor.GetValue() );

}

BottomLiftSubsystem::BottomLiftSubsystem(): Subsystem("BottomLiftSubsystem"),
  bottomLiftLeftRelay( BOTTOM_LIFT_LEFT_SPIKE_RELAY_CHANNEL ),
  bottomLiftRightRelay( BOTTOM_LIFT_RIGHT_SPIKE_RELAY_CHANNEL ),
  baseBallSensor  ( BALL_SENSOR_MODULE, BOT_LIFT_BASE_BALL_SENSOR_CHANNEL  ),
  middleBallSensor( BALL_SENSOR_MODULE, BOT_LIFT_MIDDLE_BALL_SENSOR_CHANNEL)
{
	
}
