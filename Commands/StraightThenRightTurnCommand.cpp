#include "StraightThenRightTurnCommand.h"

#include "DriveForwardAutoCommand.h"
#include "RightTurnCommand.h"

StraightThenRightTurnCommand::StraightThenRightTurnCommand() : CommandGroup("StraightThenRightTurnCommand")
{
	AddSequential( new DriveForwardAutoCommand() );
	AddSequential( new RightTurnCommand() );
}
