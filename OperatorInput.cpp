#include "OperatorInput.h"
#include "HardwareSettings.h"
#include "Commands/DriveForwardAutoCommand.h"
#include "Commands/RightTurnCommand.h"

OperatorInput OperatorInput::instance;

OperatorInput::OperatorInput() :driveStick(DRIVE_STICK_PORT)
{
<<<<<<< HEAD
	driveStraight = new JoystickButton( &driveStick, 7 );
	driveStraight->WhenPressed( new DriveForwardAutoCommand );
=======
	driveStickTriggerButton = new JoystickButton( &driveStick, 1 );
	driveStickTriggerButton->WhenPressed( new DriveForwardAutoCommand() );
	
	driveStickButtonTwo = new JoystickButton( &driveStick, 2 );
	driveStickButtonTwo->WhenPressed( new PrintCommand("Drive Stick Button Pressed: 2\n ") );
	
	driveStickButtonThree = new JoystickButton( &driveStick, 3 );
	driveStickButtonThree->WhenPressed( new PrintCommand("Drive Stick Button Pressed: 3\n ") );
	
	driveStickButtonFour = new JoystickButton( &driveStick, 4 );
	driveStickButtonFour->WhenPressed( new PrintCommand("Drive Stick Button Pressed: 4\n ") );
	
	driveStickButtonFive = new JoystickButton( &driveStick, 5 );
	driveStickButtonFive->WhenPressed( new PrintCommand("Drive Stick Button Pressed: 5\n ") );
	
	driveStickButtonSix = new JoystickButton( &driveStick, 6 );
	driveStickButtonSix->WhenPressed( new RightTurnCommand() );
	
	driveStickButtonSeven = new JoystickButton( &driveStick, 7 );
	driveStickButtonSeven->WhenPressed( new PrintCommand("Drive Stick Button Pressed: 7\n ") );
	
	driveStickButtonEight = new JoystickButton( &driveStick, 8 );
	driveStickButtonEight->WhenPressed( new PrintCommand("Drive Stick Button Pressed: 8\n ") );
	
	driveStickButtonNine = new JoystickButton( &driveStick, 9 );
	driveStickButtonNine->WhenPressed( new PrintCommand("Drive Stick Button Pressed: 9\n ") );
	
	driveStickButtonTen = new JoystickButton( &driveStick, 10 );
	driveStickButtonTen->WhenPressed( new PrintCommand("Drive Stick Button Pressed: 10\n ") );
	
	driveStickButtonEleven = new JoystickButton( &driveStick, 11 );
	driveStickButtonEleven->WhenPressed( new PrintCommand("Drive Stick Button Pressed: 11\n ") );
	
	driveStickButtonTwelve = new JoystickButton( &driveStick, 12 );
	driveStickButtonTwelve->WhenPressed( new PrintCommand("Drive Stick Button Pressed: 12\n ") );
>>>>>>> sam
}

