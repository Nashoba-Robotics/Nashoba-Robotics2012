#ifndef TOP_LIFT_RECEIVE_CONTINUOUS_COMMAND_H_
#define TOP_LIFT_RECEIVE_CONTINUOUS_COMMAND_H_

#include "../CommandBase.h"

class TopLiftReceiveContinuousCommand : public CommandBase
{
private:
public:
	TopLiftReceiveContinuousCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
#endif
