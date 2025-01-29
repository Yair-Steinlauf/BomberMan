#pragma once
#include "SFML/Graphics.hpp"
#include "Screens.h"

class GameOverScreen : public Screens {
public:
	GameOverScreen();
	void setIsVictoryNPoints(bool isVictory, int points);
	void eventHandler(sf::Event& event, sf::RenderWindow& window, GameState& status);
private:
	void handleClick(sf::Vector2f& mousePos, GameState& status) override;

};