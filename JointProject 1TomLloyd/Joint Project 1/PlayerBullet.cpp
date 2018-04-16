#include "PlayerBullet.h"

PlayerBullet::PlayerBullet()
{
	setBody();	//Set Up Textures and Sprites
	speed = 4;	//Speed of the Arrow
}

//Initital Arrow Setup
void PlayerBullet::setBody()
{
	setTexture();	//Load Textures 
	setSprite();	//Set Sprites to Textures

	//bulletSprite.setOrigin(sf::Vector2f(5, 5));
}

void PlayerBullet::setTexture()
{
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
	//LEFT
	if (direction == WEST)
	{
		bulletSprite.setTexture(textureWEST,true);
	}
	//RIGHT
	else if (direction == EAST)
	{
		bulletSprite.setTexture(textureEAST, true);
	}
	//NORTH
	else if (direction == NORTH)
	{
		bulletSprite.setTexture(textureNORTH, true);
	}
	//SOUTH
	else if (direction == SOUTH)
	{
		bulletSprite.setTexture(textureSOUTH, true);
	}
}

//Update for the Bullet
void PlayerBullet::update()
{
	if (bulletFired == true)	//Check if Bullet is Fired
	{
		bulletSprite.setPosition(bulletVec);
		isMoving = true;	//Bullet is Moving
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
	if (pos.y < 0 - BULLET_WIDTH_HEIGHT)
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

//Passing the player Direction
void PlayerBullet::getPlayerDirection(int t_playerDirection)
{
	direction = t_playerDirection;	//Arrow Directions is the same as player Direction
}

//Return Player Sprite
sf::Sprite PlayerBullet::getPlayerArrowSprite()
{
	return sf::Sprite(bulletSprite);	//Collision and Drawing
}

void PlayerBullet::getPlayerPosition(sf::Vector2f t_playerPosition)
{
	sf::Vector2f centerBullet(7, 10);	//Centers the bullet on the player Sprite

	bulletVec = t_playerPosition + centerBullet;	//Bullet Vec Spawns Bullet on Players Position
}

void PlayerBullet::fired()
{
		bulletFired = true;	//Bool to see if bullet is Fired
}

void PlayerBullet::bulletDestroy()
{
	bulletFired = false;
	isMoving = false;
	bulletSprite.setPosition(-10, -10);
}

void PlayerBullet::move()
{

}

void PlayerBullet::hit()
{
}