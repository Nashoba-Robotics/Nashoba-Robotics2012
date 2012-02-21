#ifndef BALL_INTAKE_SUBSYSTEM_H
#define BALL_INTAKE_SUBSYSTEM_H
#include "WPILib.h"
#include "../BallSensor.h"

class IntakeIdleCommand;
class IntakeReceiveContinuousCommand;
class IntakeRejectContinuousCommand;

typedef enum {
	BIS_UNKNOWN,
	BIS_ERROR,
	BIS_GOT_BALL,
	BIS_START_OUTGOING,
	BIS_OUTGOING,
	BIS_RECEIVING,
	BIS_START_RECEIVING,
	BIS_START_REJECTING,
	BIS_REJECTING	
} BallIntakeBallState;



class BallIntakeSubsystem: public Subsystem 
{
private:
	Victor ballIntakeVictor;

	BallIntakeBallState ballIntakeBallState;

    unsigned int     time_ms;
    IntakeIdleCommand*    intakeIdleCommand;
    IntakeReceiveContinuousCommand* intakeReceiveCommand;
    IntakeRejectContinuousCommand*  intakeRejectCommand;
    
public:

	BallSensor intakeBallSensor;
	BallSensor baseBallSensor;
	
	void InitDefaultCommand();
	
	void IntakeIdle();
	
	void IntakeIn();
	
	void IntakeOut();
	
	void              UpdateSmartDashboard();
	
	void              UpdateBallStateMachine();
	
	BallIntakeBallState  GetBallIntakeBallState();
	
	void              ResetBallState();
	void              DisableBallState();
	
	void 			  ResetTime();
	
	BallIntakeSubsystem();
};

#endif
