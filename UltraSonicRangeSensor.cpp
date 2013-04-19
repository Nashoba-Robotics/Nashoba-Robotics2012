#include "UltraSonicRangeSensor.h"
#include "math.h"


UltraSonicRangeSensor::UltraSonicRangeSensor(UINT32 channel):AnalogChannel(channel)
{
	factor = 0.5;
	offset = 5.0;	
}

float UltraSonicRangeSensor::GetDistance()
{
	return (offset + (GetVoltage() * factor));
};
