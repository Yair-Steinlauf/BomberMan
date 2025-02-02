#pragma once
#include <vector>
#include <string>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Types.h"


enum Sound_Type {
	S_START_GAME,
	S_VICTORY,
	S_KEY,
	S_GIFT,
	S_DEFEAT,
	S_COLLID_GUARD,
	S_LEVEL_UP
};

class SoundHandle {
public:
	~SoundHandle();
	static SoundHandle& getInstance();
	void playSound(Sound_Type soundType);
	void changeSoundMode();
	bool getIsSoundOn();

private:
	SoundHandle();
	std::vector<sf::SoundBuffer> m_buffers;
	std::vector<sf::Sound> m_sounds;
	bool m_isSoundOn = true;

};

