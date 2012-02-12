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

BottomLiftSubsystem::BottomLiftSubsystem(): Subsystem("BottomLiftSubsystem"),
//will be changed to spike relays or something at somepoint
  BottomLiftLeftRelay( BOTTOM_LIFT_LEFT_SPIKE_RELAY_CHANNEL ),
  BottomLiftRightRelay( BOTTOM_LIFT_RIGHT_SPIKE_RELAY_CHANNEL )
{
	
}
