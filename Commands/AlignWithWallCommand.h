#ifndef ALIGN_WITH_WALL_COMMAND_H
#define ALIGN_WITH_WALL_COMMAND_H

#include "../CommandBase.h"

/**
 *
 * By Sam Kirschbaum 1/16/2012
 * 
 */

class AlignWithWallCommand: public CommandBase {
private:
	

public:
	AlignWithWallCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
