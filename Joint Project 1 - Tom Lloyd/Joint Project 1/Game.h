// Game class declaration
#pragma once

#include "Player.h"   // Include Player Class
#include "EnemyEasy.h"	//Include Enemy Easy Class
#include "EnemyHard.h"	//Include Enemy Hard Class

#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function

#include "Globals.h"   // include Global header file

class Game
{
	// private data members

	// put your game objects here eg player object and 
	// array of enemy objects etc.

	sf::RenderWindow window;

public:
	sf::Font m_font;  // font for writing text
	sf::Text m_message;  // text to write on the screen
	Player Link;
	EnemyEasy Skeleton;
	EnemyHard Knight;
	


public:	  // declaration of member functions	
	Game(); // default constructor
	void	loadContent();
	void	run();
	void	update();
	void	draw();
};
