#include "GameOver.h"

GameOver::GameOver()	//Constructor
{
	setBody();
	setPosition();
}

void GameOver::setBody()	//Set textures and Sprite
{
	loadTextures();
	setSprite();
}

void GameOver::setPosition()	//Set Position of Sprite
{
	gameOverSprite.setPosition(0, 0);
}

void GameOver::loadTextures()	//Load texture
{
	if (!gameOverTexture.loadFromFile("ASSETS/Sprites/bgGameover.png"))
	{
		std::cout << "Game Over texture didnt Load" << std::endl;
	}
}

void GameOver::setSprite()	//Set texture to Sprite
{
	gameOverSprite.setTexture(gameOverTexture);
}

sf::Sprite GameOver::getGameOverSprite()	//Return Sprite
{
	return sf::Sprite(gameOverSprite);
}

