#ifndef CAMERA_ROTATE_TO_TARGET_COMMAND_H
#define CAMERA_ROTATE_TO_TARGET_COMMAND_H

#include "../CommandBase.h"
#include "WPILib.h"

class CameraRotateToTargetCommand : public PIDCommand
{
private:
	float cameraAngle;
	int within_tolerance;
	Timer timer;

public:
	CameraRotateToTargetCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	
	virtual NetworkTable* GetTable();
	inline double ReturnPIDInput();
	
	void UsePIDOutput(double output);
	
	static DriveSubsystem *drivesubsystem;
};
#endif
