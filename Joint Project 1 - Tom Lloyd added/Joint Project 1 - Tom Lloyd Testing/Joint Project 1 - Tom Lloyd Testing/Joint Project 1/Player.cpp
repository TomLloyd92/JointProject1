#include "Player.h"   // include Player header file

// Player function definitions here

Player::Player()
{
	// place the player object in the centre of the screen
	int xPos = SCREEN_WIDTH / 2;        
	int yPos = SCREEN_HEIGHT / 2;
	setPosition(xPos, yPos);		

	//Set Up Player Body
	setBody();	

	//Spawning Stats
	speed = 3;
	health = 5;
	score = 0;
	direction = 3;
}

//Return Sprite to be drawn
sf::Sprite Player::draw()
{
	return sf::Sprite(playerSprite);
}

//Call Texture/Sprite functions to set Body
void Player::setBody()
{
	loadTextures();
	setSprite();
}

void Player::loadTextures()
{
	//Up
	if (!textureNORTH.loadFromFile("ASSETS/Sprites/up.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
	//Down
	if (!textureSOUTH.loadFromFile("ASSETS/Sprites/down.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
	//Right
	if (!textureEAST.loadFromFile("ASSETS/Sprites/right.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
	//Left
	if (!textureWEST.loadFromFile("ASSETS/Sprites/left.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}

}

//Set the Texture as the Sprite
void Player::setSprite()	
{

	playerSprite.setTexture(textureNORTH);

}

//Function to set player in middle
void Player::setPosition(int xPos, int yPos)
{
	playerSprite.setPosition(sf::Vector2f(xPos, yPos));
}

sf::Vector2f Player::getPosition()
{

	sf::Vector2f positionVec = playerSprite.getPosition();
	return sf::Vector2f(positionVec);

}

//Handle all updates relating to the player
void Player::update()
{
	sf::Vector2f pos (playerSprite.getPosition());

	//Left
	if (pos.x > 0 + FENCE_WIDTH_LEFT)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			pos.x -= speed;	//Change Velocity of player

			direction = 1;	//Change direction of the player

			playerSprite.setTexture(textureWEST);	//Change player sprite to West
		}
	}
	//Right
	if (pos.x < SCREEN_WIDTH - FENCE_WIDTH_RIGHT)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			pos.x += speed;	//Change Velocity of player right

			direction = 2;	//Change Direction of player East

			playerSprite.setTexture(textureEAST);	//Change player Sprite to East
		}
	}
	//Up
	if (pos.y > FENCE_HEIGHT_TOP)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			pos.y -= speed;	//change Velocity of player up
		
			direction = 3;	//Change direction of player to North

			playerSprite.setTexture(textureNORTH);	//Change player sprite to North
		}
	}
	//Down
	if(pos.y < SCREEN_HEIGHT - FENCE_HEIGHT_BOT)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		pos.y += speed;	//Change velocity of player to down
									
		direction = 4;	//Change firection of player to South

		playerSprite.setTexture(textureSOUTH);	//Change player sprite to South
	}


	playerSprite.setPosition(pos);
}

void Player::shoot()
{
}

void Player::dies()
{
}

void Player::decreaseHealth()
{
}

void Player::displayPlayerStats()
{
}

void Player::increaseScore()
{
}

void Player::decreaseScore()
{
}

bool Player::getBulletFired()
{
	return bulletFired;
}

int Player::getDirection()
{
	return direction;
}
