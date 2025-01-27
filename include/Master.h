#pragma once
#include "GameManager.h"
#include "Menu.h"
#include "WinLoseScreen.h"
#include "DataLoader.h"
#include "Types.h"
class Master {
public:
	Master();
	void run();

private:
	void handelEvent(sf::Event& event, sf::RenderWindow& window, sf::Time& deltaTime);
	GameManager m_game;
	Menu m_menu;
	WinLoseScreen m_winLose;
	enum GameState m_status = MENU;

};