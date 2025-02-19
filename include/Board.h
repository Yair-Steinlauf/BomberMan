#pragma once
#include "GameObject.h"
#include "fstream"
#include "string"
#include "memory"
#include "vector"
#include "Player.h"
#include "Guard.h"
#include "Door.h"
#include "Stone.h"
#include "Wall.h"
#include "LifeGift.h"
#include "GuardGift.h"
#include "FreezGift.h"
#include "ExtraTimeGift.h"
#include "Key.h"
#include "Bomb.h"

class Board
{
public:
	Board();
	Board(std::ifstream &file);
	void draw(sf::RenderWindow &window);
	void update(const sf::Time &deltaTime);
	sf::Vector2f getDimension() const;
	void act(const sf::Time &deltaTime);
	void addObject(ObjectType type, sf::Vector2f location, bool visible = true);
	void collideHandler();
	Player &getPlayer();
	void tryAgain();
	unsigned int getNumOfGuards() const;

private:
	sf::Vector2f rowColToLocation(unsigned int row, unsigned int col) const;
	std::vector<std::string> fileTo2DString(std::ifstream &file);
	void loadFromFile(std::ifstream &file);
	float scalerCalc() const;
	std::vector<std::unique_ptr<GameObject>> m_board;
	sf::Vector2f m_dimension;
	Player *m_player;
	unsigned int m_numOfGuards = 0;
};