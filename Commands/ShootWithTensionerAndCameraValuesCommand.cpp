#include "ShootWithTensionerAndCameraValuesCommand.h"


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
	AddSequential( new CameraRotateToTargetCommand()    );
	AddSequential( new CameraRotateToTargetCommand()    );
	AddSequential( new CameraRotateToTargetCommand()    );
	AddSequential( new DisableBallStatesCommand() );
	AddSequential( new ResetBallStatesCommand() );
	AddSequential( new TensionToBankShotCommand     );
	AddSequential( new CameraRotateToTargetCommand() );
	AddSequential(new WaitCommand(2) );
	AddSequential( new ShooterTakeShotCommand()      );
}
