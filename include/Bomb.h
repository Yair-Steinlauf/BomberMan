#pragma once
#include "StaticObject.h"

enum BombState {
	SAFE,
	DANGER,
	AFTER_EXPLOAD
};

class Bomb : public StaticObject{
public:
	Bomb(const sf::Vector2f& location, float scaler);
	void act(const sf::Time& deltaTime) override;
	void collide(GameObject& other) override;
	void update(const sf::Time& deltaTime) override;
	static int counter;
private:
	BombState m_stateBomb = SAFE;
	sf::Time m_timer = sf::seconds(5.0f);
	void explode();

};