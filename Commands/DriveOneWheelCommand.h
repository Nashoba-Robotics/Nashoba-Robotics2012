#ifndef DRIVE_ONE_WHEEL_COMMAND_H
#define DRIVE_ONE_WHEEL_COMMAND_H

#include "../CommandBase.h"

/**
 *
 * By Sam Kirschbaum 1/18/2012
 * 
 */
class DriveOneWheelCommand: public CommandBase {
public:
	DriveOneWheelCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
