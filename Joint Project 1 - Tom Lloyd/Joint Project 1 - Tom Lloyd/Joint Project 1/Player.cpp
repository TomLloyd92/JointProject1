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
			pos.x -= speed;
			moveLeft();
			direction = 1;
		}
	}
	//Right
	if (pos.x < SCREEN_WIDTH - FENCE_WIDTH_RIGHT)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			pos.x += speed;
			moveRight();
			direction = 2;
		}
	}
	//Up
	if (pos.y > FENCE_HEIGHT_TOP)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			pos.y -= speed;
			moveUp();
			direction = 3;
		}
	}
	//Down
	if(pos.y < SCREEN_HEIGHT - FENCE_HEIGHT_BOT)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		pos.y += speed;
		moveDown();
		direction = 4;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		//Spawn Bullet
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

void Player::moveLeft()
{
	//Sprite load for moving Left
	playerSprite.setTexture(textureWEST);
}

void Player::moveRight()
{
	//Sprite load for moving Right
	playerSprite.setTexture(textureEAST);
}

void Player::moveUp()
{
	//Sprite load for moving Up
	playerSprite.setTexture(textureNORTH);
}

void Player::moveDown()
{
	//Sprite load for Moving Down
	playerSprite.setTexture(textureSOUTH);
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

int Player::getDirection()
{
	return direction;
}
