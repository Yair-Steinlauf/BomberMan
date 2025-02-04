#pragma once
#include "MovingObject.h"

class Guard :public MovingObject {
public:
	Guard();
	Guard(const sf::Vector2f& location);
	void update(const sf::Time& deltaTime) override;
	void collide(GameObject& other) override;
	void act(const sf::Time& deltaTime , const sf::Vector2f& playerLoc);
	void collideWithGuard(Guard& guard) override {};
	static unsigned int getNumOfGuard();
private:
	static unsigned int m_numOfGuard;
	Direction smartMove(const sf::Vector2f& playerLoc);
	Direction randMove();
};