#pragma once
#include "SFML/Graphics.hpp"
#include "DataLoader.h"
#include "vector"

enum BUTTOM {
	START,
	EXIT,
	SOUND,
	MUSIC
};

class Menu {
public:
	Menu();
	void run(sf::RenderWindow& window);
private:
	void handleClick(sf::Vector2f& mousePos);
	std::vector<std::pair<BUTTOM , sf::Text>> m_Buttoms;
	void drawNDisplay(sf::RenderWindow& window);
	sf::Font m_font;
	bool m_startGame;

};