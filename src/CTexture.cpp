#include "CTexture.h"
#include <cassert>



bool CTextureHandler::LoadTexture(const char* path, std::string id) {
	//this->Cleanup();
	if (!CRenderer::Get().GetRenderer()) {
		LOG("for some reason renderer just isnt here");
	}
	SDL_Texture* tmp_texture = IMG_LoadTexture(CRenderer::Get().GetRenderer(), path);
	if (tmp_texture == nullptr) {
		LOG("SDL could not create texture from IMG: " << IMG_GetError());
		return false;
	}
	else {
		SDL_QueryTexture(tmp_texture, nullptr, nullptr, &m_nWidth, &m_nHeight);
	}
	m_Textures[id] = tmp_texture; // This adds the texture to the list of all textures
	return m_Textures[id] != nullptr; // this returns whether its null or not
	
}

void CTextureHandler::RenderTexture(Vector2 point, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip fliptype) {
	// We subtract the 2 points with their texture widths & heights in order to center them
	SDL_Rect Rendering_Area { (int)point.x - (m_nWidth* m_nScale)/2, (int)point.y - (m_nHeight*m_nScale)/2, m_nWidth*m_nScale, m_nHeight*m_nScale};
	if (clip != nullptr) {
		Rendering_Area.h = clip->h;
		Rendering_Area.w = clip->w;
	}
	SDL_RenderCopyEx(CRenderer::Get().GetRenderer(), m_CurrentTexture, nullptr, &Rendering_Area, angle, center, fliptype);
}

void CTextureHandler::SetCurrentTexture(std::string id) {
	m_CurrentTexture = m_Textures[id];

	SDL_QueryTexture(m_CurrentTexture, nullptr, nullptr, &m_nWidth, &m_nHeight);
}



SDL_Texture* CTextureHandler::GetTexture(const std::string& id) {
	return this->m_Textures[id];
}



void CTextureHandler::SetScale(int scale) {
	m_nScale = scale;
}

void CTextureHandler::Cleanup() {
	// Get rid of all the textures
	SDL_DestroyTexture(m_CurrentTexture);
	m_CurrentTexture = nullptr;
	for (auto value : m_Textures) {
		if (value.second != nullptr) {
			SDL_DestroyTexture(value.second);
			LOG("Destroyed " << value.first);
			value.second = nullptr;
		}
	}
	m_Textures.clear();
	if (m_CurrentTexture != nullptr) {
		SDL_DestroyTexture(m_CurrentTexture);
		LOG("DESTROYED");
		m_CurrentTexture = nullptr;
		m_nWidth = 0;
		m_nHeight = 0;
	}
}

CTextureHandler::~CTextureHandler() {
  LOG("Cleaning up textures");
}
