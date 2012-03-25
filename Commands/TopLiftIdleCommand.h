#ifndef TOP_LIFT_IDLE_COMMAND_H
#define TOP_LIFT_IDLE_COMMAND_H

#include "../CommandBase.h"

class TopLiftIdleCommand : public CommandBase
{
private:
public:
	TopLiftIdleCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
