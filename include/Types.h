#pragma once
#include "SFML/Graphics.hpp"

enum ObjectType
{
	BOMB,
	EXPLODED,
	VICTORY,
	DEFEAT,
	PLAYER = '/',
	GUARD = '!',
	DOOR = 'D',
	WALL = '#',
	STONE = '@',
	LIFEGIFT = 'G',
	KEY = 'K',
	GUARDGIFT = 'X',
	FREEZGIFT = 'F',
	EXTRATIMEGIFT = 'E'
};

enum Direction
{
	UP,
	DOWN,
	RIGHT,
	LEFT,
	UPRIGHT,
	UPLEFT,
	DOWNRIGHT,
	DOWNLEFT,
	DEFAULT
};

enum GameState
{
	MENU,
	PLAYING,
	GAMEOVER,
	REMATCH,
	PAUSE,
	HELP,
	RETURN
};

static const int WINDOW_WIDTH = 800;
static const int WINDOW_HIGTH = 600;

static const sf::Vector2f ImageDimension = sf::Vector2f(256.0f, 256.0f);
static const float scoreBoardPadding = 110.f;
