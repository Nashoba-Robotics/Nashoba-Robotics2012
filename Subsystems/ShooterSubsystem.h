#ifndef SHOOTER_SUBSYSTEM_H
#define SHOOTER_SUBSYSTEM_H

#include "WPILib.h"
#include "../OperatorInput.h"
#include "Commands/PIDSubsystem.h"
#include "../HardwareSettings.h"
#include "../BallSensor.h"

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
	
	
	void InitDefaultCommand();
	

};

#endif
