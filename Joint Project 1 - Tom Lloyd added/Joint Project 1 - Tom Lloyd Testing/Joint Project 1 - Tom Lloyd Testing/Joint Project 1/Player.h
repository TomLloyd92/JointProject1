// Player class declaration
#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
#include "Globals.h"
#include "PlayerBullet.h"

class Player
{
	// private data members
	//Textures
	sf::Texture textureNORTH;
	sf::Texture textureSOUTH;
	sf::Texture textureEAST;
	sf::Texture textureWEST;
	//Sprite
	sf::Sprite playerSprite;

	//Values
	int health;
	int speed;
	int score;

	bool isAlive;

public:
	//Default Constructor
	Player();

	//SetUp Player
	void setBody();
	void loadTextures();
	void setSprite();

	//Drawing
	sf::Sprite draw();

	void update();
	void shoot();
	void dies();
	void decreaseHealth();

	//Positioning
	void setPosition(int xPos, int yPos);
	sf::Vector2f getPosition();

	int direction;
	int getDirection();

	//Player UI
	void displayPlayerStats();
	void increaseScore();
	void decreaseScore();

	//Bullet
	bool bulletFired = false;
	bool getBulletFired();

};