#pragma once
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "Board.h"
#include "Screens.h"

class GameManager : public Screens{
public:
	GameManager();
	bool loadNextLevel();
	void update(sf::Time& deltaTime);
	void drawNDisplay(sf::RenderWindow& window);
	void eventHandler(sf::Event& event, sf::Time& deltaTime, GameState& status);
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

const sf::Vector2f scoreDetailsSize(0, 100.0f);