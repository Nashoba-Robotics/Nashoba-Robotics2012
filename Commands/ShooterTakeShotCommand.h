#ifndef SHOOTER_TAKE_SHOT_COMMAND_H
#define SHOOTER_TAKE_SHOT_COMMAND_H

#include "../CommandBase.h"
#include "../Subsystems/ShooterSubsystem.h"

class ShooterTakeShotCommand : public CommandBase
{
private:
public:
	ShooterTakeShotCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
#endif
