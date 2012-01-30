#include "CommandBase.h"



CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}

// Initialize a single static instance of all of your subsystems to NULL
ExampleSubsystem* CommandBase::examplesubsystem = NULL;
DriveSubsystem* CommandBase::drivesubsystem = NULL;

void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	examplesubsystem = new ExampleSubsystem();
	drivesubsystem = new DriveSubsystem();
	shootersubsytem = new ShooterSubsystem();
	ballintakesubsystem = new BallIntakeSubsystem();
	topliftsubsystem = new TopLiftSubsystem();
	bottomliftsubsystem = new BottomLiftSubsystem();
	ramptippersubsystem = new RampTipperSubsystem();
}
