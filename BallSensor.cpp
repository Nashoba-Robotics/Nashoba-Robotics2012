#include "BallSensor.h"

BallSensor::BallSensor(UINT8 module, UINT32 channel):AnalogChannel(module, channel){}

bool BallSensor::IsBallThere()
{
	float Voltage = GetVoltage();
	if( Voltage > 3)
	{
		return false;
	}
	else
	{
		return true;
	}
	
};


