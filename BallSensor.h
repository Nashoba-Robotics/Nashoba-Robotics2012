#ifndef BALL_SENSOR_H
#define BALL_SENSOR_H

#include "WPILib.h"

class BallSensor: public AnalogChannel
{
public:
	BallSensor(UINT8 module, UINT32 channel);
	bool IsBallThere();
private:
	// make this private so no one can create one without module and channel
	BallSensor();
};





















#endif
