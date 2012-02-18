#include "CommandBasedRobot.h"
#include "Subsystems/DriveSubsystem.h"

START_ROBOT_CLASS(CommandBasedRobot);

void CommandBasedRobot::RobotInit() 
	{
		CommandBase::init();
//		autonomousCommand = new ExampleCommand();
//		NetworkTable::Initialize();
//		SmartDashboard::GetInstance()->PutData(CommandBase::drivesubsystem);
//		SmartDashboard::GetInstance()->PutData(CommandBase::shootersubsystem);		
//		SmartDashboard::GetInstance()->PutData(CommandBase::ballintakesubsystem);
//		SmartDashboard::GetInstance()->PutData(CommandBase::topliftsubsystem);		
//		SmartDashboard::GetInstance()->PutData(CommandBase::bottomliftsubsystem);		

		
//		SmartDashboard::GetInstance()->PutData(Scheduler::GetInstance());
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
	
		GetWatchdog().Feed();
//		SmartDashboard::GetInstance()->PutData(CommandBase::drivesubsystem);
//		SmartDashboard::GetInstance()->PutData(CommandBase::shootersubsystem);		
//		SmartDashboard::GetInstance()->PutData(CommandBase::ballintakesubsystem);
//		SmartDashboard::GetInstance()->PutData(CommandBase::topliftsubsystem);		
//		SmartDashboard::GetInstance()->PutData(CommandBase::bottomliftsubsystem);		
//		SmartDashboard::GetInstance()->PutData(CommandBase::ballloadersubsystem);
//		SmartDashboard::GetInstance()->PutData(CommandBase::ramptippersubsystem);
//		SmartDashboard::GetInstance()->PutDouble(drivesubsystem->gyro.GetAngle());
		
//		SmartDashboard::GetInstance()->PutData(Scheduler::GetInstance());
		Scheduler::GetInstance()->Run();
	}
	
	CommandBasedRobot::CommandBasedRobot()	
	{
		
	}
