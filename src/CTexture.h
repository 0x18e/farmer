#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Utilities.h"
#include "CRenderer.h"
#include <string>
#include <map>

class CTextureHandler {

private:
	SDL_Texture* m_CurrentTexture;
	int m_nWidth;
	int m_nHeight;
	int m_nScale;
	std::map<std::string, SDL_Texture*> m_Textures;
public:
	CTextureHandler() : m_CurrentTexture(nullptr), m_nWidth(0), m_nHeight(0), m_nScale(1) {};
	~CTextureHandler();
	
	
	bool LoadTexture(const char* path, std::string id);
	SDL_Texture* GetTexture() const;
	void RenderTexture(Vector2 point, SDL_Rect* clip = nullptr, double angle = 0, SDL_Point* center = nullptr, SDL_RendererFlip fliptype = SDL_RendererFlip::SDL_FLIP_NONE);
	void SetCurrentTexture(std::string id);
	
	


	void SetScale(int scale);
	int GetWidth() { return this->m_nWidth * m_nScale; };
	int GetHeight() { return this->m_nHeight * m_nScale;};

	
	void Cleanup();
};
// This will be a simpler version of the texture handler
// The texture handler handles textures for the entire game
class CTexture {

  private:
  SDL_Texture* m_Texture;  // This will be the main texture of the tile
  CTexture() : m_Texture(nullptr) {}; 
public:

  void SetTexture(SDL_Texture* text){
    if (text != nullptr){
      this->m_Texture = text;
    }
  }
  
  ~CTexture(); 
    


};
