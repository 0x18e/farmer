#pragma once
#include<SDL.h>

// Clock class to count time for whatever instances.
class Clock {
private:
	//The clock time when the timer started
	Uint32 mStartTicks=0;

	//The ticks stored when the timer was paused
	Uint32 mPausedTicks=0;
public:
	void Start();
	Uint32 GetTicks();
	



};