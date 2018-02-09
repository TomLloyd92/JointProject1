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

	//Drawing Bullet
	sf::Sprite draw();

	//Getting player direction/position
	void getPlayerDirection(int t_playerDirection);
	void getPlayerPosition(sf::Vector2f t_playerPosition);


	//Updates
	void update();

	//Shooting
	void hit();
	void move();
	void boundryCheck();

	bool bulletFired = false;
	bool isMoving;
	void fired();
};

