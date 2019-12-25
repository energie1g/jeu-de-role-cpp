#include "Projectile.h"

Projectile::Projectile(std::string playerID) : playerID(playerID) {
	rect.setSize(sf::Vector2f(8, 8));
	rect.setPosition(0, 0);
	rect.setFillColor(sf::Color::Blue);
	sprite.setTextureRect({ 197, 117, 8, 8 });
}

void Projectile::update() {
	if (direction == 1) {
		rect.move(0, -vitesseMovement);
		sprite.setTextureRect({ 197 + (8 + 9) * counterAnimation, 117, 8, 8 });
	}

	if (direction == 2) {
		rect.move(0, vitesseMovement);
		sprite.setTextureRect({ 197 + (8 + 9) * counterAnimation, 117, 8, 8 });
	}

	if (direction == 3) {
		rect.move(-vitesseMovement, 0);
		sprite.setTextureRect({ 197 + (8 + 9) * counterAnimation, 117, 8, 8 });
	}

	if (direction == 4) {
		rect.move(vitesseMovement, 0);
		sprite.setTextureRect({ 197 + (8 + 9) * counterAnimation, 117, 8, 8 });
	}

	counterLifeTime++;
	if (counterLifeTime >= lifeTime) {
		destroy = true;
	}

	counterAnimation++;
	if (counterAnimation == 3) {
		counterAnimation = 0;
	}
	sprite.setPosition(rect.getPosition());
}