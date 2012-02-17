#ifndef COMMAND_BASED_ROBOT_H
#define COMMAND_BASED_ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Commands/Scheduler.h"

class CommandBasedRobot : public IterativeRobot {
private:
	//Command *autonomousCommand;
	
	virtual void RobotInit(); 

	virtual void AutonomousInit(); 

	virtual void AutonomousPeriodic();
	
	virtual void TeleopInit();
	
	virtual void TeleopPeriodic();
	
public:
	
	CommandBasedRobot();	
};

#endif

