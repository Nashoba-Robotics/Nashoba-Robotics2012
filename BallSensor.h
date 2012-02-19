#ifndef BALL_SENSOR_H
#define BALL_SENSOR_H

#include "WPILib.h"

class BallSensor: public AnalogChannel
{
public:
	BallSensor(UINT8 module, UINT32 channel);
	bool IsBallThere();
private:
	
};





















#endif
