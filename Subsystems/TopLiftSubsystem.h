#ifndef TOP_LIFT_SUBSYSTEM_H
#define TOP_LIFT_SUBSYSTEM_H
#include "WPILib.h"
#include "../BallSensor.h"



class TopLiftSubsystem: public Subsystem 
{
private:
	CANJaguar topLiftJaguar;
	


public:
	BallSensor topLiftBallSensor;
	
	void InitDefaultCommand();
	
	void LiftBallUp();
	void LiftBallDown();
	void LiftIdle();
	
	void UpdateSmartDashboard();
	
	TopLiftSubsystem();
};

#endif
