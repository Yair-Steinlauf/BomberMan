#pragma once
#include "Screens.h"

class Menu :public Screens {
public:
	Menu();
	void eventHandler(sf::Event& event, sf::RenderWindow& window, GameState& status, sf::Music &backgroundMusic);
private:
	void loadButtomsVector() override;
	void handleClick(sf::Vector2f& mousePos, GameState& status, sf::Music& backgroundMusic) override;
	

};