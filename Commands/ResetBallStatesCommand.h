#ifndef RESET_BS_COMMAND_H
#define RESET_BS_COMMAND_H

#include "../CommandBase.h"
#include "../Subsystems/ShooterSubsystem.h"

class ResetBallStatesCommand : public CommandBase
{
private:
	
public:
	ResetBallStatesCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
#endif
