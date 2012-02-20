#include "StraightThenRightTurnCommand.h"

#include "DriveDurationCommand.h"
#include "RightTurnCommand.h"

StraightThenRightTurnCommand::StraightThenRightTurnCommand() : CommandGroup("StraightThenRightTurnCommand")
{
	AddSequential( new DriveDurationCommand(5, 0.5, 0) );
	AddSequential( new RightTurnCommand() );
}
