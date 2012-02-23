#include "CameraRotateToTargetCommand.h"
#include "../Debug.h"
#include "../Subsystems/DriveSubsystem.h"
#include <math.h>

CameraRotateToTargetCommand::CameraRotateToTargetCommand() : CommandBase("CameraRotateToTargetCommand")
{
	Requires( drivesubsystem );
}

void CameraRotateToTargetCommand::Initialize()
{
	printf ("CameraRotateToTargetCommand Initialized");
	ResetPrintCounter();
}

void CameraRotateToTargetCommand::Execute()
{	
	float rotate = 0;
	float magnitude = 0;
	cameraAngle = SmartDashboard::GetInstance()->GetDouble("Angle");
	if (fabs(cameraAngle) > 5)
		magnitude = .6;
	else
		magnitude = .5;
	if (cameraAngle > 0)
		rotate = -(magnitude);
	else
		rotate = magnitude;
	drivesubsystem->drive (
						0,
						0,
						rotate
							   );
}

bool CameraRotateToTargetCommand::IsFinished()
{
	if(cameraAngle < .3 && cameraAngle > -.3)
		return true;
	return false;
}

void CameraRotateToTargetCommand::End()
{
	drivesubsystem->drive(
							0,
							0,
							0
							);
	printf ("CameraRotateToTargetCommand Finished!");
}

void CameraRotateToTargetCommand::Interrupted()
{
	printf ("CameraRotateToTargetCommand Interrupted!");
}
