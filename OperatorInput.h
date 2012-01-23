#ifndef OPERATORINPUT_H
#define OPERATORINPUT_H

#include "WPILib.h"
#include "HardwareSettings.h"




//! The operator input class 
class OperatorInput 
{
private:
	static OperatorInput instance;
	Joystick driveStick;
	JoystickButton *driveStraight;

public:
	static OperatorInput& getInstance()
	{
		return instance;	
	}
	OperatorInput();
	
	Joystick& getDriveStick()
	{
		return driveStick;
	}
};

#endif
