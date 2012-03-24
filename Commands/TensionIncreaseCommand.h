#ifndef TENSION_INCREASE_COMMAND_H
#define TENSION_INCREASE_COMMAND_H

#include "../CommandBase.h"
#include "../Subsystems/ShooterSubsystem.h"

class TensionIncreaseCommand : public CommandBase
{
private:
public:
	TensionIncreaseCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
#endif
