#ifndef BOTTOM_LIFT_SUBSYSTEM_H
#define BOTTOM_LIFT_SUBSYSTEM_H
#include "WPILib.h"




class BottomLiftSubsystem: public Subsystem 
{
private:
//Need to make the objects for the motors/spike relays/other things
	CANJaguar BottomLiftLeftJaguar;
	CANJaguar BottomLiftRightJaguar;
	
public:

	void InitDefaultCommand();
	
	void LiftBallUp();
	void LiftBallDown();
	void LiftIdle();
	
	BottomLiftSubsystem();
};

#endif
