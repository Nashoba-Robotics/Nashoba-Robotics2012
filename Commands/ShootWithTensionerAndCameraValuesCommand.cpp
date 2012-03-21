#include "ShootWithTensionerAndCameraValuesCommand.h"

#include "ShooterTakeShotCommand.h"
#include "DisableBallStatesCommand.h"
#include "ResetBallStatesCommand.h"
#include "CameraRotateToTargetCommand.h"
#include "TensionToBankShotCommand.h"
#include "DriveToTensionRangeCommand.h"


ShootWithTensionerAndCameraValuesCommand::ShootWithTensionerAndCameraValuesCommand() : CommandGroup("ShootWithTensionerAndCameraValuesCommand")
{
	AddSequential( new DriveToTensionRangeCommand() );
	AddSequential( new CameraRotateToTargetCommand() );
	AddSequential( new CameraRotateToTargetCommand() );
	AddSequential( new CameraRotateToTargetCommand() );
	AddSequential( new DisableBallStatesCommand() );
	AddSequential( new ResetBallStatesCommand() );
	AddSequential( new TensionToBankShotCommand() );
	AddSequential( new CameraRotateToTargetCommand() );
	AddSequential( new WaitCommand(2) );
	AddSequential( new ShooterTakeShotCommand() );
}
