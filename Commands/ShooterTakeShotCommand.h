#ifndef SHOOTER_TAKE_SHOT_COMMAND_H
#define SHOOTER_TAKE_SHOT_COMMAND_H

#include "../CommandBase.h"
#include "../Subsystems/ShooterSubsystem.h"

typedef enum {
	SHOT_STATE_UNKNOWN,
	SHOT_STATE_SLOW_START,
	SHOT_STATE_FAST_MIDDLE,
	SHOT_STATE_SLOW_FINISH,
	SHOT_STATE_READY
} ShotState;

class ShooterTakeShotCommand : public CommandBase
{
private:
	double    speedUpPoint;
	double    endingPoint;
	double    currentPoint;
	float     speed;
	ShotState shotState;
public:
	ShooterTakeShotCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
#endif
