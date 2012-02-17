#ifndef BALL_TRACKER_H
#define BALL_TRACKER_H

#include "WPILib.h"

class BallTracker
{
public:
	//need to decide if doing this or checking each sensor, first testing to 
	//see if sensors will work (doesn't just blow past them and go where they can't see.
	int ballCount;
	
	BallTracker();
	
	DigitalInput ballIntakeIR;
	DigitalInput lowerBotLiftIR;
	DigitalInput upperBotLiftIR;
 	DigitalInput topLiftIR;
	DigitalInput shooterIR;
	
	
private:

	bool IsBallPastIntake();
	bool IsBallInLowerBotLift();
	bool IsBallInUpperBotLift();
	bool IsBallInTopLift();
	bool IsBallInShooter();
	
	//NEED TO ADD IN DIGIGTAL IR SENSORS FOR ABOVE FUNCTIONS AND THEN 
};


#endif
