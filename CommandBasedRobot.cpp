#include "CommandBasedRobot.h"
#include "Subsystems/DriveSubsystem.h"
#include "Commands/AutonomousCommand.h"
#include "CoprocessorVision.h"
#include "Commands/CancelAllCommand.h"

START_ROBOT_CLASS(CommandBasedRobot);

void CommandBasedRobot::RobotInit() 
	{
		CommandBase::init();
		autonomousCommand = new AutonomousCommand();
//		NetworkTable::Initialize();
//		SmartDashboard::GetInstance()->PutData(CommandBase::drivesubsystem);
//		SmartDashboard::GetInstance()->PutData(CommandBase::shootersubsystem);		
//		SmartDashboard::GetInstance()->PutData(CommandBase::ballintakesubsystem);
//		SmartDashboard::GetInstance()->PutData(CommandBase::topliftsubsystem);		
//		SmartDashboard::GetInstance()->PutData(CommandBase::bottomliftsubsystem);		
		
		
//		SmartDashboard::GetInstance()->PutData(Scheduler::GetInstance());
		OperatorInput::getInstance();
		coprocessorvisiontask = new Task ("Coprocessor", (FUNCPTR)CoprocessorVision::run);
		coprocessorvisiontask->Start();
	}
	
	void CommandBasedRobot::AutonomousInit() 
	{
		// this sequence causes InitDefaultCommand to be called on subsystems
		CommandBase::shootersubsystem->GetDefaultCommand();
		CommandBase::topliftsubsystem->GetDefaultCommand();
		CommandBase::bottomliftsubsystem->GetDefaultCommand();
		CommandBase::ballintakesubsystem->GetDefaultCommand();
		
		autonomousCommand->Start();
		GetWatchdog().SetEnabled( false );
	}
	
	void CommandBasedRobot::AutonomousPeriodic() {
		
		CommandBase::shootersubsystem->UpdateBallStateMachine();
		CommandBase::topliftsubsystem->UpdateBallStateMachine();
		CommandBase::bottomliftsubsystem->UpdateBallStateMachine();
		CommandBase::ballintakesubsystem->UpdateBallStateMachine();
		
		Scheduler::GetInstance()->Run();
	}
	
	void CommandBasedRobot::TeleopInit() 
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		// this sequence causes InitDefaultCommand to be called on subsystems
		CommandBase::shootersubsystem->GetDefaultCommand();
		CommandBase::topliftsubsystem->GetDefaultCommand();
		CommandBase::bottomliftsubsystem->GetDefaultCommand();
		CommandBase::ballintakesubsystem->GetDefaultCommand();
		
		// not entirely sure that we should do this...
		autonomousCommand->Cancel();
		
//		cancelAllCommand = new CancelAllCommand();
//		cancelAllCommand->Start();
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

#ifdef USE_SMART_DASHBOARD
		CommandBase::drivesubsystem->UpdateSmartDashboard();
		CommandBase::shootersubsystem->UpdateSmartDashboard();
		CommandBase::topliftsubsystem->UpdateSmartDashboard();
		CommandBase::bottomliftsubsystem->UpdateSmartDashboard();
		CommandBase::ballintakesubsystem->UpdateSmartDashboard();
#endif
		
		CommandBase::shootersubsystem->UpdateBallStateMachine();
		CommandBase::topliftsubsystem->UpdateBallStateMachine();
		CommandBase::bottomliftsubsystem->UpdateBallStateMachine();
		CommandBase::ballintakesubsystem->UpdateBallStateMachine();
		
		Scheduler::GetInstance()->Run();
	}
	
	CommandBasedRobot::CommandBasedRobot()	
	{
		
	}
