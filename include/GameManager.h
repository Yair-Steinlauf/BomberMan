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
	void restartGame();
	Board m_board;
	Player* m_player;
	int m_currLevel = 0;
	std::vector<std::string> m_levels;
	std::vector<std::string> getLevels();
	std::vector<sf::Text> m_scoreDetail;
	Board loadNewLevel(const std::string& levelName);
	Direction eventToDirection(sf::Event& event);
	sf::Text createScoreText(std::string text, sf::Vector2f location);
	
};

const sf::Vector2f scoreDetailsSize(WINDOW_WIDTH, 100.0f);