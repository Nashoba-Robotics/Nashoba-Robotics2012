#ifndef BOTTOM_LIFT_RECEIVE_CONTINUOUS_COMMAND_H_
#define BOTTOM_LIFT_RECEIVE_CONTINUOUS_COMMAND_H_

#include "../CommandBase.h"

class BottomLiftReceiveContinuousCommand : public CommandBase
{
private:
public:
	BottomLiftReceiveContinuousCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
#endif
