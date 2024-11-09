#include "CLogic.h"



CLogic::CLogic() : m_pRenderer(nullptr), m_nWindowHeight(0), m_nWindowWidth(0){
	
}


// Use this for any startup required things
void CLogic::Init(SDL_Renderer* renderer, int WindowWidth, int WindowHeight) {
	tile1.x = 0;
	tile1.y = 0;
	tile1.w = 32;
	tile1.h = 32;
	SDL_Surface* temp = IMG_Load("sprites/Tile_Select.png");
	tile_texture = SDL_CreateTextureFromSurface(CRenderer::Get().GetRenderer(), temp);
	SDL_FreeSurface(temp);
	m_nWindowWidth = WindowWidth;
	m_nWindowHeight = WindowHeight;
	player.Init();
	
	m_pEntities.push_back(&player);
	InitGrid();
}

void CLogic::AdjustResolution(int x, int y) {

	for (size_t it = 0; it < m_pEntities.size(); ++it) {
		m_pEntities[it]->AdjustForResolution(Vector2(x, y), Vector2(m_nWindowWidth, m_nWindowHeight));
	}
	m_nWindowWidth = x;
	m_nWindowHeight = y;
}

void CLogic::DrawGrid() {
	for (int x = 0; x < grid_width; ++x) {
		for (int y = 0; y < grid_height; ++y) {
			//LOG("Drawing tile at " << tiles[x][y].x << " and " << tiles[x][y].y);
			SDL_RenderCopy(CRenderer::Get().GetRenderer(), tile_texture, &tile1, &tiles[x][y]);
		}
	}
}

void CLogic::InitGrid() {
	for (int x = 0; x < grid_width; x++) {
		for (int y = 0; y < grid_height; ++y) {
			tiles[x][y].x = x * 32; // this is multiplied by the tile size
			tiles[x][y].y = y * 32;
			tiles[x][y].w = 32;
			tiles[x][y].h = 32;
		}
	}
}

void CLogic::FindPlayerGrid() {
	// since the tile is 32x32 pixels
	// we divide the players current position relative to the middle of their sprite
	// by the tile size
	Vector2 player_position_origin = Vector2(player.GetPosition().x - (player.GetDimensions().x / 2)
		, player.GetPosition().y - (player.GetDimensions().y / 2));


	int tileX = player_position_origin.x / tile_size;
	int tileY = player_position_origin.y / tile_size;

	// Ensure the indices are within the grid bounds
	if (tileX >= 0 && tileX < grid_width && tileY >= 0 && tileY < grid_height) {
		SDL_Rect currentTile = tiles[tileX][tileY];
		LOG("player is currently in " << currentTile.x << " " << currentTile.y);
	}
	else {
		// Handle the case where the player is outside the grid
		LOG("OUT OF BOUNDS");
	}
}



void CLogic::Update(float dt) {
	
	player.Move(dt);
	this->FindPlayerGrid();
}

// Draw calls
void CLogic::Render(){
	// Clear the background with all white
	SDL_SetRenderDrawColor(CRenderer::Get().GetRenderer(), 0x00, 0x00, 0x00, 0xff);
	SDL_RenderClear(CRenderer::Get().GetRenderer());

	// Rendering entities
	SDL_SetRenderDrawColor(CRenderer::Get().GetRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);

	
	DrawGrid();

	for (size_t i = 0; i < m_pEntities.size(); ++i) {
		m_pEntities[i]->Render();
	}
	
	

	// Presenting entities
	SDL_RenderPresent(CRenderer::Get().GetRenderer());
}

// Main games input handler
void CLogic::InputHandler(const SDL_Event& key) {

	player.InputHandler(key);
	// Pass input wherever it is required
}





void CLogic::Cleanup() {

}
CLogic::~CLogic() {
	LOG("Cleaning up logic..");
	for (auto& grid_texture : grid) {
		grid_texture.texture.Cleanup();
	}
	Cleanup();
}