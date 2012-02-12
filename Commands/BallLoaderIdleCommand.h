#ifndef BALL_LOADER_IDLE_COMMAND_H
#define BALL_LOADER_IDLE_COMMAND_H

#include "../CommandBase.h"

class BallLoaderIdleCommand : public CommandBase
{
private:
public:
	BallLoaderIdleCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
