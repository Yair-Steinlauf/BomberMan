#pragma once
#include "GameManager.h"
#include "Menu.h"
#include "WinLoseScreen.h"
#include "DataLoader.h"
#include "Types.h"
class Master {
public:
	Master() = default;
	void run();

private:
	void handelEvent(sf::Event& event, sf::RenderWindow& window, sf::Time& deltaTime ,GameState& status);
	Controller m_game;
	Menu m_menu;
	GameState m_status = MENU;

};