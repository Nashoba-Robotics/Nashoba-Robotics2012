#ifndef SHOOTER_READY_SHOT_COMMAND_H
#define SHOOTER_READY_SHOT_COMMAND_H

#include "../CommandBase.h"
#include "../Subsystems/ShooterSubsystem.h"

class ShooterReadyShotCommand : public CommandBase
{
private:
	
public:
	ShooterReadyShotCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
#endif
