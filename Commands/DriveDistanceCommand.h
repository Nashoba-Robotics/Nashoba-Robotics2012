#ifndef DRIVE_DISTANCE_COMMAND_H
#define DRIVE_DISTANCE_COMMAND_H

#include "../CommandBase.h"

/**
 *
 * By Sam Kirschbaum 1/16/2012
 * 
 */

class DriveDistanceCommand: public CommandBase {
private:
	float m_distance;
	float m_bearingX;
	float m_bearingY;
public:
	DriveDistanceCommand(double distance, double bearingX, double bearingY);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
