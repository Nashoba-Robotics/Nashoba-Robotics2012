#include "BallLoaderSubsystem.h"
#include "WPIlib.h"
#include "../OperatorInput.h"
#include "../CommandBasedRobot.h"
#include "../HardwareSettings.h"
#include "../Commands/BallLoaderIdleCommand.h"
#include "../Commands/BallLoaderLoadCommand.h"

void BallLoaderSubsystem::InitDefaultCommand()
{
	SetDefaultCommand( new BallLoaderIdleCommand() );
}

void BallLoaderSubsystem::Idle()
{
	ballLoaderJaguar.Set(0);
}

void BallLoaderSubsystem::LoadBall()
{
	//May need to be changed
	ballLoaderJaguar.Set(.5);
}

BallLoaderSubsystem::BallLoaderSubsystem(): Subsystem("BallLoaderSubsystem"),
  ballLoaderJaguar( BALL_LOADER_JAGUAR_CANID )
{
	
}
