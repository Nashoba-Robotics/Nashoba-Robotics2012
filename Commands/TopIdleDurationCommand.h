#ifndef TOP_IDLE_DURATION_COMMAND_H
#define TOP_IDLE_DURATION_COMMAND_H

#include "../CommandBase.h"

class TopIdleDurationCommand : public CommandBase
{
private:
public:
	TopIdleDurationCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
