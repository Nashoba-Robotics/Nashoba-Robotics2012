#ifndef DRIVE_SUBSYSTEM_H
#define DRIVE_SUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/*
 *
 * Written by Sam and Brandon with Mr. Bricknell and Mr. Carpenter 1/14/2012
 *
 */

/// This is the drive class for the robot.
/*
 * The drive class requires four Jaguars upon construction. It implements the subsystem
 * interface as defined in the command-based robot.
 */
class DriveSubsystem: public Subsystem {
private:
	CANJaguar frontLeftJaguar; 
	CANJaguar frontRightJaguar;  
	CANJaguar backLeftJaguar;
	CANJaguar backRightJaguar;
	
	RobotDrive myWPIdrive;

public:
	void drive(float x, float rotation, float z);
	
	void frontLeftJaguarDrive (float speed); 
	void frontRightJaguarDrive (float speed);
	void backLeftJaguarDrive (float speed);
	void backRightJaguarDrive (float speed);
	
	DriveSubsystem( 
		   
		 	   	 );
	
	
	void InitDefaultCommand();
};

#endif