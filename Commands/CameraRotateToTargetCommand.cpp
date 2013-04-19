#include "CameraRotateToTargetCommand.h"
#include "../Debug.h"
#include "../Subsystems/DriveSubsystem.h"
#include <cmath>
#include "Timer.h"

CameraRotateToTargetCommand::CameraRotateToTargetCommand() :
CommandBase("CameraRotateToTargetCommand")
{
	Requires( CommandBase::drivesubsystem );
}

inline double CameraRotateToTargetCommand::ReturnPIDInput()
{
	return SmartDashboard::GetNumber("Angle");
}

NetworkTable* CameraRotateToTargetCommand::GetTable()
{
	return GetTable();
};
void CameraRotateToTargetCommand::UsePIDOutput(double output)
{
	/*
	SmartDashboard::PutNumber("P", GetPIDController()->GetP());
	SmartDashboard::PutNumber("I", GetPIDController()->GetI());
	SmartDashboard::PutNumber("D", GetPIDController()->GetD());
	*/
	if( IsRunning() )
	{	
		drivesubsystem->drive (
							0,
							0,
							output
								  );
	}
}

void CameraRotateToTargetCommand::Initialize()
{
	//SmartDashboard::PutData("PID_Control", this->GetPIDController() );
	//SetTimeout(10);
	float Pref_p = Preferences::GetInstance()->GetDouble("P", .1);
	float Pref_i = Preferences::GetInstance()->GetDouble("I", 0.0);
	float Pref_d = Preferences::GetInstance()->GetDouble("D", 0.0);
	
	GetPIDController()->SetPID(Pref_p, Pref_i, Pref_d);
	
#ifndef _DEBUG
	printf ("CameraRotateToTargetCommand Initialized");
#endif
	//ResetPrintCounter();
	timer.Reset();
	timer.Start();
	within_tolerance = 0;
}

void CameraRotateToTargetCommand::Execute()
{	
/*	SmartDashboard::PutNumber("_Within_Tol", within_tolerance);
	
	float rotate = 0;
	float magnitude = 0;
	cameraAngle = SmartDashboard::GetNumber("Angle");
	printf ("Getting Angle And Moving!");
	if (fabs(cameraAngle) > 2)
		magnitude = .4;
	else
		magnitude = .3;
	
	magnitude = Preferences::GetInstance()->GetDouble("Magnitude", .5);
	
	if (cameraAngle > 0)
		rotate = -(magnitude);
	else
		rotate = magnitude;
	CommandBase::drivesubsystem->drive (
						0,
						0,
						rotate
							   );

	SmartDashboard::PutNumber("Clock: ", timer.Get()); */
}

bool CameraRotateToTargetCommand::IsFinished()
{
	double tolerance = Preferences::GetInstance()->GetDouble("Tolerance", .3);
	//SmartDashboard::PutNumber("_Tolerance", tolerance);
	if((cameraAngle < tolerance) && (cameraAngle > -tolerance))
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
	End();
#ifndef _DEBUG
	printf ("CameraRotateToTargetCommand Interrupted!");
#endif
}
