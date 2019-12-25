#pragma once
#include "Element.h"
class Obstacle : public Element {

	public:
		Obstacle() = default;
		Obstacle(const sf::Sprite& sprite, int x, int y);
};

