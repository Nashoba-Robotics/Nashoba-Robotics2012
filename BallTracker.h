
#ifndef BALL_TRACKER_H
#define BALL_TRACKER_H

enum {
	
};
class BallTracker
{
public:	
	BallTracker();
	
	void HandleLift();
	void BallShot();
	static BallTracker* GetInstance();
	
	int ballCount;
	bool hasBeenCounted;
	
private:
	static	BallTracker *_instance;
};


#endif

