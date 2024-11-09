#include "CEntity.h"
#include "CEngine.h"


CEntity::~CEntity() {
	m_EntityTexture.Cleanup();
	LOG("Entity Cleaned");
}


void CEntity::Render(SDL_Rect* clip, SDL_Point* center, SDL_RendererFlip fliptype){
	// Base Rendering function
	m_EntityTexture.RenderTexture(m_Position, nullptr, m_dAngle, center, fliptype);
}

void CEntity::AdjustForResolution(Vector2 newres, Vector2 oldres) {
	// Proportionality
	this->m_Position = (newres * m_Position) / oldres;
}
