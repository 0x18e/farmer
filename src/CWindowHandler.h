#pragma once
#include<SDL.h>
#include "Utilities.h"


class CWindowHandler {
private:
	SDL_Window* m_pWindow;
	int m_nWindowWidth;
	int m_nWindowHeight;
	const char* m_pszWindowTitle;
	int m_nSDLFlags;
	

public:
	CWindowHandler() :m_nWindowWidth(1640), m_nWindowHeight(480),
		m_pszWindowTitle("Keebler"), m_pWindow(nullptr), m_nSDLFlags(SDL_WINDOW_SHOWN) {};

	bool CreateWindow(const char* window_title, int x, int y, int w, int h, int SDL_Flags);
	void ChangeWindowSize(int x, int y);

	SDL_Window* GetWindow() { return m_pWindow; };

	// Cleanup
	void Cleanup();

	~CWindowHandler();
};