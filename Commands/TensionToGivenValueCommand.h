#ifndef TENTION_TO_GIVEN_VALUE_COMMAND_H
#define TENTION_TO_GIVEN_VALUE_COMMAND_H

#include "../CommandBase.h"

class TensionToGivenValueCommand : public CommandBase
{
private:
	float cameraAngle;
	float currentTension;
	float tensionValue;
public:
	TensionToGivenValueCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
#endif
