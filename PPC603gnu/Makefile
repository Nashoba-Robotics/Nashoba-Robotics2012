# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = PPC603gnu
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := C:/WindRiver/workspace
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/CommandBasedRobotTemplate



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = ppc
CPU = PPC603
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 

IDE_DEFINES = 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif


#Project Targets
PROJECT_TARGETS = CommandBasedRobotTemplate/$(MODE_DIR)/CommandBasedRobotTemplate.out \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/CommandBassedRobotTemplate_partialImage.o


#Rules

# CommandBasedRobotTemplate
ifeq ($(DEBUG_MODE),1)
CommandBasedRobotTemplate/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
CommandBasedRobotTemplate/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
CommandBasedRobotTemplate/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
CommandBasedRobotTemplate/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
CommandBasedRobotTemplate/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
CommandBasedRobotTemplate/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
CommandBasedRobotTemplate/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
CommandBasedRobotTemplate/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
CommandBasedRobotTemplate/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
CommandBasedRobotTemplate/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
CommandBasedRobotTemplate/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
CommandBasedRobotTemplate/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
CommandBasedRobotTemplate/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
CommandBasedRobotTemplate/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
CommandBasedRobotTemplate/$(MODE_DIR)/% : IDE_DEFINES = 
CommandBasedRobotTemplate/$(MODE_DIR)/% : PROJECT_TYPE = DKM
CommandBasedRobotTemplate/$(MODE_DIR)/% : DEFINES = 
CommandBasedRobotTemplate/$(MODE_DIR)/% : EXPAND_DBG = 0
CommandBasedRobotTemplate/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
CommandBasedRobotTemplate/$(MODE_DIR)/% : CPU = PPC603
CommandBasedRobotTemplate/$(MODE_DIR)/% : TOOL_FAMILY = gnu
CommandBasedRobotTemplate/$(MODE_DIR)/% : TOOL = gnu
CommandBasedRobotTemplate/$(MODE_DIR)/% : TOOL_PATH = 
CommandBasedRobotTemplate/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
CommandBasedRobotTemplate/$(MODE_DIR)/% : LIBPATH = 
CommandBasedRobotTemplate/$(MODE_DIR)/% : LIBS = 
CommandBasedRobotTemplate/$(MODE_DIR)/% : OBJ_DIR := CommandBasedRobotTemplate/$(MODE_DIR)

OBJECTS_CommandBasedRobotTemplate = CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/CommandBassedRobotTemplate_partialImage.o

CommandBasedRobotTemplate/$(MODE_DIR)/CommandBasedRobotTemplate.out : $(OBJECTS_CommandBasedRobotTemplate)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmppc $(OBJECTS_CommandBasedRobotTemplate) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_CommandBasedRobotTemplate) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

CommandBasedRobotTemplate/$(MODE_DIR)/CommandBasedRobotTemplate_compile_file : $(FILE) ;

_clean :: CommandBasedRobotTemplate/$(MODE_DIR)/CommandBasedRobotTemplate_clean

CommandBasedRobotTemplate/$(MODE_DIR)/CommandBasedRobotTemplate_clean : 
	$(TRACE_FLAG)if [ -d "CommandBasedRobotTemplate" ]; then cd "CommandBasedRobotTemplate"; rm -rf $(MODE_DIR); fi


# CommandBassedRobotTemplate_partialImage
ifeq ($(DEBUG_MODE),1)
CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/% : IDE_DEFINES = 
CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/% : DEFINES = 
CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/% : CPU = PPC603
CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = gnu
CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/% : TOOL = gnu
CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/% : LIBPATH = 
CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/% : LIBS = 
CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/% : OBJ_DIR := CommandBassedRobotTemplate_partialImage/$(MODE_DIR)

CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/AnalogIRSensor.o : $(PRJ_ROOT_DIR)/AnalogIRSensor.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/BallSensor.o : $(PRJ_ROOT_DIR)/BallSensor.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/BallTracker.o : $(PRJ_ROOT_DIR)/BallTracker.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/CommandBase.o : $(PRJ_ROOT_DIR)/CommandBase.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/CommandBasedRobot.o : $(PRJ_ROOT_DIR)/CommandBasedRobot.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/AlignBackWithWallCommand.o : $(PRJ_ROOT_DIR)/Commands/AlignBackWithWallCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/AlignFrontWithWallCommand.o : $(PRJ_ROOT_DIR)/Commands/AlignFrontWithWallCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/AllIdleCommand.o : $(PRJ_ROOT_DIR)/Commands/AllIdleCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/AllReceiveCommand.o : $(PRJ_ROOT_DIR)/Commands/AllReceiveCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/AllRejectCommand.o : $(PRJ_ROOT_DIR)/Commands/AllRejectCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/AutonomousCommand.o : $(PRJ_ROOT_DIR)/Commands/AutonomousCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/BottomLiftIdleCommand.o : $(PRJ_ROOT_DIR)/Commands/BottomLiftIdleCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/BottomLiftReceiveContinuousCommand.o : $(PRJ_ROOT_DIR)/Commands/BottomLiftReceiveContinuousCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/BottomLiftRejectContinuousCommand.o : $(PRJ_ROOT_DIR)/Commands/BottomLiftRejectContinuousCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/CameraRotateToTargetCommand.o : $(PRJ_ROOT_DIR)/Commands/CameraRotateToTargetCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/CancelAllCommand.o : $(PRJ_ROOT_DIR)/Commands/CancelAllCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DisableBallStatesCommand.o : $(PRJ_ROOT_DIR)/Commands/DisableBallStatesCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DriveDistanceCommand.o : $(PRJ_ROOT_DIR)/Commands/DriveDistanceCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DriveDurationCommand.o : $(PRJ_ROOT_DIR)/Commands/DriveDurationCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DriveIntoCornerContinuousCommand.o : $(PRJ_ROOT_DIR)/Commands/DriveIntoCornerContinuousCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DriveIntoFrontWallCommand.o : $(PRJ_ROOT_DIR)/Commands/DriveIntoFrontWallCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DriveIntoSideWallCommand.o : $(PRJ_ROOT_DIR)/Commands/DriveIntoSideWallCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DriveOneWheelCommand.o : $(PRJ_ROOT_DIR)/Commands/DriveOneWheelCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DriveToCornerCommand.o : $(PRJ_ROOT_DIR)/Commands/DriveToCornerCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DriveToForwardWallCommand.o : $(PRJ_ROOT_DIR)/Commands/DriveToForwardWallCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DriveToTensionRangeCommand.o : $(PRJ_ROOT_DIR)/Commands/DriveToTensionRangeCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/ExampleCommand.o : $(PRJ_ROOT_DIR)/Commands/ExampleCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/GoToCornerCommand.o : $(PRJ_ROOT_DIR)/Commands/GoToCornerCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/IntakeIdleCommand.o : $(PRJ_ROOT_DIR)/Commands/IntakeIdleCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/IntakeReceiveContinuousCommand.o : $(PRJ_ROOT_DIR)/Commands/IntakeReceiveContinuousCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/IntakeRejectContinuousCommand.o : $(PRJ_ROOT_DIR)/Commands/IntakeRejectContinuousCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/JoyStickDriveCommand.o : $(PRJ_ROOT_DIR)/Commands/JoyStickDriveCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/OurWaitCommand.o : $(PRJ_ROOT_DIR)/Commands/OurWaitCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/ResetBallStatesCommand.o : $(PRJ_ROOT_DIR)/Commands/ResetBallStatesCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/ResetCamCommand.o : $(PRJ_ROOT_DIR)/Commands/ResetCamCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/ResetGyroCommand.o : $(PRJ_ROOT_DIR)/Commands/ResetGyroCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/RightTurnCommand.o : $(PRJ_ROOT_DIR)/Commands/RightTurnCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/ShootWithTensionerAndCameraValuesCommand.o : $(PRJ_ROOT_DIR)/Commands/ShootWithTensionerAndCameraValuesCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/ShooterIdleCommand.o : $(PRJ_ROOT_DIR)/Commands/ShooterIdleCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/ShooterReadyShotCommand.o : $(PRJ_ROOT_DIR)/Commands/ShooterReadyShotCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/ShooterTakeShotCommand.o : $(PRJ_ROOT_DIR)/Commands/ShooterTakeShotCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/StraightThenRightTurnCommand.o : $(PRJ_ROOT_DIR)/Commands/StraightThenRightTurnCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/TensionDecreaseCommand.o : $(PRJ_ROOT_DIR)/Commands/TensionDecreaseCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/TensionIncreaseCommand.o : $(PRJ_ROOT_DIR)/Commands/TensionIncreaseCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/TensionToBankShotCommand.o : $(PRJ_ROOT_DIR)/Commands/TensionToBankShotCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/TensionToGivenValueCommand.o : $(PRJ_ROOT_DIR)/Commands/TensionToGivenValueCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/TopIdleDurationCommand.o : $(PRJ_ROOT_DIR)/Commands/TopIdleDurationCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/TopLiftIdleCommand.o : $(PRJ_ROOT_DIR)/Commands/TopLiftIdleCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/TopLiftReceiveContinuousCommand.o : $(PRJ_ROOT_DIR)/Commands/TopLiftReceiveContinuousCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/TopLiftRejectContinuousCommand.o : $(PRJ_ROOT_DIR)/Commands/TopLiftRejectContinuousCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/TopReceiveDurationCommand.o : $(PRJ_ROOT_DIR)/Commands/TopReceiveDurationCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/CoprocessorVision.o : $(PRJ_ROOT_DIR)/CoprocessorVision.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/OperatorInput.o : $(PRJ_ROOT_DIR)/OperatorInput.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Subsystems/BallIntakeSubsystem.o : $(PRJ_ROOT_DIR)/Subsystems/BallIntakeSubsystem.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Subsystems/BottomLiftSubsystem.o : $(PRJ_ROOT_DIR)/Subsystems/BottomLiftSubsystem.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Subsystems/DriveSubsystem.o : $(PRJ_ROOT_DIR)/Subsystems/DriveSubsystem.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Subsystems/ShooterSubsystem.o : $(PRJ_ROOT_DIR)/Subsystems/ShooterSubsystem.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Subsystems/TopLiftSubsystem.o : $(PRJ_ROOT_DIR)/Subsystems/TopLiftSubsystem.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/UltraSonicRangeSensor.o : $(PRJ_ROOT_DIR)/UltraSonicRangeSensor.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_CommandBassedRobotTemplate_partialImage = CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/AnalogIRSensor.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/BallSensor.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/BallTracker.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/CommandBase.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/CommandBasedRobot.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/AlignBackWithWallCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/AlignFrontWithWallCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/AllIdleCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/AllReceiveCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/AllRejectCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/AutonomousCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/BottomLiftIdleCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/BottomLiftReceiveContinuousCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/BottomLiftRejectContinuousCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/CameraRotateToTargetCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/CancelAllCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DisableBallStatesCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DriveDistanceCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DriveDurationCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DriveIntoCornerContinuousCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DriveIntoFrontWallCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DriveIntoSideWallCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DriveOneWheelCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DriveToCornerCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DriveToForwardWallCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DriveToTensionRangeCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/ExampleCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/GoToCornerCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/IntakeIdleCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/IntakeReceiveContinuousCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/IntakeRejectContinuousCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/JoyStickDriveCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/OurWaitCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/ResetBallStatesCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/ResetCamCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/ResetGyroCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/RightTurnCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/ShootWithTensionerAndCameraValuesCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/ShooterIdleCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/ShooterReadyShotCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/ShooterTakeShotCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/StraightThenRightTurnCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/TensionDecreaseCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/TensionIncreaseCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/TensionToBankShotCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/TensionToGivenValueCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/TopIdleDurationCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/TopLiftIdleCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/TopLiftReceiveContinuousCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/TopLiftRejectContinuousCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/TopReceiveDurationCommand.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/CoprocessorVision.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/OperatorInput.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Subsystems/BallIntakeSubsystem.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Subsystems/BottomLiftSubsystem.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Subsystems/DriveSubsystem.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Subsystems/ShooterSubsystem.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Subsystems/TopLiftSubsystem.o \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/UltraSonicRangeSensor.o

CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/CommandBassedRobotTemplate_partialImage.o : $(OBJECTS_CommandBassedRobotTemplate_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X  -o "$@" $(OBJECTS_CommandBassedRobotTemplate_partialImage) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS)  && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/CommandBassedRobotTemplate_partialImage_compile_file : $(FILE) ;

_clean :: CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/CommandBassedRobotTemplate_partialImage_clean

CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/CommandBassedRobotTemplate_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "CommandBassedRobotTemplate_partialImage" ]; then cd "CommandBassedRobotTemplate_partialImage"; rm -rf $(MODE_DIR); fi

force : 

DEP_FILES := CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/AnalogIRSensor.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/BallSensor.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/BallTracker.d \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/CommandBase.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/CommandBasedRobot.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/AlignBackWithWallCommand.d \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/AlignFrontWithWallCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/AllIdleCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/AllReceiveCommand.d \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/AllRejectCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/AutonomousCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/BottomLiftIdleCommand.d \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/BottomLiftReceiveContinuousCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/BottomLiftRejectContinuousCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/CameraRotateToTargetCommand.d \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/CancelAllCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DisableBallStatesCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DriveDistanceCommand.d \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DriveDurationCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DriveIntoCornerContinuousCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DriveIntoFrontWallCommand.d \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DriveIntoSideWallCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DriveOneWheelCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DriveToCornerCommand.d \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DriveToForwardWallCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/DriveToTensionRangeCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/ExampleCommand.d \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/GoToCornerCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/IntakeIdleCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/IntakeReceiveContinuousCommand.d \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/IntakeRejectContinuousCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/JoyStickDriveCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/OurWaitCommand.d \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/ResetBallStatesCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/ResetCamCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/ResetGyroCommand.d \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/RightTurnCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/ShootWithTensionerAndCameraValuesCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/ShooterIdleCommand.d \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/ShooterReadyShotCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/ShooterTakeShotCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/StraightThenRightTurnCommand.d \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/TensionDecreaseCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/TensionIncreaseCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/TensionToBankShotCommand.d \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/TensionToGivenValueCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/TopIdleDurationCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/TopLiftIdleCommand.d \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/TopLiftReceiveContinuousCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/TopLiftRejectContinuousCommand.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Commands/TopReceiveDurationCommand.d \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/CoprocessorVision.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/OperatorInput.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Subsystems/BallIntakeSubsystem.d \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Subsystems/BottomLiftSubsystem.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Subsystems/DriveSubsystem.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Subsystems/ShooterSubsystem.d \
	 CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/Subsystems/TopLiftSubsystem.d CommandBassedRobotTemplate_partialImage/$(MODE_DIR)/Objects/CommandBasedRobotTemplate/UltraSonicRangeSensor.d
-include $(DEP_FILES)



-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

main_all : external_build $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
