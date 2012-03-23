#ifndef TOP_RECEIVE_DURATION_COMMAND_H_
#define TOP_RECEIVE_DURATION_COMMAND_H_

#include "../CommandBase.h"


class TopReceiveDurationCommand : public CommandBase
{
private:
public:
	TopReceiveDurationCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
#endif
