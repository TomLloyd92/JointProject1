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
	speed = 5;
	health = 5;
	score = 0;
	direction = 4;
}

//Return Sprite to be drawn
sf::Sprite Player::draw()
{
	return sf::Sprite(playerSprite);
}

//Call Texture/Sprite functions to set Body
void Player::setBody()
{
	setTexture();
	setSprite();
}

//Load the Texture
void Player::setTexture()
{
	if (!texture.loadFromFile("ASSETS/Sprites/down.png"))	
	{
		std::cout << "Load Failed!" << std::endl;
	}

}

//Set the Texture as the Sprite
void Player::setSprite()	
{
	playerSprite.setTexture(texture);
}

//Function to set player in middle
void Player::setPosition(int xPos, int yPos)
{
	playerSprite.setPosition(sf::Vector2f(xPos, yPos));
}

//Handle all updates relating to the player
void Player::update()
{
	sf::Vector2f pos (playerSprite.getPosition());

	//Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		pos.x -= speed;
		moveLeft();
		direction = 1;
	}
	//Right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		pos.x += speed;
		moveRight();
		direction = 2;
	}
	//Up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		pos.y -= speed;
		moveUp();
		direction = 3;
	}
	//Down
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
	if (!texture.loadFromFile("ASSETS/Sprites/left.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
}

void Player::moveRight()
{
	//Sprite load for moving Right
	if (!texture.loadFromFile("ASSETS/Sprites/right.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
}

void Player::moveUp()
{
	//Sprite load for moving Up
	if (!texture.loadFromFile("ASSETS/Sprites/up.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
}

void Player::moveDown()
{
	//Sprite load for Moving Down
	if (!texture.loadFromFile("ASSETS/Sprites/down.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
}

void Player::boundryCheck()
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
