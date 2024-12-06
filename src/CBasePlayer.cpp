#include "CBasePlayer.h"


CBasePlayer::CBasePlayer() {
	

}
void CBasePlayer::Init() {


	flip = SDL_RendererFlip::SDL_FLIP_NONE;
	this->m_EntityTexture.SetScale(1);
	m_EntityTexture.LoadTexture("sprites/woman.png", "peyton");
	m_EntityTexture.SetCurrentTexture("peyton");
	m_Position.x = 400 + (this->GetDimensions().x / 2);
	m_Position.y = 400 + (this->GetDimensions().y / 2);

}








void CBasePlayer::InputHandler(const SDL_Event& event) {
	switch (event.type) {
	case SDL_MOUSEMOTION:
		break;
	case SDL_MOUSEBUTTONDOWN:
		
		break;
	case SDL_MOUSEBUTTONUP:
		break;

	case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
				// Left
				case SDLK_a:
					m_MovementDirection.LEFT = 1;
					flip = SDL_RendererFlip::SDL_FLIP_NONE;
					break;
				// Right
				case SDLK_d:
					m_MovementDirection.RIGHT = 1;
					flip = SDL_RendererFlip::SDL_FLIP_HORIZONTAL;
					break;
				// Up
				case SDLK_w:
					m_MovementDirection.UP = 1;
					break;
				// Down
				case SDLK_s:
					m_MovementDirection.DOWN = 1;
					break;
				case SDLK_e:
					break;
				default:
					break;
			}
			break;
		// Reset the velocities
	case SDL_KEYUP:
				switch (event.key.keysym.sym) {
					// Left
				case SDLK_a:
					m_MovementDirection.LEFT = 0;
					break;
					// Right
				case SDLK_d:
					m_MovementDirection.RIGHT = 0;
					break;
					// Up
				case SDLK_w:
					m_MovementDirection.UP = 0;
					break;
					// Down
				case SDLK_s:
					m_MovementDirection.DOWN = 0;
					break;
				default:
					break;
				}
				break;
			
		default:
			break;
	}
	
	
}



void CBasePlayer::Move(float dt) {
	
	if (m_MovementDirection.LEFT > 0) {
		m_Velocity.x = -m_PlayerSpeed;
	}
	
	else if (m_MovementDirection.RIGHT > 0) {
		m_Velocity.x = m_PlayerSpeed;
	}
	else {
		m_Velocity.x = 0;
	}
	
	if (m_MovementDirection.UP > 0) {
		m_Velocity.y = -m_PlayerSpeed;
	}
	else if (m_MovementDirection.DOWN) {
		m_Velocity.y = m_PlayerSpeed;
	}
	else {
		m_Velocity.y = 0;
	}
	
	
	// Add our velocity to our position
	this->m_Position += this->m_Velocity * dt;
	
}



void CBasePlayer::Destroy() {
	m_EntityTexture.Cleanup();
	m_Position = Vector2(0, 0);
	m_Velocity = Vector2(0, 0);
	LOG("Player Destroyed");
}

void CBasePlayer::Render(SDL_Rect* clip, SDL_Point* center, SDL_RendererFlip fliptype) {
	
	m_EntityTexture.RenderTexture(m_Position, nullptr, m_dAngle, center, this->flip);
}

CBasePlayer::~CBasePlayer() {
	Destroy();
}
