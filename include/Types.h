#pragma once
#include "SFML/Graphics.hpp"




enum ObjectType {
	PLAYER = '/',
	GUARD = '!',
	DOOR = 'D',
	WALL = '#',
	STONE = '@',
	LIFEGIFT = 'G',
	BOMB,
	EXPLODE,
	KEY = 'K',
	SLOWER = 's',
	GUARDGIFT = 'X',
	FREEZGIFT = 'F',
	EXTRATIMEGIFT = 'E'
};

enum Direction {
	UP, DOWN, RIGHT, LEFT, UPRIGHT, UPLEFT, DOWNRIGHT, DOWNLEFT, DEFAULT
};

enum GameState {
	MENU,
	PLAYING,
	GAMEOVER,
	REMATCH,
	PAUSE
};

static const float DefaultSpeed = 1.0f;
static const int WINDOW_WIDTH = 800;
static const int WINDOW_HIGTH = 600;

static const sf::Vector2f ImageDimension = sf::Vector2f(256.0f , 256.0f );