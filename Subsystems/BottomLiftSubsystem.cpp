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
	BottomLiftLeftRelay.Set( Relay::kForward );
	BottomLiftRightRelay.Set( Relay::kForward );
}

void BottomLiftSubsystem::LiftBallDown()
{
	BottomLiftLeftRelay.Set( Relay::kReverse );
	BottomLiftRightRelay.Set( Relay::kReverse );
}

void BottomLiftSubsystem::LiftIdle()
{
	BottomLiftLeftRelay.Set( Relay::kOff );
	BottomLiftRightRelay.Set( Relay::kOff );
}
void BottomLiftSubsystem::UpdateSmartDashboard()
{
	SmartDashboard::GetInstance()->PutBoolean("BaseBallSensor", BaseBallSensor.IsBallThere() );	
	SmartDashboard::GetInstance()->PutDouble("BaseBallSensorV", BaseBallSensor.GetVoltage() );	
	SmartDashboard::GetInstance()->PutBoolean("MiddleBallSensor", MiddleBallSensor.IsBallThere() );
	SmartDashboard::GetInstance()->PutDouble("MiddleBallSensorV", MiddleBallSensor.GetVoltage() );	

}

BottomLiftSubsystem::BottomLiftSubsystem(): Subsystem("BottomLiftSubsystem"),
  BottomLiftLeftRelay( BOTTOM_LIFT_LEFT_SPIKE_RELAY_CHANNEL ),
  BottomLiftRightRelay( BOTTOM_LIFT_RIGHT_SPIKE_RELAY_CHANNEL ),
  BaseBallSensor  ( BALL_SENSOR_MODULE, BOT_LIFT_BASE_BALL_SENSOR_CHANNEL  ),
  MiddleBallSensor( BALL_SENSOR_MODULE, BOT_LIFT_MIDDLE_BALL_SENSOR_CHANNEL)
{
	
}
