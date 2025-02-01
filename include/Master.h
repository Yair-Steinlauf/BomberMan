#pragma once
#include "GameManager.h"
#include "Menu.h"
#include "GameOverScreen.h"
#include "PauseScreen.h"
#include "DataLoader.h"
#include "Types.h"
class Master {
public:
	Master();
	void run();

private:
	void handelEvent(sf::Event& event, sf::RenderWindow& window, sf::Time& deltaTime, bool &isMouseClicked);
	
	sf::Music m_backgroundMusic;
	GameManager m_game;
	PauseScreen m_pauseScreen;
	Menu m_menu;
	GameOverScreen m_GameOver;
	enum GameState m_status = MENU;

};