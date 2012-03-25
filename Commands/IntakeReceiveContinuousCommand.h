#ifndef INTAKE_RECEIVE_CONTINUOUS_COMMAND_H
#define INTAKE_RECEIVE_CONTINUOUS_COMMAND_H

#include "../CommandBase.h"
#include "../Subsystems/BallIntakeSubsystem.h"

class IntakeReceiveContinuousCommand : public CommandBase
{
private:
public:
	IntakeReceiveContinuousCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
