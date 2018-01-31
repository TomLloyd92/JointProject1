#include "EnemyHard.h"

EnemyHard::EnemyHard()
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

sf::Sprite EnemyHard::draw()
{
	return sf::Sprite(EnemyHardSprite);
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

void EnemyHard::setSprite()
{
	EnemyHardSprite.setTexture(textureSOUTH);
}

void EnemyHard::setPosition(int xPos, int yPos)
{
	EnemyHardSprite.setPosition(xPos, yPos);
}

void EnemyHard::update()
{
	//Get Position
	sf::Vector2f pos(EnemyHardSprite.getPosition());


	//Movement
	//WEST = 1	EAST = 2	NORTH = 3	SOUTH = 4

	//Left
	if (direction == 1)
	{
		pos.x -= speed;
		moveLeft();
	}
	//Right
	else if (direction == 2)
	{
		pos.x += speed;
		moveRight();
	}
	//Up
	else if (direction == 3)
	{
		pos.y -= speed;
		moveUp();
	}
	//Down
	else if (direction == 4)
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
	EnemyHardSprite.setPosition(pos);

}

void EnemyHard::dies()
{
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

void EnemyHard::boundryCheck()
{
}
