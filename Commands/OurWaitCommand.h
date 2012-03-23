#ifndef OUR_WAIT_COMMAND_H
#define OUR_WAIT_COMMAND_H

#include "../CommandBase.h"

/**
 *
 * By Sam Kirschbaum 1/16/2012
 * 
 */

class OurWaitCommand: public CommandBase {
private:
	float m_duration;
public:
	OurWaitCommand(double duration);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
