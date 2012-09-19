#define DRIVE_TO_TENSION_RANGE_COMMAND_H
#ifdef DRIVE_TO_TENSION_RANGE_COMMAND_H

#include "../CommandBase.h"

class DriveToTensionRangeCommand : public CommandBase
{
private:
	float tensionValue;
public:
	DriveToTensionRangeCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
#endif
