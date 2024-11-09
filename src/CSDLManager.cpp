#include "CSDLManager.h"


CSDLManager::CSDLManager() {
	
}

bool CSDLManager::InitSDL(){

	bool bFlag = true;
	int SDL_InitFlags = SDL_INIT_VIDEO | SDL_INIT_AUDIO;
	int IMG_InitFlags = IMG_INIT_PNG;
	if (SDL_Init(SDL_InitFlags) == -1) {
		
		LOG("Could not initialize SDL " << SDL_GetError());
		return false;
	}
	else {
		LOG("SDL initialized");
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0")) {
			LOG("Nearest texture filtering is not enabled!");
		}
	}

	return bFlag;

}

bool CSDLManager::InitSDL_Image()
{
	int IMG_InitFlags = IMG_INIT_PNG;
	if (!IMG_Init(IMG_InitFlags)) {
		LOG("Could not initialize SDL_Image: " << IMG_GetError());
		return false;
	}
	else {
		LOG("SDL_Image initialized");
	}
	return true;
}

void CSDLManager::Quit(){
	LOG("Quitting SDL_Image");
	IMG_Quit();
	LOG("Quitting SDL");
	SDL_Quit();
	LOG("SDL quit");
}

CSDLManager::~CSDLManager(){

}


