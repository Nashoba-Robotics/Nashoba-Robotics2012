#ifndef RESET_GYRO_COMMAND_H
#define RESET_GYRO_COMMAND_H

#include "../CommandBase.h"
#include "../Subsystems/DriveSubsystem.h"

class ResetGyroCommand : public CommandBase
{
private:
	
public:
	ResetGyroCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
#endif
