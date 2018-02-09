#include "EnemyEasy.h"

EnemyEasy::EnemyEasy()
{
	//Set Position to random on the Screen
	int xPos = rand() % 400;
	int yPos = rand() % 320;
	setPosition(xPos, yPos);

	//Set Up Texture and Sprite
	setBody();

	speed = 3;
	direction = rand() % 4 + 1;
}

sf::Sprite EnemyEasy::draw()
{
	return sf::Sprite(EnemyEasySprite);
}

void EnemyEasy::setBody()
{
	loadTextures();
	setSprite();
}

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

void EnemyEasy::setSprite()
{
	EnemyEasySprite.setTexture(textureSOUTH);
}

void EnemyEasy::setPosition(int xPos, int yPos)
{
	EnemyEasySprite.setPosition(xPos, yPos);
}


void EnemyEasy::update()
{
	//Get Position
	sf::Vector2f pos(EnemyEasySprite.getPosition());


	//Movement
	//WEST = 1	EAST = 2	NORTH = 3	SOUTH = 4
	//Left
	if (direction == 1)
	{
		pos.x -= speed;
		moveLeft();

		if (pos.x <= 0 + FENCE_WIDTH_LEFT)
		{
			direction = 3;
		}
	}
	//Right
	else if(direction == 2)
	{
		pos.x += speed;
		moveRight();

		if (pos.x >= SCREEN_WIDTH - FENCE_WIDTH_RIGHT_SKEL)
		{
			direction = 4;
		}
	}
	//Up
	else if(direction == 3)
	{
		pos.y -= speed;
		moveUp();

		if (pos.y < 0 + FENCE_HEIGHT_TOP)
		{
			direction = 2;
		}
	}
	//Down
	else if(direction == 4)
	{
		pos.y += speed;
		moveDown();

		if (pos.y >= SCREEN_HEIGHT - FENCE_HEIGHT_BOT)
		{
			direction = 1;
		}
	}

	//WEST = 1	EAST = 2	NORTH = 3	SOUTH = 4

	//Set New Position
	EnemyEasySprite.setPosition(pos);

}

void EnemyEasy::dies()
{
	
}

void EnemyEasy::moveLeft()
{
	EnemyEasySprite.setTexture(textureWEST);
}

void EnemyEasy::moveRight()
{
	EnemyEasySprite.setTexture(textureEAST);
}

void EnemyEasy::moveUp()
{
	EnemyEasySprite.setTexture(textureNORTH);
}

void EnemyEasy::moveDown()
{
	EnemyEasySprite.setTexture(textureSOUTH);
}

void EnemyEasy::boundryCheck()
{
}
