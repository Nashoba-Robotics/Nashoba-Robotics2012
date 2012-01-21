<<<<<<< HEAD
#include "CommandBase.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Commands/Scheduler.h"
#include "OperatorInput.h"
#include "Subsystems/DriveSubsystem.h"


CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}

// Initialize a single static instance of all of your subsystems to NULL
ExampleSubsystem* CommandBase::examplesubsystem = NULL;
OperatorInput* CommandBase::operatorinput = NULL;
DriveSubsystem* CommandBase::drivesubsystem = NULL;

void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	examplesubsystem = new ExampleSubsystem();
	drivesubsystem = new DriveSubsystem();
}
=======
#include "CommandBase.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Commands/Scheduler.h"
#include "OperatorInput.h"
#include "Subsystems/DriveSubsystem.h"


CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}

// Initialize a single static instance of all of your subsystems to NULL
ExampleSubsystem* CommandBase::examplesubsystem = NULL;
OperatorInput* CommandBase::operatorinput = NULL;
DriveSubsystem* CommandBase::drivesubsystem = NULL;

void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	examplesubsystem = new ExampleSubsystem();
	drivesubsystem = new DriveSubsystem();
}
>>>>>>> origin/brandon
