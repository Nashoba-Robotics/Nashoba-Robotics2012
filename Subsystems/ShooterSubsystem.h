#ifndef SHOOTER_SUBSYSTEM_H
#define SHOOTER_SUBSYSTEM_H

#include "WPILib.h"
#include "../OperatorInput.h"
#include "Commands/PIDSubsystem.h"
#include "../HardwareSettings.h"
#include "../BallSensor.h"

typedef enum {
	SBS_UNKNOWN,
	SBS_EMPTY_NOT_READY,
	SBS_EMPTY_READY,
	SBS_ARMED,
	SBS_UNSTABLE	
} ShooterBallState;

//This is the Shooter class of the robot. Controls the shooter. 

class ShooterSubsystem: public Subsystem
{
private:

public:	
	CANJaguar ShooterJaguar;
	CANJaguar TensionerJaguar;
	
	BallSensor ShooterBallSensor;
	
	ShooterSubsystem();
	
	void Shoot( float );
	void Rearm();
	void Stop();
	void Tensioner( float );
	
	void UpdateSmartDashboard();
	
	void InitDefaultCommand();

	ShooterBallState    getShooterBallState();	

};

#endif
