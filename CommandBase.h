#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "Commands/Command.h"
#include "OperatorInput.h"
#include "Subsystems/DriveSubsystem.h"
#include "Subsystems/ShooterSubsystem.h"
#include "Subsystems/BallIntakeSubsystem.h"
#include "Subsystems/TopLiftSubsystem.h"
#include "Subsystems/BottomLiftSubsystem.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command 
{
private:
	int executionCounter;
	int reportPeriod;
	
protected:
	bool IsTimeToPrint();
	void ResetPrintCounter();
	void SetReportPeriod( int mseconds );
	
public:
	CommandBase(const char *name);
	CommandBase();
	static void init();
	
	// Create a single static instance of all of your subsystems
	
	static DriveSubsystem *drivesubsystem;
	static ShooterSubsystem *shootersubsystem;
	static BallIntakeSubsystem *ballintakesubsystem;
	static TopLiftSubsystem *topliftsubsystem;
	static BottomLiftSubsystem *bottomliftsubsystem;

};

#endif
