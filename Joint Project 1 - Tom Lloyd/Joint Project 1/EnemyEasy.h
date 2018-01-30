#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
#include "Globals.h"


class EnemyEasy
{
	//Private
	sf::Texture texture;
	sf::Sprite EnemyEasySprite;

	int health;
	int speed;
	int direction;

	bool isAlive;

public:
	//Default Constructor and Draw
	EnemyEasy();
	sf::Sprite draw();

	//Setting Up Body
	void setBody();
	void setTexture();
	void setSprite();

	//Seting Up Possition
	void setPosition(int xPos, int yPos);

	//Handle all EasyEnemey Updates
	void update();

	void dies();
	
	//Movement
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void boundryCheck();
};