#pragma once
#include<SDL.h>
#include "Utilities.h"


// This might be a singleton in order to pass the renderer all throughout the program
class CRenderer {

private:
	SDL_Renderer* m_pRenderer;
	CRenderer();
	~CRenderer();
	static CRenderer m_sInstance;
public:
	static CRenderer& Get() {
		return m_sInstance;
	}
	bool Initialize(SDL_Window *window);
	SDL_Renderer* GetRenderer() { return m_pRenderer; };
	void Cleanup();
};