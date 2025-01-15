#pragma once
#include "GameObject.h"

class MovingObject : public GameObject {
public:
	MovingObject(enum ObjectType type, const sf::Vector2f& location);
	//virtual sf::Vector2f move(sf::Time deltaTime, const sf::Event& type) {};
	void setSpeed(const float newSpeed);

protected:
	sf::Vector2f diffMove(sf::Time deltaTime) const;
	float m_speed = DefaultSpeed;

	void increaseHealth() override;
	void decreaseHealth() override;

};
