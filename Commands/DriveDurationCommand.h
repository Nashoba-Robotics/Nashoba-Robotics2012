#ifndef DRIVE_DURATION_COMMAND_H
#define DRIVE_DURATION_COMMAND_H

#include "../CommandBase.h"

/**
 *
 * By Sam Kirschbaum 1/16/2012
 * 
 */

class DriveDurationCommand: public CommandBase {
private:
	double m_duration;
	double m_bearingX;
	double m_bearingY;
public:
	DriveDurationCommand(double duration, double bearingX, double bearingY);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
