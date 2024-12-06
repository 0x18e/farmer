#pragma once
#include "CTexture.h"
#include "Utilities.h"
#include<SDL.h>
#include "CEntity.h"
#include "CBasePlayer.h"
#include "CRenderer.h"


enum TileType {
	EMPTY,
	FLOOR,
	WALL,
	TILED_DIRT,
	PLANTED_SEED
};
struct Tile { 
  Vector2 position;
  Vector2 dimensions;

  TileType type;
  CTexture texture;
  Tile() : position(0, 0), dimensions(0, 0), type(EMPTY) {}
};

class CLogic {

private:
	SDL_Renderer* m_pRenderer;
	CBasePlayer player;
	std::vector<CEntity*> m_pEntities;
	int tile_size = 32;
	int grid_width;
	int grid_height;
  SDL_Texture * m_CurrentTexture;
  CTextureHandler m_TextureHandler; 	
	
  // To place a tile, we need to find out what tile type it is,
  // then its position relative to the players mouse, and if its in an adjacent block
  void PlaceTile(const TileType& tiletype, const Vector2 &tile_pos, std::string texture_id);


  // Now to write this whole thing using my own stuff
  std::vector<std::vector<Tile>> tiles;
  SDL_Texture* adj_texture;
	SDL_Rect tile1;
	SDL_Rect tile2;
	std::vector<Tile> grid;
	SDL_Texture* tile_texture;
	Vector2 FindInGrid(Vector2 item);
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
