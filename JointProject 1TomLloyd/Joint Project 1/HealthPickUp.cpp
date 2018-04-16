#include "HealthPickUp.h"

HealthPickUp::HealthPickUp()	//Default Constructor
{
	setBody();
	setPosition();

	healthCollected = false;
}

void HealthPickUp::setBody()
{
	loadTextures();
	setSprite();
}

void HealthPickUp::loadTextures()
{
	if (!texture.loadFromFile("ASSETS/Sprites/PickUpLives.png"))
	{
		std::cout << "Load Failed Health PickUp!" << std::endl;
	}
}

void HealthPickUp::setSprite()
{
	healthSprite.setTexture(texture);	//Set Up Sprite Health Pick Up
}

void HealthPickUp::setPosition()
{
	int xPos = rand() % 400;	//Random Starting Position X
	if (xPos < FENCE_WIDTH_LEFT)	//Spawn them INSIDE the fence perimiter X
	{
		xPos = xPos + FENCE_WIDTH_LEFT;
	}
	else if (xPos >(SCREEN_WIDTH - FENCE_WIDTH_RIGHT))
	{
		xPos = xPos - FENCE_WIDTH_RIGHT;
	}

	int yPos = rand() % 320;	//Random Starting Position Y
	if (yPos < FENCE_HEIGHT_TOP)	//Spawn them INSIDE the fence perimiter Y
	{
		yPos = yPos + FENCE_HEIGHT_TOP;
	}
	else if (yPos >(SCREEN_HEIGHT - FENCE_HEIGHT_BOT))
	{
		yPos = yPos - FENCE_HEIGHT_BOT;
	}

	healthSprite.setPosition(xPos, yPos);
}

sf::Sprite HealthPickUp::getSprite()
{
	return sf::Sprite(healthSprite);	//return the Health Pick Up sprite
}

void HealthPickUp::update()
{
	sf::Vector2f pos = healthSprite.getPosition();

	if (healthCollected == true)	//If the health is collected put it off the screen so player cannot pick it up
	{
		pos = { 0,0 };
	}

	healthSprite.setPosition(pos);
}

void HealthPickUp::healthPickedUp()	//Changes boolean to picked up
{
	healthCollected = true;
}

void HealthPickUp::reset()
{
	setBody();
	setPosition();

	healthCollected = false;
}

bool HealthPickUp::getHealthCollected()
{
	return healthCollected;
}
