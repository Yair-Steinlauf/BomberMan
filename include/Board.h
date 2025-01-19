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
	sf::Vector2f getDimension()const;
	void setDirection(const sf::Time& deltaTime);
	void collideHandler();
	Player& getPlayer();
private:
	sf::Vector2f rowColToLocation(unsigned int row, unsigned int col) const;
	std::vector<std::string> fileTo2DString(std::ifstream& file) ;
	void addObject(ObjectType type, sf::Vector2f location);
	void loadFromFile(std::ifstream& file);
	void tryAgain();
	std::vector<std::unique_ptr<GameObject>> m_board;
	sf::Vector2f m_dimension;

};