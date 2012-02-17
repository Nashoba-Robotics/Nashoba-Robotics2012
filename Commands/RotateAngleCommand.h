#ifndef ROTATEANGLECOMMAND_H_
#define ROTATEANGLECOMMAND_H_

#include "WPILib.h"
#include "../CommandBase.h"

class RotateAngleCommand : public CommandBase
{
public:
	RotateAngleCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
