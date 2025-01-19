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
	sf::Text createButtom(std::string text, sf::Vector2f location);
	void loadButtomsVector();
	void handleClick(sf::Vector2f& mousePos, GameState& status);
	std::vector<std::pair<BUTTOM , sf::Text>> m_Buttoms;
	bool m_startGame;

};