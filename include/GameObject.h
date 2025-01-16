#pragma once
#include "SFML/Graphics.hpp"
#include "Types.h"
#include "DataLoader.h"

//----Forward decleration----
class Player;
class Guard;
class Wall;
class Stone;
class Door;

class GameObject {
public:
	virtual void draw(sf::RenderWindow& window);
	sf::Vector2f getLocation()const;
	virtual void collide(GameObject& other) =0;
	virtual void collideWithPlayer(Player& player) {};
	virtual void collideWithGuard(Guard& guard) {};
	virtual void collideWithStone(Stone& stone) {};
	virtual void collideWithWall(Wall& Wall) {};
	virtual void collideWithDoor(Door& ddor) {};

	virtual ~GameObject();
protected:
	GameObject(const GameObject&) = default;
	GameObject& operator=(const GameObject&) = default;
	GameObject();
	GameObject(const sf::Vector2f& location);
	void setLocation(const sf::Vector2f& newLocation);
	sf::Sprite m_sprite;

};