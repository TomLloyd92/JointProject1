#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
#include "Globals.h"

class EnemyEasy
{
	//Private
	sf::Texture textureNORTH;	//texture for the enemy going North
	sf::Texture textureSOUTH;	//Texture for the enemy going South
	sf::Texture textureEAST;	//Texture for the enemy going East
	sf::Texture textureWEST;	//texture for the enemy going West

	//Sprite
	sf::Sprite EnemyEasySprite;	//Enemy Sprite taht the object will use

	//Varibles
	int health;	//Health of enemy
	int speed;	//Speed of the enemy
	int direction;	//Direction of the enemy
	bool isAlive;	//Bool to tell if the enemy is alive



public:
	//Default Constructor and Draw
	EnemyEasy();

	//Setting Up Body
	void setBody();	//Loads Textures Sets Sprite
	void loadTextures();	//Load all textures at the start
	void setSprite();	//Set Sprite at start
	sf::Sprite getEnemyEasySprite();	//Public Sprite used for Collision/Drawing

	//Seting Up Possition
	void setPosition();

	//Handle all EasyEnemey Updates
	void update();
	void kill();
	
	//Movement
	void moveLeft();	//Moves the enemy west
	void moveRight();	//Moves the enmey East
	void moveUp();	//Moves the enemy north
	void moveDown();	//Moves the enemy down

	bool getAlive();	//Returns the bool isAlive
	void respawn();	//Resets the enemys varibles to the same as the constructors
};