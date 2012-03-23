#ifndef DRIVE_INTO_CORNER_CONTINUOUS_COMMAND_H
#define DRIVE_INTO_CORNER_CONTINUOUS_COMMAND_H

#include "../CommandBase.h"

/**
 *
 * By Sam Kirschbaum 1/16/2012
 * 
 */

class DriveIntoCornerContinuousCommand: public CommandBase {
private:
	

public:
	DriveIntoCornerContinuousCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
