#pragma once
#include "GameObject.h"

class StaticObject : public GameObject {
public:
	void update(const sf::Time& deltaTime) {};
	void act(const sf::Time& deltaTime , const sf::Vector2f& playerLoc) override {};
	void collide(GameObject& other) override;
	void collideWithGuard(Guard& guard) override{};
protected:
	StaticObject();
	StaticObject(const sf::Vector2f& location, float scaler);

};