#ifndef BOTTOM_LIFT_SUBSYSTEM_H
#define BOTTOM_LIFT_SUBSYSTEM_H
#include "WPILib.h"
#include "../BallSensor.h"



class BottomLiftSubsystem: public Subsystem 
{
private:

	Relay bottomLiftLeftRelay;
	Relay bottomLiftRightRelay;

public:
	BallSensor baseBallSensor;
	BallSensor middleBallSensor;
	
	void InitDefaultCommand();
	
	void LiftBallUp();
	void LiftBallDown();
	void LiftIdle();
	void UpdateSmartDashboard();
	
	BottomLiftSubsystem();
};

#endif
