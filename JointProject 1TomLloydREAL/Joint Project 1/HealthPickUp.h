#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
#include "Globals.h"

class HealthPickUp
{
	sf::Texture texture;
	sf::Sprite healthSprite;
	void setPosition();

public:
	HealthPickUp();
	
	void setBody();	//Loads Textures Sets Sprite
	void loadTextures();	//Load all textures at the start
	void setSprite();	//Set Sprite at start

	sf::Sprite getSprite();	//Return the Sprite

	void update();	//Update health
	void healthPickedUp();	//changes healthcollected bool

	void reset();

	bool getHealthCollected();
	bool healthCollected;	//Bool to see if health is alive

};
