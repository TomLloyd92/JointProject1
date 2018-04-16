#include "EnemyEasy.h"

EnemyEasy::EnemyEasy()
{
	//Set Position to random on the Screen
	setPosition();

	//Set Up Texture and Sprite
	setBody();

	//Varible set Ups
	speed = 3;
	direction = rand() % 4 + 1;
	isAlive = true;
}

//Set Textures and Sprites
void EnemyEasy::setBody()
{
	loadTextures();
	setSprite();
}

//Pre Load all textures
void EnemyEasy::loadTextures()
{
	//Up
	if (!textureNORTH.loadFromFile("ASSETS/Sprites/enemyUp.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
	//Down
	if (!textureSOUTH.loadFromFile("ASSETS/Sprites/enemyDown.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
	//Left
	if (!textureWEST.loadFromFile("ASSETS/Sprites/enemyLeft.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
	//Right
	if (!textureEAST.loadFromFile("ASSETS/Sprites/enemyRight.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
}

//Set Sprite to Texture
void EnemyEasy::setSprite()
{
	EnemyEasySprite.setTexture(textureSOUTH);
}

//Return Sprite
sf::Sprite EnemyEasy::getEnemyEasySprite()
{
	return sf::Sprite(EnemyEasySprite);
}

//Set initial position
void EnemyEasy::setPosition()
{
	int xPos = rand() % 400;	//Random Starting Position X
	if (xPos < FENCE_WIDTH_LEFT)	//Spawn them INSIDE the fence perimiter X
	{
		xPos = xPos + FENCE_WIDTH_LEFT;
	}
	else if (xPos >(SCREEN_WIDTH - FENCE_WIDTH_RIGHT))
	{
		xPos = xPos - FENCE_WIDTH_RIGHT;
	}

	int yPos = rand() % 320;	//Random Starting Position Y
	if (yPos < FENCE_HEIGHT_TOP)	//Spawn them INSIDE the fence perimiter Y
	{
		yPos = yPos + FENCE_HEIGHT_TOP;
	}
	else if (yPos >(SCREEN_HEIGHT - FENCE_HEIGHT_BOT))
	{
		yPos = yPos - FENCE_HEIGHT_BOT;
	}

	EnemyEasySprite.setPosition(xPos, yPos);
}

//All Updates
void EnemyEasy::update()
{
	//Get Position
	sf::Vector2f pos(EnemyEasySprite.getPosition());

	if (isAlive == true)
	{
		//Movement
		//Left
		if (direction == WEST)
		{
			pos.x -= speed;
			moveLeft();

			if (pos.x <= 0 + FENCE_WIDTH_LEFT)
			{
				direction = NORTH;
			}
		}
		//Right
		else if (direction ==EAST)
		{
			pos.x += speed;
			moveRight();

			if (pos.x >= SCREEN_WIDTH - FENCE_WIDTH_RIGHT_SKEL)
			{
				direction = SOUTH;
			}
		}
		//Up
		else if (direction == NORTH)
		{
			pos.y -= speed;
			moveUp();

			if (pos.y < 0 + FENCE_HEIGHT_TOP)
			{
				direction = EAST;
			}
		}
		//Down
		else if (direction == SOUTH)
		{
			pos.y += speed;
			moveDown();

			if (pos.y >= SCREEN_HEIGHT - FENCE_HEIGHT_BOT)
			{
				direction = WEST;
			}
		}

		//Set New Position
		EnemyEasySprite.setPosition(pos);
	}
	else if (isAlive == false)
	{
		pos = { 0,0 };	//set possition to zero when killed
		EnemyEasySprite.setPosition(pos);
	}
}
void EnemyEasy::kill()
{
	isAlive = false;	//change bool on Kill
}

//Left Sprite
void EnemyEasy::moveLeft()
{
	EnemyEasySprite.setTexture(textureWEST);
}

//Right Sprite
void EnemyEasy::moveRight()
{
	EnemyEasySprite.setTexture(textureEAST);
}

//Up Sprite
void EnemyEasy::moveUp()
{
	EnemyEasySprite.setTexture(textureNORTH);
}

//Down Sprite
void EnemyEasy::moveDown()
{
	EnemyEasySprite.setTexture(textureSOUTH);
}

//Return Alive Bool
bool EnemyEasy::getAlive()
{
	return isAlive;
}

void EnemyEasy::respawn()	//Set to original constructor on respawn
{
	//Set Position to random on the Screen
	setPosition();

	//Set Up Texture and Sprite
	setBody();

	speed = 3;
	direction = rand() % 4 + 1;
	isAlive = true;
}
