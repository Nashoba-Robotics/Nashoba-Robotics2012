#include "CommandBase.h"
#include "Debug.h"


CommandBase::CommandBase(const char *name) : Command(name) 
{
	executionCounter = 0;
	SetReportPeriod ( REPORT_PERIOD );
}

CommandBase::CommandBase() : Command() {
}

// Initialize a single static instance of all of your subsystems to NULL
ExampleSubsystem* CommandBase::examplesubsystem = NULL;
DriveSubsystem* CommandBase::drivesubsystem = NULL;
ShooterSubsystem* CommandBase::shootersubsystem = NULL;
BallIntakeSubsystem* CommandBase::ballintakesubsystem = NULL;
TopLiftSubsystem* CommandBase::topliftsubsystem = NULL;
BottomLiftSubsystem* CommandBase::bottomliftsubsystem = NULL;
//RampTipperSubsystem* CommandBase::ramptippersubsystem = NULL;
BallLoaderSubsystem* CommandBase::ballloadersubsystem = NULL;

void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	examplesubsystem = new ExampleSubsystem();
	drivesubsystem = new DriveSubsystem();
	shootersubsystem = new ShooterSubsystem();
	ballintakesubsystem = new BallIntakeSubsystem();
	topliftsubsystem = new TopLiftSubsystem();
	bottomliftsubsystem = new BottomLiftSubsystem();
//	ramptippersubsystem = new RampTipperSubsystem();
	ballloadersubsystem = new BallLoaderSubsystem();
}

bool CommandBase::IsTimeToPrint()
{
	return ( 0 == (executionCounter++ % reportPeriod) );
}

void CommandBase::ResetPrintCounter()
{
	executionCounter = 0;
}

void CommandBase::SetReportPeriod( int mseconds )
{
	reportPeriod = mseconds / 20;
}
