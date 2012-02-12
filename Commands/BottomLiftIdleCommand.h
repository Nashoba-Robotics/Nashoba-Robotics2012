#ifndef BOTTOM_LIFT_IDLE_COMMAND_H
#define BOTTOM_LIFT_IDLE_COMMAND_H

#include "../CommandBase.h"

class BottomLiftIdleCommand : public CommandBase
{
private:
public:
	BottomLiftIdleCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
