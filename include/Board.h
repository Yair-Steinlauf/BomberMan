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


class Board {
public:
	Board();
	Board(std::ifstream& file);
	void draw(sf::RenderWindow& window);
	void update(const sf::Time& deltaTime);
	Player& getPlayer();
	void addObject(ObjectType type, sf::Vector2f location);
	std::vector<std::string> fileTo2DString(std::ifstream& file) ;
	void loadFromFile(std::ifstream& file);
	sf::Vector2f rowColToLocation(unsigned int row, unsigned int col) const;
	sf::Vector2f getDimension()const;
private:
	Player m_player;
	std::vector<std::unique_ptr<GameObject>> m_board;
	sf::Vector2f m_dimension;

};