#include "Pickables.h"

class Key : public Pickables {
public:
	Key();
	Key(const sf::Vector2f& location);
	void collide(GameObject& other) override;

private:
};