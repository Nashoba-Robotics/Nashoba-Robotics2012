#ifndef TOP_LIFT_SUBSYSTEM_H
#define TOP_LIFT_SUBSYSTEM_H
#include "WPILib.h"
#include "../BallSensor.h"

class TopLiftReceiveContinuousCommand;

typedef enum {
	TLS_UNKNOWN,
	TLS_ERROR,
	TLS_GOT_BALL,
	TLS_NEEDS_BALL,
	TLS_START_INCOMING,
	TLS_INCOMING,
	TLS_START_OUTGOING,
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
	
	void              DisableBallState();
	
	void 			  ResetTime();
	
};

#endif
