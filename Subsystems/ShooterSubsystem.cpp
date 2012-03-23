#include "ShooterSubsystem.h"
#include "WPIlib.h"
#include "math.h"
#include "../OperatorInput.h"
#include "../CommandBasedRobot.h"
#include "../HardwareSettings.h"
#include "../Commands/ShooterIdleCommand.h"
#include "../Commands/ShooterReadyShotCommand.h"
#include "../Commands/ShooterTakeShotCommand.h"
#include "../Commands/TensionIncreaseCommand.h"
#include "../Commands/TensionDecreaseCommand.h"

char *sbs_state_name[] =
{
		"UNKNOWN",
		"ERROR",
		"EMPTY_NOT_READY",
		"NEEDS_BALL",
		"ARMED",
		"UNSTABLE"
};

ShooterSubsystem::ShooterSubsystem(): Subsystem("ShooterSubsystem"),
  shooterJaguar    ( SHOOTER_JAGUAR_CANID ),
  tensionerJaguar  ( TENSIONER_JAGUAR_CANID ),
  shooterBallSensor( BALL_SENSOR_MODULE, SHOOTER_BALL_SENSOR_CHANNEL),
  tensionerPot     ( SHOOTER_TENSIONER_SENSOR_MODULE, SHOOTER_TENSIONER_SENSOR_CHANNEL )
{
	// we do not know what the initial ball state is.
	ResetBallState();
	adjustmentAngle = 0;
	ResetTime();
}

void ShooterSubsystem::ResetTime()
{
	time_ms = 0;	
}

void ShooterSubsystem::InitDefaultCommand()
{
	SetDefaultCommand( new ShooterIdleCommand() );
	shooterJaguar.ConfigEncoderCodesPerRev(360) ;
	shooterJaguar.SetPositionReference(CANJaguar::kPosRef_QuadEncoder);
	tensionerJaguar.SetPositionReference(CANJaguar::kPosRef_Potentiometer);
}

//right now this is just being used for testing purposes, will be changed at later date ....
void ShooterSubsystem::Shoot( float speed )
{
	shooterJaguar.Set( speed );
}


void ShooterSubsystem::Stop()
{
	shooterJaguar.Set( 0 );
	tensionerJaguar.Set ( 0 );
}

float  ShooterSubsystem::GetCamAngle()
{
	float currentAngle;
	INT16 tempInteger;
	
	// get position which is a negative ever increasing absolute value
	// where each rotation increases it by 1.0
	currentAngle = - shooterJaguar.GetPosition();
	
	// adjust angle based on an established offset
	currentAngle = (currentAngle - adjustmentAngle);
			
	// do this madness because trunc() function is not available
	tempInteger = (UINT16)currentAngle;
	
	// take the fraction portion stripping off the whole number portion
	currentAngle = currentAngle - (float)tempInteger;
	
	return currentAngle;
}

bool ShooterSubsystem::ShooterArmReady()
{
	// use limit switch connected to tensioner jaguar to tell
	// if arm is in ready position
	// Analog value
	return (tensionerJaguar.GetPosition() > .5);
//			|| (( GetCamAngle() > 0.9 ) || (GetCamAngle() <.1)) ;
}
void ShooterSubsystem::ResetCamAngle()
{
	// set adjustment angle to present value to make new offset
	adjustmentAngle = - shooterJaguar.GetPosition();
}

void ShooterSubsystem::Tensioner( float speed )
{
#define ZERO_TENSION_VALUE 200
#define MAX_TENSION_VALUE  575
	
	if( speed < 0 )
	{
		// if we are loosening do not let it rotation past zero tension point
		if( tensionerPot.GetValue() < ZERO_TENSION_VALUE )
			speed = 0;
	}
	else
	{
		if( tensionerPot.GetValue() > MAX_TENSION_VALUE)
			speed = 0;
	}
	tensionerJaguar.Set( speed );
}

void ShooterSubsystem::UpdateSmartDashboard()
{
	/*
	SmartDashboard::GetInstance()->PutBoolean("ShooterBallSensor",  shooterBallSensor.IsBallThere() );	
	SmartDashboard::GetInstance()->PutDouble ("ShooterBallSensorV", shooterBallSensor.GetVoltage() );	
	SmartDashboard::GetInstance()->PutDouble ("TensionerPotDial",  tensionerPot.GetValue() );	
	SmartDashboard::GetInstance()->PutInt    ("TensionerPot",      tensionerPot.GetValue() );
	
	SmartDashboard::GetInstance()->PutDouble ("JAG 10 position",  tensionerJaguar.GetPosition() );
    SmartDashboard::GetInstance()->PutBoolean("Shooter Arm Ready", ShooterArmReady() );
	// send state name out to dashboard.
	SmartDashboard::GetInstance()->PutString ( "ShooterBallState",  sbs_state_name[shooterBallState] );	

	float currentPoint;
	
	currentPoint = -shooterJaguar.GetPosition();
	
	SmartDashboard::GetInstance()->PutDouble("Cam Encoder SH", currentPoint);
	
	currentPoint = GetCamAngle();
	SmartDashboard::GetInstance()->PutDouble("Cam Value SH", currentPoint);	
	*/
}

ShooterBallState ShooterSubsystem::GetShooterBallState()
{
	return shooterBallState;
}

bool ShooterSubsystem::IsShooterCamReadyToShoot()
{
	return ShooterArmReady();
}

void ShooterSubsystem::ResetBallState()
{
	shooterBallState = SBS_UNKNOWN;
}

void ShooterSubsystem::DisableBallState()
{
	shooterBallState = SBS_ERROR;
}

void ShooterSubsystem::UpdateBallStateMachine()
{
	time_ms += 20; // keep time for use by state machine
	
	// check shooter ball states first since the lower states
	// depend on its state
	switch( shooterBallState )
	{
	case SBS_UNKNOWN:
		// check sensor to see if we start empty or full
		if( shooterBallSensor.IsBallThere() )
		{
			shooterBallState = SBS_ARMED;
		}
		else
		{
			shooterBallState = SBS_EMPTY_NOT_READY;
		}
		break;
		
	case SBS_EMPTY_NOT_READY:
		// we are empty check to see if is stopped cam is in
		// position
		if( IsShooterCamReadyToShoot() ) //check if cam is in right position )
		{
			shooterBallState = SBS_NEEDS_BALL;
		}
		break;
	
	case SBS_NEEDS_BALL:
		// check to see if the sensor indicates a ball
		if( shooterBallSensor.IsBallThere() )
		{
			shooterBallState = SBS_ARMED;
		}
		// otherwise stay empty
		break;
	
	case SBS_ARMED:
		// check sensor to see if ball is missing
		if( false == shooterBallSensor.IsBallThere() &&
				!ShooterArmReady() )
		{
		    shooterBallState = SBS_EMPTY_NOT_READY;
		}
		break;
		
	case SBS_UNSTABLE:
		// ball is being jostled, need to wait until ball is stable.
		// this state may not be needed
		break;
		
	case SBS_ERROR:
	    // something bad has happened,
		break;
		
	}
	
	
}


