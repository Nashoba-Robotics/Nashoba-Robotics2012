#include "AnalogIRSensor.h"
#include "math.h"


AnalogIRSensor::AnalogIRSensor(UINT32 channel):AnalogChannel(channel){}

float AnalogIRSensor::GetDistance()
{
	float Voltage = GetVoltage();
	float Distance = 21.054 * pow((Voltage),(-0.9274));
	return Distance;
};


