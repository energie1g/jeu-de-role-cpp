#pragma once
#include<iostream>
#include "Element.h"
#include "Projectile.h"

class Guerrier : public Element {
	private:
		std::string playerID = "first";
		int hp = 100;
		float speedMovement = 2;
		int counterWalking = 0;
		int direction = 0; // 1-up / 2-down / 3-left / 4-right
		float frameCounter = 0, switchFrame = 100, frameSpeed = 500;
		sf::Clock clock;
		bool moveTop = true, moveBottom = true, moveRight = true, moveLeft = true;

	public:
		Guerrier(std::string player, int x, int y);
		std::vector<Projectile>::const_iterator it;
		std::vector<Projectile> projectileArr;
		std::string getPlayerID() { return playerID; };
		void update();
		void updateMovement();
		void playerCollision(Guerrier& gc);
		int& getDirection();
		void setMoveTop(bool mt) { moveTop = mt; }
		void setMoveBottom(bool mb) { moveBottom = mb; }
		void setMoveRight(bool mr) { moveRight = mr; }
		void setMoveLeft(bool ml) { moveLeft = ml; }
		bool getMoveTop(bool mt) { return moveTop; }
		bool getMoveBottom(bool mb) { return moveBottom; }
		bool getMoveRight(bool mr) { return moveRight; }
		bool getMoveLeft(bool ml) { return moveLeft; }
		void setHp(int hp) { this->hp = hp; };
		int getHp() { return hp; };
};