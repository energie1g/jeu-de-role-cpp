#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Element.h"
#include "Guerrier.h"
#include "Obstacle.h"
#include "Projectile.h"

class Carte : public Element {

	private:
		int width = 1280;
		int height = 768;
		sf::Texture tileTexture;
		int map[50][50];
		int loadCounterX = 0, loadCounterY = 0;
		std::vector<Obstacle> obstacles;
		std::vector<Obstacle>::const_iterator obsIt;
		int oCnt = 0;
		int pCnt = 0;
		//sf::RenderWindow win;

	public:
		Carte(const std::string &f);
		void update(Guerrier& guerrier, std::vector<Projectile>& proj, std::vector<Projectile>::const_iterator it);
		void updateGuerrierCollision(Guerrier& guerrier, Guerrier& guerrier2);
		void draw(sf::RenderWindow& window);
		int getWidth() { return width; };
		int getHeight() { return height; };
		void ajoutGuerrier();
		void ajoutObjectRamassable();
};