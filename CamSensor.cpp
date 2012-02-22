/*#include "CamSensor.h"

CamSensor::CamSensor(UINT32 channel) : AnalogChannel(channel)
{
	initialvoltage = 0;
	finalvoltage = 1;
	initialturns = 0;
	finalturns = 5;
}

float CamSensor::Rotations()
{

	float m = (finalvoltage - initialvoltage) / (finalturns - initialturns);
	float y = GetVoltage();
	float x = (y - initialturns) / m;
	return x;
}
*/
