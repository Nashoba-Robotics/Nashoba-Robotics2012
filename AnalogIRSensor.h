#ifndef ANALOG_IR_SENSOR_H
#define ANALOG_IR_SENSOR_H

#include "WPILib.h"

class AnalogIRSensor: public AnalogChannel
{
public:
	AnalogIRSensor(UINT32 channel);
	float GetDistance();
private:
	
};





















#endif
