#ifndef TOP_LIFT_SUBSYSTEM_H
#define TOP_LIFT_SUBSYSTEM_H
#include "WPILib.h"
#include "../BallSensor.h"

class TopLiftReceiveContinuousCommand;

typedef enum {
	TLS_UNKNOWN,
	TLS_ERROR,
	TLS_BALL_AT_REST,
	TLS_EMPTY_READY,
	TLS_INCOMING,
	TLS_OUTGOING	
} TopLiftBallState;

class TopLiftSubsystem: public Subsystem 
{
private:
	CANJaguar        topLiftJaguar;
    TopLiftBallState topLiftBallState;
    
    unsigned int     time_ms;
    
    TopLiftReceiveContinuousCommand*  liftUpCommand;
    
public:
	BallSensor topLiftBallSensor;
	
	TopLiftSubsystem();
	
	void InitDefaultCommand();
	
	void LiftBallUp();
	void LiftBallDown();
	void LiftIdle();
	
	void              UpdateSmartDashboard();
	
	void              UpdateBallStateMachine();
	
	TopLiftBallState  GetTopLiftBallState();
	
	void              ResetBallState();
	
	void 			  ResetTime();
	
};

#endif
