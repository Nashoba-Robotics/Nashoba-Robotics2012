#ifndef DRIVE_FORWARD_AUTO_COMMAND_H
#define DRIVE_FORWARD_AUTO_COMMAND_H

#include "../CommandBase.h"

class DriveForwardAutoCommand: public CommandBase {
private:
	
public:
	DriveForwardAutoCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
