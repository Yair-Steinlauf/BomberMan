#pragma once
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "Board.h"

class Controller {
public:
	Controller();
	bool loadNextLevel();
	void update(sf::Time& deltaTime);
	void screenDrawNDisplay(sf::RenderWindow& window);
	void handelEvent(sf::Event& event, sf::Time& deltaTime, GameState& status);
private:
	Board m_board;
	Player* m_player;
	sf::RenderWindow m_window;
	int m_currLevel = 0;
	Board loadNewLevel(const std::string& levelName);
	Direction eventToDirection(sf::Event& event);
	std::vector<std::string> m_levels;
	std::vector<std::string> getLevels();
};