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
	void drawNDisplay(sf::RenderWindow& window);
	void eventHandler(sf::Event& event, sf::RenderWindow& window, GameState& status);
private:
	void handleClick(sf::Vector2f& mousePos, GameState& status);
	std::vector<std::pair<BUTTOM , sf::Text>> m_Buttoms;
	sf::Font m_font;
	bool m_startGame;

};