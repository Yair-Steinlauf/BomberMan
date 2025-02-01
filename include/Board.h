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
#include "Gift.h"
#include "GuardGift.h"
#include "FreezGift.h"
#include "ExtraTimeGift.h"
#include "Key.h"


class Board {
public:
	Board();
	Board(std::ifstream& file);
	void draw(sf::RenderWindow& window);
	void update(const sf::Time& deltaTime, bool isFreezGuards);
	sf::Vector2f getDimension()const;
	void act(const sf::Time& deltaTime);
	void collideHandler();
	Player& getPlayer();
	int getCountGuards();
	void eraseGuard();
	
private:
	sf::Vector2f rowColToLocation(unsigned int row, unsigned int col) const;
	std::vector<std::string> fileTo2DString(std::ifstream& file) ;
	void addObject(ObjectType type, sf::Vector2f location);
	void loadFromFile(std::ifstream& file);
	void tryAgain();
	std::vector<std::unique_ptr<GameObject>> m_board;
	sf::Vector2f m_dimension;
	
	

};