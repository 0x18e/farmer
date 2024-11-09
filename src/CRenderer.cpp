#include "CRenderer.h"

CRenderer CRenderer::m_sInstance;
CRenderer::CRenderer() : m_pRenderer(nullptr) {


}

CRenderer::~CRenderer() {
	
}


bool CRenderer::Initialize(SDL_Window *window) {
	bool b_Flag = true;

	int n_RendererFlags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	// Attempt to create an SDL_Renderer
	m_pRenderer = SDL_CreateRenderer(window, -1, n_RendererFlags);
	if (m_pRenderer == nullptr) {
		SDL_Log("Could not create SDL Renderer %s", SDL_GetError());
		b_Flag = false;
	}
	else {
		LOG("SDL Renderer created");
	}

	return b_Flag;
}
void CRenderer::Cleanup() {
	if (m_pRenderer != nullptr) {
		SDL_DestroyRenderer(m_pRenderer);
		m_pRenderer = nullptr;
		LOG("Destroyed Renderer");
	}

	
}