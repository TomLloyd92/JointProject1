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
	sf::Vector2f bulletVec;
	sf::Vector2f playerPosition;

	const int BULLET_WIDTH_HEIGHT = 15;

public:
	//Default Constructor
	PlayerBullet();

	//Setting up the Bullet
	void setBody();
	void setTexture();
	void setSprite();
	sf::Sprite getPlayerArrowSprite();	//return arrow sprite

	//Getting player direction/position
	void getPlayerDirection(int t_playerDirection);	//passed a int that is the direction
	void getPlayerPosition(sf::Vector2f t_playerPosition);	//passed a vector position

	//Updates
	void update();

	//Shooting
	void hit();
	void move();

	bool bulletFired = false;
	bool isMoving;
	void fired();

	void bulletDestroy();	//Deconstructor for the bullet
};

