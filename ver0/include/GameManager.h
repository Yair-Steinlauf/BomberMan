#pragma once
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "Board.h"

class GameManager {
public:
	GameManager();
	void run();
private:
	Board m_board;
	std::vector<std::string> m_levels;
	std::vector<std::string> loadLevels(const std::string& playlist);
	void handelEvent(const sf::Event& event);



	
};