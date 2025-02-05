#pragma once
#include "GameManager.h"
#include "Menu.h"
#include "GameOverScreen.h"
#include "PauseScreen.h"
#include "HelpScreen.h"
#include "DataLoader.h"
#include "Types.h"
class Master {
public:
	Master();
	void run();

private:
	void handelEvent(sf::Event& event, sf::RenderWindow& window);
	void drawNdisplay(sf::RenderWindow& window, sf::Time& deltaTime);
// to update in cpp logic
	// void handelEvent(sf::Event& event, sf::RenderWindow& window, sf::Time& deltaTime, bool &isMouseClicked);
	
	
	GameManager m_game;
	PauseScreen m_pauseScreen;
	Menu m_menu;
	GameOverScreen m_GameOver;
	HelpScreen m_helpScreen;
	enum GameState m_status = MENU;
	enum GameState m_lastStatus = MENU;

};