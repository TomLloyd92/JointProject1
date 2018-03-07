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

	//health
	sf::Texture textureHealth;	//Heart texture
	sf::Sprite healthSprite[MAX_HEALTH];	//Maximum health array

	//Values
	int currentMaxHealth;
	int currentHealth;
	int speed;
	int score;

	bool isAlive;	//Bool for player alive

public:
	//Default Constructor
	Player();

	//SetUp Player
	void setBody();
	void loadTextures();
	void setSprite();

	sf::Sprite getPlayerSprite();
	sf::Sprite getHealthSprite(int i);


	void update();	//update player
	void shoot();
	void dies();
	void decreaseHealth();	//Decrease health by 1

	//Positioning
	void setPlayerPosition();	//Player
	sf::Vector2f getPosition();
	void resetPosition();
	void resetPlayer();

	void setHealthPosition();	//Health

	int direction;	//direction facing
	int getDirection();	//Return direction facing

	//Bullet
	bool bulletFired = false;
	bool getBulletFired();	//return bullet fired

	//Score
	void increaseScore();	//Increase players score
	int getScore();

	//health
	int getCurrentHealth();	//return current health
	void healthIncrease();	//increase players health
};