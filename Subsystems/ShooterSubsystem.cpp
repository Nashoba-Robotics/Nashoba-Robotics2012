#include "ShooterSubsystem.h"
#include "WPIlib.h"
#include "../OperatorInput.h"
#include "../CommandBasedRobot.h"
#include "../HardwareSettings.h"
#include "../Commands/ShooterIdleCommand.h"
#include "../Commands/ShooterReadyShotCommand.h"
#include "../Commands/ShooterTakeShotCommand.h"

void ShooterSubsystem::InitDefaultCommand()
{
	SetDefaultCommand( new ShooterIdleCommand() );
}

void ShooterSubsystem::Shoot()
{
	//TODO
}

void ShooterSubsystem::Rearm()
{
	//TODO
}

void ShooterSubsystem::Stop()
{
	//TODO
}

ShooterSubsystem::ShooterSubsystem(): Subsystem("ShooterSubsystem"),
  ShooterJaguar( SHOOTER_JAGUAR_CANID )
{
	
}
