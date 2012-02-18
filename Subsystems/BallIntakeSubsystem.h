#ifndef BALL_INTAKE_SUBSYSTEM_H
#define BALL_INTAKE_SUBSYSTEM_H
#include "WPILib.h"
#include "../BallSensor.h"




class BallIntakeSubsystem: public Subsystem 
{
private:
Victor BallIntakeVictor;

public:

	BallSensor IntakeBallSensor;
	
	void InitDefaultCommand();
	
	void IntakeIdle();
	
	void IntakeIn();
	
	void IntakeOut();
	
	BallIntakeSubsystem();
};

#endif
