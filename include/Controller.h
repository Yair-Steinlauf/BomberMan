#pragma once
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "Board.h"

class Controller {
public:
	Controller();
	void run(sf::RenderWindow& window);
private:
	Board m_board;
	sf::RenderWindow m_window;
	void screenHandler(sf::Time& deltaTime, sf::RenderWindow& window);
	void screenDrawNDisplay(sf::RenderWindow& window);
	Board loadNewLevel(const std::string& levelName);
	Direction eventToDirection(sf::Event& event);
	std::vector<std::string> m_levels;
	std::vector<std::string> getLevels();
};