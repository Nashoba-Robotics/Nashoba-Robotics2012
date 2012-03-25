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
DriveSubsystem* CommandBase::drivesubsystem = NULL;
ShooterSubsystem* CommandBase::shootersubsystem = NULL;
BallIntakeSubsystem* CommandBase::ballintakesubsystem = NULL;
TopLiftSubsystem* CommandBase::topliftsubsystem = NULL;
BottomLiftSubsystem* CommandBase::bottomliftsubsystem = NULL;


void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	if( drivesubsystem == NULL )
		drivesubsystem = new DriveSubsystem();
	
	if( shootersubsystem == NULL )
		shootersubsystem = new ShooterSubsystem();
	
	if( ballintakesubsystem == NULL )
		ballintakesubsystem = new BallIntakeSubsystem();
	
	if( topliftsubsystem == NULL )
	    topliftsubsystem = new TopLiftSubsystem();
	
	if( bottomliftsubsystem == NULL )
		bottomliftsubsystem = new BottomLiftSubsystem();

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
