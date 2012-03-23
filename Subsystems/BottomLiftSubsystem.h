#ifndef BOTTOM_LIFT_SUBSYSTEM_H
#define BOTTOM_LIFT_SUBSYSTEM_H
#include "WPILib.h"
#include "../BallSensor.h"

class BottomLiftReceiveContinuousCommand;

typedef enum {
	BLS_UNKNOWN,
	BLS_ERROR,
	BLS_GOT_BALL,
	BLS_NEEDS_BALL,
	BLS_START_INCOMING,
	BLS_INCOMING,
	BLS_START_OUTGOING,
	BLS_OUTGOING	
} BottomLiftBallState;

class BottomLiftSubsystem: public Subsystem 
{
private:

	Relay bottomLiftLeftRelay;
	Relay bottomLiftRightRelay;
    
	BottomLiftBallState bottomLiftBallState;
    
    unsigned int     time_ms;
    
    BottomLiftReceiveContinuousCommand*  liftUpCommand;
    
public:
	BallSensor baseBallSensor;
	BallSensor middleBallSensor;
	
	void InitDefaultCommand();
	
	void LiftBallUp();
	void LiftBallDown();
	void LiftIdle();
	
	void              UpdateSmartDashboard();
	
	void              UpdateBallStateMachine();
	
	BottomLiftBallState  GetBottomLiftBallState();
	
	void              ResetBallState();
	
	void              DisableBallState();
	
	void 			  ResetTime();
	
	BottomLiftSubsystem();
};

#endif
