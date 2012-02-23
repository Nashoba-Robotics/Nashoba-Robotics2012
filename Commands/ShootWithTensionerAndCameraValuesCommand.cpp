#include "ShootWithTensionerAndCameraValuesCommand.h"

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
#include "CameraRotateToTargetCommand.h"
#include "TensionToBankShotCommand.h"


ShootWithTensionerAndCameraValuesCommand::ShootWithTensionerAndCameraValuesCommand() : CommandGroup("ShootWithTensionerAndCameraValuesCommand")
{
	/*AddSequential( new DriveDurationCommand(.5, 0, -0.5) );
	AddSequential( new DriveToForwardWallCommand() );
	AddSequential( new DriveIntoSideWallCommand()  );
	AddSequential( new DriveIntoFrontWallCommand() );
	AddSequential( new DriveIntoCornerContinuousCommand() );*/
	
	AddSequential( new CameraRotateToTargetCommand()    );
	AddSequential( new CameraRotateToTargetCommand()    );
	AddSequential( new CameraRotateToTargetCommand()    );
	AddSequential( new TensionToBankShotCommand     );
	AddSequential( new ShooterTakeShotCommand()      );

	
/*	AddSequential( new TopReceiveDurationCommand() );
	AddSequential( new ShooterTakeShotCommand() );
	AddSequential( new ShooterReadyShotCommand() );*/
}
