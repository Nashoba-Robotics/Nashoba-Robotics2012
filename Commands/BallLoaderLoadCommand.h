#ifndef BALL_LOADER_LOAD_COMMAND_H
#define BALL_LOADER_LOAD_COMMAND_H

#include "../CommandBase.h"

class BallLoaderLoadCommand : public CommandBase
{
private:
public:
	BallLoaderLoadCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
