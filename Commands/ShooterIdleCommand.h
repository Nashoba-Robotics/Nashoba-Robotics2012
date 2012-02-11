#ifndef SHOOTER_IDLE_COMMAND_H
#define SHOOTER_IDLE_COMMAND_H

#include "../CommandBase.h"

class ShooterIdleCommand : public CommandBase
{
private:

public:
	ShooterIdleCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
#endif
