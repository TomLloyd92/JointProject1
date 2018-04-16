#include "Player.h"   // include Player header file

Player::Player()
{
	// place the player object in the centre of the screen
	setPlayerPosition();		//Set Location to Center

	//Set Up Player Body
	setBody();	

	//Spawning Stats
	speed = 3;	//Movement Speed
	currentMaxHealth = 3;	//Ammount of Health
	currentHealth = 3;
	score = 0;	//Starting Score
	direction = 3;	//
}

//Call Texture/Sprite functions to set Body
void Player::setBody()
{
	loadTextures();	//Load all textures at the start
	setSprite();	//Set Sprites Up
	setHealthPosition();
}

void Player::loadTextures()
{
	//Up
	if (!textureNORTH.loadFromFile("ASSETS/Sprites/up.png"))
	{
		std::cout << "Load Failed Up!" << std::endl;
	}
	//Down
	if (!textureSOUTH.loadFromFile("ASSETS/Sprites/down.png"))
	{
		std::cout << "Load Failed Down!" << std::endl;
	}
	//Right
	if (!textureEAST.loadFromFile("ASSETS/Sprites/right.png"))
	{
		std::cout << "Load Failed Right!" << std::endl;
	}
	//Left
	if (!textureWEST.loadFromFile("ASSETS/Sprites/left.png"))
	{
		std::cout << "Load Failed Left!" << std::endl;
	}
	//Health
	if(!textureHealth.loadFromFile("ASSETS/Sprites/lives.png"))
	{
		std::cout << "Load Failed Health!" << std::endl;
	}
}

//Set the Texture as the Sprite
void Player::setSprite()	
{
	playerSprite.setTexture(textureNORTH);	//Setup Starting Sprite

	for (int i = 0; i < MAX_HEALTH; i++)
	{
		healthSprite[i].setTexture(textureHealth);	//Set Up starting Health
	}
}

//Reutuns the Player Sprite
sf::Sprite Player::getPlayerSprite()
{
	return sf::Sprite(playerSprite);	//Used for collision and drawing
}

//Returns the Player Health Sprite
sf::Sprite Player::getHealthSprite(int i)
{
	return sf::Sprite(healthSprite[i]);	//Used for Drawing
}

//Function to set player in middle
void Player::setPlayerPosition()
{
	int xPos = SCREEN_WIDTH / 2;	//Center X
	int yPos = SCREEN_HEIGHT / 2;	//Center Y

	playerSprite.setPosition(sf::Vector2f(xPos, yPos));	//Pass the starting location and set player to mid	
}

//Setting up health Sprite
void Player::setHealthPosition()
{
	int healthX = 252;	//Starting X value of Health
	int healthY = 19;	//Starting Y value of Health

	for (int i = 0; i < MAX_HEALTH; i++)
	{
		healthSprite[i].setPosition(sf::Vector2f(healthX, healthY));	//Set Position of Health
		healthX = healthX + 8;	//Increase the X position of the Health to draw it in the next availible health space
	}
}

//Resturns Vector of Player Location
sf::Vector2f Player::getPosition()
{
	sf::Vector2f positionVec = playerSprite.getPosition();	//Make a vector and get position
	return sf::Vector2f(positionVec);	//Return the position
}
void Player::resetPosition()
{
	setPlayerPosition();		//Set Location to Center
}
void Player::resetPlayer()
{
	// place the player object in the centre of the screen
	setPlayerPosition();		//Set Location to Center

								//Set Up Player Body
	setBody();

	//Spawning Stats
	speed = 3;	//Movement Speed
	currentMaxHealth = 3;	//Ammount of Health
	currentHealth = 3;
	score = 0;	//Starting Score
	direction = 3;	//

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

bool Player::getBulletFired()
{
	return bulletFired;	//Public Bool for bullet Fired
}

int Player::getScore()
{
	return score;	//Public Player Score
}

int Player::getCurrentHealth()
{
	return currentHealth;
}

void Player::healthIncrease()
{
	currentHealth = currentHealth + 1;
	currentMaxHealth = currentMaxHealth + 1;
}

int Player::getDirection()
{
	return direction;	//Public Bool for Direction
}

void Player::shoot()
{
}

void Player::dies()
{
}

void Player::decreaseHealth()	//Decrease Player Health By 1
{
	currentHealth = currentHealth - 1;
}

void Player::increaseScore()	//Increase the Players Score
{
	score = score + 2;
}

