#include "Clock.h"
#include "Utilities.h"
void Clock::Start()
{
	mStartTicks = SDL_GetTicks();
}

Uint32 Clock::GetTicks()
{
	Uint32 time = 0;

	time = SDL_GetTicks() - mStartTicks;


	return time;
}