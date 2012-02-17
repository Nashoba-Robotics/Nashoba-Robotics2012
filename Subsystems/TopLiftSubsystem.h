#ifndef TOP_LIFT_SUBSYSTEM_H
#define TOP_LIFT_SUBSYSTEM_H
#include "WPILib.h"




class TopLiftSubsystem: public Subsystem 
{
private:
	CANJaguar TopLiftJaguar;
	


public:

	void InitDefaultCommand();
	
	void LiftBallUp();
	void LiftBallDown();
	void LiftIdle();
	
	TopLiftSubsystem();
};

#endif
