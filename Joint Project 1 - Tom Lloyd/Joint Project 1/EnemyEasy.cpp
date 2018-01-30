#include "EnemyEasy.h"

EnemyEasy::EnemyEasy()
{
	//Set Position to random on the Screen
	int xPos = rand() % 800;
	int yPos = rand() % 600;
	setPosition(xPos, yPos);

	//Set Up Texture and Sprite
	setBody();

	speed = 5;
	direction = rand() % 4 + 1;
}

sf::Sprite EnemyEasy::draw()
{
	return sf::Sprite(EnemyEasySprite);
}

void EnemyEasy::setBody()
{
	setTexture();
	setSprite();
}

void EnemyEasy::setTexture()
{
	if (!texture.loadFromFile("ASSETS/Sprites/enemyDown.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
}

void EnemyEasy::setSprite()
{
	EnemyEasySprite.setTexture(texture);
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
	if(direction == 1)
	{
		pos.x -= speed;
		moveLeft();
	}
	//Right
	else if(direction == 2)
	{
		pos.x += speed;
		moveRight();
	}
	//Up
	else if(direction == 3)
	{
		pos.y -= speed;
		moveUp();
	}
	//Down
	else if(direction == 4)
	{
		pos.y += speed;
		moveDown();
	}

	if (pos.x >= SCREEN_WIDTH || pos.x <= 0)
	{
		direction = rand() % 4 + 1;
	}

	if (pos.y >= SCREEN_HEIGHT || pos.y <= 0)
	{
		direction = rand() % 4 + 1;
	}

	//Set New Position
	EnemyEasySprite.setPosition(pos);

}

void EnemyEasy::dies()
{
	
}

void EnemyEasy::moveLeft()
{
	if (!texture.loadFromFile("ASSETS/Sprites/enemyLeft.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
}

void EnemyEasy::moveRight()
{
	if (!texture.loadFromFile("ASSETS/Sprites/enemyRight.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
}

void EnemyEasy::moveUp()
{
	if (!texture.loadFromFile("ASSETS/Sprites/enemyUp.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
}

void EnemyEasy::moveDown()
{
	if (!texture.loadFromFile("ASSETS/Sprites/enemyDown.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
}

void EnemyEasy::boundryCheck()
{
}
