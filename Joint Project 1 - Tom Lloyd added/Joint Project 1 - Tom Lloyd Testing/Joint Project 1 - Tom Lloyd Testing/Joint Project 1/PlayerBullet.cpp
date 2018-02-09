#include "PlayerBullet.h"

PlayerBullet::PlayerBullet()
{
	setBody();
	speed = 3;

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
		bulletFired = true;
}

void PlayerBullet::move()
{

}

void PlayerBullet::getPlayerPosition(sf::Vector2f t_playerPosition)
{
	bulletVec = t_playerPosition;
}

sf::Sprite PlayerBullet::draw()
{
	return sf::Sprite(bulletSprite);
}

void PlayerBullet::update()
{
	if (bulletFired == true)
	{
		bulletSprite.setPosition(bulletVec);
		isMoving = true;
	}

	sf::Vector2f pos(bulletSprite.getPosition());

	if (isMoving == true)
	{
		if (direction == 1)
		{
			bulletVec.x -= speed;
		}
		else if (direction == 2)
		{
			bulletVec.x += speed;
		}
		else if (direction == 3)
		{
			bulletVec.y -= speed;
		}
		else if (direction == 4)
		{
			bulletVec.y += speed;
		}
	}
	
	if (pos.x < 0 - BULLET_WIDTH_HEIGHT)
	{
		bulletFired = false;
	}
	if (pos.x > SCREEN_WIDTH + BULLET_WIDTH_HEIGHT)
	{
		bulletFired = false;
	}
	if (pos.y < 0 - BULLET_WIDTH_HEIGHT )
	{
		bulletFired = false;
	}
	if (pos.y > SCREEN_HEIGHT + BULLET_WIDTH_HEIGHT)
	{
		bulletFired = false;
	}

	bulletSprite.setPosition(pos);
	setSprite();
}

void PlayerBullet::boundryCheck()
{

}