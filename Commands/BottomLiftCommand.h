#ifndef BOTTOMLIFTCOMMAND_H_
#define BOTTOMLIFTCOMMAND_H_

#include "../CommandBase.h"
#include "../Subsystems/BottomLiftSubsystem.h"

class BottomLiftCommand : public CommandBase
{
private:
public:
	BottomLiftCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
#endif
