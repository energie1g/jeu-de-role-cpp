#pragma once
#include "Element.h"

class Projectile : public Element {
	private:
		std::string playerID = "first";
		int vitesseMovement = 10;
		int degatsAttaque = 5;
		int direction = 0; // 1-up / 2-down / 3-left / 4-right
		int counterAnimation = 0;
		int counterLifeTime = 0;
		int lifeTime = 100;

	public:
		bool destroy = false;
		Projectile(std::string playerID);
		void update();
		int getDirection() { return direction; };
		void setDirection(int dir) { direction = dir; };
		int getDestroy() { return destroy; };
		void setDestroy(bool dest) { destroy = dest; };
		void setdDegatsAttaque(int degatsAttaque) { this->degatsAttaque = degatsAttaque; };
		int getDegatsAttaque() { return degatsAttaque; };
		std::string getPlayerID() { return playerID; };
};

