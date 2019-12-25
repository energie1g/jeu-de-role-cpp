#include "Obstacle.h"

Obstacle::Obstacle(const sf::Sprite& spr, int x, int y) {
	rect.setSize(sf::Vector2f(32, 32));
	rect.setPosition(x, y);
	sprite = spr;
}