#pragma once

#include "SFML\Graphics.hpp"
#include <iostream>
#include "Globals.h"

class GameOver
{
	sf::Texture gameOverTexture;
	sf::Sprite gameOverSprite;

	//Setting Up Class
	void setBody();	//Loads Textures Sets Sprite
	void loadTextures();	//Load all textures at the start
	void setSprite();	//Set Sprite at start
	void setPosition();

public:
	GameOver();
	sf::Sprite getGameOverSprite();
};