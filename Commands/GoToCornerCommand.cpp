#include "GoToCornerCommand.h"

#include "DriveToForwardWallCommand.h"
#include "DriveIntoSideWallCommand.h"
#include "DriveIntoFrontWallCommand.h"
#include "DriveIntoCornerContinuousCommand.h"


GoToCornerCommand::GoToCornerCommand() : CommandGroup("GoToCornerCommand")
{
	AddSequential( new DriveToForwardWallCommand() );
	AddSequential( new DriveIntoSideWallCommand()  );
	AddSequential( new DriveIntoFrontWallCommand() );
	AddSequential( new DriveIntoCornerContinuousCommand() );
}
