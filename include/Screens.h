#pragma once
#include "SFML/Graphics.hpp"
#include "DataLoader.h"
#include "vector"
#include <SFML/Audio/Music.hpp>
#include "SoundHandle.h"

enum BUTTOM
{
	START,
	EXIT,
	SOUND,
	MUSIC,
	AGAIN,
	RESUME,
	S_HELP,
	BACK
};

class Screens
{
public:
	Screens() = default;
	virtual void drawNDisplay(sf::RenderWindow &window, GameState &status);
	virtual void eventHandler(sf::Event& event, sf::RenderWindow& window, GameState& status);

protected:
	virtual void loadButtomsVector() {};
	sf::Text createButtom(std::string text, sf::Vector2f location);
	virtual void handleClick(sf::Vector2f &mousePos, GameState &status) {};
	std::vector<std::pair<BUTTOM, sf::Text>> m_Buttoms;
	sf::Text m_sfText;
	sf::Sprite m_gameOverImage;
};