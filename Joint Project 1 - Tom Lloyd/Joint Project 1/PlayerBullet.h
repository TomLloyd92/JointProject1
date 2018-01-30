#pragma once

#include "SFML\Graphics.hpp"
#include "Globals.h"
#include "Player.h"

class PlayerBullet
{
	//Private Members
	sf::Texture texture;
	sf::Sprite bulletSprite;

	int speed;
	int direction;
	bool isAlive;

public:
	PlayerBullet();

	void setBody();
	void setTexture();
	void setSprite();
	sf::Sprite draw();

	void hit();
	void fired();
	void move();




};

