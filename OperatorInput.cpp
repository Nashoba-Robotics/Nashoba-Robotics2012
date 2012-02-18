#include "OperatorInput.h"
#include "HardwareSettings.h"
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
#include "Subsystems/DriveSubsystem.h"
#include "WPIlib.h"
#include "CommandBasedRobot.h"


OperatorInput *OperatorInput::instance = NULL;

OperatorInput::OperatorInput() :driveStick(DRIVE_STICK_PORT), camStick(CAM_STICK_PORT)
{
	driveStickTriggerButton = new JoystickButton( &driveStick, 1 );
	driveStickTriggerButton->WhenPressed( new JoyStickDriveCommand() );
	
	driveStickButtonTwo = new JoystickButton( &driveStick, 2 );
	driveStickButtonTwo->WhenPressed( new IntakeReceiveContinuousCommand());
	
	driveStickButtonThree = new JoystickButton( &driveStick, 3 );
	driveStickButtonThree->WhenPressed( new IntakeIdleCommand() );
	
	driveStickButtonFour = new JoystickButton( &driveStick, 4 );
	driveStickButtonFour->WhenPressed( new IntakeRejectContinuousCommand() );
	
	driveStickButtonFive = new JoystickButton( &driveStick, 5 );
	driveStickButtonFive->WhenPressed( new TopLiftReceiveContinuousCommand() );
	
	driveStickButtonSix = new JoystickButton( &driveStick, 6 );
	driveStickButtonSix->WhenPressed( new TopLiftIdleCommand()  );
	
	driveStickButtonSeven = new JoystickButton( &driveStick, 7 );
	driveStickButtonSeven->WhenPressed( new BottomLiftReceiveContinuousCommand() );
	
	driveStickButtonEight = new JoystickButton( &driveStick, 8 );
	driveStickButtonEight->WhenPressed( new BottomLiftIdleCommand() );
	
	driveStickButtonNine = new JoystickButton( &driveStick, 9 );
	driveStickButtonNine->WhenPressed( new BottomLiftRejectContinuousCommand() );
	
	driveStickButtonTen = new JoystickButton( &driveStick, 10 );
	driveStickButtonTen->WhenPressed( new AlignBackWithWallCommand() );
	
	driveStickButtonEleven = new JoystickButton( &driveStick, 11 );
	driveStickButtonEleven->WhenPressed( new AlignFrontWithWallCommand() );
	
	driveStickButtonTwelve = new JoystickButton( &driveStick, 12 );
	driveStickButtonTwelve->WhenPressed( new DriveToCornerCommand () );
	
	
	camStickButtonThree = new JoystickButton( &camStick, 3 );
	camStickButtonThree->WhenPressed( new AllReceiveCommand() );
	
	camStickButtonFour = new JoystickButton( &camStick, 4 );
	camStickButtonFour->WhenPressed( new AllIdleCommand() );
	
	camStickButtonFive = new JoystickButton( &camStick, 5 );
	camStickButtonFive->WhenPressed( new AllRejectCommand() );
	
	camStickButtonSix = new JoystickButton( &camStick, 6 );
	camStickButtonSix->WhenPressed( new ShooterTakeShotCommand() );
	
	camStickButtonSeven = new JoystickButton( &camStick, 7 );
	camStickButtonSeven->WhileHeld( new ShooterReadyShotCommand() );
	
	camStickButtonTen = new JoystickButton( &camStick, 10 );
	camStickButtonTen->WhileHeld( new TensionDecreaseCommand() );
	
	camStickButtonEleven = new JoystickButton( &camStick, 11 );
	camStickButtonEleven->WhileHeld( new TensionIncreaseCommand() );
	
	camStickButtonTwo = new JoystickButton (&camStick, 2 );
	camStickButtonTwo->WhenPressed( new DriveDurationCommand(1.5, 0.5, 0) );
	
	camStickButtonEight = new JoystickButton (&camStick, 8);
	camStickButtonEight->WhenPressed( new DriveDurationCommand(1.5, 0, 0.5 ) );
	
	camStickButtonNine = new JoystickButton (&camStick, 9);
	camStickButtonNine->WhenPressed( new DriveDurationCommand(1.5, 0.5, 0.5) );
	
}



OperatorInput& OperatorInput::getInstance()
{
	if (instance == NULL)
		instance = new OperatorInput();
	return *instance;	
}
