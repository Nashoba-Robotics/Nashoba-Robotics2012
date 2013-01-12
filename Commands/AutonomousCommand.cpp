#include "AutonomousCommand.h"

#include "DriveDurationCommand.h"
#include "DriveToForwardWallCommand.h"
#include "DriveIntoSideWallCommand.h"
#include "DriveIntoFrontWallCommand.h"
#include "DriveIntoCornerContinuousCommand.h"
#include "ShooterTakeShotCommand.h"

//#define AUTONOMOUS_WITH_OUT_SET_CAM


AutonomousCommand::AutonomousCommand() : CommandGroup("AutonomousCommand")
{	
	AddSequential( new DriveDurationCommand(3.5, 0.5, 0) );
	AddSequential( new DriveDurationCommand(2, 0, 0.5) );
	
	AddParallel( new ShooterTakeShotCommand() );
 	AddParallel( new DriveDurationCommand(1, 0.5, 0.5) );
	
#ifdef AUTONOMOUS_WITH_OUT_SET_CAM
	
	AddSequential( new ShooterTakeShotCommand() );
	AddSequential (new WaitCommand ( 1.0 ) );
	
#endif
	
	AddSequential( new WaitCommand (2.75) );
	AddSequential( new ShooterTakeShotCommand() );
	AddSequential( new WaitCommand (1.7) );
	AddSequential( new ShooterTakeShotCommand() );
}
