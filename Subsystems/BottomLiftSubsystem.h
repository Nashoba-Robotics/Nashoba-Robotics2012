#ifndef BOTTOM_LIFT_SUBSYSTEM_H
#define BOTTOM_LIFT_SUBSYSTEM_H
#include "WPILib.h"




class BottomLiftSubsystem: public Subsystem 
{
private:

	Relay BottomLiftLeftRelay;
	Relay BottomLiftRightRelay;
	
public:

	void InitDefaultCommand();
	
	void LiftBallUp();
	void LiftBallDown();
	void LiftIdle();
	
	BottomLiftSubsystem();
};

#endif
