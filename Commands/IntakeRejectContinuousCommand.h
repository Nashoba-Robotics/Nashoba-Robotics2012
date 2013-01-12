#ifndef INTAKE_REJECT_CONTINUOUS_COMMAND_H
#define INTAKE_REJECT_CONTINUOUS_COMMAND_H

#include "../CommandBase.h"
#include "../Subsystems/BallIntakeSubsystem.h"

class IntakeRejectContinuousCommand : public CommandBase
{
private:
public:
	IntakeRejectContinuousCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
