#ifndef INTAKE_IDLE_COMMAND_H
#define INTAKE_IDLE_COMMAND_H

#include "../CommandBase.h"

class IntakeIdleCommand : public CommandBase
{
private:
public:
	IntakeIdleCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
