#include "AnalogIRSensor.h"
#include <cmath>


AnalogIRSensor::AnalogIRSensor(UINT32 channel):AnalogChannel(channel){}

double AnalogIRSensor::GetDistance()
{
	double Voltage = GetVoltage();
	double Distance = (27.86 * pow((Voltage),(-1.15)) ) / 2.54;
	return Distance;
};


