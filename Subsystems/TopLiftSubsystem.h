#ifndef TOP_LIFT_SUBSYSTEM_H
#define TOP_LIFT_SUBSYSTEM_H
#include "WPILib.h"
#include "../BallSensor.h"



class TopLiftSubsystem: public Subsystem 
{
private:
	CANJaguar TopLiftJaguar;
	


public:

	BallSensor TopLiftBallSensor;
	
	void InitDefaultCommand();
	
	void LiftBallUp();
	void LiftBallDown();
	void LiftIdle();
	
	TopLiftSubsystem();
};

#endif
