#pragma once
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "Board.h"
#include "Screens.h"



class GameManager : public Screens{
public:
	GameManager();
	void drawNDisplay(sf::RenderWindow& window, sf::Time& deltaTime);
	void eventHandler(sf::Event& event, GameState& status);
	static GameManagerState m_state; //TODO: chek if needed

	int getPlayerScore() const;
	bool isWon();
		
private:
	//void playerEvent(sf::Event& event, const sf::Time& deltaTime);
	bool loadNextLevel();
	void restartGame();
	void update(sf::Time& deltaTime);
	Board m_board;
	Player* m_player;
	int m_currLevel = 0;
	
	
	std::vector<std::string> m_levels;
	std::vector<std::string> getLevels();
	std::vector<sf::Text> m_scoreDetail;
	Board loadNewLevel(const std::string& levelName);
	Direction eventToDirection(sf::Event& event);
	sf::Text createScoreText(std::string text, sf::Vector2f location);
	sf::Time m_timer;
	
	
};

const sf::Vector2f scoreDetailsSize(0, 100.0f);