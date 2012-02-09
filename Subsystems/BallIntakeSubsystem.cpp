#include "ShooterSubsystem.h"
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

void IntakeIdle()
{
	
}

void IntakeIn()
{
	
}

void IntakeRejectOut()
{
	
}

BallIntakeSubsystem::BallIntakeSubsystem(): Subsystem("BallIntakeSubsyetm"),
//check to see if slot,port or if the order is port,slot
  BallIntakeVictor( BALL_INTAKE_VICTOR_SLOT, BALL_INTAKE_VICTOR_PORT )
{
	
}
