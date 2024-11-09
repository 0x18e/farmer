#pragma once
#include "Utilities.h"
#include<SDL.h>
#include "CEntity.h"
#include "CBasePlayer.h"
#include "CRenderer.h"


enum TileType {
	EMPTY,
	FLOOR
};
struct Tile {
	int x, y;
	TileType type;
	CTextureHandler texture;
};

class CLogic {

private:
	SDL_Renderer* m_pRenderer;
	//std::vector<std::vector<int>> grid;
	CBasePlayer player;
	std::vector<CEntity*> m_pEntities;
	int tile_size = 32;
	static const int grid_width = 1280 /32;
	static const int grid_height = 800 /32;
	SDL_Rect tiles[grid_width][grid_height];
	SDL_Rect tile1;
	std::vector<Tile> grid;
	SDL_Texture* tile_texture;
	void FindPlayerGrid();


	// Set local window widths and heights
	int m_nWindowWidth;
	int m_nWindowHeight;
public:
	CLogic();
	~CLogic();
	
	void Init(SDL_Renderer* renderer, int WindowWidth, int WindowHeight);
	void AdjustResolution(int x, int y);
	void DrawGrid();
	void InitGrid();

	// Core functions
	void Update(float dt);
	void Render();
	void Cleanup();
	void InputHandler(const SDL_Event &key);
};