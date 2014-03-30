#include "CommandBasedRobot.h"
#include "Subsystems/DriveSubsystem.h"
#include "Commands/AutonomousCommand.h"
#include "CoprocessorVision.h"
#include "Commands/CancelAllCommand.h"
#include "Commands/CameraRotateToTargetCommand.h"

#include "SmartDashboard/SmartDashboard.h"

START_ROBOT_CLASS(CommandBasedRobot);

void CommandBasedRobot::RobotInit() 
	{
	//	SmartDashboard::init();
		CommandBase::init();

		autonomousCommand = new AutonomousCommand();
//		NetworkTable::Initialize();
//		SmartDashboard::PutData(CommandBase::drivesubsystem);
//		SmartDashboard::PutData(CommandBase::shootersubsystem);		
//		SmartDashboard::PutData(CommandBase::ballintakesubsystem);
//		SmartDashboard::PutData(CommandBase::topliftsubsystem);		
//		SmartDashboard::PutData(CommandBase::bottomliftsubsystem);		
		
		
//		SmartDashboard::PutData(Scheduler::GetInstance());
		
		Preferences::GetInstance()->PutDouble("_Test", .3);
		
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
//		SmartDashboard::PutData(Scheduler::GetInstance());
	}
	
	void CommandBasedRobot::TeleopPeriodic() {
	
		GetWatchdog().Feed();
//		SmartDashboard::PutData(CommandBase::drivesubsystem);
//		SmartDashboard::PutData(CommandBase::shootersubsystem);		
//		SmartDashboard::PutData(CommandBase::ballintakesubsystem);
//		SmartDashboard::PutData(CommandBase::topliftsubsystem);		
//		SmartDashboard::PutData(CommandBase::bottomliftsubsystem);		
//		SmartDashboard::PutData(CommandBase::ballloadersubsystem);
//		SmartDashboard::PutData(CommandBase::ramptippersubsystem);
//		SmartDashboard::PutNumber(drivesubsystem->gyro.GetAngle());
		
//		SmartDashboard::PutData(Scheduler::GetInstance());

#ifdef USE_SMART_DASHBOARD
		CommandBase::drivesubsystem->UpdateSmartDashboard();
		CommandBase::shootersubsystem->UpdateSmartDashboard();
		CommandBase::topliftsubsystem->UpdateSmartDashboard();
		CommandBase::bottomliftsubsystem->UpdateSmartDashboard();
		CommandBase::ballintakesubsystem->UpdateSmartDashboard();
		//CameraRotateToTargetCommand::drivesubsystem = CommandBase::drivesubsystem;
		
		SmartDashboard::PutNumber( "Front Left Jag Bus Voltage", CommandBase::drivesubsystem->frontLeftJaguar.GetBusVoltage());
		SmartDashboard::PutNumber( "Front Left Jag Output Voltage", CommandBase::drivesubsystem->frontLeftJaguar.GetOutputVoltage());
		SmartDashboard::PutNumber( "Front Left Jag Output Current", CommandBase::drivesubsystem->frontLeftJaguar.GetOutputCurrent());
		SmartDashboard::PutNumber( "Front Left Jag Temp", CommandBase::drivesubsystem->frontLeftJaguar.GetTemperature());
		SmartDashboard::PutNumber( "Front Left Jag Speed", CommandBase::drivesubsystem->frontLeftJaguar.GetSpeed());
		
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
