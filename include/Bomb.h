#pragma once
#include "StaticObject.h"

enum BombState
{
	SAFE,
	DANGER,
	AFTER_EXPLOAD
};

class Bomb : public StaticObject
{
public:
	Bomb(const sf::Vector2f &location, float scaler);
	Bomb(const sf::Vector2f &location, float scaler, bool visible);
	void act(const sf::Time &deltaTime, const sf::Vector2f &playerLoc) override;
	void collide(GameObject &other) override;
	void update(const sf::Time &deltaTime) override;
	static int counter;

private:
	bool m_visible;
	BombState m_stateBomb = SAFE;
	sf::Time m_timer = sf::seconds(3.0f);
	void explode();
};