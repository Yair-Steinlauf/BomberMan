#pragma once
#include "Controller.h"
#include "Menu.h"
#include "WinLoseScreen.h"
#include "DataLoader.h"

class Master {
public:
	Master() = default;
	void run();

private:
	Controller m_game;
	Menu m_menu;

};