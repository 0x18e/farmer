#include "CLogic.h"
#include "SDL_render.h"
#include "Utilities.h"
#include <cmath>



CLogic::CLogic() : m_pRenderer(nullptr), m_nWindowHeight(0), m_nWindowWidth(0){
	
}


// Use this for any startup required things
void CLogic::Init(SDL_Renderer* renderer, int WindowWidth, int WindowHeight) {
	tile1.x = 0;
	tile1.y = 0;
	tile1.w = 32;
	tile1.h = 32;
	tile2.x = 0;
	tile2.y = 0;
	tile2.w = 32;
	tile2.h = 32;

  
  m_CurrentTexture = nullptr; 
	SDL_Surface* temp = IMG_Load("sprites/Tile_Select.png");
	tile_texture = SDL_CreateTextureFromSurface(CRenderer::Get().GetRenderer(), temp);
	SDL_Surface* temp2 = IMG_Load("sprites/bloc.png");
	adj_texture = SDL_CreateTextureFromSurface(CRenderer::Get().GetRenderer(), temp2);
  

	SDL_FreeSurface(temp);
	SDL_FreeSurface(temp2);

	m_nWindowWidth = WindowWidth;
	m_nWindowHeight = WindowHeight;
	grid_width = m_nWindowWidth / tile_size;
	grid_height = m_nWindowHeight / tile_size;
	// grid_width += 5;
	// grid_height += 5;

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
	for (int y = 0; y < tiles.size(); ++y) {
		for (int x = 0; x < tiles[y].size(); ++x) {
			// Check for adjacent tiles here
			// LOG("Drawing tile at " << tiles[x][y].x << " and " << tiles[x][y].y);
	    SDL_Rect dstRect;
      dstRect.x = tiles[y][x].position.x;
      dstRect.y = tiles[y][x].position.y;
      dstRect.w = tiles[y][x].dimensions.x;
      dstRect.h = tiles[y][x].dimensions.y;
       
      if (tiles[y][x].type == FLOOR) {
        // Render floor tile
        m_CurrentTexture = tile_texture;
      }
      else if (tiles[y][x].type ==WALL)
      {
        LOG("typeis wall");
        m_CurrentTexture = adj_texture;
      }
      SDL_RenderCopy(CRenderer::Get().GetRenderer(), 
                  m_CurrentTexture, 
                  &tile1, &dstRect);


			// Adjacency 
	
		
		}
	}
}

void CLogic::InitGrid() {

	// initialize the grid here

	for (int x = 0; x < grid_width; x++) {
		std::vector<Tile> row;
		for (int y = 0; y < grid_height; ++y) {
			Tile tile;
			tile.position.x = x * tile_size; // this is multiplied by the tile size
			tile.position.y = y * tile_size;
			tile.dimensions.x = tile_size;
			tile.dimensions.y = tile_size;
      int rand = GetRandomNumber(0, 2);
      if (rand == 0){
        LOG("random!");
        tile.type = FLOOR;
      }
      else{
        LOG("wall!");
        tile.type = WALL;
      }
      
			row.push_back(tile);
		}
		tiles.push_back(row);
	}
}

void CLogic::AddRow() {
	// this function should just add one more tile to the grid

	// if it is drawn like this
	/*
	* tiles[0] this gives me the row
	* tiles[0][0] this gives me the first tile in the first row
	* it has properties like its width, height, position and all that jazz
	* so to add another tile to the last row
	* we loop through the last column
	* tiles[tiles.size()-1] this takes us to the last column
	* then we add a rect to that last column
	
	*/
	//SDL_Rect tile{ 1290, 900, 32, 32 };
	//tiles[tiles.size() - 1].push_back(tile);
	// this works

	// now we just need to get the final tiles last position
	// std::vector<SDL_Rect> final_column = tiles[tiles.size() - 1]; // this goes through and gets the last
	// rows size
	// SDL_Rect final_tile = final_column[final_column.size() - 1];
	// Tile tile{ Vector2(final_tile.x + 32, final_tile.y), Vector2(32, 32) };
	// SDL_Rect tile2{ final_tile.x, final_tile.y+32, 32, 32 };
  // this is a whole load of garbo code
	//LOG("final tile position " <<  final_x << " " << final_y);
	// tiles[tiles.size() - 1].push_back(tile);
	// tiles[tiles.size() - 1].push_back(tile);

}



void CLogic::DrawAdjacency(Vector2 tile_position) {
  		Vector2 player_tile_positions = this->FindPlayerGrid();

			SDL_SetRenderDrawColor(CRenderer::Get().GetRenderer(), 0, 255, 0, 0);			
	
  
}
Vector2 CLogic::FindPlayerGrid() {
	// since the tile is 32x32 pixels
	// we divide the players current position relative to the middle of their sprite
	// by the tile size
	Vector2 player_position_origin = player.GetPosition();


	int tileX = player_position_origin.x / tile_size;
	int tileY = player_position_origin.y / tile_size;

	// Ensure the indices are within the grid bounds
	if (tileX >= 0 && tileX < grid_width && tileY >= 0 && tileY < grid_height) {
		Tile currentTile = tiles[tileX][tileY];
		//LOG("player is currently in " << currentTile.x << " " << currentTile.y);
		return Vector2(tileX, tileY);
	}
	else {
		// Handle the case where the player is outside the grid
		LOG("OUT OF BOUNDS");
	}
	return Vector2(0, 0);
}



void CLogic::Update(float dt) {
	
	player.Move(dt);
	//this->FindPlayerGrid();
  
}

// Draw calls
void CLogic::Render(){
	// Clear the background with all white
	SDL_SetRenderDrawColor(CRenderer::Get().GetRenderer(), 0x00, 0x00, 0x00, 0xff);
	SDL_RenderClear(CRenderer::Get().GetRenderer());

	// Rendering entities
	SDL_SetRenderDrawColor(CRenderer::Get().GetRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
  
	
	

	for (size_t i = 0; i < m_pEntities.size(); ++i) {
		m_pEntities[i]->Render();
	}
	
	DrawGrid();
  DrawAdjacency(Vector2(0, 0));	

	// Presenting entities
	SDL_RenderPresent(CRenderer::Get().GetRenderer());
}

// Main games input handler
void CLogic::InputHandler(const SDL_Event& key) {

	player.InputHandler(key);

	switch (key.type) {
	case SDL_KEYDOWN:
		switch (key.key.keysym.sym) {
		case SDLK_t:
			LOG("adding Row");
			AddRow();
			break;
		default:
			break;
		}
	}





	// Pass input wherever it is required
}





void CLogic::Cleanup() {

}
CLogic::~CLogic() {
	LOG("Cleaning up logic..");

  SDL_DestroyTexture(m_CurrentTexture);
	SDL_DestroyTexture(tile_texture);
	SDL_DestroyTexture(adj_texture);
  
	for (auto& grid_texture : grid) {
		grid_texture.texture.Cleanup();
	}
	Cleanup();
}
