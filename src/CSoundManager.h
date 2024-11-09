#pragma once
#include<SDL_mixer.h>
#include "Utilities.h"
#include <map>
#include <string>


class CSoundManager {
private:
	CSoundManager() {};
	~CSoundManager();
	static CSoundManager m_sInstance;
public:
	
	static CSoundManager& Get() {
		return m_sInstance;
	}

	std::map<std::string, Mix_Chunk*> m_pSounds;

	bool Init();
	void PlaySound(std::string sound);


};