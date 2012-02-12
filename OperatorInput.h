#ifndef OPERATORINPUT_H
#define OPERATORINPUT_H

#include "WPILib.h"


#define SNAP_TO_VALUE( snapValue, plusMinus, actualValue ) ( (((actualValue) > ((snapValue)-(plusMinus))) && ( (actualValue) < ((snapValue)+(plusMinus))))  ? (snapValue) : (actualValue) )

//! The operator input class 
class OperatorInput 
{
private:
	static OperatorInput *instance;
	Joystick driveStick;
	Joystick camStick;
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
	JoystickButton *camStickButtonSix;
	JoystickButton *camStickButtonTen;
	JoystickButton *camStickButtonEleven;

public:
	static OperatorInput& getInstance();

	OperatorInput();
	
	Joystick& getDriveStick()
	{
		return driveStick;
	}
	
	Joystick& getCamStick()
	{
		return camStick;
	}
};

#endif
