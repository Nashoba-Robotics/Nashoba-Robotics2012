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
#include "Commands/BallLoaderIdleCommand.h"
#include "Commands/BallLoaderLoadCommand.h"
#include "Commands/AlignFrontWithWallCommand.h"
#include "Commands/AlignBackWithWallCommand.h"
#include "Commands/DriveToCornerCommand.h"
#include "Subsystems/DriveSubsystem.h"
#include "WPIlib.h"
#include "CommandBasedRobot.h"


OperatorInput *OperatorInput::instance = NULL;

OperatorInput::OperatorInput() :driveStick(DRIVE_STICK_PORT), camStick(CAM_STICK_PORT)
{
	driveStickTriggerButton = new JoystickButton( &driveStick, 1 );
	driveStickTriggerButton->WhenPressed( new DriveDurationCommand(Preferences::GetInstance()->GetInt("duration"), 0.5, 0) );
	
	driveStickButtonTwo = new JoystickButton( &driveStick, 2 );
	driveStickButtonTwo->WhenPressed( new TopLiftReceiveContinuousCommand()  );
	
	driveStickButtonThree = new JoystickButton( &driveStick, 3 );
	driveStickButtonThree->WhenPressed( new IntakeIdleCommand() );
	
	driveStickButtonFour = new JoystickButton( &driveStick, 4 );
	driveStickButtonFour->WhenPressed( new IntakeRejectContinuousCommand() );
	
	driveStickButtonFive = new JoystickButton( &driveStick, 5 );
	driveStickButtonFive->WhenPressed( new IntakeReceiveContinuousCommand() );
	
	driveStickButtonSix = new JoystickButton( &driveStick, 6 );
	driveStickButtonSix->WhenPressed( new RightTurnCommand() );
	
	driveStickButtonSeven = new JoystickButton( &driveStick, 7 );
	driveStickButtonSeven->WhenPressed( new BottomLiftReceiveContinuousCommand() );
	
	driveStickButtonEight = new JoystickButton( &driveStick, 8 );
	driveStickButtonEight->WhenPressed( new BottomLiftRejectContinuousCommand() );
	
	driveStickButtonNine = new JoystickButton( &driveStick, 9 );
	driveStickButtonNine->WhenPressed( new BottomLiftIdleCommand() );
	
	driveStickButtonTen = new JoystickButton( &driveStick, 10 );
	driveStickButtonTen->WhenPressed( new TopLiftRejectContinuousCommand() );
	
	driveStickButtonEleven = new JoystickButton( &driveStick, 11 );
	driveStickButtonEleven->WhenPressed( new StraightThenRightTurnCommand());
	
	driveStickButtonTwelve = new JoystickButton( &driveStick, 12 );
	driveStickButtonTwelve->WhenPressed( new TopLiftIdleCommand() );
	
	camStickButtonSix = new JoystickButton( &camStick, 6 );
	camStickButtonSix->WhileHeld( new ShooterTakeShotCommand() );
	
	camStickButtonTen = new JoystickButton( &camStick, 10 );
	camStickButtonTen->WhileHeld( new TensionDecreaseCommand() );
	
	camStickButtonEleven = new JoystickButton( &camStick, 11 );
	camStickButtonEleven->WhileHeld( new TensionIncreaseCommand() );
	
}



OperatorInput& OperatorInput::getInstance()
{
	if (instance == NULL)
		instance = new OperatorInput();
	return *instance;	
}
