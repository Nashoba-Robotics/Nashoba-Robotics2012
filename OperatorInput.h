#ifndef OPERATORINPUT_H
#define OPERATORINPUT_H

#include "WPILib.h"




//! The operator input class 
class OperatorInput 
{
private:
	static OperatorInput *instance;
	Joystick driveStick;
	JoystickButton *driveStickTriggerButton;
	JoystickButton *driveStickdriveStickButtonTwo;
	JoystickButton *driveStickButtonTwo;
	JoystickButton *driveStickButtonThree;
	JoystickButton *driveStickButtonFour;
	JoystickButton *driveStickButtonFive;
	JoystickButton *driveStickButtonSix;
	JoystickButton *driveStickButtonSeven;
	JoystickButton *driveStickButtonEight;
	JoystickButton *driveStickButtonNine;
	JoystickButton *driveStickButtonTen;
	JoystickButton *driveStickButtonEleven;
	JoystickButton *driveStickButtonTwelve;
	

public:
	static OperatorInput& getInstance()
	{
		if (instance == NULL)
			instance = new OperatorInput();
		return *instance;	
	}
	OperatorInput();
	
	Joystick& getDriveStick()
	{
		return driveStick;
	}
};

#endif
