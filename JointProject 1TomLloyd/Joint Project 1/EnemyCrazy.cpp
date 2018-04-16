#include "EnemyCrazy.h"

EnemyCrazy::EnemyCrazy()
{
	//Set Position to random on the Screen
	setPosition();

	//Set Up Texture and Sprite
	setBody();

	//Bool set up
	isAlive = true;	
}

//Set Up textures and Sprites
void EnemyCrazy::setBody()
{
	loadTextures();
	setSprite();
}

//PreLoad All Textures
void EnemyCrazy::loadTextures()
{
	if (!crazyTexture.loadFromFile("ASSETS/Sprites/bat.png"))	//Load Texture Bat
	{
		std::cout << "Load Failed!" << std::endl;
	}
}

//Set Sprite to Texture
void EnemyCrazy::setSprite()
{
	EnemyCrazySprite.setTexture(crazyTexture);
}

//Return Crazy Enemy Sprite
sf::Sprite EnemyCrazy::getEnemyCrazySprite()
{
	return sf::Sprite(EnemyCrazySprite);
}

void EnemyCrazy::setPosition()
{
	int xPos = rand() % 400;	//Random Starting Position X
	if (xPos < FENCE_WIDTH_LEFT)	//Spawn them INSIDE the fence perimiter X
	{
		xPos = xPos + FENCE_WIDTH_LEFT;
	}
	else if (xPos > (SCREEN_WIDTH - FENCE_WIDTH_RIGHT))
	{
		xPos = xPos - FENCE_WIDTH_RIGHT;
	}

	int yPos = rand() % 320;	//Random Starting Position Y
	if (yPos < FENCE_HEIGHT_TOP)	//Spawn them INSIDE the fence perimiter Y
	{
		yPos = yPos + FENCE_HEIGHT_TOP;
	}
	else if (yPos > (SCREEN_HEIGHT - FENCE_HEIGHT_BOT))
	{
		yPos = yPos - FENCE_HEIGHT_BOT;
	}
	EnemyCrazySprite.setPosition(xPos,yPos);
}


void EnemyCrazy::update()
{
	//Get Position
	sf::Vector2f pos(EnemyCrazySprite.getPosition());

	if (isAlive == true)
	{
		//Movement
		pos = pos + velVector;

		//Set New Position
		EnemyCrazySprite.setPosition(pos);


		if (pos.x <= 0 + FENCE_WIDTH_LEFT)	//Reverse X when hits fence
		{
			velVector.x = velVector.x * -1;
		}
		else if (pos.x >= SCREEN_WIDTH - FENCE_WIDTH_RIGHT_SKEL)	//Reverse x when hits fence
		{
			velVector.x = velVector.x * -1;
		}
		else if (pos.y < 0 + FENCE_HEIGHT_TOP)	//Reverse Y when hits fence
		{
			velVector.y = velVector.y * -1;
		}
		else if (pos.y >= SCREEN_HEIGHT - FENCE_HEIGHT_BOT)	//Reverse Y when hits fence
		{
			velVector.y = velVector.y * -1;
		}
	}
	else if (isAlive == false)
	{
		pos = { 0,0 };	//Change position to 0,0 when dead
		EnemyCrazySprite.setPosition(pos);
	}
}

bool EnemyCrazy::getAlive()
{
	return isAlive;	//return Alive bool
}

void EnemyCrazy::kill()
{
	isAlive = false;	//Change alive to false 
}

//Reset stats to constructor on respawn
void EnemyCrazy::respawn()
{
	//Set Position to random on the Screen
	setPosition();

	//Set Up Texture and Sprite
	setBody();

	//Bool set up
	isAlive = true;
}
