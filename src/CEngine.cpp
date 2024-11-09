#include "CEngine.h"

CEngine::CEngine() {
	
}

bool CEngine::Initialize() {
	// This is where all the initializing happens
	// Initializations such as renderer creations, SDL, SDL_IMG initializations, etc



	bool SDLCheck = m_SDLManager.InitSDL();
	bool WindowCheck = m_Window.CreateWindow("Lorem Ipsum", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_nWindowWidth, m_nWindowHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	bool RendererCheck = CRenderer::Get().Initialize(m_Window.GetWindow());
	bool SDL_ImgCheck = m_SDLManager.InitSDL_Image();
	

	bool AudioCheck = CSoundManager::Get().Init();
	m_GameLogic.Init(nullptr, m_nWindowWidth, m_nWindowHeight);

	SDL_GetDisplayMode(0, 0, &m_Display);
	m_nScreenFPS = m_Display.refresh_rate;
	m_nScreenTicksPerFrame = 1000 / m_nScreenFPS;


	return SDLCheck && WindowCheck && RendererCheck && AudioCheck && SDL_ImgCheck;
}

void CEngine::Run() {


	SDL_Event event;
	m_MainClock.Start();
	m_FPSTimer.Start();

	int CountedFrames = 0;
	float AvgFPS = 0;
	// Main game loop
	while (b_isRunning) {

		m_CapTimer.Start();
		m_fDeltaTime = m_MainClock.GetTicks() / 1000.f; // Time in seconds


		while (SDL_PollEvent(&event) != 0) {
			switch (event.type) {
			case SDL_QUIT:
				b_isRunning = false;

				break;
				// Debug Keys

			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_f) {
					std::cout << AvgFPS << "\n";
					LOG(m_nScreenFPS);
				}
				break;

			case SDL_WINDOWEVENT:
				if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
					SDL_GetWindowSize(m_Window.GetWindow(), &m_nWindowWidth, &m_nWindowHeight);
					m_Window.ChangeWindowSize(m_nWindowWidth, m_nWindowHeight);
					m_GameLogic.AdjustResolution(m_nWindowWidth, m_nWindowHeight);
					LOG("Changing resolution");
				}
				break;
			default:
				break;
			}
			m_GameLogic.InputHandler(event);
		}
		// temp code
		AvgFPS = CountedFrames / (m_FPSTimer.GetTicks() / 1000.f);
		if (AvgFPS > 2000000)
		{
			AvgFPS = 0;
		}


		// end of temp
		m_GameLogic.Update(m_fDeltaTime);

		// Reset clock to account for delta time, might change this clock to be game clock.
		m_MainClock.Start();

		m_GameLogic.Render();

		// temp
		++CountedFrames;

		int FrameTicks = m_CapTimer.GetTicks();
		if (FrameTicks < m_nScreenTicksPerFrame) {
			SDL_Delay(m_nScreenTicksPerFrame - FrameTicks);
		}
	}
}

void CEngine::Shutdown() {
	m_GameLogic.Cleanup();
	m_Window.Cleanup();
	m_SDLManager.Quit();
}

CEngine::~CEngine() {
	LOG("Shutting down engine");
	Shutdown();
}