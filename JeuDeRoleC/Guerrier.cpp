#include "Guerrier.h"

Guerrier::Guerrier(std::string playerID, int x, int y) : playerID(playerID) {
	rect.setSize(sf::Vector2f(30, 52));
	//rect.setFillColor(sf::Color::White);
	rect.setPosition(x, y);
	//sprite.setTextureRect({ 9, 6, 33, 49 });
	sprite.setTextureRect({ 20, 588, 24, 50 });
}

void Guerrier::update() {
	sprite.setPosition(rect.getPosition());
}

void Guerrier::updateMovement() {
	if (playerID == "first" && hp > 0) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (moveLeft && rect.getPosition().x > 0) {
				rect.move(-speedMovement, 0);
				//sprite.setTextureRect({ 1 + ((38 + 19) * counterWalking), 62, 38, 43 });
				sprite.setTextureRect({ 20 + ((24 + 40) * counterWalking), 588, 24, 50 });
				//sprite.setOrigin({ rect.getLocalBounds().width / 2, 0 });
				//sprite.setScale({ -1, 1 });
				direction = 3;
				moveLeft = true;
				moveRight = true;
				moveBottom = true;
				moveTop = true;
			}
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (moveRight && rect.getPosition().x < (1280 - rect.getSize().x)) {
				rect.move(speedMovement, 0);
				//sprite.setTextureRect({ 11 + ((38 + 20) * counterWalking), 120, 38, 43 });
				sprite.setTextureRect({ 20 + ((24 + 40) * counterWalking), 716, 24, 50 });
				//sprite.setOrigin({ rect.getLocalBounds().width, 0 });
				//sprite.setScale({ 1, 1 });
				direction = 4;
				moveLeft = true;
				moveRight = true;
				moveBottom = true;
				moveTop = true;
			}
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if (moveTop && rect.getPosition().y > 0) {
				rect.move(0, -speedMovement);
				//sprite.setTextureRect({ 9 + ((28 + 30) * counterWalking), 177, 28, 43 });
				sprite.setTextureRect({ 17 + ((34 + 30) * counterWalking), 525, 30, 48 });
				//std::cout << "PLAYER TOP: " << rect.getGlobalBounds().top << " : WIDTH: " << rect.getGlobalBounds().width << std::endl;
				direction = 1;
				moveLeft = true;
				moveRight = true;
				moveBottom = true;
				moveTop = true;
			}
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			if (moveBottom && rect.getPosition().y < (768 - rect.getSize().y)) {
				rect.move(0, speedMovement);
				sprite.setTextureRect({ 17 + ((34 + 30) * counterWalking), 650 , 30, 52 });
				direction = 2;
				moveLeft = true;
				moveRight = true;
				moveBottom = true;
				moveTop = true;
			}
		}
		else {}
	}
	else if (playerID == "second" && hp > 0) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (moveLeft && rect.getPosition().x > 0) {
				rect.move(-speedMovement, 0);
				//sprite.setTextureRect({ 1 + ((38 + 19) * counterWalking), 62, 38, 43 });
				sprite.setTextureRect({ 20 + ((24 + 40) * counterWalking), 588, 24, 50 });
				//sprite.setOrigin({ rect.getLocalBounds().width / 2, 0 });
				//sprite.setScale({ -1, 1 });
				direction = 3;
				moveLeft = true;
				moveRight = true;
				moveBottom = true;
				moveTop = true;
			}
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (moveRight && rect.getPosition().x < (1280 - rect.getSize().x)) {
				rect.move(speedMovement, 0);
				//sprite.setTextureRect({ 11 + ((38 + 20) * counterWalking), 120, 38, 43 });
				sprite.setTextureRect({ 20 + ((24 + 40) * counterWalking), 716, 24, 50 });
				//sprite.setOrigin({ rect.getLocalBounds().width, 0 });
				//sprite.setScale({ 1, 1 });
				direction = 4;
				moveLeft = true;
				moveRight = true;
				moveBottom = true;
				moveTop = true;
			}
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (moveTop && rect.getPosition().y > 0) {
				rect.move(0, -speedMovement);
				//sprite.setTextureRect({ 9 + ((28 + 30) * counterWalking), 177, 28, 43 });
				sprite.setTextureRect({ 17 + ((34 + 30) * counterWalking), 525, 30, 48 });
				//std::cout << "PLAYER TOP: " << rect.getGlobalBounds().top << " : WIDTH: " << rect.getGlobalBounds().width << std::endl;
				direction = 1;
				moveLeft = true;
				moveRight = true;
				moveBottom = true;
				moveTop = true;
			}
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (moveBottom && rect.getPosition().y < (768 - rect.getSize().y)) {
				rect.move(0, speedMovement);
				sprite.setTextureRect({ 17 + ((34 + 30) * counterWalking), 650 , 30, 52 });
				direction = 2;
				moveLeft = true;
				moveRight = true;
				moveBottom = true;
				moveTop = true;
			}
		}
		else {}
	}

	frameCounter += (frameSpeed * clock.restart().asSeconds()) * 3;
	if (frameCounter >= switchFrame) {
		frameCounter = 0;
		counterWalking++;
		if (counterWalking >= 8) {
			counterWalking = 0;
		}
	}
}

void Guerrier::playerCollision(Guerrier& gc) {
	if (rect.getGlobalBounds().intersects(gc.rect.getGlobalBounds())) {

		if (direction == 1) {
			moveTop = false;
			rect.move(0, 1);
		}
		if (direction == 2) {
			moveBottom = false;
			rect.move(0, -1);
		}
		if (direction == 3) {
			moveLeft = false;
			rect.move(1, 0);
		}
		if (direction == 4) {
			moveRight = false;
			rect.move(-1, 0);
		}

	}
}

int& Guerrier::getDirection() {
	return direction;
}