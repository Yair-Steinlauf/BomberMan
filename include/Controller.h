#pragma once
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "Board.h"

class Controller {
public:
	Controller();
	void run();
private:
	Board loadNewLevel(const std::string& levelName);
	//Board m_board;
	std::vector<std::string> m_levels;
	std::vector<std::string> getLevels();
};