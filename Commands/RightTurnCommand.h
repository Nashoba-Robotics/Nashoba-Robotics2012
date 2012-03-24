#ifndef RIGHT_TURN_COMMAND_H
#define RIGHT_TURN_COMMAND_H

#include "../CommandBase.h"

/**
 *
 * By Sam Kirschbaum 1/16/2012
 * 
 */

class RightTurnCommand: public CommandBase {
public:
	RightTurnCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
