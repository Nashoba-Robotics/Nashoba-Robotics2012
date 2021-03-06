#ifndef SHOOTER_SUBSYSTEM_H
#define SHOOTER_SUBSYSTEM_H

#include "WPILib.h"
#include "../OperatorInput.h"
#include "Commands/PIDSubsystem.h"
#include "../HardwareSettings.h"
#include "../BallSensor.h"

typedef enum {
	SBS_UNKNOWN,
	SBS_ERROR,
	SBS_EMPTY_NOT_READY,
	SBS_NEEDS_BALL,
	SBS_ARMED,
	SBS_UNSTABLE	
} ShooterBallState;


//This is the Shooter class of the robot. Controls the shooter. 

class ShooterSubsystem: public Subsystem
{
private:
    ShooterBallState  shooterBallState;
    double            adjustmentAngle;
    
    bool              IsShooterCamReadyToShoot();

	unsigned int      time_ms;
    
public:	
	CANJaguar         shooterJaguar;
	CANJaguar         tensionerJaguar;
	
	BallSensor        shooterBallSensor;
	AnalogChannel     tensionerPot;
	
	ShooterSubsystem();
	
	void              Shoot( float );

	void              Stop();
	
	void              Tensioner( float );
	
	float             GetCamAngle( );
	void              ResetCamAngle( );
	bool              ShooterArmReady();
	
	void              UpdateSmartDashboard();
	
	void              UpdateBallStateMachine();
	
	ShooterBallState  GetShooterBallState();	
	
	void              ResetBallState();
	
	void              DisableBallState();
	
	void 			  ResetTime();
	
	void              InitDefaultCommand();



};

#endif
