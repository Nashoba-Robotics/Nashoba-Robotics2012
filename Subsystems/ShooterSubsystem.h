#ifndef SHOOTER_SUBSYSTEM_H
#define SHOOTER_SUBSYSTEM_H

#include "WPILib.h"
#include "Commands/PIDSubsystem.h"
#include "../OperatorInput.h"
#include "../HardwareSettings.h"

//This is the Shooter class of the robot. Controls the shooter. 

class ShooterSubsystem: public Subsystem
{
private:
public:
	void load();
	void shoot();
	void IsLoaded();
	ShooterSubsystem(
		
					  );
	
	void InitDefaultCommand();
};
#endif
