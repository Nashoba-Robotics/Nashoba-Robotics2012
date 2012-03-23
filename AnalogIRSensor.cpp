#include "AnalogIRSensor.h"
#include "math.h"


AnalogIRSensor::AnalogIRSensor(UINT32 channel):AnalogChannel(channel){}

float AnalogIRSensor::GetDistance()
{
	float Voltage = GetVoltage();
	float Distance = (27.86 * pow((Voltage),(-1.15)) ) / 2.54;
	return Distance;
};


