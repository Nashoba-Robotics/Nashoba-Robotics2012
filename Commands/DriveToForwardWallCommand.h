#ifndef DRIVE_TO_FORWARD_WALL_COMMAND_H
#define DRIVE_TO_FORWARD_WALL_COMMAND_H

#include "../CommandBase.h"

/**
 *
 * By Sam Kirschbaum 1/16/2012
 * 
 */

class DriveToForwardWallCommand: public CommandBase {
private:
	

public:
	DriveToForwardWallCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
