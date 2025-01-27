#pragma once
#include "SFML/Graphics.hpp"
enum ObjectType {
	PLAYER = '/',
	GUARD = '!',
	DOOR = 'D',
	WALL = '#',
	STONE = '@',
	GIFT = 'G',
	KEY = 'K'
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
static const int WINDOW_WIDTH = 800;
static const int WINDOW_HIGTH = 600;
static const sf::Vector2f ImageDefDimension = sf::Vector2f(256, 256);
static const float ImageScale = 1;//0.5* std::min(ImageDefDimension.x/WINDOW_WIDTH, ImageDefDimension.y / WINDOW_HIGTH);

static const sf::Vector2f ImageDimension = sf::Vector2f(256.0f *ImageScale, 256.0f *ImageScale);