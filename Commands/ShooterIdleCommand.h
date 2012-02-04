#ifndef SHOOT_COMMAND_H
#define SHOOT_COMMAND_H

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
