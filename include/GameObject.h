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
class Gift;
class GuardGift;
class FreezGift;
class ExtraTimeGift;
class Pickables;
class Key;

class GameObject {
public:
	virtual void draw(sf::RenderWindow& window);
	sf::Vector2f getLocation()const;
	virtual void update(const sf::Time& deltaTime) = 0;
	virtual void act(const sf::Time& deltaTime) = 0;
	bool intersect(GameObject& other);
	virtual void collide(GameObject& other) =0;
	virtual void collideWithPlayer(Player& player) {};
	virtual void collideWithGuard(Guard& guard) = 0;
	virtual void collideWithStone(Stone& stone) {};
	virtual void collideWithStatic(StaticObject& wall) {};
	virtual void collideWithDoor(Door& ddor) {};
	virtual void collideWithGift(Gift& gift) {};
	virtual void collideWithGuardGift(GuardGift& guardGift) {};
	virtual void collideWithFreezGift(FreezGift& freezGift) {};
	virtual void collideWithExtraTimeGift(ExtraTimeGift& extraTimeGift) {};
	virtual void collideWithPickable(Pickables& pickable) {};
	virtual void collideWithKey(Key& key) {};
	sf::Vector2f getBottomRight() const;
	sf::Vector2f getTopLeft() const;
	bool isActive() const;
	void setNoActive();
	virtual ~GameObject();
protected:
	bool m_isActive = true;
	GameObject(const GameObject&) = default;
	GameObject& operator=(const GameObject&) = default;
	GameObject();
	GameObject(const sf::Vector2f& location);
	void setLocation(const sf::Vector2f& newLocation);
	sf::Sprite m_sprite;
	bool isHigherThan(const GameObject& other) const;
	bool isLeftThan(const GameObject& other) const;

};