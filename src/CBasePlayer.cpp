#include "CBasePlayer.h"


CBasePlayer::CBasePlayer() {
	

}
void CBasePlayer::Init() {


	m_Position.x = 400;
	m_Position.y = 400;
	this->m_EntityTexture.SetScale(5);
	m_EntityTexture.LoadTexture("sprites/Newton.png", "newton");
	m_EntityTexture.SetCurrentTexture("newton");
	
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
					break;
				// Right
				case SDLK_d:
					m_MovementDirection.RIGHT = 1;
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

CBasePlayer::~CBasePlayer() {
	Destroy();
}
