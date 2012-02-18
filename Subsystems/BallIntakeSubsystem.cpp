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
	BallIntakeVictor.Set(0.0);
}

void BallIntakeSubsystem::IntakeIn()
{
	BallIntakeVictor.Set(-1.0);
}

void BallIntakeSubsystem::IntakeOut()
{
	BallIntakeVictor.Set(1.0);
}

BallIntakeSubsystem::BallIntakeSubsystem(): Subsystem("BallIntakeSubsyetm"),
  BallIntakeVictor( BALL_INTAKE_VICTOR_CHANNEL ),
  IntakeBallSensor( BALL_SENSOR_MODULE, INTAKE_BALL_SENSOR_CHANNEL )
{
	
}
