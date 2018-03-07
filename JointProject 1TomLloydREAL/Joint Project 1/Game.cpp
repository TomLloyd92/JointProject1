// Name: Tom Lloyd
// Login: C00231308
// Date: 16/02/2018
// Time taken: 20hours
//---------------------------------------------------------------------------
// Project description: Zelda - Top Down hack and slash game.
// ---------------------------------------------------------------------------
// Known Bugs: "Bat" enemy may escape screen. Rarely happens but when it does the player cannot continue. 
// ?

//////////////////////////////////////////////////////////// 
// include correct library file for release and debug versions
//////////////////////////////////////////////////////////// 

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include "Game.h"   // include Game header file

int main()
{
	Game aGame;
	aGame.loadContent();
	aGame.run();

	return 0;
}

Game::Game() : window(sf::VideoMode(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGHT)), "Joint Project Game", sf::Style::Default)
// Default constructor
{
}

void Game::loadContent()
// load the font file & setup the message
{
	//BackGround
	if (!texture.loadFromFile("ASSETS/Sprites/bg.png"))
	{
		std::cout << "Load Failed!" << std::endl;
	}
	backgroundSprite.setTexture(texture);


	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file file";
	}

	// set up the message string 
	m_message.setFont(m_font);  // set the font for the text
	m_message.setCharacterSize(24); // set the text size
	m_message.setFillColor(sf::Color::White); // set the text colour
	m_message.setPosition(10, 10);  // its position on the screen
}

void Game::run()
// This function contains the main game loop which controls the game. 
{
	srand(time(nullptr)); // set the seed once

	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// the clock object keeps the time.
	sf::Clock clock;


	clock.restart();

	while (window.isOpen())
	{
		// check if the close window button is clicked on
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//get the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.
		if (timeSinceLastUpdate > timePerFrame)
		{

			update();
			draw();

			// reset the timeSinceLastUpdate to 0 
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}  // end while loop

}

void Game::update()
// This function updates the game world
{
	if (linkAlive == true)
	{
		//Music
		//Object Updates
		Link.update();	//Update Link Every Frame
		for (int i = 0; i < currentSkeletons; i++)	//Skeleton Update Loop
		{
			if (Skeleton[i].getAlive() == true)	//Check the Skeleton is alive before updating
			{
				Skeleton[i].update();
			}
		}
		for (int i = 0; i < currentKnights; i++)	//Knight Update Loop
		{
			if (Knight[i].getAlive() == true)	//Check the Knight is alive before Updating
			{
				Knight[i].update();
			}
		}
		for (int i = 0; i < currentBats; i++)	//Bat Update Loop
		{
			if (bat[i].getAlive() == true)
			{
				bat[i].update();	//Check the bat is alive before Updating
			}
		}

		bullet.update();	//Bullet Update
		health.update();	//health Pick Up Update

		//Bullet Key Press
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))	//Fire on Spacebar Press
		{
			if (bullet.bulletFired == false)	//If Bullet is not already fired
			{
				bullet.getPlayerDirection(Link.getDirection());	//Get Players Direction
				bullet.getPlayerPosition(Link.getPosition());	//Get Players Position
				bullet.fired();	//Fire Bullet
			}
		}

		//Knight set to follow
		for (int i = 0; i < currentKnights; i++)	//Loop through all knights to follow
		{
			Knight[i].getPlayerPosition(Link.getPosition());	//Get Player Position and Knight Follows
		}

		//Collision Detection
		collisionPlayer();	//Check Enemys Hitting Player
		collisionArrow();	//Check Arrows Hitting Enemys

		//Update Health if Link is hit
		if (playerHit == true && m_shieldRemaining-- == 0)
		{
			Link.decreaseHealth();	//Decrease Health
			playerHit = false;
			//Link.spriteColor();
		}

		//Link Alive Checker
		linkAliveChecker();

		//Check Enemys Still Alive
		enemysLiving = enemysAlive();
		if (enemysLiving == false)	//If Enemys Are All Dead
		{
			std::cout << "Level Cleared!" << std::endl;	//Cleared Level
			level++;	//Increase Level

			monsterSpawner();	//Spawn new amount of monsters
			reset();	//reset 
		}
	}
	else if (linkAlive == false)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))	//Press "R" to restart
		{
			linkAlive = true;	//Link Is Now Alive on reset

			level = 1;	//level reset to 1

			monsterSpawner();	//Spawn Monsters
			reset();	//Reset Monsters/health
			Link.resetPlayer();	//Reset Player Stats
		}
	}

	//Set Text and Score
	scoreDisplay();
	restartText();
}

void Game::draw()
// This function draws the game world
{
	// Clear the screen and draw your game sprites
	window.clear();
	window.draw(backgroundSprite);
	window.draw(Link.getPlayerSprite());
	if (health.getHealthCollected() == false)
	{
		window.draw(health.getSprite());
	}
	for (int i = 0; i < currentSkeletons; i++)	//Skelton Drawing Loop
	{		
		if (Skeleton[i].getAlive() == true)
		{
			window.draw(Skeleton[i].getEnemyEasySprite());
		}
	}

	for (int i = 0; i < currentKnights; i++)	//Knight Drawing Loop
	{
		if (Knight[i].getAlive() == true)
		{
			window.draw(Knight[i].getEnemyHardSprite());
		}
	}

	for (int i = 0; i < currentBats; i++)	//Bat Drawing Loop
	{
		if (bat[i].getAlive() == true)
		{
			window.draw(bat[i].getEnemyCrazySprite());
		}
	}
	window.draw(bullet.getPlayerArrowSprite());

	for (int i = 0; i < Link.getCurrentHealth(); i++)
	{
		window.draw(Link.getHealthSprite(i));
	}

	if (linkAlive == false)
	{
		window.draw(gameOver.getGameOverSprite());
		window.draw(m_restart);		
	}
	
	window.draw(m_restart);

	window.draw(m_message);  // write message to the screen
	window.display();
}//END OF DRAWING

void Game::scoreDisplay()
{
	m_message.setPosition(10, 20);
	m_message.setString("SCORE: " + std::to_string(Link.getScore()));
	m_message.setCharacterSize(12);
}

//Check Arrow Hitting Enemys
void Game::collisionArrow()
{
	for (int i = 0; i < currentSkeletons; i++)	//Arrow collision detection loop Skeletons
	{
		if (Skeleton[i].getAlive() == true)	//Check if Skeleton is alive before checking collision
		{
			if (bullet.getPlayerArrowSprite().getGlobalBounds().intersects(Skeleton[i].getEnemyEasySprite().getGlobalBounds()))
			{
				std::cout << "Bullet Hit Skeleton!" << std::endl;
				bullet.bulletDestroy();
				Link.increaseScore();
				Skeleton[i].kill();
			}
		}
	}
	for (int i = 0; i < currentKnights; i++)	//Arrow collision detection loop Knights
	{
		if (Knight[i].getAlive() == true)	//Check if the knight is alive before checking collision
		{
			if (bullet.getPlayerArrowSprite().getGlobalBounds().intersects(Knight[i].getEnemyHardSprite().getGlobalBounds()))
			{
				std::cout << "Bullet Hit Knight!" << std::endl;
				bullet.bulletDestroy();
				Link.increaseScore();
				Knight[i].kill();
			}
		}
	}
	for (int i = 0; i < currentBats; i++)	//Arrow collision detection loop Bats
	{
		if (bat[i].getAlive() == true)	//Check if the bat is alive before checking collision
		{
			if (bullet.getPlayerArrowSprite().getGlobalBounds().intersects(bat[i].getEnemyCrazySprite().getGlobalBounds()))
			{
				std::cout << "Bullet Hit Bat!" << std::endl;
				bullet.bulletDestroy();
				Link.increaseScore();
				bat[i].kill();
			}
		}
	}
}

//Check Enemys/HealthPickups Hitting Link
void Game::collisionPlayer()
{
	if (Link.getPlayerSprite().getGlobalBounds().intersects(health.getSprite().getGlobalBounds()))
	{
		health.healthPickedUp();
		Link.healthIncrease();
	}

	if (playerHit == false)
	{
		for (int i = 0; i < currentSkeletons; i++)	//Link collision loop with Skeletons
		{
			if (Skeleton[i].getAlive() == true)	//Check if Skeleton is alive before checking collision
			{
				if (Link.getPlayerSprite().getGlobalBounds().intersects(Skeleton[i].getEnemyEasySprite().getGlobalBounds()))
				{
					std::cout << "Link Has Been Hit by Easy Enemy!" << std::endl;
					playerHit = true;
					m_shieldRemaining = 60;
				}
			}
		}
		for (int i = 0; i < currentKnights; i++)	//Link collision loop with Knights
		{
			if (Knight[i].getAlive() == true)	//Check if the knight is alive before checking collision
			{
				if (Link.getPlayerSprite().getGlobalBounds().intersects(Knight[i].getEnemyHardSprite().getGlobalBounds()))
				{
					std::cout << "Link Has Been Hit by Hard Enemy!" << std::endl;
					playerHit = true;
					m_shieldRemaining = 60;
				}
			}
		}
		for (int i = 0; i < currentBats; i++)	//Link collision loop with Bats
		{
			if (bat[i].getAlive() == true)	//Check if the bat is alive before checking collision
			{
				if (Link.getPlayerSprite().getGlobalBounds().intersects(bat[i].getEnemyCrazySprite().getGlobalBounds()))
				{
					std::cout << "Link Has Been Hit by Crazy Enemy!" << std::endl;
					playerHit = true;
					m_shieldRemaining = 60;
				}
			}
		}
	}
}

void Game::playerHitFun()
{
	if (playerHit == true)
	{
		for (int i = 0; i <= 60; i++)	//One second of invunrability
		{
			if (i == 0)
			{
				Link.decreaseHealth();
			}
			else if (i == 60)
			{
				playerHit = false;
			}
		}
	}
}

bool Game::enemysAlive()
{
	bool enemysAlive;
	bool skeletonsAliveBool;
	bool knightsAliveBool;
	bool batsAliveBool;

	skeletonsAliveBool = skeletonsAlive();
	knightsAliveBool = knightsAlive();
	batsAliveBool = batsAlive();

	if (skeletonsAliveBool == true || knightsAliveBool == true || batsAliveBool == true)
	{
		enemysAlive = true;
	}
	else
	{
		enemysAlive = false;
	}
	return enemysAlive;
}

bool Game::skeletonsAlive()	//Check for any Skeletons Alive
{
	bool skeletonsAlive = false;

	for (int i = 0; i < currentSkeletons; i++)	
	{
		if (Skeleton[i].getAlive() == true)
		{
			skeletonsAlive = true;
		}
	}
	return skeletonsAlive;
}

bool Game::knightsAlive()	//Check for any Knights Alive
{
	bool knightsAlive = false;

	for (int i = 0; i < currentKnights; i++)	
	{
		if (Knight[i].getAlive() == true)
		{
			knightsAlive = true;
		}
	}
	return knightsAlive;
}

bool Game::batsAlive()	//Check for any Bats Alive
{
	bool batsAlive = false;

	for (int i = 0; i < currentBats; i++)	
	{
		if (bat[i].getAlive() == true)
		{
			batsAlive = true;
		}
	}
	return batsAlive;
}

void Game::linkAliveChecker()
{
	if (Link.getCurrentHealth() == 0)
	{
		linkAlive = false;
	}
}

void Game::gameOverScreen()
{
}

void Game::restartText()
{
	/*
	m_restart.setPosition(10, 50);
	m_restart.setString("Press 'R' to restart");
	m_restart.setCharacterSize(10);
	m_restart.setFillColor(sf::Color(255,255,255));
	*/

	m_restart.setPosition(10, 20);
	m_restart.setString("SCORE: " + std::to_string(Link.getScore()));
	m_restart.setCharacterSize(12);
}

void Game::reset()
{
	Link.resetPosition();	//Reset Link to the middle of the screen
	for (int i = 0; i < currentBats; i++)	//Spawn All Current Bats
	{
		bat[i].respawn();
	}
	for (int i = 0; i < currentKnights; i++)	//Spawn All Current Knights
	{
		Knight[i].respawn();
	}
	for (int i = 0; i < currentSkeletons; i++)	//Spawn All Current Skeletons
	{
		Skeleton[i].respawn();
	}
	health.reset();
}

void Game::musicLoad()
{
	

}

void Game::monsterSpawner()
{
	if (level == 1)	//Level One Basic Skeleton Only
	{
		currentSkeletons = 1;
		currentKnights = 0;
		currentBats = 0;
	}
	else if (level == 2)	//Level Two introduce the Knight
	{
		currentSkeletons = 2;
		currentKnights = 1;
		currentBats = 0;
	}
	else if (level == 3)	//Level Three Introduce the Bat
	{
		currentSkeletons = 2;
		currentKnights = 0;
		currentBats = 1;
	}
	else if (level == 4)	//All Enemys Active
	{
		currentSkeletons = 2;
		currentKnights = 1;
		currentBats = 1;
	}
	else
	{
		currentSkeletons = currentSkeletons + 1;	//Every Level Increase Enemys by 1
		currentKnights = currentKnights + 1;
		currentBats = currentBats + 1;
	}
}