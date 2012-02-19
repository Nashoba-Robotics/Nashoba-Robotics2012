#include "BallIntakeSubsystem.h"
#include "WPIlib.h"
#include "../OperatorInput.h"
#include "../CommandBasedRobot.h"
#include "../HardwareSettings.h"
#include "../Commands/IntakeIdleCommand.h"
#include "../Commands/IntakeReceiveContinuousCommand.h"
#include "../Commands/IntakeRejectContinuousCommand.h"


void BallIntakeSubsystem::InitDefaultCommand()
{
	SetDefaultCommand( new IntakeIdleCommand() );
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
	SmartDashboard::GetInstance()->PutBoolean("IntakeBallSensor", intakeBallSensor.IsBallThere() );	
	SmartDashboard::GetInstance()->PutDouble("IntakeBallSensorV", intakeBallSensor.GetVoltage() );
//	SmartDashboard::GetInstance()->PutInt("IntakeBallSensorI", intakeBallSensor.GetValue() );
}

BallIntakeSubsystem::BallIntakeSubsystem(): Subsystem("BallIntakeSubsyetm"),
  ballIntakeVictor( BALL_INTAKE_VICTOR_CHANNEL ),
  intakeBallSensor( BALL_SENSOR_MODULE, INTAKE_BALL_SENSOR_CHANNEL )
{
	
}
