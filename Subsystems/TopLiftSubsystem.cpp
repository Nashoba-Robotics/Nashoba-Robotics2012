#include "TopLiftSubsystem.h"
#include "WPIlib.h"
#include "../OperatorInput.h"
#include "../CommandBasedRobot.h"
#include "../HardwareSettings.h"
#include "../Commands/TopLiftReceiveContinuousCommand.h"
#include "../Commands/TopLiftRejectContinuousCommand.h"
#include "../Commands/TopLiftIdleCommand.h"

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
void TopLiftSubsystem::UpdateSmartDashboard()
{
	SmartDashboard::GetInstance()->PutBoolean("TopLiftBallSensor", topLiftBallSensor.IsBallThere() );	
	SmartDashboard::GetInstance()->PutDouble("TopLiftBallSensorV", topLiftBallSensor.GetVoltage() );	
//	SmartDashboard::GetInstance()->PutInt("TopLiftBallSensorI", topLiftBallSensor.GetValue() );	
}

TopLiftSubsystem::TopLiftSubsystem(): Subsystem("TopLiftSubsystem"),
  topLiftJaguar( TOP_LIFT_JAGUAR_CANID ),
  topLiftBallSensor( BALL_SENSOR_MODULE, TOP_LIFT_BALL_SENSOR_CHANNEL )
{
	
}
