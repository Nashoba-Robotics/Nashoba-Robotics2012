#include "AddParallelTestingCommand.h"

#include "DriveForwardAutoCommand.h"
#include "PrintfOneSecInterval.h"

AddParallelTestingCommand::AddParallelTestingCommand() : CommandGroup("AddParallelTestingCommand")
{
	AddParallel( new DriveForwardAutoCommand() );
	AddParallel( new PrintfOneSecInterval() );
}
