#include "EnemyHard.h"

EnemyHard::EnemyHard()
{
	//Set Position to random on the Screen
	setPosition();

	//Set Up Texture and Sprite
	setBody();

	speed = 2;
	isAlive = true;
}

void EnemyHard::setBody()
{
	loadTextures();
	setSprite();
}

void EnemyHard::loadTextures()
{
	//Up
	if (!textureNORTH.loadFromFile("ASSETS/Sprites/enemy1Up.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
	//Down
	if (!textureSOUTH.loadFromFile("ASSETS/Sprites/enemy1Down.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
	//Right
	if (!textureEAST.loadFromFile("ASSETS/Sprites/enemy1Right.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
	//Left
	if (!textureWEST.loadFromFile("ASSETS/Sprites/enemy1Left.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
}

//Set Sprite to texture
void EnemyHard::setSprite()
{
	EnemyHardSprite.setTexture(textureSOUTH);
}

//Return Sprite
sf::Sprite EnemyHard::getEnemyHardSprite()
{
	return sf::Sprite(EnemyHardSprite);
}

//Set Starting Position
void EnemyHard::setPosition()
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

	EnemyHardSprite.setPosition(xPos, yPos);
}

void EnemyHard::update()
{
	//Get Position
	sf::Vector2f pos(EnemyHardSprite.getPosition());

	if (isAlive == true)
	{
		//Movement
		//Left
		if (direction == WEST)
		{
			//pos.x -= speed;
			moveLeft();
		}
		//Right
		else if (direction == EAST)
		{
			//pos.x += speed;
			moveRight();
		}
		//Up
		else if (direction == NORTH)
		{
			//	pos.y -= speed;
			moveUp();
		}
		//Down
		else if (direction == SOUTH)
		{
			//	pos.y += speed;
			moveDown();
		}

		//Moving Towards Player
		if (playerPosition.x > pos.x)
		{
			pos.x++;
			direction = 2;
		}
		if (playerPosition.x < pos.x)
		{
			pos.x--;
			direction = 1;
		}
		if (playerPosition.y > pos.y)
		{
			pos.y++;
			direction = 4;
		}
		if (playerPosition.y < pos.y)
		{
			pos.y--;
			direction = 3;
		}
	}
	else if (isAlive == false)
	{
		pos = { 0,0 };
	}

	//Set New Position
	EnemyHardSprite.setPosition(pos);
}

void EnemyHard::kill()
{
	isAlive = false;
}

void EnemyHard::respawn()
{
	//Set Position to random on the Screen
	setPosition();

	//Set Up Texture and Sprite
	setBody();

	speed = 2;
	isAlive = true;
}

void EnemyHard::moveLeft()
{
	//Left
	EnemyHardSprite.setTexture(textureWEST);
}

void EnemyHard::moveRight()
{
	//Right
	EnemyHardSprite.setTexture(textureEAST);
}

void EnemyHard::moveUp()
{
	//Up
	EnemyHardSprite.setTexture(textureNORTH);
}

void EnemyHard::moveDown()
{
	//Down
	EnemyHardSprite.setTexture(textureSOUTH);
}

//Find Player Position
void EnemyHard::getPlayerPosition(sf::Vector2f t_playerPosition)	//Pass Player Position
{
	playerPosition = t_playerPosition;
}

//Return Alive Bool
bool EnemyHard::getAlive()
{
	return isAlive;
}
