#pragma once
#include "Utilities.h"
#include "CSDLManager.h"
#include "CWindowHandler.h"
#include "CRenderer.h"
#include "CLogic.h"
#include "Clock.h"
#include "CSoundManager.h"

class CEngine {
private:
	bool b_isRunning = true;

	CSDLManager m_SDLManager;
	CWindowHandler m_Window;

	// Fps cap
	SDL_DisplayMode m_Display;
	int m_nScreenFPS = 0; //SDL_GetDisplayMode(0, 0, &display);
	int m_nScreenTicksPerFrame = 0; //1000 / display.refresh_rate;


	// All of the games logic will be stored here
	CLogic m_GameLogic;
	// Main games clocks
	Clock m_MainClock;
	Clock m_CapTimer;
	Clock m_FPSTimer;
	// Variable to hold time elapsed between each frame
	float m_fDeltaTime;


	int m_nWindowWidth = 1280;
	int m_nWindowHeight = 800;

public:
	CEngine();
	~CEngine();
	bool Initialize();
	void Run();
	void Shutdown();



};