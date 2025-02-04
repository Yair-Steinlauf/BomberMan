#pragma once
#include "SFML/Graphics.hpp"
#include "Types.h"
#include "DataLoader.h"
#include "SoundHandle.h"

//----Forward decleration----
class Player;
class Guard;
class Wall;
class Stone;
class Door;
class StaticObject;
class LifeGift;
class GuardGift;
class FreezGift;
class ExtraTimeGift;
class Pickables;
class Key;
class Bomb;

class GameObject {
public:
	virtual void draw(sf::RenderWindow& window);
	sf::Vector2f getLocation()const;
	virtual void update(const sf::Time& deltaTime) = 0;
	virtual void act(const sf::Time& deltaTime , const sf::Vector2f& playerLoc) = 0;
	bool intersect(GameObject& other);
	virtual void moveToStartPos() {};
	virtual void collide(GameObject& other) =0;
	virtual void collideWithPlayer(Player& player) {};
	virtual void collideWithGuard(Guard& guard) = 0;
	virtual void collideWithStone(Stone& stone) {};
	virtual void collideWithStatic(StaticObject& wall) {};
	virtual void collideWithDoor(Door& ddor) {};
	virtual void collideWithLifeGift(LifeGift& lifeGift) {};
	virtual void collideWithGuardGift(GuardGift& guardGift) {};
	virtual void collideWithFreezGift(FreezGift& freezGift) {};
	virtual void collideWithExtraTimeGift(ExtraTimeGift& extraTimeGift) {};
	virtual void collideWithPickable(Pickables& pickable) {};
	virtual void collideWithKey(Key& key) {};
	virtual void collideWithBomb(Bomb& key) {};
	sf::Vector2f getBottomRight() const;
	sf::Vector2f getTopLeft() const;
	bool isActive() const;
	void setNoActive();
	virtual ~GameObject();
	void setScale(float factor);
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