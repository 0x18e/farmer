#pragma once
#include "CTexture.h"
#include "Utilities.h"

class CEntity {
protected:
	CTextureHandler m_EntityTexture;
	Vector2 m_Position;
	Vector2 m_Velocity;
	double m_dAngle;
	int m_nScale;
public:
	CEntity() : m_Position(0, 0), m_Velocity(0, 0), m_nScale(1), m_dAngle(0.0) {} ;
	~CEntity();

	virtual void Render(SDL_Rect* clip = nullptr, SDL_Point* center = nullptr, SDL_RendererFlip fliptype = SDL_RendererFlip::SDL_FLIP_NONE);
	void AdjustForResolution(Vector2 newres, Vector2 oldres);

	
};