#pragma once
#include "GameObject.h"

class StaticObject : public GameObject {
public:
	void update(const sf::Time& deltaTime) {};
	void act(const sf::Time& deltaTime) override {};
	void collide(GameObject& other) override;
protected:
	StaticObject();
	StaticObject(const sf::Vector2f& location);

};