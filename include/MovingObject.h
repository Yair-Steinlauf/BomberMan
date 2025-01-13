#pragma once
#include "GameObject.h"

class MovingObject : public GameObject {
public:
	virtual sf::Vector2f move(float deltaTime, sf::Event type);
	void setSpeed(const sf::Vector2f newSpeed);
protected:
	sf::Vector2f m_speed = { 1.0f,1.0f };

};
