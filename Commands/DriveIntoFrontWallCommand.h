#ifndef DRIVE_INTO_FRONT_WALL_COMMAND_H
#define DRIVE_INTO_FRONT_WALL_COMMAND_H

#include "../CommandBase.h"

/**
 *
 * By Sam Kirschbaum 1/16/2012
 * 
 */

class DriveIntoFrontWallCommand: public CommandBase {
private:
	

public:
	DriveIntoFrontWallCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
