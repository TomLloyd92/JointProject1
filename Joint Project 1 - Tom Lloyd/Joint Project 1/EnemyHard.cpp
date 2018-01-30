#include "EnemyHard.h"

EnemyHard::EnemyHard()
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

sf::Sprite EnemyHard::draw()
{
	return sf::Sprite(EnemyHardSprite);
}

void EnemyHard::setBody()
{
	setTexture();
	setSprite();
}

void EnemyHard::setTexture()
{
	if (!texture.loadFromFile("ASSETS/Sprites/enemy1Down.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
}

void EnemyHard::setSprite()
{
	EnemyHardSprite.setTexture(texture);
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
	if (!texture.loadFromFile("ASSETS/Sprites/enemy1Left.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
}

void EnemyHard::moveRight()
{
	if (!texture.loadFromFile("ASSETS/Sprites/enemy1Right.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
}

void EnemyHard::moveUp()
{
	if (!texture.loadFromFile("ASSETS/Sprites/enemy1Up.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
}

void EnemyHard::moveDown()
{
	if (!texture.loadFromFile("ASSETS/Sprites/enemy1Down.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
}

void EnemyHard::boundryCheck()
{
}
