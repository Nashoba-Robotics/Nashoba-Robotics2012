#ifndef TOP_LIFT_REJECT_CONTINUOUS_COMMAND_H_
#define TOP_LIFT_REJECT_CONTINUOUS_COMMAND_H_

#include "../CommandBase.h"

class TopLiftRejectContinuousCommand : public CommandBase
{
public:
	TopLiftRejectContinuousCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
