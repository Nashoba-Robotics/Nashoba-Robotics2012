#ifndef BOTTOM_LIFT_SUBSYSTEM_H
#define BOTTOM_LIFT_SUBSYSTEM_H
#include "WPILib.h"
#include "../BallSensor.h"

class BottomLiftReceiveContinuousCommand;

typedef enum {
	BLS_UNKNOWN,
	BLS_ERROR,
	BLS_BALL_AT_REST,
	BLS_EMPTY_READY,
	BLS_INCOMING,
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
	
	void 			  ResetTime();
	
	BottomLiftSubsystem();
};

#endif
