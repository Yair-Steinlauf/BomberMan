#pragma once
#include "SFML/Graphics.hpp"
#include "DataLoader.h"
#include "vector"

enum BUTTOM {
	START,
	EXIT,
	SOUND,
	MUSIC,
	REMATCH,
	RESUME,
};

class Screens {
public:
	Screens() = default;
	virtual void drawNDisplay(sf::RenderWindow& window);
	virtual void eventHandler(sf::Event& event, sf::RenderWindow& window, GameState& status);
protected:
	virtual void loadButtomsVector() {};
	sf::Text createButtom(std::string text, sf::Vector2f location);
	virtual void handleClick(sf::Vector2f& mousePos, GameState& status) {};
	std::vector<std::pair<BUTTOM, sf::Text>> m_Buttoms;
};