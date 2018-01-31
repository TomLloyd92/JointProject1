#pragma once

#include "SFML\Graphics.hpp"
#include "Globals.h"
#include "Player.h"

class PlayerBullet
{
	//Private Members
	//Textures
	sf::Texture textureNORTH;
	sf::Texture textureEAST;
	sf::Texture textureSOUTH;
	sf::Texture textureWEST;

	//Sprite
	sf::Sprite bulletSprite;

	//Values
	int speed;
	int direction;
	bool isAlive;

public:
	//Default Constructor
	PlayerBullet();

	//Setting up the Bullet
	void setBody();
	void setTexture();
	void setSprite();

	void setPosition(int xPos, int yPos);

	//Drawing Bullet
	sf::Sprite draw();

	//Getting direction
	void getPlayerDirection(int t_playerDirection);

	//Updates
	void update();

	//Shooting
	void hit();
	void fired();
	void move();

	
};

