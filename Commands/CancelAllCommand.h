#ifndef CANCEL_ALL_COMMAND_H
#define CANCEL_ALL_COMMAND_H

#include "../CommandBase.h"


class CancelAllCommand: public CommandBase {
private:
	

public:
	CancelAllCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
