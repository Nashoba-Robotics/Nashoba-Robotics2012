#include "TopLiftSubsystem.h"
#include "WPIlib.h"
#include "../OperatorInput.h"
#include "../CommandBasedRobot.h"
#include "../HardwareSettings.h"
#include "../Commands/IntakeReceiveContinuousCommand.h"
#include "../Commands/IntakeRejectContinuousCommand.h"
#include "../Commands/IntakeIdleCommand.h"

void TopLiftSubsystem::InitDefaultCommand()
{

}

void TopLiftSubsystem::LiftBallUp()
{
	//TODO
}

void TopLiftSubsystem::LiftBallDown()
{
	//TODO
}

void TopLiftSubsystem::LiftIdle()
{
	//TODO
}

TopLiftSubsystem::TopLiftSubsystem(): Subsystem("TopLiftSubsystem"),
  TopLiftJaguar( TOP_LIFT_JAGUAR_CANID )
{
	
}
