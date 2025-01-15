#pragma once
#include "SFML/Graphics.hpp"
enum ObjectType {
	PLAYER = '/',
	GUARD = '!',
	DOOR = 'D',
	WALL = '#',
	STONE = '@',
	GIFT
};

enum GameState {
	MENU,
	PLAYING,
	GAMEOVER
};

static const float DefaultSpeed = 1.0f;

static const sf::Vector2f ImageDimension = sf::Vector2f(256.0f, 256.0f);