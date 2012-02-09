#ifndef JOYSTICK_DRIVE_COMMAND_H
#define JOYSTICK_DRIVE_COMMAND_H

#include "../CommandBase.h"

/**
 *
 * Written by Sam Kirschbaum 1/16/2012
 * 
 */

//Command to Drive with Joystick, inherits from CommandBase

class JoyStickDriveCommand: public CommandBase {
private:

public:
	JoyStickDriveCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
