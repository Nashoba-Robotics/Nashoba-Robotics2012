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
	TopLiftJaguar.Set(1.0);
}

void TopLiftSubsystem::LiftBallDown()
{
	TopLiftJaguar.Set(-1.0);
}

void TopLiftSubsystem::LiftIdle()
{
	TopLiftJaguar.Set(0.0);
}

TopLiftSubsystem::TopLiftSubsystem(): Subsystem("TopLiftSubsystem"),
  TopLiftJaguar( TOP_LIFT_JAGUAR_CANID ),
  TopLiftBallSensor( BALL_SENSOR_MODULE, TOP_LIFT_BALL_SENSOR_CHANNEL )
{
	
}
