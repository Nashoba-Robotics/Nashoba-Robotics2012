#ifndef DRIVE_FORWARD_AUTO_COMMAND_H
#define DRIVE_FORWARD_AUTO_COMMAND_H

#include "../CommandBase.h"

/**
 *
 * By Sam Kirschbaum 1/16/2012
 * 
 */
class DriveForwardAutoCommand: public CommandBase {
public:
	DriveForwardAutoCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
