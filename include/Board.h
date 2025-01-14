#pragma once
#include "GameObject.h"
#include "fstream"
#include "string"
#include "memory"
#include "Player.h"
#include "Guard.h"
#include "MovingObject.h"
#include "StaticObject.h"
class Board {
public:
	Board(std::string& fileName);
	void draw(sf::RenderWindow& window) const;
	void update(const sf::Event& event, const sf::Time& deltaTime);
private:
	std::vector<std::unique_ptr<GameObject>> m_objects;
	sf::Vector2f m_dimension;
	enum ObjectType charToObjectType(const char& a) const;
	std::vector<std::string> fileToString(std::ifstream& file) const;
	sf::Vector2f getDimension()const;
	sf::Vector2f rowColToLocation(unsigned int row, unsigned int col) const;
	void addObject(ObjectType type, sf::Vector2f location);
};