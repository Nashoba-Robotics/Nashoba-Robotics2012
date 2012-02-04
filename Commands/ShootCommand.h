#ifndef SHOOT_COMMAND_H
#define SHOOT_COMMAND_H

#include "../CommandBase.h"

class ShootCommand : public CommandBase
{
private:
public:
	ShootCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
#endif
