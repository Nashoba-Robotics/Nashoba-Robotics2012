#ifndef ALIGN_FRONT_WITH_WALL_COMMAND_H
#define ALIGN_FRONT_WITH_WALL_COMMAND_H

#include "../CommandBase.h"

/**
 *
 * By Sam Kirschbaum 1/16/2012
 * 
 */

class AlignFrontWithWallCommand: public CommandBase {
private:
	

public:
	AlignFrontWithWallCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
