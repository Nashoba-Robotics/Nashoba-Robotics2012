#include "ShooterSubsystem.h"
#include "WPIlib.h"
#include "../OperatorInput.h"
#include "../CommandBasedRobot.h"
#include "../HardwareSettings.h"
#include "../Commands/ShooterIdleCommand.h"
#include "../Commands/ShooterReadyShotCommand.h"
#include "../Commands/ShooterTakeShotCommand.h"
#include "../Commands/TensionIncreaseCommand.h"
#include "../Commands/TensionDecreaseCommand.h"

void ShooterSubsystem::InitDefaultCommand()
{
	SetDefaultCommand( new ShooterIdleCommand() );
}

//right now this is just being used for testing purposes, will be changed at later date ....
void ShooterSubsystem::Shoot( float speed )
{
	shooterJaguar.Set( speed );
}

void ShooterSubsystem::Rearm()
{
	//TODO
}

void ShooterSubsystem::Stop()
{
	shooterJaguar.Set( 0 );
	tensionerJaguar.Set ( 0 );
}

void ShooterSubsystem::Tensioner( float speed )
{
	tensionerJaguar.Set( speed );
}



ShooterSubsystem::ShooterSubsystem(): Subsystem("ShooterSubsystem"),
  shooterJaguar( SHOOTER_JAGUAR_CANID ),
  tensionerJaguar( TENSIONER_JAGUAR_CANID )
{
	
}
