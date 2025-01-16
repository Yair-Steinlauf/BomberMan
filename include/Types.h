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

enum Direction {
	UP, DOWN, RIGHT, LEFT, DEFAULT
};

enum GameState {
	MENU,
	PLAYING,
	GAMEOVER
};

static const float DefaultSpeed = 1.0f;
static const float ImageScale = 0.125;

static const sf::Vector2f ImageDimension = sf::Vector2f(256.0f *ImageScale, 256.0f *ImageScale);