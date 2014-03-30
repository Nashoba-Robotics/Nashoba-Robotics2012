#include "AllRejectCommand.h"

#include "BottomLiftRejectContinuousCommand.h"
#include "TopLiftRejectContinuousCommand.h"
#include "IntakeRejectContinuousCommand.h"

AllRejectCommand::AllRejectCommand() : CommandGroup("AllRejectCommand")
{
	AddParallel( new BottomLiftRejectContinuousCommand() );
	AddParallel( new TopLiftRejectContinuousCommand() );
	AddParallel( new IntakeRejectContinuousCommand() );
}
