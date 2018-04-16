// Game class declaration
#pragma once

#include "Player.h"   // Include Player Class
#include "EnemyEasy.h"	//Include Enemy Easy Class
#include "EnemyHard.h"	//Include Enemy Hard Class
#include "EnemyCrazy.h"	//Include Enemy Crazy Class
#include "GameOver.h" //Include the Game Over Class
#include "HealthPickUp.h"	//Include the Health PickUp Class

#include "SFML/Graphics.hpp" 
#include "SFML/Audio.hpp"
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function

#include <string>

#include "Globals.h"   // include Global header file

class Game
{
	// private data members
	// put your game objects here eg player object and 
	// array of enemy objects etc.
	sf::RenderWindow window;

public:
	sf::Texture texture;
	sf::Sprite backgroundSprite;

	//Text
	sf::Font m_font;  // font for writing text
	sf::Text m_message;  // text to write on the screen
	sf::Text m_restart; //text to tell player to restart

	//Sounds
	void musicLoad();

	//Objects
	static const int maxSkeletons = 10;	//Absalout Max Skeletons aloud in the game at once
	static const int maxKnights = 10;	//Absaloute Max Knights Aloud in the game at once
	static const int maxBats = 10;	//Absaloute Max Bats Aloud in the Game at once

	int currentSkeletons = 1;	//Current Amount of Skeletons in game
	int currentKnights = 0;	//Current Amount of Knights in Game
	int currentBats = 0;	//Current Amount of Bats in Game

	void monsterSpawner();	//Increase/Decrease Amount of Monsters in the game currently

	Player Link;	//Player Object Link
	PlayerBullet bullet;	//Players Bullet Object

	EnemyEasy Skeleton[maxSkeletons];	//Skeleton Array
	EnemyHard Knight[maxKnights];	//Knights Array
	EnemyCrazy bat[maxBats];	//Bats Array
	GameOver gameOver;	//Game over
	HealthPickUp health;	//Health pick Up Object
	
	//Collisions
	void collisionArrow();	//Checking the boundry of player bullet against enemy sprites
	void collisionPlayer();	//Checking the boundy of Player against enemy sprites
	bool playerHit = false;	//Player hit boolean
	void playerHitFun();	//Deals with consequence of the player being hit

	//Enemys/Link Alive Checker
	bool enemysLiving;	//Bool that when changed will change the game state
	bool enemysAlive();
	bool skeletonsAlive();
	bool knightsAlive();
	bool batsAlive();
	bool linkAlive = true;	//Link starts the game alive

	void linkAliveChecker();
	void gameOverScreen();
	void reset();

	/*
	//Sound
	sf::SoundBuffer buffer;
	sf::Sound sound;

	if (!buffer.loadFromFile("ASSETS/Sounds/MainTheme.wav"))
	{
		std::cout << "Main Theme didnt load!" << std::endl;
	}
	sound.setBuffer(buffer);
	*/

	//Level
	int level = 1;	//Level, begining at 1
	int m_shieldRemaining{ 0 }; // normally zero set to 60 when hit


public:	  // declaration of member functions	
	Game(); // default constructor
	void	loadContent();
	void	run();
	void	update();
	void	draw();

	void restartText();
	void scoreDisplay();	//Displays the score that the player has achived
};
