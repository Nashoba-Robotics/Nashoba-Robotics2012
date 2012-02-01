#ifndef BALLINTAKECOMMAND_H_
#define BALLINTAKECOMMAND_H_

#include "../CommandBase.h"
#include "../Subsystems/BallIntakeSubsystem.h"

class BallIntakeCommand : public CommandBase
{
private:
public:
	BallIntakeCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
