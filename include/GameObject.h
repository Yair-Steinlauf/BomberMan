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
class StaticObject;

class GameObject {
public:
	virtual void draw(sf::RenderWindow& window);
	sf::Vector2f getLocation()const;
	virtual void update(const sf::Time& deltaTime) = 0;
	bool intersect(GameObject& other);
	virtual void collide(GameObject& other) =0;
	virtual void collideWithPlayer(Player& player) {};
	virtual void collideWithGuard(Guard& guard) {};
	virtual void collideWithStone(Stone& stone) {};
	virtual void collideWithStatic(StaticObject& wall) {};
	virtual void collideWithDoor(Door& ddor) {};
	sf::Vector2f getBottomRight() const;
	sf::Vector2f getTopLeft() const;
	virtual void act(const sf::Time& deltaTime) = 0;
	virtual ~GameObject();
protected:
	GameObject(const GameObject&) = default;
	GameObject& operator=(const GameObject&) = default;
	GameObject();
	GameObject(const sf::Vector2f& location);
	void setLocation(const sf::Vector2f& newLocation);
	bool isHigherThan(const GameObject& other) const;
	bool isLeftThan(const GameObject& other) const;
	sf::Sprite m_sprite;

};