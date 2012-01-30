#ifndef PRINTF_ONE_SEC_INTERVAL_H
#define PRINTF_ONE_SEC_INTERVAL_H

#include "../CommandBase.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class PrintfOneSecInterval: public CommandBase {
public:
	PrintfOneSecInterval();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
