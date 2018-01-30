#include "PlayerBullet.h"

PlayerBullet::PlayerBullet()
{
}

void PlayerBullet::setBody()
{
}

void PlayerBullet::setTexture()
{
	
	//WEST = 1	EAST = 2	NORTH = 3	SOUTH = 4
	//if ( == 1)
	{
		if (!texture.loadFromFile("ASSETS/Sprites/down.png"))
		{
			std::cout << "Load Failed!" << std::endl;
		}
	}
}

void PlayerBullet::setSprite()
{
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

sf::Sprite PlayerBullet::draw()
{
	return sf::Sprite();
}
