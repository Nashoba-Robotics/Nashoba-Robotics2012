#ifndef DRIVE_SUBSYSTEM_H
#define DRIVE_SUBSYSTEM_H
#include "Commands/PIDSubsystem.h"
#include "../AnalogIRSensor.h"
#include "../UltraSonicRangeSensor.h"
#include "WPILib.h"

class DriveSubsystem: public Subsystem 
{
public:
	CANJaguar frontLeftJaguar; 
	CANJaguar frontRightJaguar;  
	CANJaguar backLeftJaguar;
	CANJaguar backRightJaguar;
	
	Gyro gyro;
	
private:
	RobotDrive myWPIdrive;
public:
	AnalogIRSensor shooterIRSensor;
	AnalogIRSensor leftFrontIRSensor;
	AnalogIRSensor leftBackIRSensor;
	AnalogIRSensor rightFrontIRSensor;
	AnalogIRSensor rightBackIRSensor;
	
	UltraSonicRangeSensor sonicRangeSensor;

	void drive(float x, float rotation, float z);
	void driveField(float x, float rotation, float z);
/*	void polarDrive (float magnitiude, float direction, float rotation);*/
	
	void initialize();
	
	void frontLeftJaguarDrive (float speed); 
	void frontRightJaguarDrive (float speed);
	void backLeftJaguarDrive (float speed);
	void backRightJaguarDrive (float speed);
	
	void UpdateSmartDashboard();
	
	DriveSubsystem();
	
	void InitDefaultCommand();
};

#endif
