#ifndef TOPLIFTCOMMAND_H_
#define TOPLIFTCOMMAND_H_

#include "../CommandBase.h"
#include "../Subsystems/TopLiftSubsystem.h"

class TopLiftCommand : public CommandBase
{
private:
public:
	TopLiftCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
