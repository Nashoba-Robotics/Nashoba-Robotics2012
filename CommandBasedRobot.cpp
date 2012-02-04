#include "CommandBasedRobot.h"


START_ROBOT_CLASS(CommandBasedRobot);

void CommandBasedRobot::RobotInit() 
	{
		CommandBase::init();
//		autonomousCommand = new ExampleCommand();
		NetworkTable::Initialize();
		SmartDashboard::GetInstance()->PutData(CommandBase::drivesubsystem);
//		SmartDashboard::GetInstance()->PutData(Scheduler::GetInstance());
//		SmartDashboard::GetInstance()->PutInt("Hello World",1768);
		OperatorInput::getInstance();
	}
	
	void CommandBasedRobot::AutonomousInit() 
	{
//		autonomousCommand->Start();
		GetWatchdog().SetEnabled( false );
	}
	
	void CommandBasedRobot::AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
	}
	
	void CommandBasedRobot::TeleopInit() 
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
//		autonomousCommand->Cancel();
		GetWatchdog().SetEnabled( false );
//		SmartDashboard::GetInstance()->PutData(Scheduler::GetInstance());
	}
	
	void CommandBasedRobot::TeleopPeriodic() {
	
//		GetWatchdog().Feed();
//		Scheduler::GetInstance()->Run();
//		SmartDashboard::GetInstance()->PutData(CommandBase::drivesubsystem);
//		SmartDashboard::GetInstance()->PutInt("Hello World",1768);
//		static int i=0;
//		SmartDashboard::GetInstance()->PutInt("Blair", i++);
//		SmartDashboard::GetInstance()->PutString("Sam", "1768");
//		SmartDashboard::GetInstance()->PutString("Brandon", "17234");
//		SmartDashboard::GetInstance()->PutString("Alex", "171238");
//		SmartDashboard::GetInstance()->PutString("Zach", "11234");
//		SmartDashboard::GetInstance()->PutString("Fordiani", "1723268");
//		SmartDashboard::GetInstance()->PutString("Carpenter", "1721134");
//		SmartDashboard::GetInstance()->PutString("Ethan", "1762238");
//		SmartDashboard::GetInstance()->PutString("Hamilton", "17222234");
//		SmartDashboard::GetInstance()->PutString("Bricknell", "1768342");
//		SmartDashboard::GetInstance()->PutString("Ursuliak", "17123234");
	}
	
	CommandBasedRobot::CommandBasedRobot()	
	{
		
	}
