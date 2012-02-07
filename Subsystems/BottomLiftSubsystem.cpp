#include "BottomLiftSubsystem.h"
#include "WPIlib.h"
#include "../OperatorInput.h"
#include "../CommandBasedRobot.h"
#include "../HardwareSettings.h"
#include "../Commands/IntakeReceiveContinuousCommand.h"
#include "../Commands/IntakeRejectContinuousCommand.h"
#include "../Commands/IntakeIdleCommand.h"

void BottomLiftSubsystem::InitDefaultCommand()
{

}

void BottomLiftSubsystem::LiftBallUp()
{
	//TODO
}

void BottomLiftSubsystem::LiftBallDown()
{
	//TODO
}

void BottomLiftSubsystem::LiftIdle()
{
	//TODO
}

BottomLiftSubsystem::BottomLiftSubsystem(): Subsystem("BottomLiftSubsystem"),
//will be changed to spike relays or something at somepoint
  BottomLiftLeftJaguar( BOTTOM_LIFT_LEFT_JAGUAR_CANID ),
  BottomLiftRightJaguar( BOTTOM_LIFT_RIGHT_JAGUAR_CANID )
{
	
}
