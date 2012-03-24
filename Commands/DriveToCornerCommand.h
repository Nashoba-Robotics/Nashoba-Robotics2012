#ifndef DRIVE_TO_CORNER_COMMAND_H
#define DRIVE_TO_CORNER_COMMAND_H

#include "../CommandBase.h"

/**
 *
 * By Sam Kirschbaum 1/16/2012
 * 
 */

class DriveToCornerCommand: public CommandBase {
private:
	

public:
	DriveToCornerCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
