#ifndef BOTTOM_LIFT_REJECT_CONTINUOUS_COMMAND_H_
#define BOTTOM_LIFT_REJECT_CONTINUOUS_COMMAND_H_

#include "../CommandBase.h"

class BottomLiftRejectContinuousCommand : public CommandBase
{
public:
	BottomLiftRejectContinuousCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
