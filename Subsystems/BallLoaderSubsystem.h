#ifndef BALL_LOADER_SUBSYSTEM_H
#define BALL_LOADER_SUBSYSTEM_H
#include "WPILib.h"




class BallLoaderSubsystem: public Subsystem 
{
private:
	CANJaguar ballLoaderJaguar;
	
public:

	void InitDefaultCommand();
	
	void LoadBall();
	void Idle();
	
	BallLoaderSubsystem();
};

#endif
