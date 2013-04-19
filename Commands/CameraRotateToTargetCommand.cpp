#include "CameraRotateToTargetCommand.h"
#include "../Debug.h"
#include "../Subsystems/DriveSubsystem.h"
#include <cmath>

CameraRotateToTargetCommand::CameraRotateToTargetCommand() :
CommandBase("CameraRotateToTargetCommand")
{
	Requires( CommandBase::drivesubsystem );
}

void CameraRotateToTargetCommand::Initialize()
{
	SetTimeout(5);
#ifdef _DEBUG
	printf ("CameraRotateToTargetCommand Initialized");
#endif
	ResetPrintCounter();
}

void CameraRotateToTargetCommand::Execute()
{	
	float rotate = 0;
	float magnitude = 0;
	cameraAngle = SmartDashboard::GetNumber("Angle");
	printf ("Getting Angle And Moving!");
	if (fabs(cameraAngle) > 5)
		magnitude = .3;
	else
		magnitude = .2;
	if (cameraAngle > 0)
		rotate = -(magnitude);
	else
		rotate = magnitude;
	CommandBase::drivesubsystem->drive (
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
	CommandBase::drivesubsystem->drive(
							0,
							0,
							0
							);
#ifdef _DEBUG
	printf ("CameraRotateToTargetCommand Finished!");
#endif
}

void CameraRotateToTargetCommand::Interrupted()
{
#ifdef _DEBUG
	printf ("CameraRotateToTargetCommand Interrupted!");
#endif
}
