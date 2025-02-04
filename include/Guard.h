#pragma once
#include "MovingObject.h"
enum Difficulty {
	Low,
	Mid,
	High,
	Pro
};
class Guard :public MovingObject {
public:
	Guard();
	Guard(const sf::Vector2f& location, float scaler);
	void collide(GameObject& other) override;
	void update(const sf::Time& deltaTime) override;
	void collideWithBomb(Bomb& bomb) override;
	void act(const sf::Time& deltaTime , const sf::Vector2f& playerLoc);
	void collideWithGuard(Guard& guard) override {};
private:
	static void increaseDifficulty();
	void updateToDiffLevel();
	static Difficulty m_difficulty;
	sf::Time m_guardMove = sf::seconds(0);
	Direction smartMove(const sf::Vector2f& playerLoc);
	Direction randMove();
};