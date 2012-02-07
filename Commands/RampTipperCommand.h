#ifndef RAMPTIPPERCOMMAND_H_
#define RAMPTIPPERCOMMAND_H_

#include "../CommandBase.h"
#include "../Subsystems/RampTipperSubsystem.h"

class RampTipperCommand : public CommandBase
{
private:
public:
	RampTipperCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
#endif
