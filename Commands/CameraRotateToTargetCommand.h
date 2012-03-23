#ifndef CAMERA_ROTATE_TO_TARGET_COMMAND_H
#define CAMERA_ROTATE_TO_TARGET_COMMAND_H

#include "../CommandBase.h"

class CameraRotateToTargetCommand : public CommandBase
{
private:
	float cameraAngle;
public:
	CameraRotateToTargetCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
#endif
