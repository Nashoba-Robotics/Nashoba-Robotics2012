#ifndef RESET_CAM_COMMAND_H
#define RESET_CAM_COMMAND_H

#include "../CommandBase.h"
#include "../Subsystems/ShooterSubsystem.h"

class ResetCamCommand : public CommandBase
{
private:
	
public:
	ResetCamCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
#endif
