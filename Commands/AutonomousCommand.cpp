#include "AutonomousCommand.h"

#include "DriveDurationCommand.h"
#include "DriveToForwardWallCommand.h"
#include "DriveIntoSideWallCommand.h"
#include "DriveIntoFrontWallCommand.h"
#include "DriveIntoCornerContinuousCommand.h"
#include "OurWaitCommand.h"
#include "ShooterTakeShotCommand.h"
#include "ShooterReadyShotCommand.h"
#include "TopIdleDurationCommand.h"
#include "TopReceiveDurationCommand.h"
#include "DisableBallStatesCommand.h"
#include "ResetBallStatesCommand.h"


AutonomousCommand::AutonomousCommand() : CommandGroup("AutonomousCommand")
{
	AddSequential( new DriveDurationCommand(2, 0, -0.5) );
	AddSequential( new DriveToForwardWallCommand() );
	AddSequential( new DriveIntoSideWallCommand()  );
	AddSequential( new DriveIntoFrontWallCommand() );
	AddSequential( new DriveIntoCornerContinuousCommand() );
	
//	AddSequential( new DisableBallStatesCommand()    );
//	AddSequential( new ShooterReadyShotCommand()     );
	AddSequential( new ShooterTakeShotCommand()      );
//	AddSequential( new ResetBallStatesCommand()      );
	AddSequential( new WaitCommand (2) );
//	AddSequential( new ShooterReadyShotCommand()     );
	AddSequential( new ShooterTakeShotCommand()      );

	
/*	AddSequential( new TopReceiveDurationCommand() );
	AddSequential( new ShooterTakeShotCommand() );
	AddSequential( new ShooterReadyShotCommand() );*/
}
