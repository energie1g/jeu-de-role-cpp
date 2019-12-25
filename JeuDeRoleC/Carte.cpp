#include "Carte.h"

Carte::Carte(const std::string& f) {
	std::ifstream tileSet(f);
	int rowCounter = 0;
	if (tileSet.is_open()) {

		std::string tileLocation;
		tileSet >> tileLocation;
		tileTexture.loadFromFile(tileLocation);
		sprite.setTexture(tileTexture);
		while (!tileSet.eof()) {

			int ID;
			char com;
			tileSet >> ID;
			rowCounter++;

			map[loadCounterX][loadCounterY] = ID;

			if (rowCounter == 40) {
				rowCounter = 0;
				loadCounterX = 0;
				loadCounterY++;
			}
			else {
				loadCounterX++;
			}
			tileSet.ignore();
		}
		tileSet.close();
	}
}

void Carte::update(Guerrier& g, std::vector<Projectile>& proj, std::vector<Projectile>::const_iterator it) {
	oCnt = 0;
	if (obstacles.size() != 0) {
		for (obsIt = obstacles.begin(); obsIt != obstacles.end(); obsIt++) {
			if (g.rect.getGlobalBounds().intersects(obstacles[oCnt].rect.getGlobalBounds())) {

				if (g.getDirection() == 1) {
					g.setMoveTop(false);
					g.rect.move(0, 1);
				}
				if (g.getDirection() == 2) {
					g.setMoveBottom(false);
					g.rect.move(0, -1);
				}
				if (g.getDirection() == 3) {
					g.setMoveLeft(false);
					g.rect.move(1, 0);
				}
				if (g.getDirection() == 4) {
					g.setMoveRight(false);
					g.rect.move(-1, 0);
				}

			}
			oCnt++;
		}
		
		pCnt = 0;
		for (it = proj.begin(); it != proj.end(); it++) {
			oCnt = 0;
			for (obsIt = obstacles.begin(); obsIt != obstacles.end(); obsIt++) {
				if (proj[pCnt].rect.getGlobalBounds().intersects(obstacles[oCnt].rect.getGlobalBounds())) {
					proj[pCnt].destroy = true;
				}

				oCnt++;
			}
			pCnt++;
		}

		pCnt = 0;
		for (it = proj.begin(); it != proj.end(); it++) {
			if (proj[pCnt].getPlayerID() != g.getPlayerID() && proj[pCnt].rect.getGlobalBounds().intersects(g.rect.getGlobalBounds())) {
				proj[pCnt].destroy = true;
				if (g.getHp() > 0) {
					int newHp = g.getHp() - proj[pCnt].getDegatsAttaque();
					g.setHp(newHp);
					if (g.getHp() <= 0) {
						g.rect.setSize(sf::Vector2f(34, 36));
						g.sprite.setTextureRect({ 338, 1308, 34, 36 });
					}
				}
				else {
					g.rect.setSize(sf::Vector2f(34, 36));
					g.sprite.setTextureRect({ 338, 1308, 34, 36 });
				}
				break;
			 }
		}
	}
}

void Carte::draw(sf::RenderWindow& window) {
	obstacles.clear();
	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 40; j++) {
			// if we were to use if statements to initialize an object
			// we need to have a pointer, so that it points to a memory address
			// then initialise it with the <new> operator.
			sprite.setPosition(j * 32, i * 32);
			if (map[j][i] == 38) {
				sprite.setTextureRect({192, 128, 32, 32});
				Obstacle obs(sprite, j * 32, i * 32);
				obstacles.push_back(obs);
			}

			if (map[j][i] == 48) {
				sprite.setTextureRect({ 0, 192, 32, 32 });
			}
			if (map[j][i] == 51) {
				sprite.setTextureRect({ 96, 192, 32, 32 });
			}
			window.draw(sprite);
		}
	}
}