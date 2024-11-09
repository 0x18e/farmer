#include "CSoundManager.h"


CSoundManager CSoundManager::m_sInstance;

bool CSoundManager::Init() {
	bool flag = true;

	return flag;
}

void CSoundManager::PlaySound(std::string sound) {
	int check = Mix_PlayChannel(-1, m_pSounds[sound], 0);
	if (check < 0) {
		LOG("Could not play " << sound);
	}
}

CSoundManager::~CSoundManager() {
	// Destroy all loaded sounds
	for (auto sound : m_pSounds) {
		if (sound.second != nullptr) {
			Mix_FreeChunk(sound.second);
			sound.second = nullptr;
		}
	}
	m_pSounds.clear();
}