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
	ShooterJaguar.ConfigEncoderCodesPerRev(360) ;
}

//right now this is just being used for testing purposes, will be changed at later date ....
void ShooterSubsystem::Shoot( float speed )
{
	ShooterJaguar.Set( speed );
	//TODO Find out how to instance and use encoder to shoot and rearm with 1 360 degree motion
}

void ShooterSubsystem::Rearm()
{
	//TODO
}

void ShooterSubsystem::Stop()
{
	ShooterJaguar.Set( 0 );
	TensionerJaguar.Set ( 0 );
}

void ShooterSubsystem::Tensioner( float speed )
{
	TensionerJaguar.Set( speed );
}

void ShooterSubsystem::UpdateSmartDashboard()
{
	SmartDashboard::GetInstance()->PutBoolean("ShooterBallSensor", ShooterBallSensor.IsBallThere() );	
}



ShooterSubsystem::ShooterSubsystem(): Subsystem("ShooterSubsystem"),
  ShooterJaguar( SHOOTER_JAGUAR_CANID ),
  TensionerJaguar( TENSIONER_JAGUAR_CANID ),
  ShooterBallSensor( BALL_SENSOR_MODULE, SHOOTER_BALL_SENSOR_CHANNEL)
{
	
}
