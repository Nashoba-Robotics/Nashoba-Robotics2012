#ifndef TENSION_DECREASE_COMMAND_H
#define TENSION_DECREASE_COMMAND_H

#include "../CommandBase.h"
#include "../Subsystems/ShooterSubsystem.h"

class TensionDecreaseCommand : public CommandBase
{
private:
public:
	TensionDecreaseCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
#endif
