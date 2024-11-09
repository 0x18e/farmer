#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Utilities.h"


class CSDLManager {
public:
	CSDLManager();
	// If this function returns false, we tell the program not to run.
	bool InitSDL();
	bool InitSDL_Image();
	// Call Quit in the destructor
	void Quit();
	~CSDLManager();

};
