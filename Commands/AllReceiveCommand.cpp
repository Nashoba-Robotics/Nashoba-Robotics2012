#include "AllReceiveCommand.h"

#include "BottomLiftReceiveContinuousCommand.h"
#include "TopLiftReceiveContinuousCommand.h"
#include "IntakeReceiveContinuousCommand.h"

AllReceiveCommand::AllReceiveCommand() : CommandGroup("AllReceiveCommand")
{
	AddParallel( new BottomLiftReceiveContinuousCommand() );
	AddParallel( new TopLiftReceiveContinuousCommand() );
	AddParallel( new IntakeReceiveContinuousCommand() );
}
