#include "AllIdleCommand.h"

#include "BottomLiftIdleCommand.h"
#include "TopLiftIdleCommand.h"
#include "IntakeIdleCommand.h"

AllIdleCommand::AllIdleCommand() : CommandGroup("AllIdleCommand")
{
	AddParallel( new BottomLiftIdleCommand() );
	AddParallel( new TopLiftIdleCommand() );
	AddParallel( new IntakeIdleCommand() );
}
