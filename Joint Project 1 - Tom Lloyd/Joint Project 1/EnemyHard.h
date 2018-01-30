#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
#include "Globals.h"


class EnemyHard
{
	//Private
	sf::Texture texture;
	sf::Sprite EnemyHardSprite;

	int health;
	int speed;
	int direction;

	bool isAlive;

public:
	//Default Constructor and Draw
	EnemyHard();
	sf::Sprite draw();

	//Setting Up Body
	void setBody();
	void setTexture();
	void setSprite();

	//Seting Up Possition
	void setPosition(int xPos, int yPos);

	//Handle all HardEnemey Updates
	void update();

	void dies();

	//Movement
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void boundryCheck();
};
