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
	int tile_size = 64;
	int grid_width;
	int grid_height;
	//SDL_Rect tiles[grid_width][grid_height];
	//
	std::vector<std::vector<SDL_Rect>> tiles;
	SDL_Texture* adj_texture;
	SDL_Rect tile1;
	SDL_Rect tile2;
	std::vector<Tile> grid;
	SDL_Texture* tile_texture;
	Vector2 FindPlayerGrid();
	void AddRow();
	void DrawAdjacency(Vector2);


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
