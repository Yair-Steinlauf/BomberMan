#pragma once
#include "SFML/Graphics.hpp"
#include "Screens.h"
#include <SFML/Audio/Music.hpp>

class PauseScreen : public Screens
{
public:
	PauseScreen();
	void pauseClicked(int score);
	void eventHandler(sf::Event &event, sf::RenderWindow &window, GameState &status);

private:
	void handleClick(sf::Vector2f &mousePos, GameState &status) override;
};