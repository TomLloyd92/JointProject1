// Player class declaration
#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
#include "Globals.h"
#include "PlayerBullet.h"

class Player
{
	// private data members
	sf::Texture texture;
	sf::Sprite playerSprite;
	int health;
	int speed;
	int score;

	bool isAlive;

public:
	Player();	//Default Constructor
	sf::Sprite draw();

	void setBody();
	void setTexture();
	void setSprite();
	
	void setPosition(int xPos, int yPos);

	void update();
	void shoot();
	void dies();
	void decreaseHealth();

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void boundryCheck();
	void displayPlayerStats();
	void increaseScore();
	void decreaseScore();

	int direction;
};