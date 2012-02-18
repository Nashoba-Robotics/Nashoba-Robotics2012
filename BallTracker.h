#ifndef BALL_TRACKER_H
#define BALL_TRACKER_H

#include "WPILib.h"

class BallTracker
{
public:
	int ballCount;
	
	
private:
	bool isBallCounted;
	
	bool IsBallPastIntake();
	bool IsBallInBotLift();
	bool IsBallInTopLift();
	bool IsBallInShooter();
	
	//NEED TO ADD IN DIGIGTAL IR SENSORS FOR ABOVE FUNCTIONS AND THEN 
};


#endif
