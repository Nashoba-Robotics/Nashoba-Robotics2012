#include "RampTipperCommand.h"

RampTipperCommand::RampTipperCommand() : CommandBase("RampTipperCommand")
{
//	Requires( ramptippersubsystem );
}

void RampTipperCommand::Initialize()
{
	ResetPrintCounter();
	printf ("RampTipperCommand Initialized \n");
}

void RampTipperCommand::Execute()
{

}

bool RampTipperCommand::IsFinished()
{
	return true;
}

void RampTipperCommand::End()
{

}

void RampTipperCommand::Interrupted()
{

}
