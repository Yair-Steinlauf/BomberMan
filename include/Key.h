#include "Pickables.h"

class Key : public Pickables
{
public:
	Key();
	Key(const sf::Vector2f &location, float scaler);
	void collide(GameObject &other) override;

private:
};