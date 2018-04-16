#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
#include "Globals.h"

class EnemyCrazy
{
	//Private
	sf::Texture crazyTexture;	//Texture for the object

	//Sprite
	sf::Sprite EnemyCrazySprite;	//Sprite for the object

	//Varibles
	int health;	//Health
	int direction;	//Direction the enemy is facing
	float speedVel;	//Speed at which the enemy is moving

	sf::Vector2f velVector{ 2, 2 };

	bool isAlive;	//Boolean to see if the enemy is alive

public:
	//Default Constructor and Draw
	EnemyCrazy();

	//Setting Up Body
	void setBody();	//Loads Textures Sets Sprite
	void loadTextures();	//Load all textures at the start
	void setSprite();	//Set Sprite at start
	sf::Sprite getEnemyCrazySprite();	//Public Sprite used for Collision/Drawing
								
	void setPosition();	//Seting Up Possition

	//Handle all EasyEnemey Updates
	void update();

	//Killing/Spawing
	bool getAlive();	//Returns the current boolean "isAlive"
	void kill();	//Changes Alive boolean to false when called
	void respawn();	//Set objects varibles back to that of the constructors 
};