#ifndef COPROCESSOR_VISION_H
#define COPROCESSOR_VISION_H

//#include "WPILib.h"

class CoprocessorVision //: public PIDCommand 
{
public:
	CoprocessorVision();
	static CoprocessorVision * getInstance();
	static int run();
private:
	static CoprocessorVision * instance;
};

#endif
