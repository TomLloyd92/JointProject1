#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
#include "Globals.h"


class EnemyHard
{
	//Private
	sf::Texture textureNORTH;	//Texture for the Enemy going North
	sf::Texture textureEAST;	//Texture for the enemy going Easy
	sf::Texture textureSOUTH;	//Texture for the enemy going south
	sf::Texture textureWEST;	//texture fo the enemy going West


	sf::Sprite EnemyHardSprite;	//Enemy Sprite

	int health;	//Heakth of the enemy
	int speed;	//Speed of the enemy
	int direction;	//Direction of the enemy

	bool isAlive;	//Bool to see if the enemy is alive

public:
	//Default Constructor and Draw
	EnemyHard();

	//Setting Up Body
	void setBody();
	void loadTextures();
	void setSprite();
	sf::Sprite getEnemyHardSprite();	//Returns the Sprite of the enemy

	//Seting Up Possition
	void setPosition();

	//Handle all HardEnemey Updates
	void update();
	bool getAlive();
	void kill();	//Changes the isAlive bool to false
	void respawn();	//Changes the enemys varibles to the same as the constructors

	//Movement
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	//Player Information
	void getPlayerPosition(sf::Vector2f t_playerPosition);	//Gets passed the possition of a vector
	sf::Vector2f playerPosition;	//Vector varible for storing the passed position vector
};
