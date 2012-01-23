#ifndef COMMAND_BASED_ROBOT_H
#define COMMAND_BASED_ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
//#include "HardwareSettings.h"
#include "Commands/Scheduler.h"

class CommandBasedRobot : public IterativeRobot {
private:
	Command *autonomousCommand;

	virtual void RobotInit() 
	{
		CommandBase::init();
		autonomousCommand = new ExampleCommand();
//		NetworkTable::Initialize();
//		SmartDashboard::GetInstance()->PutData("SchedulerData", Scheduler::GetInstance());
//		SmartDashboard::GetInstance()->PutInt("Hello World",1768);
		
	}
	
	virtual void AutonomousInit() 
	{
		autonomousCommand->Start();
	}
	
	virtual void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TeleopInit() 
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		autonomousCommand->Cancel();
	}
	
	virtual void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();
	}
	
public:
	
	CommandBasedRobot()	
	{
		
	}
};



#endif

