#ifndef COPROCESSOR_VISION_H
#define COPROCESSOR_VISION_H

class CoprocessorVision 
{
public:
	CoprocessorVision();
	static CoprocessorVision * getInstance();
	static int run();
private:
	static CoprocessorVision * instance;
};

#endif
