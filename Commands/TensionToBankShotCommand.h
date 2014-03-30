#ifndef TENTION_TO_BANK_SHOT_COMMAND_H
#define TENTION_TO_BANK_SHOT_COMMAND_H

#include "../CommandBase.h"

class TensionToBankShotCommand : public CommandBase
{
private:
	float cameraAngle;
	float currentTension;
	float tensionValue;
public:
	TensionToBankShotCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
#endif
