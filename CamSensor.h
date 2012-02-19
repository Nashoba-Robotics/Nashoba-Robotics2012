#ifndef POTENTIOMETERSENSOR_H_
#define POTENTIOMETERSENSOR_H_

#include "WPILib.h"

class CamSensor : public AnalogChannel
{
public:
	CamSensor(UINT32 channel);
	float Rotations();
	static float initialvoltage;
	static float finalvoltage;
	static float initialturns;
	static float finalturns;
private:
};

#endif
