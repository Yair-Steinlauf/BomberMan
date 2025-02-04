#pragma once
#include "MovingObject.h"

class Player : public MovingObject {
public:
	Player();
	Player(const sf::Vector2f& location);
	void update(const sf::Time& deltaTime) override;
	void collide(GameObject& other) override;
	void act(const sf::Time& deltaTime , const sf::Vector2f& playerLoc) override;
	void collideWithDoor(Door& door) override;
	void collideWithGuard(Guard& guard) override;
	void collideWithKey(Key& key) override;
	void collideWithLifeGift(LifeGift& lifeGift) override;
	void collideWithGuardGift(GuardGift& guardGift) override;
	void collideWithFreezGift(FreezGift& freezGift) override;
	void collideWithExtraTimeGift(ExtraTimeGift& extraTimeGift) override;
	bool gotGuardGift();
	bool gotExtraTimeGift();
	bool gotCollidWithGuard();
	sf::Time gotFreezGift(sf::Time& deltaTime);
	bool won()const;
	bool gotKey()const;
	int getScore();
	void addScore(int score);
	void decreaseScore(int score);
	void setScore(int score);
	void resetScore();

private:
	int m_score = 0;
	bool m_win = false;
	bool m_Key = false;
	bool m_isGotGuardGift = false;	
	sf::Time m_freezGiftTime;
	bool m_isGotExtraTimeGift = false;
	bool m_collidWithGuard = false;

};