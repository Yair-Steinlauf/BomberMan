#pragma once
#include "Screens.h"

class HelpScreen :public Screens {
public:
	HelpScreen();
	void eventHandler(sf::Event& event, sf::RenderWindow& window, GameState& status);
private:
	void loadButtomsVector() override;
	void handleClick(sf::Vector2f& mousePos, GameState& status) override;


};