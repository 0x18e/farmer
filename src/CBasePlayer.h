#pragma once
#include<SDL.h>
#include "Utilities.h"
#include "CEntity.h"
#include <map>


class CBasePlayer : public CEntity {
private:
	float m_PlayerSpeed = 400;
	int m_nMousePositionX = 0;
	int m_nMousePositionY = 0;
	bool m_bIsShooting = false;
	
	SDL_RendererFlip flip;

	struct DIRECTIONS {
		int UP = 0;
		int DOWN = 0;
		int LEFT = 0;
		int RIGHT = 0;
	} m_MovementDirection;

public:
	CBasePlayer();
	~CBasePlayer();

	void Init();
	void Destroy();
	void Render(SDL_Rect* clip = nullptr, SDL_Point* center = nullptr, SDL_RendererFlip fliptype = SDL_RendererFlip::SDL_FLIP_NONE) override;
	Vector2 GetPosition() const {
		return m_Position;
	}
	Vector2 GetDimensions() {
		return Vector2(m_EntityTexture.GetWidth(), m_EntityTexture.GetHeight());
	}
	void InputHandler(const SDL_Event& key);
	void Move(float dt);

};