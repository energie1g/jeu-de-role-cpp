#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include "Guerrier.h"
#include "Projectile.h"
#include "Carte.h"

using namespace std;

int main()
{
	int pCnt = 0;
	sf::RenderWindow window(sf::VideoMode(1280, 768), "SFML works!");
	window.setFramerateLimit(60);
	Carte carte("assets/jeuderole.txt");
	sf::Clock projClock;

	sf::Texture image;
	if (!image.loadFromFile("assets/player.png")) {
		return EXIT_FAILURE;
	}

	sf::Texture image2;
	if (!image2.loadFromFile("assets/projectiles.png")) {
		return EXIT_FAILURE;
	}

	sf::Font font;
	if(!font.loadFromFile("assets/vcr.ttf")) {
		return EXIT_FAILURE;
	}

	sf::Music music;
	if (!music.openFromFile("assets/sound/music.ogg"))
		return EXIT_FAILURE;

	sf::SoundBuffer fireSoundBuffer;
	sf::Sound fireSound;
	if (!fireSoundBuffer.loadFromFile("assets/sound/fire.ogg"))
		return EXIT_FAILURE;
	else
		fireSound.setBuffer(fireSoundBuffer);



	sf::Text score1("Guerrier 1 HP: ", font, 15);
	score1.setFillColor(sf::Color::Yellow);
	score1.setPosition(1, 0);

	sf::Text score2("Guerrier 2 HP:   ", font, 15);
	score2.setFillColor(sf::Color::Yellow);
	score2.setPosition(window.getSize().x - score2.getLocalBounds().width * 1.1, 0);

	//Guerrier (1)
	class Guerrier g1("first", 50, 100);
	g1.sprite.setTexture(image);

	class Guerrier g2("second", 200, 200);
	g2.sprite.setTexture(image);

	//Projectiles
	vector<Projectile>::const_iterator it;
	vector<Projectile> projArr;

	class Projectile proj1("first");
	proj1.sprite.setTexture(image2);

	class Projectile proj2("second");
	proj2.sprite.setTexture(image2);

	//Obstacles - Collision
	//vector<Obstacle>::const_iterator obsIt;

	music.setVolume(30);
	music.setLoop(true);
	music.play();

	while (window.isOpen()) 
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		sf::Time projElapsedTime = projClock.getElapsedTime();
		score1.setString("Guerrier 1 HP: " + to_string(g1.getHp()));
		score2.setString("Guerrier 2 HP: " + to_string(g2.getHp()));
		

		//carte.updateGuerrierCollision(g1, g2);
		g1.playerCollision(g2);
		g2.playerCollision(g1);

		carte.update(g1, projArr, it);
		carte.update(g2, projArr, it);
		carte.draw(window);

		pCnt = 0;
		for (it = projArr.begin(); it != projArr.end(); it++) {
			if (projArr[pCnt].destroy == true) {
				projArr.erase(it);
				break;
			}
			pCnt++;
		}
		
		if (projElapsedTime.asSeconds() >= 0.09) {
			projClock.restart();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && g1.getHp() > 0) {
				//g1.sprite.setTextureRect({338, 1308, 34, 36});
				fireSound.play();
				proj1.rect.setPosition(g1.rect.getPosition().x + g1.rect.getSize().x/2 - proj1.rect.getSize().x/2, g1.rect.getPosition().y + g1.rect.getSize().y/2 - proj1.rect.getSize().y / 2);
				proj1.setDirection(g1.getDirection());
				projArr.push_back(proj1);
			}
		}

		if (projElapsedTime.asSeconds() >= 0.09) {
			projClock.restart();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && g2.getHp() > 0) {
				fireSound.play();
				proj2.rect.setPosition(g2.rect.getPosition().x + g2.rect.getSize().x / 2 - proj2.rect.getSize().x / 2, g2.rect.getPosition().y + g2.rect.getSize().y / 2 - proj2.rect.getSize().y / 2);
				proj2.setDirection(g2.getDirection());
				projArr.push_back(proj2);
			}
		}

		pCnt = 0;
		for (it = projArr.begin(); it != projArr.end(); it++) {
			projArr[pCnt].update(); // Update Projectile
			//window.draw(projArr[pCnt].rect);
			window.draw(projArr[pCnt].sprite);
			pCnt++;
		}

		
		g1.updateMovement();
		g1.update();
		g2.updateMovement();
		g2.update();

		window.draw(g1.sprite);
		window.draw(g2.sprite);
		window.draw(score1);
		window.draw(score2);

		window.display();
	}
	return 0;
};