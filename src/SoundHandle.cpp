#include "SoundHandle.h"

SoundHandle::~SoundHandle() {}

SoundHandle& SoundHandle::getInstance() {
	static SoundHandle instance;
	return instance;
}

void SoundHandle::playSound(Sound_Type soundType)
{
	if(m_isSoundOn)
		m_sounds[soundType].play();
}

void SoundHandle::changeSoundMode()
{
	m_isSoundOn = !m_isSoundOn;
}

bool SoundHandle::getIsSoundOn()
{
	return m_isSoundOn;
}



SoundHandle::SoundHandle() {

	if (!m_backgroundMusic.openFromFile("background-music.ogg")) {
		std::cerr << "Error loading music!" << std::endl;
		exit(EXIT_FAILURE);
	}
	m_backgroundMusic.setLoop(true);
	m_backgroundMusic.setVolume(100);
	m_backgroundMusic.play();

	const std::vector<std::pair<enum Sound_Type, std::string>> soundNames =
	{ { S_START_GAME, "S_START_GAME" } ,
		{ S_VICTORY, "S_VICTORY" },
		{ S_KEY, "S_KEY" },
		{ S_GIFT, "S_GIFT" },
		{ S_DEFEAT, "S_DEFEAT" },
		{S_COLLID_GUARD , "S_COLLID_GUARD"},
		{S_LEVEL_UP, "S_LEVEL_UP"},
		{S_EXPLODE, "S_EXPLODE"},
		{S_GUARDBOMBED, "S_GUARDBOMBED"},

	};
	int i = 0;
	for (const auto& object : soundNames)
	{		
		sf::SoundBuffer soundBuffer;
		sf::Sound sound;
		m_buffers.push_back(soundBuffer);
		m_sounds.push_back(sound);		
		std::string name = object.second + ".wav";		
		m_buffers[i].loadFromFile(name);
		i++;
	}
	for (int j = 0; j < m_buffers.size(); j++)
	{
		m_sounds[j].setBuffer(m_buffers[j]);
	}



}