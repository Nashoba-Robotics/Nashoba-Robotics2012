#include "OperatorInput.h"
#include "HardwareSettings.h"
#include "Commands/DriveToForwardWallCommand.h"
#include "Commands/TensionToGivenValueCommand.h"
#include "Commands/TensionToBankShotCommand.h"
#include "Commands/DriveIntoFrontWallCommand.h"
#include "Commands/CameraRotateToTargetCommand.h"
#include "Commands/ShooterReadyShotCommand.h"
#include "Commands/ShooterTakeShotCommand.h"
#include "Commands/ShooterIdleCommand.h"
#include "Commands/DriveDurationCommand.h"
#include "Commands/RightTurnCommand.h"
#include "Commands/StraightThenRightTurnCommand.h"
#include "Commands/IntakeIdleCommand.h"
#include "Commands/IntakeReceiveContinuousCommand.h"
#include "Commands/IntakeRejectContinuousCommand.h"
#include "Commands/TensionIncreaseCommand.h"
#include "Commands/TensionDecreaseCommand.h"
#include "Commands/TopLiftReceiveContinuousCommand.h"
#include "Commands/TopLiftRejectContinuousCommand.h"
#include "Commands/TopLiftIdleCommand.h"
#include "Commands/BottomLiftIdleCommand.h"
#include "Commands/BottomLiftReceiveContinuousCommand.h"
#include "Commands/BottomLiftRejectContinuousCommand.h"
#include "Commands/AlignFrontWithWallCommand.h"
#include "Commands/AlignBackWithWallCommand.h"
#include "Commands/DriveToCornerCommand.h"
#include "Commands/JoyStickDriveCommand.h"
#include "Commands/AllReceiveCommand.h"
#include "Commands/AllIdleCommand.h"
#include "Commands/AllRejectCommand.h"
#include "Commands/ResetCamCommand.h"
#include "Commands/ResetGyroCommand.h"
#include "Subsystems/DriveSubsystem.h"
#include "Commands/ResetBallStatesCommand.h"
#include "Commands/DisableBallStatesCommand.h"
#include "Commands/DriveIntoSideWallCommand.h"
#include "Commands/DriveIntoCornerContinuousCommand.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/ShootWithTensionerAndCameraValuesCommand.h"
#include "Commands/DriveToTensionRangeCommand.h"
#include "Commands/CancelAllCommand.h"
#include "WPIlib.h"
#include "CommandBasedRobot.h"
#define USE_SMART_DASHBOARD 1

OperatorInput *OperatorInput::instance = NULL;

OperatorInput::OperatorInput() : stickOne(DRIVE_STICK_PORT), stickTwo(CAM_STICK_PORT), stickThree(DASH_BOARD_PORT)
{
	stickOneTriggerButton = new JoystickButton( &stickOne, 1 );
	stickOneTriggerButton->WhenPressed( new JoyStickDriveCommand() );
	
	stickOneButtonTwo = new JoystickButton( &stickOne, 2 );
	stickOneButtonTwo->WhenPressed( new IntakeReceiveContinuousCommand());
	
	stickOneButtonThree = new JoystickButton( &stickOne, 3 );
	stickOneButtonThree->WhenPressed( new IntakeIdleCommand() );
	
	stickOneButtonFour = new JoystickButton( &stickOne, 4 );
	stickOneButtonFour->WhenPressed( new IntakeRejectContinuousCommand() );
	
	stickOneButtonFive = new JoystickButton( &stickOne, 5 );
	stickOneButtonFive->WhenPressed( new TopLiftReceiveContinuousCommand() );
	
	stickOneButtonSix = new JoystickButton( &stickOne, 6 );
	stickOneButtonSix->WhenPressed( new TopLiftIdleCommand()  );
	
	stickOneButtonSeven = new JoystickButton( &stickOne, 7 );
	stickOneButtonSeven->WhenPressed( new BottomLiftReceiveContinuousCommand() );
	
	stickOneButtonEight = new JoystickButton( &stickOne, 8 );
	stickOneButtonEight->WhenPressed( new BottomLiftIdleCommand() );
	
	stickOneButtonNine = new JoystickButton( &stickOne, 9 );
	stickOneButtonNine->WhenPressed( new BottomLiftRejectContinuousCommand() );
	
	stickOneButtonTen = new JoystickButton( &stickOne, 10 );
	stickOneButtonTen->WhenPressed( new AlignBackWithWallCommand() );
	
	stickOneButtonEleven = new JoystickButton( &stickOne, 11 );
	stickOneButtonEleven->WhenPressed( new AlignFrontWithWallCommand() );
	
	stickOneButtonTwelve = new JoystickButton( &stickOne, 12 );
	stickOneButtonTwelve->WhenPressed( new DriveToCornerCommand () );
		
	stickTwoButtonTwo = new JoystickButton (&stickTwo, 2 );
	stickTwoButtonTwo->WhenPressed( new DriveDurationCommand(1.5, 0.5, 0) );
		
	stickTwoButtonThree = new JoystickButton( &stickTwo, 3 );
	stickTwoButtonThree->WhenPressed( new AllReceiveCommand() );
	
	stickTwoButtonFour = new JoystickButton( &stickTwo, 4 );
	stickTwoButtonFour->WhenPressed( new AllIdleCommand() );
	
	stickTwoButtonFive = new JoystickButton( &stickTwo, 5 );
	stickTwoButtonFive->WhenPressed( new AllRejectCommand() );
	
	stickTwoButtonFive = new JoystickButton( &stickTwo, 5 );
	stickTwoButtonFive->WhenPressed( new ResetCamCommand() );
		
	stickTwoButtonSix = new JoystickButton( &stickTwo, 6 );
	stickTwoButtonSix->WhenPressed( new ShooterTakeShotCommand() );
	
	stickTwoButtonSeven = new JoystickButton( &stickTwo, 7 );
	stickTwoButtonSeven->WhileHeld( new ShooterReadyShotCommand() );
	
	stickTwoButtonEight = new JoystickButton (&stickTwo, 8);
	stickTwoButtonEight->WhenPressed( new DriveDurationCommand(1.5, 0, 0.5 ) );
	
	stickTwoButtonNine = new JoystickButton (&stickTwo, 9);
	stickTwoButtonNine->WhileHeld( new TensionIncreaseCommand() );

	stickTwoButtonTen = new JoystickButton( &stickTwo, 10 );
	stickTwoButtonTen->WhileHeld( new TensionDecreaseCommand() );

	stickThreeTriggerButton = new JoystickButton (&stickThree, 1 );
	stickThreeTriggerButton->WhenPressed( new CancelAllCommand() );
	
	stickThreeButtonTwo = new JoystickButton (&stickThree, 2);
	stickThreeButtonTwo->WhenPressed( new AutonomousCommand() );
	
	stickThreeButtonSix = new JoystickButton( &stickThree, 6 );
	stickThreeButtonSix->WhenPressed( new CameraRotateToTargetCommand() );
	
	stickThreeButtonSeven = new JoystickButton( &stickThree, 7);
	stickThreeButtonSeven->WhenPressed( new ShootWithTensionerAndCameraValuesCommand() );
	
	stickThreeButtonEight = new JoystickButton( &stickThree, 8 );
	stickThreeButtonEight->WhenPressed( new TensionToGivenValueCommand() );
	
	stickThreeButtonNine = new JoystickButton( &stickThree, 9 );
	stickThreeButtonNine->WhenPressed( new TensionToBankShotCommand() );
	
	stickThreeButtonTen = new JoystickButton( &stickThree, 10 );
	stickThreeButtonTen->WhenPressed( new ResetBallStatesCommand() );
	
	stickThreeButtonEleven = new JoystickButton( &stickThree, 11 );
	stickThreeButtonEleven->WhenPressed( new AllRejectCommand() );



#ifdef USE_SMART_DASHBOARD
    resetCamButton = new InternalButton();
    resetCamButton->WhenPressed( new ResetCamCommand( ) );
    SmartDashboard::GetInstance()->PutData( "ResetCam", resetCamButton );
    
    resetGyroButton = new InternalButton();
    resetGyroButton->WhenPressed( new ResetGyroCommand( ) );
    SmartDashboard::GetInstance()->PutData( "ResetGyro", resetGyroButton );

    resetBallStatesButton = new InternalButton();
    resetBallStatesButton->WhenPressed( new ResetBallStatesCommand( ) );
    SmartDashboard::GetInstance()->PutData( "ResetBallStates", resetBallStatesButton );
    
    disableBallStatesButton = new InternalButton();
    disableBallStatesButton->WhenPressed( new DisableBallStatesCommand( ) );
    SmartDashboard::GetInstance()->PutData( "DisableBallStates", disableBallStatesButton );
 
    pukeBallsButton = new InternalButton();
    pukeBallsButton->WhenPressed( new AllRejectCommand( ) );
    SmartDashboard::GetInstance()->PutData( "PUKE", pukeBallsButton );
    
    driveToForwardWallButton = new InternalButton();
    driveToForwardWallButton->WhenPressed( new DriveToForwardWallCommand( ) );
    SmartDashboard::GetInstance()->PutData( "DriveToFowardWall", driveToForwardWallButton );
    
    driveIntoSideWallButton = new InternalButton();
    driveIntoSideWallButton->WhenPressed( new DriveIntoSideWallCommand( ) );
    SmartDashboard::GetInstance()->PutData( "DriveIntoSideWall", driveIntoSideWallButton );
    
    driveIntoFrontWallButton = new InternalButton();
    driveIntoFrontWallButton->WhenPressed( new DriveIntoFrontWallCommand( ) );
    SmartDashboard::GetInstance()->PutData( "DriveIntoFrontWall", driveIntoFrontWallButton );
    
    driveIntoCornerContinuousButton = new InternalButton();
    driveIntoCornerContinuousButton->WhenPressed( new DriveIntoCornerContinuousCommand( ) );
    SmartDashboard::GetInstance()->PutData( "DriveIntoCornerContinuous", driveIntoCornerContinuousButton );
   
    autonomousButton = new InternalButton();
    autonomousButton->WhenPressed( new AutonomousCommand() );
    SmartDashboard::GetInstance()->PutData( "AutonomousCommand", autonomousButton );
    
    cameraRotateToTargetButton = new InternalButton();
    cameraRotateToTargetButton->WhenPressed( new CameraRotateToTargetCommand() );
    SmartDashboard::GetInstance()->PutData( "CameraRotateToTargetCommand", cameraRotateToTargetButton );

    tensionToGivenValueButton = new InternalButton();
    tensionToGivenValueButton->WhenPressed( new TensionToGivenValueCommand() );
    SmartDashboard::GetInstance()->PutData( "TensionToGivenValueCommand", tensionToGivenValueButton );
    
    tensionToBankShotButton = new InternalButton();
    tensionToBankShotButton->WhenPressed( new TensionToBankShotCommand() );
    SmartDashboard::GetInstance()->PutData( "TensionBankShotCommand", tensionToBankShotButton );
    
    shootWithTensionerAndCameraValuesButton = new InternalButton();
    shootWithTensionerAndCameraValuesButton->WhenPressed( new ShootWithTensionerAndCameraValuesCommand() );
    SmartDashboard::GetInstance()->PutData( "ShootWithTensionerAndCameraValuesCommand", shootWithTensionerAndCameraValuesButton );

//    driveToTensionRangeButton = new InternalButton();
//    driveToTensionRangeButton->WhenPressed( new DriveToTensionRangeCommand() );
//    SmartDashboard::GetInstance()->PutData( "DriveToTensionRangeCommand", driveToTensionRangeButton );
#endif
    
}



OperatorInput& OperatorInput::getInstance()
{
	if (instance == NULL)
		instance = new OperatorInput();
	return *instance;	
}
