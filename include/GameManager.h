#pragma once
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "Board.h"
#include "Screens.h"
#include <bitset>

class GameManager : public Screens{
public:
	GameManager();
	void drawNDisplay(sf::RenderWindow& window, sf::Time& deltaTime);
	void eventHandler(sf::Event& event, GameState& status);
	static bool m_removeGuardGift;
	static bool m_guardFreeze;
	static bool m_guardBombed;
	int getPlayerScore() const;
	bool isWon();
	
		
private:
	//void playerEvent(sf::Event& event, const sf::Time& deltaTime);
	bool loadNextLevel();
	void restartLevel();
	void update(sf::Time& deltaTime);
	Board m_board;
	Player* m_player;
	int m_currLevel = 0;
	int m_startLevelScore = 0;
	
	std::vector<std::string> m_levels;
	std::vector<std::string> getLevels();
	std::vector<sf::Text> m_scoreDetail;
	Board loadNewLevel(const std::string& levelName);
	Direction eventToDirection(sf::Event& event);
	sf::Text createScoreText(std::string text, sf::Vector2f location);
	sf::Time m_timer;
	
	
	
};

