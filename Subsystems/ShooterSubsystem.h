#ifndef SHOOTER_SUBSYSTEM_H
#define SHOOTER_SUBSYSTEM_H

#include "WPILib.h"
#include "../OperatorInput.h"
#include "../HardwareSettings.h"

//This is the Shooter class of the robot. Controls the shooter. 

class ShooterSubsystem: public Subsystem
{
private:


public:
	virtual void load();
	virtual void shoot();
	virtual bool IsLoaded();
	ShooterSubsystem(
		
					  );
	
	void InitDefaultCommand();
};

#endif
