#include "PlayerBullet.h"

PlayerBullet::PlayerBullet()
{
	int xPos = 100;
	int yPos = 100;

	setPosition(xPos, yPos);

	setBody();

}

void PlayerBullet::setBody()
{
	setTexture();
	setSprite();
}

void PlayerBullet::getPlayerDirection(int t_playerDirection)
{
	direction = t_playerDirection;
}

void PlayerBullet::setTexture()
{
	//WEST = 1	EAST = 2	NORTH = 3	SOUTH = 4
	//Left
	if (!textureWEST.loadFromFile("ASSETS/Sprites/arrowLeft.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
	//Right
	if (!textureEAST.loadFromFile("ASSETS/Sprites/arrowRight.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
	//Up
	if (!textureNORTH.loadFromFile("ASSETS/Sprites/arrowUp.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
	//Down
	if (!textureSOUTH.loadFromFile("ASSETS/Sprites/arrowDown.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
}

void PlayerBullet::setSprite()
{
	//WEST = 1	EAST = 2	NORTH = 3	SOUTH = 4
	//LEFT
	if (direction == 1)
	{
		bulletSprite.setTexture(textureWEST);
	}
	//RIGHT
	else if (direction == 2)
	{
		bulletSprite.setTexture(textureEAST);
	}
	//NORTH
	else if (direction == 3)
	{
		bulletSprite.setTexture(textureNORTH);
	}
	//SOUTH
	else if (direction == 4)
	{
		bulletSprite.setTexture(textureSOUTH);
	}
}

void PlayerBullet::hit()
{
}

void PlayerBullet::fired()
{
}

void PlayerBullet::move()
{
}

void PlayerBullet::setPosition(int xPos,int yPos)
{
	bulletSprite.setPosition(sf::Vector2f(xPos, yPos));
}

sf::Sprite PlayerBullet::draw()
{
	return sf::Sprite(bulletSprite);
}


void PlayerBullet::update()
{
	sf::Vector2f pos(bulletSprite.getPosition());

	setSprite();

	bulletSprite.setPosition(pos);

}
