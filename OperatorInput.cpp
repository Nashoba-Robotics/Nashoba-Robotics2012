<<<<<<< HEAD
#include "OperatorInput.h"
#include "Commands/DriveForwardAutoCommand.h"

OperatorInput OperatorInput::instance;

OperatorInput::OperatorInput() :driveStick(DRIVE_STICK_PORT)
{
	driveStraight = new JoystickButton( &driveStick, Joystick::kTriggerButton );
	driveStraight->WhenPressed( new DriveForwardAutoCommand() );
}
=======
#include "OperatorInput.h"
#include "Commands/DriveForwardAutoCommand.h"

OperatorInput OperatorInput::instance;

OperatorInput::OperatorInput() :driveStick(DRIVE_STICK_PORT)
{
	driveStraight = new JoystickButton( &driveStick, 7 );
	driveStraight->WhenPressed( new DriveForwardAutoCommand );
}
>>>>>>> origin/brandon
