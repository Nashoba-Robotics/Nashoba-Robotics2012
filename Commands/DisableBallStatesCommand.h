
#ifndef DISABLE_BS_COMMAND_H
#define DISABLE_BS_COMMAND_H

#include "../CommandBase.h"

class DisableBallStatesCommand : public CommandBase
{
private:
	
public:
	DisableBallStatesCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
#endif
