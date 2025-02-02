#pragma once
#include "SFML/Graphics.hpp"
#include "Screens.h"

class GameOverScreen : public Screens {
public:
	GameOverScreen();
	void setIsVictoryNScore(bool isVictory, int score, sf::Music& backgroundMusic);
	void eventHandler(sf::Event& event, sf::RenderWindow& window, GameState& status, sf::Music &backgroundMusic, bool& isMouseClicked);
private:
	void handleClick(sf::Vector2f& mousePos, GameState& status, sf::Music& backgroundMusic, bool &isMouseClicked) override;

};