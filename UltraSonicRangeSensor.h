#ifndef ULTRA_SONIC_RANGE_SENSOR_H
#define ULTRA_SONIC_RANGE_SENOSR_H

#include "WPILib.h"

class UltraSonicRangeSensor: public AnalogChannel
{
public:
	UltraSonicRangeSensor(UINT32 channel);
	float GetDistance();
private:
	float offset;
	float factor;
};

#endif
